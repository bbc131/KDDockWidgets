/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/


/**
 * @file
 * @brief The MainWindow base class that's shared between QtWidgets and QtQuick stack
 *
 * @author Sérgio Martins \<sergio.martins@kdab.com\>
 */

#include "MainWindow.h"
#include "KDDockWidgets.h"
#include "private/DockRegistry_p.h"
#include "private/MDILayoutWidget_p.h"
#include "private/DropArea_p.h"
#include "private/Utils_p.h"
#include "private/Logging_p.h"
#include "private/WidgetResizeHandler_p.h"
#include "FrameworkWidgetFactory.h"
#include "private/DropAreaWithCentralFrame_p.h"
#include "private/LayoutSaver_p.h"
#include "private/multisplitter/Item_p.h"

#include "controllers/DockWidget_p.h"
#include "controllers/Frame.h"
#include "controllers/SideBar.h"

// Or we can have a createDockWidget() in the factory
#ifdef KDDOCKWIDGETS_QTQUICK
#include "DockWidgetQuick.h"
#else
// TODO: Use framework factory instead
#include "views_qtwidgets/DockWidget_qtwidgets.h"
#include "views_qtwidgets/MainWindow_qtwidgets.h"
#endif

using namespace KDDockWidgets;
using namespace KDDockWidgets::Controllers;

static LayoutWidget *createLayoutWidget(MainWindow *mainWindow, MainWindowOptions options)
{
    if (options & MainWindowOption_MDI)
        return new MDILayoutWidget(mainWindow->view()->asQWidget());

    return new DropAreaWithCentralFrame(mainWindow->view()->asQWidget(), options);
}

class MainWindow::Private
{
public:
    explicit Private(MainWindow *mainWindow, const QString &, MainWindowOptions options)
        : m_options(options)
        , q(mainWindow)
    {
    }

    bool supportsCentralFrame() const
    {
        return m_options & MainWindowOption_HasCentralFrame;
    }

    bool supportsPersistentCentralWidget() const
    {
        if (!dropArea()) {
            // This is the MDI case
            return false;
        }

        return (m_options & MainWindowOption_HasCentralWidget) == MainWindowOption_HasCentralWidget;
    }

    Controllers::DockWidget *createPersistentCentralDockWidget(const QString &uniqueName) const
    {
        if (!supportsPersistentCentralWidget())
            return nullptr;

        auto dw = new Controllers::DockWidget(QStringLiteral("%1-persistentCentralDockWidget").arg(uniqueName));
        dw->dptr()->m_isPersistentCentralDockWidget = true;
        Controllers::Frame *frame = dropArea()->m_centralFrame;
        if (!frame) {
            qWarning() << Q_FUNC_INFO << "Expected central frame";
            return nullptr;
        }

        frame->addWidget(dw);
        return dw;
    }

    DropAreaWithCentralFrame *dropArea() const
    {
        return qobject_cast<DropAreaWithCentralFrame *>(m_layoutWidget);
    }

    CursorPositions allowedResizeSides(SideBarLocation loc) const;

    QRect rectForOverlay(Controllers::Frame *, SideBarLocation) const;
    SideBarLocation preferredSideBar(Controllers::DockWidget *) const;
    void updateOverlayGeometry(QSize suggestedSize);
    void clearSideBars();

    QString name;
    QStringList affinities;
    const MainWindowOptions m_options;
    MainWindow *const q;
    QPointer<Controllers::DockWidget> m_overlayedDockWidget;
    LayoutWidget *m_layoutWidget = nullptr;
    Controllers::DockWidget *m_persistentCentralDockWidget = nullptr;
};

MainWindow::MainWindow(const QString &uniqueName, KDDockWidgets::MainWindowOptions options,
                       WidgetType *parent, Qt::WindowFlags flags)
    : Controller(Type::MainWindow, new Views::MainWindow_qtwidgets(this, parent, flags))
    , d(new Private(this, uniqueName, options))
{
    init(uniqueName, true);
}

MainWindow::MainWindow(View *view, const QString &uniqueName, MainWindowOptions options)
    : Controller(Type::MainWindow, view)
    , d(new Private(this, uniqueName, options))
{
    // Convenience CTOR called by Views
}

void MainWindow::init(const QString &name, bool initView)
{
    d->m_layoutWidget = createLayoutWidget(this, d->m_options);

    if (initView)
        view()->init();

    d->m_persistentCentralDockWidget = d->createPersistentCentralDockWidget(d->name);

    setUniqueName(name);

    connect(d->m_layoutWidget, &LayoutWidget::visibleWidgetCountChanged, this,
            &MainWindow::frameCountChanged);
}

MainWindow::~MainWindow()
{
    DockRegistry::self()->unregisterMainWindow(this);
    delete d;
}

void MainWindow::addDockWidgetAsTab(Controllers::DockWidget *widget)
{
    Q_ASSERT(widget);
    qCDebug(addwidget) << Q_FUNC_INFO << widget;

    if (!DockRegistry::self()->affinitiesMatch(d->affinities, widget->affinities())) {
        qWarning() << Q_FUNC_INFO << "Refusing to dock widget with incompatible affinity."
                   << widget->affinities() << affinities();
        return;
    }

    if (widget->options() & Controllers::DockWidget::Option_NotDockable) {
        qWarning() << Q_FUNC_INFO << "Refusing to dock non-dockable widget" << widget;
        return;
    }

    if (isMDI()) {
        // Not applicable to MDI
        return;
    }

    if (d->supportsPersistentCentralWidget()) {
        qWarning() << Q_FUNC_INFO << "Not supported with MainWindowOption_HasCentralWidget."
                   << "MainWindowOption_HasCentralWidget can only have 1 widget in the center."
                   << "Use MainWindowOption_HasCentralFrame instead, which is similar but supports tabbing";
    } else if (d->supportsCentralFrame()) {
        dropArea()->m_centralFrame->addWidget(widget);
    } else {
        qWarning() << Q_FUNC_INFO << "Not supported without MainWindowOption_HasCentralFrame";
    }
}

void MainWindow::addDockWidget(Controllers::DockWidget *dw, Location location,
                               Controllers::DockWidget *relativeTo, InitialOption option)
{
    if (dw->options() & Controllers::DockWidget::Option_NotDockable) {
        qWarning() << Q_FUNC_INFO << "Refusing to dock non-dockable widget" << dw;
        return;
    }

    if (isMDI()) {
        // Not applicable to MDI
        return;
    }

    dropArea()->addDockWidget(dw, location, relativeTo, option);
}

QString MainWindow::uniqueName() const
{
    return d->name;
}

MainWindowOptions MainWindow::options() const
{
    return d->m_options;
}

DropAreaWithCentralFrame *MainWindow::dropArea() const
{
    return qobject_cast<DropAreaWithCentralFrame *>(d->m_layoutWidget);
}

MultiSplitter *MainWindow::multiSplitter() const
{
    return dropArea();
}

LayoutWidget *MainWindow::layoutWidget() const
{
    return d->m_layoutWidget;
}

MDILayoutWidget *MainWindow::mdiLayoutWidget() const
{
    return qobject_cast<MDILayoutWidget *>(layoutWidget());
}

void MainWindow::setAffinities(const QStringList &affinityNames)
{
    QStringList affinities = affinityNames;
    affinities.removeAll(QString());

    if (d->affinities == affinities)
        return;

    if (!d->affinities.isEmpty()) {
        qWarning() << Q_FUNC_INFO
                   << "Affinity is already set, refusing to change."
                   << "Submit a feature request with a good justification.";
        return;
    }

    d->affinities = affinities;
}

QStringList MainWindow::affinities() const
{
    return d->affinities;
}

void MainWindow::layoutEqually()
{
    dropArea()->layoutEqually();
}

void MainWindow::layoutParentContainerEqually(Controllers::DockWidget *dockWidget)
{
    dropArea()->layoutParentContainerEqually(dockWidget);
}

CursorPositions MainWindow::Private::allowedResizeSides(SideBarLocation loc) const
{
    // When a sidebar is on top, you can only resize its bottom.
    // and so forth...

    switch (loc) {
    case SideBarLocation::North:
        return CursorPosition_Bottom;
    case SideBarLocation::East:
        return CursorPosition_Left;
    case SideBarLocation::West:
        return CursorPosition_Right;
    case SideBarLocation::South:
        return CursorPosition_Top;
    case SideBarLocation::None:
        return CursorPosition_Undefined;
    }

    return CursorPosition_Undefined;
}

QRect MainWindow::Private::rectForOverlay(Controllers::Frame *frame, SideBarLocation location) const
{
    Controllers::SideBar *sb = q->sideBar(location);
    if (!sb)
        return {};

    const QRect centralAreaGeo = q->centralAreaGeometry();
    const QMargins centerWidgetMargins = q->centerWidgetMargins();

    QRect rect;
    const int margin = 1;
    switch (location) {
    case SideBarLocation::North:
    case SideBarLocation::South: {

        Controllers::SideBar *leftSideBar = q->sideBar(SideBarLocation::West);
        Controllers::SideBar *rightSideBar = q->sideBar(SideBarLocation::East);
        const int leftSideBarWidth = (leftSideBar && leftSideBar->isVisible()) ? leftSideBar->width()
                                                                               : 0;
        const int rightSideBarWidth = (rightSideBar && rightSideBar->isVisible()) ? rightSideBar->width()
                                                                                  : 0;
        rect.setHeight(qMax(300, frame->view()->minSize().height()));
        rect.setWidth(centralAreaGeo.width() - margin * 2 - leftSideBarWidth - rightSideBarWidth);
        rect.moveLeft(margin + leftSideBarWidth);
        if (location == SideBarLocation::South) {
            rect.moveTop(centralAreaGeo.bottom() - centerWidgetMargins.bottom() - rect.height() - sb->height());
        } else {
            rect.moveTop(centralAreaGeo.y() + sb->height() + centerWidgetMargins.top());
        }
        break;
    }
    case SideBarLocation::West:
    case SideBarLocation::East: {
        Controllers::SideBar *topSideBar = q->sideBar(SideBarLocation::North);
        Controllers::SideBar *bottomSideBar = q->sideBar(SideBarLocation::South);
        const int topSideBarHeight = (topSideBar && topSideBar->isVisible()) ? topSideBar->height()
                                                                             : 0;
        const int bottomSideBarHeight = (bottomSideBar && bottomSideBar->isVisible()) ? bottomSideBar->height()
                                                                                      : 0;
        rect.setWidth(qMax(300, frame->view()->minSize().width()));
        rect.setHeight(centralAreaGeo.height() - topSideBarHeight - bottomSideBarHeight - centerWidgetMargins.top() - centerWidgetMargins.bottom());
        rect.moveTop(sb->view()->asQWidget()->mapTo(q->view()->asQWidget(), QPoint(0, 0)).y() + topSideBarHeight - 1);
        if (location == SideBarLocation::East) {
            rect.moveLeft(centralAreaGeo.width() - rect.width() - sb->width() - centerWidgetMargins.right() - margin);
        } else {
            rect.moveLeft(margin + centralAreaGeo.x() + centerWidgetMargins.left() + sb->width());
        }

        break;
    }
    case SideBarLocation::None:
        break;
    }

    return rect;
}

static SideBarLocation opposedSideBarLocationForBorder(Layouting::LayoutBorderLocation loc)
{
    switch (loc) {
    case Layouting::LayoutBorderLocation_North:
        return SideBarLocation::South;
    case Layouting::LayoutBorderLocation_East:
        return SideBarLocation::West;
    case Layouting::LayoutBorderLocation_West:
        return SideBarLocation::East;
    case Layouting::LayoutBorderLocation_South:
        return SideBarLocation::North;
    case Layouting::LayoutBorderLocation_All:
    case Layouting::LayoutBorderLocation_Verticals:
    case Layouting::LayoutBorderLocation_Horizontals:
    case Layouting::LayoutBorderLocation_None:
        break;
    }

    qWarning() << Q_FUNC_INFO << "Unknown loc" << loc;
    return SideBarLocation::None;
}

static SideBarLocation sideBarLocationForBorder(Layouting::LayoutBorderLocations loc)
{
    switch (loc) {
    case Layouting::LayoutBorderLocation_North:
        return SideBarLocation::North;
    case Layouting::LayoutBorderLocation_East:
        return SideBarLocation::East;
    case Layouting::LayoutBorderLocation_West:
        return SideBarLocation::West;
    case Layouting::LayoutBorderLocation_South:
        return SideBarLocation::South;
    case Layouting::LayoutBorderLocation_All:
    case Layouting::LayoutBorderLocation_Verticals:
    case Layouting::LayoutBorderLocation_Horizontals:
    case Layouting::LayoutBorderLocation_None:
        break;
    }

    return SideBarLocation::None;
}

SideBarLocation MainWindow::Private::preferredSideBar(Controllers::DockWidget *dw) const
{
    // TODO: Algorithm can still be made smarter

    Layouting::Item *item = q->layoutWidget()->itemForFrame(dw->d->frame());
    if (!item) {
        qWarning() << Q_FUNC_INFO << "No item for dock widget";
        return SideBarLocation::None;
    }

    const Layouting::LayoutBorderLocations borders = item->adjacentLayoutBorders();
    const qreal aspectRatio = dw->width() / (std::max(1, dw->height()) * 1.0);

    /// 1. It's touching all borders
    if (borders == Layouting::LayoutBorderLocation_All) {
        return aspectRatio > 1.0 ? SideBarLocation::South
                                 : SideBarLocation::East;
    }

    /// 2. It's touching 3 borders
    for (auto borderLoc : { Layouting::LayoutBorderLocation_North, Layouting::LayoutBorderLocation_East,
                            Layouting::LayoutBorderLocation_West, Layouting::LayoutBorderLocation_South }) {
        if (borders == (Layouting::LayoutBorderLocation_All & ~borderLoc))
            return opposedSideBarLocationForBorder(borderLoc);
    }

    /// 3. It's touching left and right borders
    if ((borders & Layouting::LayoutBorderLocation_Verticals) == Layouting::LayoutBorderLocation_Verticals) {
        // We could measure the distance to the top though.
        return SideBarLocation::South;
    }

    /// 4. It's touching top and bottom borders
    if ((borders & Layouting::LayoutBorderLocation_Horizontals) == Layouting::LayoutBorderLocation_Horizontals) {
        // We could measure the distance to the left though.
        return SideBarLocation::East;
    }

    // 5. It's in a corner
    if (borders == (Layouting::LayoutBorderLocation_West | Layouting::LayoutBorderLocation_South)) {
        return aspectRatio > 1.0 ? SideBarLocation::South
                                 : SideBarLocation::West;
    } else if (borders == (Layouting::LayoutBorderLocation_East | Layouting::LayoutBorderLocation_South)) {
        return aspectRatio > 1.0 ? SideBarLocation::South
                                 : SideBarLocation::East;
    } else if (borders == (Layouting::LayoutBorderLocation_West | Layouting::LayoutBorderLocation_North)) {
        return aspectRatio > 1.0 ? SideBarLocation::North
                                 : SideBarLocation::West;
    } else if (borders == (Layouting::LayoutBorderLocation_East | Layouting::LayoutBorderLocation_North)) {
        return aspectRatio > 1.0 ? SideBarLocation::North
                                 : SideBarLocation::East;
    }


    {
        // 6. It's only touching 1 border
        SideBarLocation loc = sideBarLocationForBorder(borders);
        if (loc != SideBarLocation::None)
            return loc;
    }

    // It's not touching any border, use aspect ratio.
    return aspectRatio > 1.0 ? SideBarLocation::South
                             : SideBarLocation::West;
}

void MainWindow::Private::updateOverlayGeometry(QSize suggestedSize)
{
    if (!m_overlayedDockWidget)
        return;

    Controllers::SideBar *sb = q->sideBarForDockWidget(m_overlayedDockWidget);
    if (!sb) {
        qWarning() << Q_FUNC_INFO << "Expected a sidebar";
        return;
    }

    const QRect defaultGeometry = rectForOverlay(m_overlayedDockWidget->d->frame(), sb->location());
    QRect newGeometry = defaultGeometry;

    Controllers::Frame *frame = m_overlayedDockWidget->d->frame();

    if (suggestedSize.isValid() && !suggestedSize.isEmpty()) {
        // Let's try to honour the suggested overlay size
        switch (sb->location()) {
        case SideBarLocation::North: {
            const int maxHeight = q->height() - frame->pos().y() - 10; // gap
            newGeometry.setHeight(qMin(suggestedSize.height(), maxHeight));
            break;
        }
        case SideBarLocation::South: {
            const int maxHeight = sb->pos().y() - m_layoutWidget->View::pos().y() - 10; // gap
            const int bottom = newGeometry.bottom();
            newGeometry.setHeight(qMin(suggestedSize.height(), maxHeight));
            newGeometry.moveBottom(bottom);
            break;
        }
        case SideBarLocation::East: {
            const int maxWidth = sb->pos().x() - m_layoutWidget->View::pos().x() - 10; // gap
            const int right = newGeometry.right();
            newGeometry.setWidth(qMin(suggestedSize.width(), maxWidth));
            newGeometry.moveRight(right);
            break;
        }
        case SideBarLocation::West: {
            const int maxWidth = q->width() - frame->pos().x() - 10; // gap
            newGeometry.setWidth(qMin(suggestedSize.width(), maxWidth));
            break;
        }
        case SideBarLocation::None:
            qWarning() << Q_FUNC_INFO << "Unexpected sidebar value";
            break;
        }
    }

    m_overlayedDockWidget->d->frame()->view()->setGeometry(newGeometry);
}

void MainWindow::Private::clearSideBars()
{
    for (auto loc : { SideBarLocation::North, SideBarLocation::South,
                      SideBarLocation::East, SideBarLocation::West }) {
        if (Controllers::SideBar *sb = q->sideBar(loc))
            sb->clear();
    }
}

void MainWindow::moveToSideBar(Controllers::DockWidget *dw)
{
    moveToSideBar(dw, d->preferredSideBar(dw));
}

void MainWindow::moveToSideBar(Controllers::DockWidget *dw, SideBarLocation location)
{
    if (dw->isPersistentCentralDockWidget())
        return;

    if (Controllers::SideBar *sb = sideBar(location)) {
        QScopedValueRollback<bool> rollback(dw->d->m_isMovingToSideBar, true);
        dw->forceClose();
        sb->addDockWidget(dw);
    } else {
        // Shouldn't happen
        qWarning() << Q_FUNC_INFO << "Minimization supported, probably disabled in Config::self().flags()";
    }
}

void MainWindow::restoreFromSideBar(DockWidgetBase *dw)
{
    // First un-overlay it, if it's overlayed
    if (dw == d->m_overlayedDockWidget)
        clearSideBarOverlay();

    Controllers::SideBar *sb = sideBarForDockWidget(dw);
    if (!sb) {
        // Doesn't happen
        qWarning() << Q_FUNC_INFO << "Dock widget isn't in any sidebar";
        return;
    }

    sb->removeDockWidget(dw);
    dw->setFloating(false); // dock it
}

void MainWindow::overlayOnSideBar(DockWidgetBase *dw)
{
    if (!dw || dw->isPersistentCentralDockWidget())
        return;

    const Controllers::SideBar *sb = sideBarForDockWidget(dw);
    if (!sb) {
        qWarning() << Q_FUNC_INFO << "You need to add the dock widget to the sidebar before you can overlay it";
        return;
    }

    if (d->m_overlayedDockWidget == dw) {
        // Already overlayed
        return;
    }

    // We only support one overlay at a time, remove any existing overlay
    clearSideBarOverlay();

    auto frame = new Controllers::Frame(nullptr, FrameOption_IsOverlayed);
    frame->view()->asQWidget()->setParent(view()->asQWidget()); // TODOv2
    d->m_overlayedDockWidget = dw;
    frame->addWidget(dw);
    d->updateOverlayGeometry(dw->d->lastPosition()->lastOverlayedGeometry(sb->location()).size());

    frame->setAllowedResizeSides(d->allowedResizeSides(sb->location()));
    frame->view()->show();

    Q_EMIT dw->isOverlayedChanged(true);
}

void MainWindow::toggleOverlayOnSideBar(DockWidgetBase *dw)
{
    const bool wasOverlayed = d->m_overlayedDockWidget == dw;
    clearSideBarOverlay(); // Because only 1 dock widget can be overlayed each time
    if (!wasOverlayed) {
        overlayOnSideBar(dw);
    }
}

void MainWindow::clearSideBarOverlay(bool deleteFrame)
{
    if (!d->m_overlayedDockWidget)
        return;

    Controllers::Frame *frame = d->m_overlayedDockWidget->d->frame();
    if (!frame) { // prophylactic check
        d->m_overlayedDockWidget = nullptr;
        return;
    }

    const SideBarLocation loc = d->m_overlayedDockWidget->sideBarLocation();
    d->m_overlayedDockWidget->d->lastPosition()->setLastOverlayedGeometry(
        loc, frame->geometry());

    frame->unoverlay();

    if (deleteFrame) {
        d->m_overlayedDockWidget->setParent(nullptr);
        d->m_overlayedDockWidget->view()->setParent(nullptr);
        Q_EMIT d->m_overlayedDockWidget->isOverlayedChanged(false);
        d->m_overlayedDockWidget = nullptr;
        delete frame;
    } else {
        // No cleanup, just unset. When we drag the overlay it becomes a normal floating window
        // meaning we reuse Frame. Don't delete it.
        Q_EMIT d->m_overlayedDockWidget->isOverlayedChanged(false);
        d->m_overlayedDockWidget = nullptr;
    }
}

Controllers::SideBar *MainWindow::sideBarForDockWidget(const DockWidgetBase *dw) const
{
    for (auto loc : { SideBarLocation::North, SideBarLocation::South,
                      SideBarLocation::East, SideBarLocation::West }) {

        if (Controllers::SideBar *sb = sideBar(loc)) {
            if (sb->containsDockWidget(const_cast<DockWidgetBase *>(dw)))
                return sb;
        }
    }

    return nullptr;
}

DockWidgetBase *MainWindow::overlayedDockWidget() const
{
    return d->m_overlayedDockWidget;
}

bool MainWindow::sideBarIsVisible(SideBarLocation loc) const
{
    if (Controllers::SideBar *sb = sideBar(loc)) {
        return !sb->isEmpty(); // isVisible() is always true, but its height is 0 when empty.
    }

    return false;
}

bool MainWindow::anySideBarIsVisible() const
{
    for (auto loc : { SideBarLocation::North, SideBarLocation::South,
                      SideBarLocation::East, SideBarLocation::West }) {
        if (sideBarIsVisible(loc))
            return true;
    }

    return false;
}

bool MainWindow::isMDI() const
{
    return d->m_options & MainWindowOption_MDI;
}

bool MainWindow::closeDockWidgets(bool force)
{
    bool allClosed = true;

    const auto dockWidgets = d->m_layoutWidget->dockWidgets();
    for (DockWidgetBase *dw : dockWidgets) {
        Controllers::Frame *frame = dw->d->frame();

        if (force) {
            dw->forceClose();
        } else {
            const bool closed = dw->view()->close();
            allClosed = allClosed && closed;
        }

        if (frame->beingDeletedLater()) {
            // The dock widget was closed and this frame is empty, delete immediately instead of
            // waiting. I'm not a big fan of deleting stuff later, as state becomes inconsistent

            // Empty frames are historically deleted later since they are triggered by mouse click
            // on the title bar, and the title bar is inside the frame.
            // When doing it programmatically we can delete immediately.

            delete frame;
        }
    }

    return allClosed;
}

void MainWindow::setUniqueName(const QString &uniqueName)
{
    if (uniqueName.isEmpty())
        return;

    if (d->name.isEmpty()) {
        d->name = uniqueName;
        Q_EMIT uniqueNameChanged();
        DockRegistry::self()->registerMainWindow(this);
    } else {
        qWarning() << Q_FUNC_INFO << "Already has a name." << this->uniqueName() << uniqueName;
    }
}

void MainWindow::onResized(QResizeEvent *)
{
    if (d->m_overlayedDockWidget)
        d->updateOverlayGeometry(d->m_overlayedDockWidget->d->frame()->size());
}

bool MainWindow::deserialize(const LayoutSaver::MainWindow &mw)
{
    if (mw.options != options()) {
        qWarning() << Q_FUNC_INFO << "Refusing to restore MainWindow with different options"
                   << "; expected=" << mw.options << "; has=" << options();
        return false;
    }

    if (d->affinities != mw.affinities) {
        qWarning() << Q_FUNC_INFO << "Affinty name changed from" << d->affinities
                   << "; to" << mw.affinities;

        d->affinities = mw.affinities;
    }

    const bool success = layoutWidget()->deserialize(mw.multiSplitterLayout);

    // Restore the SideBars
    d->clearSideBars();
    for (SideBarLocation loc : { SideBarLocation::North, SideBarLocation::East, SideBarLocation::West, SideBarLocation::South }) {
        Controllers::SideBar *sb = sideBar(loc);
        if (!sb)
            continue;

        const QStringList dockWidgets = mw.dockWidgetsPerSideBar.value(loc);
        for (const QString &uniqueName : dockWidgets) {

            DockWidgetBase *dw = DockRegistry::self()->dockByName(uniqueName, DockRegistry::DockByNameFlag::CreateIfNotFound);
            if (!dw) {
                qWarning() << Q_FUNC_INFO << "Could not find dock widget" << uniqueName
                           << ". Won't restore it to sidebar";
                continue;
            }

            sb->addDockWidget(dw);
        }
    }

    // Commented-out for now, we don't want to restore the popup/overlay. popups are perishable
    // if (!mw.overlayedDockWidget.isEmpty())
    //    overlayOnSideBar(DockRegistry::self()->dockByName(mw.overlayedDockWidget));

    return success;
}

LayoutSaver::MainWindow MainWindow::serialize() const
{
    LayoutSaver::MainWindow m;

    QWindow *whandle = view()->asQWidget()->windowHandle();

    m.options = options();
    m.geometry = windowGeometry();
    m.normalGeometry = view()->normalGeometry();
    m.isVisible = isVisible();
    m.uniqueName = uniqueName();
    m.screenIndex = screenNumberForWidget(view()->asQWidget());
    m.screenSize = screenSizeForWidget(view()->asQWidget());
    m.multiSplitterLayout = layoutWidget()->serialize();
    m.affinities = d->affinities;
    m.windowState = whandle ? whandle->windowState()
                            : Qt::WindowNoState;

    for (SideBarLocation loc : { SideBarLocation::North, SideBarLocation::East, SideBarLocation::West, SideBarLocation::South }) {
        if (Controllers::SideBar *sb = sideBar(loc)) {
            const QStringList dockwidgets = sb->serialize();
            if (!dockwidgets.isEmpty())
                m.dockWidgetsPerSideBar.insert(loc, dockwidgets);
        }
    }

    return m;
}

QRect MainWindow::windowGeometry() const
{
    if (QWindow *window = view()->asQWidget()->windowHandle())
        return window->geometry();

    return window()->geometry();
}

void MainWindow::setPersistentCentralWidget(QWidgetOrQuick *widget)
{
    if (!d->supportsPersistentCentralWidget()) {
        qWarning() << "MainWindow::setPersistentCentralWidget() requires MainWindowOption_HasCentralWidget";
        return;
    }

    auto dw = d->m_persistentCentralDockWidget;
    if (dw) {
        dw->setWidget(widget);
    } else {
        qWarning() << Q_FUNC_INFO << "Unexpected null central dock widget";
    }
}

QWidgetOrQuick *MainWindow::persistentCentralWidget() const
{
    if (auto dw = d->m_persistentCentralDockWidget)
        return dw->widget();

    return nullptr;
}

void MainWindow::setContentsMargins(int left, int top, int right, int bottom)
{
    auto v = qobject_cast<Views::MainWindow_qtwidgets *>(view()->asQWidget());
    v->setContentsMargins(left, top, right, bottom);
}

QMargins MainWindow::centerWidgetMargins() const
{
    auto v = qobject_cast<Views::MainWindow_qtwidgets *>(view()->asQWidget());
    return v->centerWidgetMargins();
}

Controllers::SideBar *MainWindow::sideBar(SideBarLocation loc) const
{
    auto v = qobject_cast<Views::MainWindow_qtwidgets *>(view()->asQWidget());
    return v->sideBar(loc);
}

QRect MainWindow::centralAreaGeometry() const
{
    auto v = qobject_cast<Views::MainWindow_qtwidgets *>(view()->asQWidget());
    return v->centralAreaGeometry();
}