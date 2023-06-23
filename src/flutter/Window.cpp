/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/


#include "Window.h"
#include "core/Logging_p.h"

#include <QVariant>

using namespace KDDockWidgets;
using namespace KDDockWidgets::flutter;

Window::Window(std::shared_ptr<Core::View> rootView)
    : Core::Window()
    , m_rootView(rootView)
{
    if (rootView)
        setGeometry(rootView->geometry());
}

Window::~Window() = default;

std::shared_ptr<Core::View> Window::rootView() const
{
    return m_rootView;
}

Core::Window::Ptr Window::transientParent() const
{
    return nullptr;
}

void Window::setGeometry(QRect r)
{
    m_geometry = r;
}

void Window::setVisible(bool is)
{
    if (is == m_isVisible)
        return;

    // TODO:  Actually hide the flutter window

    m_isVisible = is;
}

bool Window::supportsHonouringLayoutMinSize() const
{
    // maybe...
    return false;
}

void Window::setWindowState(WindowState)
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
}

QRect Window::geometry() const
{
    return m_geometry;
}

void Window::setProperty(const char *, const QVariant &)
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
}

QVariant Window::property(const char *) const
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
    return {};
}

bool Window::isVisible() const
{
    return m_isVisible;
}

WId Window::handle() const
{
    return WId(m_rootView ? m_rootView->handle() : HANDLE());
}

bool Window::equals(std::shared_ptr<Core::Window> w) const
{
    if (!w)
        return false;

    auto window = std::static_pointer_cast<flutter::Window>(w);
    return window->handle() == handle();
}

void Window::setFramePosition(QPoint pt)
{
    m_geometry.moveTopLeft(pt);
    m_rootView->setGeometry(m_geometry);
}

QRect Window::frameGeometry() const
{
    // TODO: How to get this from flutter
    return m_geometry;
}

void Window::resize(int w, int h)
{
    QRect geo = geometry();
    geo.setSize({ w, h });
    setGeometry(geo);
}

bool Window::isActive() const
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
    return {};
}

WindowState Window::windowState() const
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
    return {};
}

QPoint Window::mapFromGlobal(QPoint) const
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
    return {};
}

QPoint Window::mapToGlobal(QPoint) const
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
    return {};
}

void Window::destroy()
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
}

QSize Window::minSize() const
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
    return {};
}

QSize Window::maxSize() const
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
    return {};
}

QPoint Window::fromNativePixels(QPoint) const
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
    return {};
}

bool Window::isFullScreen() const
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
    return {};
}

Core::Screen::Ptr Window::screen() const
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
    return {};
}

void Window::onScreenChanged(QObject *, WindowScreenChangedCallback)
{
    spdlog::warn("{}, Not implemented yet", Q_FUNC_INFO);
}
