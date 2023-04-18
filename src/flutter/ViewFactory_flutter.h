/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#ifndef KDDOCKWIDGETS_ViewFactory_flutter_H
#define KDDOCKWIDGETS_ViewFactory_flutter_H
#pragma once

#include "core/ViewFactory.h"
#include "NonQtCompat_p.h"

// clazy:excludeall=ctor-missing-parent-argument

/**
 * @file
 * @brief A factory class for allowing the user to customize some internal widgets.
 *
 * @author Sérgio Martins \<sergio.martins@kdab.com\>
 */


namespace KDDockWidgets {

class DropIndicatorOverlay;

namespace Core {
class MDILayoutWidget;
class DropArea;
class Separator;
class TabBar;
class SideBar;
class FloatingWindow;
class MainWindow;
}

/**
 * @brief The default ViewFactory for Flutter frontend
 */
class DOCKS_EXPORT ViewFactory_flutter : public Core::ViewFactory
{
    Q_OBJECT
public:
    ViewFactory_flutter() = default;
    ~ViewFactory_flutter() override;

    Core::View *createDockWidget(const QString &uniqueName, DockWidgetOptions = {},
                                 LayoutSaverOptions = {}, Qt::WindowFlags = {}) const override;

    Core::View *createGroup(Core::Group *, Core::View *parent = nullptr) const override;
    Core::View *createTitleBar(Core::TitleBar *, Core::View *parent) const override;
    Core::View *createStack(Core::Stack *, Core::View *parent) const override;
    Core::View *createTabBar(Core::TabBar *tabBar, Core::View *parent = nullptr) const override;
    Core::View *createSeparator(Core::Separator *, Core::View *parent = nullptr) const override;
    Core::View *createFloatingWindow(Core::FloatingWindow *,
                                     Core::MainWindow *parent = nullptr,
                                     Qt::WindowFlags windowFlags = {}) const override;
    Core::View *createRubberBand(Core::View *parent) const override;
    Core::View *createSideBar(Core::SideBar *, Core::View *parent) const override;
    Core::View *createDropArea(Core::DropArea *, Core::View *parent) const override;
    Core::View *createMDILayout(Core::MDILayout *, Core::View *parent) const override;
    Icon iconForButtonType(TitleBarButtonType type, qreal dpr) const override;
    QAbstractButton *createTitleBarButton(QWidget *parent, TitleBarButtonType) const;

    Core::ClassicIndicatorWindowViewInterface *
    createClassicIndicatorWindow(Core::ClassicIndicators *) const override;

    Core::View *createSegmentedDropIndicatorOverlayView(Core::SegmentedIndicators *controller,
                                                        Core::View *parent = nullptr) const override;

private:
    Q_DISABLE_COPY(ViewFactory_flutter)
};

}

#endif
