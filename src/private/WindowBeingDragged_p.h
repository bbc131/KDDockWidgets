/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#ifndef KD_WINDOWBEINGDRAGGED_P_H
#define KD_WINDOWBEINGDRAGGED_P_H

#include "kddockwidgets/docks_export.h"
#include "kddockwidgets/controllers/FloatingWindow.h"
#include "View.h"

#include <QPointer>

QT_BEGIN_NAMESPACE
class QPixmap;
QT_END_NAMESPACE

namespace KDDockWidgets {

namespace Controllers {
class Frame;
class FloatingWindow;
class Layout;
}

class Draggable;

struct DOCKS_EXPORT_FOR_UNIT_TESTS WindowBeingDragged
{
public:
    explicit WindowBeingDragged(Controllers::FloatingWindow *fw, Draggable *draggable);

#ifdef DOCKS_DEVELOPER_MODE
    // For tests.
    explicit WindowBeingDragged(Controllers::FloatingWindow *fw);
#endif

    virtual ~WindowBeingDragged();
    void init();

    Controllers::FloatingWindow *floatingWindow() const
    {
        return m_floatingWindow;
    }

    ///@brief grabs or releases the mouse
    void grabMouse(bool grab);

    /// @brief returns whether this window being dragged contains the specified drop area
    /// useful since we don't want to drop onto ourselves.
    bool contains(Controllers::Layout *) const;

    ///@brief returns the affinities of the window being dragged
    virtual QStringList affinities() const;

    ///@brief size of the window being dragged contents
    virtual QSize size() const;

    /// @brief returns the min-size of the window being dragged contents
    virtual QSize minSize() const;

    /// @brief returns the max-size of the window being dragged contents
    virtual QSize maxSize() const;

    /// @brief Returns a pixmap representing this Window. For purposes of QDrag. Wayland only.
    virtual QPixmap pixmap() const;

    /// @brief Returns the list of dock widgets being dragged
    virtual QVector<Controllers::DockWidget *> dockWidgets() const;

    /// @brief Returns the draggable
    Draggable *draggable() const;

protected:
    explicit WindowBeingDragged(Draggable *);
    Q_DISABLE_COPY(WindowBeingDragged)
    QPointer<Controllers::FloatingWindow> m_floatingWindow;
    Draggable *const m_draggable;
    View *m_draggableWidget;
    QPointer<QObject> m_guard;
};

struct WindowBeingDraggedWayland : public WindowBeingDragged
{
public:
    explicit WindowBeingDraggedWayland(Draggable *draggable);
    ~WindowBeingDraggedWayland() override;

    QSize size() const override;
    QSize minSize() const override;
    QSize maxSize() const override;
    QPixmap pixmap() const override;
    QStringList affinities() const override;
    QVector<Controllers::DockWidget *> dockWidgets() const override;

    // These two are set for Wayland only, where we can't make the floating window immediately (no way to position it)
    // So we're dragging either a frame with multiple dock widgets or a single tab, keep them here.
    // It's important to know what we're dragging, so drop rubber band respect min/max sizes.
    QPointer<Controllers::Frame> m_frame;
    QPointer<Controllers::DockWidget> m_dockWidget;
};

}

#endif
