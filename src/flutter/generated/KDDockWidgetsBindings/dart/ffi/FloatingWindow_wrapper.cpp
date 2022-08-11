/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2022 Klarälvdalens Datakonsult AB, a KDAB Group company
  <info@kdab.com> Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/
#include "FloatingWindow_wrapper.h"


#include <QDebug>


namespace Dartagnan {

typedef int (*CleanupCallback)(void *thisPtr);
static CleanupCallback s_cleanupCallback = nullptr;

template<typename T>
struct ValueWrapper
{
    T value;
};

}
namespace KDDockWidgetsBindings_wrappersNS {
FloatingWindow_wrapper::FloatingWindow_wrapper(KDDockWidgets::Controllers::Group *group,
                                               QRect suggestedGeometry)
    : ::KDDockWidgets::Controllers::FloatingWindow(group, suggestedGeometry)
{
}
FloatingWindow_wrapper::FloatingWindow_wrapper(QRect suggestedGeometry)
    : ::KDDockWidgets::Controllers::FloatingWindow(suggestedGeometry)
{
}
void FloatingWindow_wrapper::activatedChanged()
{
    ::KDDockWidgets::Controllers::FloatingWindow::activatedChanged();
}
bool FloatingWindow_wrapper::allDockWidgetsHave(KDDockWidgets::DockWidgetOption arg__1) const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::allDockWidgetsHave(arg__1);
}
bool FloatingWindow_wrapper::allDockWidgetsHave(KDDockWidgets::LayoutSaverOption arg__1) const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::allDockWidgetsHave(arg__1);
}
bool FloatingWindow_wrapper::anyDockWidgetsHas(KDDockWidgets::DockWidgetOption arg__1) const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::anyDockWidgetsHas(arg__1);
}
bool FloatingWindow_wrapper::anyDockWidgetsHas(KDDockWidgets::LayoutSaverOption arg__1) const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::anyDockWidgetsHas(arg__1);
}
bool FloatingWindow_wrapper::anyNonClosable() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::anyNonClosable();
}
bool FloatingWindow_wrapper::anyNonDockable() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::anyNonDockable();
}
bool FloatingWindow_wrapper::beingDeleted() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::beingDeleted();
}
void FloatingWindow_wrapper::customEvent(QEvent *event)
{
    if (m_customEventCallback) {
        const void *thisPtr = this;
        m_customEventCallback(const_cast<void *>(thisPtr), event);
    } else {
        ::KDDockWidgets::Controllers::FloatingWindow::customEvent(event);
    }
}
void FloatingWindow_wrapper::customEvent_nocallback(QEvent *event)
{
    ::KDDockWidgets::Controllers::FloatingWindow::customEvent(event);
}
QRect FloatingWindow_wrapper::dragRect() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::dragRect();
}
KDDockWidgets::Controllers::DropArea *FloatingWindow_wrapper::dropArea() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::dropArea();
}
void FloatingWindow_wrapper::ensureRectIsOnScreen(QRect &geometry)
{
    ::KDDockWidgets::Controllers::FloatingWindow::ensureRectIsOnScreen(geometry);
}
bool FloatingWindow_wrapper::event(QEvent *event)
{
    if (m_eventCallback) {
        const void *thisPtr = this;
        return m_eventCallback(const_cast<void *>(thisPtr), event);
    } else {
        return ::KDDockWidgets::Controllers::FloatingWindow::event(event);
    }
}
bool FloatingWindow_wrapper::event_nocallback(QEvent *event)
{
    return ::KDDockWidgets::Controllers::FloatingWindow::event(event);
}
bool FloatingWindow_wrapper::eventFilter(QObject *watched, QEvent *event)
{
    if (m_eventFilterCallback) {
        const void *thisPtr = this;
        return m_eventFilterCallback(const_cast<void *>(thisPtr), watched, event);
    } else {
        return ::KDDockWidgets::Controllers::FloatingWindow::eventFilter(watched, event);
    }
}
bool FloatingWindow_wrapper::eventFilter_nocallback(QObject *watched, QEvent *event)
{
    return ::KDDockWidgets::Controllers::FloatingWindow::eventFilter(watched, event);
}
bool FloatingWindow_wrapper::hasSingleDockWidget() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::hasSingleDockWidget();
}
bool FloatingWindow_wrapper::hasSingleFrame() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::hasSingleFrame();
}
bool FloatingWindow_wrapper::isInDragArea(QPoint globalPoint) const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::isInDragArea(globalPoint);
}
bool FloatingWindow_wrapper::isMDI() const
{
    if (m_isMDICallback) {
        const void *thisPtr = this;
        return m_isMDICallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::Controllers::FloatingWindow::isMDI();
    }
}
bool FloatingWindow_wrapper::isMDI_nocallback() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::isMDI();
}
bool FloatingWindow_wrapper::isWindow() const
{
    if (m_isWindowCallback) {
        const void *thisPtr = this;
        return m_isWindowCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::Controllers::FloatingWindow::isWindow();
    }
}
bool FloatingWindow_wrapper::isWindow_nocallback() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::isWindow();
}
KDDockWidgets::Controllers::Layout *FloatingWindow_wrapper::layout() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::layout();
}
void FloatingWindow_wrapper::maybeCreateResizeHandler()
{
    ::KDDockWidgets::Controllers::FloatingWindow::maybeCreateResizeHandler();
}
KDDockWidgets::Controllers::DropArea *FloatingWindow_wrapper::multiSplitter() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::multiSplitter();
}
void FloatingWindow_wrapper::numFramesChanged()
{
    ::KDDockWidgets::Controllers::FloatingWindow::numFramesChanged();
}
void FloatingWindow_wrapper::scheduleDeleteLater()
{
    ::KDDockWidgets::Controllers::FloatingWindow::scheduleDeleteLater();
}
void FloatingWindow_wrapper::setParentView_impl(KDDockWidgets::View *parent)
{
    if (m_setParentView_implCallback) {
        const void *thisPtr = this;
        m_setParentView_implCallback(const_cast<void *>(thisPtr), parent);
    } else {
        ::KDDockWidgets::Controllers::FloatingWindow::setParentView_impl(parent);
    }
}
void FloatingWindow_wrapper::setParentView_impl_nocallback(KDDockWidgets::View *parent)
{
    ::KDDockWidgets::Controllers::FloatingWindow::setParentView_impl(parent);
}
void FloatingWindow_wrapper::setSuggestedGeometry(QRect suggestedRect)
{
    ::KDDockWidgets::Controllers::FloatingWindow::setSuggestedGeometry(suggestedRect);
}
KDDockWidgets::Controllers::Group *FloatingWindow_wrapper::singleFrame() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::singleFrame();
}
KDDockWidgets::Controllers::TitleBar *FloatingWindow_wrapper::titleBar() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::titleBar();
}
QString FloatingWindow_wrapper::tr(const char *s, const char *c, int n)
{
    return ::KDDockWidgets::Controllers::FloatingWindow::tr(s, c, n);
}
void FloatingWindow_wrapper::updateTitleAndIcon()
{
    ::KDDockWidgets::Controllers::FloatingWindow::updateTitleAndIcon();
}
void FloatingWindow_wrapper::updateTitleBarVisibility()
{
    ::KDDockWidgets::Controllers::FloatingWindow::updateTitleBarVisibility();
}
int FloatingWindow_wrapper::userType() const
{
    return ::KDDockWidgets::Controllers::FloatingWindow::userType();
}
void FloatingWindow_wrapper::windowStateChanged()
{
    ::KDDockWidgets::Controllers::FloatingWindow::windowStateChanged();
}
FloatingWindow_wrapper::~FloatingWindow_wrapper()
{
}

}
static KDDockWidgets::Controllers::FloatingWindow *fromPtr(void *ptr)
{
    return reinterpret_cast<KDDockWidgets::Controllers::FloatingWindow *>(ptr);
}
static KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper *>(ptr);
}
extern "C" {
void c_KDDockWidgets__Controllers__FloatingWindow_Finalizer(void *, void *cppObj, void *)
{
    delete reinterpret_cast<KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper *>(cppObj);
}
void *
c_KDDockWidgets__Controllers__FloatingWindow__constructor_Group_QRect(void *group_,
                                                                      void *suggestedGeometry_)
{
    auto group = reinterpret_cast<KDDockWidgets::Controllers::Group *>(group_);
    assert(suggestedGeometry_);
    auto &suggestedGeometry = *reinterpret_cast<QRect *>(suggestedGeometry_);
    auto ptr =
        new KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper(group, suggestedGeometry);
    return reinterpret_cast<void *>(ptr);
}
void *c_KDDockWidgets__Controllers__FloatingWindow__constructor_QRect(void *suggestedGeometry_)
{
    assert(suggestedGeometry_);
    auto &suggestedGeometry = *reinterpret_cast<QRect *>(suggestedGeometry_);
    auto ptr = new KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper(suggestedGeometry);
    return reinterpret_cast<void *>(ptr);
}
// activatedChanged()
void c_KDDockWidgets__Controllers__FloatingWindow__activatedChanged(void *thisObj)
{
    fromPtr(thisObj)->activatedChanged();
}
// allDockWidgetsHave(KDDockWidgets::DockWidgetOption arg__1) const
bool c_KDDockWidgets__Controllers__FloatingWindow__allDockWidgetsHave_DockWidgetOption(
    void *thisObj, int arg__1)
{
    return fromPtr(thisObj)->allDockWidgetsHave(
        static_cast<KDDockWidgets::DockWidgetOption>(arg__1));
}
// allDockWidgetsHave(KDDockWidgets::LayoutSaverOption arg__1) const
bool c_KDDockWidgets__Controllers__FloatingWindow__allDockWidgetsHave_LayoutSaverOption(
    void *thisObj, int arg__1)
{
    return fromPtr(thisObj)->allDockWidgetsHave(
        static_cast<KDDockWidgets::LayoutSaverOption>(arg__1));
}
// anyDockWidgetsHas(KDDockWidgets::DockWidgetOption arg__1) const
bool c_KDDockWidgets__Controllers__FloatingWindow__anyDockWidgetsHas_DockWidgetOption(void *thisObj,
                                                                                      int arg__1)
{
    return fromPtr(thisObj)->anyDockWidgetsHas(
        static_cast<KDDockWidgets::DockWidgetOption>(arg__1));
}
// anyDockWidgetsHas(KDDockWidgets::LayoutSaverOption arg__1) const
bool c_KDDockWidgets__Controllers__FloatingWindow__anyDockWidgetsHas_LayoutSaverOption(
    void *thisObj, int arg__1)
{
    return fromPtr(thisObj)->anyDockWidgetsHas(
        static_cast<KDDockWidgets::LayoutSaverOption>(arg__1));
}
// anyNonClosable() const
bool c_KDDockWidgets__Controllers__FloatingWindow__anyNonClosable(void *thisObj)
{
    return fromPtr(thisObj)->anyNonClosable();
}
// anyNonDockable() const
bool c_KDDockWidgets__Controllers__FloatingWindow__anyNonDockable(void *thisObj)
{
    return fromPtr(thisObj)->anyNonDockable();
}
// beingDeleted() const
bool c_KDDockWidgets__Controllers__FloatingWindow__beingDeleted(void *thisObj)
{
    return fromPtr(thisObj)->beingDeleted();
}
// customEvent(QEvent * event)
void c_KDDockWidgets__Controllers__FloatingWindow__customEvent_QEvent(void *thisObj, void *event_)
{
    auto event = reinterpret_cast<QEvent *>(event_);
    fromWrapperPtr(thisObj)->customEvent_nocallback(event);
}
// dragRect() const
void *c_KDDockWidgets__Controllers__FloatingWindow__dragRect(void *thisObj)
{
    return new Dartagnan::ValueWrapper<QRect> { fromPtr(thisObj)->dragRect() };
}
// dropArea() const
void *c_KDDockWidgets__Controllers__FloatingWindow__dropArea(void *thisObj)
{
    return fromPtr(thisObj)->dropArea();
}
// ensureRectIsOnScreen(QRect & geometry)
void c_static_KDDockWidgets__Controllers__FloatingWindow__ensureRectIsOnScreen_QRect(
    void *geometry_)
{
    assert(geometry_);
    auto &geometry = *reinterpret_cast<QRect *>(geometry_);
    KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper::ensureRectIsOnScreen(geometry);
}
// event(QEvent * event)
bool c_KDDockWidgets__Controllers__FloatingWindow__event_QEvent(void *thisObj, void *event_)
{
    auto event = reinterpret_cast<QEvent *>(event_);
    return [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->event_nocallback(event);
        } else {
            return targetPtr->event(event);
        }
    }();
}
// eventFilter(QObject * watched, QEvent * event)
bool c_KDDockWidgets__Controllers__FloatingWindow__eventFilter_QObject_QEvent(void *thisObj,
                                                                              void *watched_,
                                                                              void *event_)
{
    auto watched = reinterpret_cast<QObject *>(watched_);
    auto event = reinterpret_cast<QEvent *>(event_);
    return [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->eventFilter_nocallback(watched, event);
        } else {
            return targetPtr->eventFilter(watched, event);
        }
    }();
}
// hasSingleDockWidget() const
bool c_KDDockWidgets__Controllers__FloatingWindow__hasSingleDockWidget(void *thisObj)
{
    return fromPtr(thisObj)->hasSingleDockWidget();
}
// hasSingleFrame() const
bool c_KDDockWidgets__Controllers__FloatingWindow__hasSingleFrame(void *thisObj)
{
    return fromPtr(thisObj)->hasSingleFrame();
}
// isInDragArea(QPoint globalPoint) const
bool c_KDDockWidgets__Controllers__FloatingWindow__isInDragArea_QPoint(void *thisObj,
                                                                       void *globalPoint_)
{
    assert(globalPoint_);
    auto &globalPoint = *reinterpret_cast<QPoint *>(globalPoint_);
    return fromPtr(thisObj)->isInDragArea(globalPoint);
}
// isMDI() const
bool c_KDDockWidgets__Controllers__FloatingWindow__isMDI(void *thisObj)
{
    return [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->isMDI_nocallback();
        } else {
            return targetPtr->isMDI();
        }
    }();
}
// isWindow() const
bool c_KDDockWidgets__Controllers__FloatingWindow__isWindow(void *thisObj)
{
    return [&] {
        auto targetPtr = fromPtr(thisObj);
        auto wrapperPtr =
            dynamic_cast<KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper *>(targetPtr);
        if (wrapperPtr) {
            return wrapperPtr->isWindow_nocallback();
        } else {
            return targetPtr->isWindow();
        }
    }();
}
// layout() const
void *c_KDDockWidgets__Controllers__FloatingWindow__layout(void *thisObj)
{
    return fromPtr(thisObj)->layout();
}
// maybeCreateResizeHandler()
void c_KDDockWidgets__Controllers__FloatingWindow__maybeCreateResizeHandler(void *thisObj)
{
    fromPtr(thisObj)->maybeCreateResizeHandler();
}
// multiSplitter() const
void *c_KDDockWidgets__Controllers__FloatingWindow__multiSplitter(void *thisObj)
{
    return fromPtr(thisObj)->multiSplitter();
}
// numFramesChanged()
void c_KDDockWidgets__Controllers__FloatingWindow__numFramesChanged(void *thisObj)
{
    fromPtr(thisObj)->numFramesChanged();
}
// scheduleDeleteLater()
void c_KDDockWidgets__Controllers__FloatingWindow__scheduleDeleteLater(void *thisObj)
{
    fromPtr(thisObj)->scheduleDeleteLater();
}
// setParentView_impl(KDDockWidgets::View * parent)
void c_KDDockWidgets__Controllers__FloatingWindow__setParentView_impl_View(void *thisObj,
                                                                           void *parent_)
{
    auto parent = reinterpret_cast<KDDockWidgets::View *>(parent_);
    fromWrapperPtr(thisObj)->setParentView_impl_nocallback(parent);
}
// setSuggestedGeometry(QRect suggestedRect)
void c_KDDockWidgets__Controllers__FloatingWindow__setSuggestedGeometry_QRect(void *thisObj,
                                                                              void *suggestedRect_)
{
    assert(suggestedRect_);
    auto &suggestedRect = *reinterpret_cast<QRect *>(suggestedRect_);
    fromPtr(thisObj)->setSuggestedGeometry(suggestedRect);
}
// singleFrame() const
void *c_KDDockWidgets__Controllers__FloatingWindow__singleFrame(void *thisObj)
{
    return fromPtr(thisObj)->singleFrame();
}
// titleBar() const
void *c_KDDockWidgets__Controllers__FloatingWindow__titleBar(void *thisObj)
{
    return fromPtr(thisObj)->titleBar();
}
// tr(const char * s, const char * c, int n)
void *c_static_KDDockWidgets__Controllers__FloatingWindow__tr_char_char_int(const char *s,
                                                                            const char *c, int n)
{
    return new Dartagnan::ValueWrapper<QString> {
        KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper::tr(s, c, n)
    };
}
// updateTitleAndIcon()
void c_KDDockWidgets__Controllers__FloatingWindow__updateTitleAndIcon(void *thisObj)
{
    fromPtr(thisObj)->updateTitleAndIcon();
}
// updateTitleBarVisibility()
void c_KDDockWidgets__Controllers__FloatingWindow__updateTitleBarVisibility(void *thisObj)
{
    fromPtr(thisObj)->updateTitleBarVisibility();
}
// userType() const
int c_KDDockWidgets__Controllers__FloatingWindow__userType(void *thisObj)
{
    return fromPtr(thisObj)->userType();
}
// windowStateChanged()
void c_KDDockWidgets__Controllers__FloatingWindow__windowStateChanged(void *thisObj)
{
    fromPtr(thisObj)->windowStateChanged();
}
void c_KDDockWidgets__Controllers__FloatingWindow__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_KDDockWidgets__Controllers__FloatingWindow__registerVirtualMethodCallback(void *ptr,
                                                                                 void *callback,
                                                                                 int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 295:
        wrapper->m_customEventCallback = reinterpret_cast<
            KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper::Callback_customEvent>(
            callback);
        break;
    case 306:
        wrapper->m_eventCallback = reinterpret_cast<
            KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper::Callback_event>(callback);
        break;
    case 307:
        wrapper->m_eventFilterCallback = reinterpret_cast<
            KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper::Callback_eventFilter>(
            callback);
        break;
    case 1406:
        wrapper->m_isMDICallback = reinterpret_cast<
            KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper::Callback_isMDI>(callback);
        break;
    case 1408:
        wrapper->m_isWindowCallback = reinterpret_cast<
            KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper::Callback_isWindow>(callback);
        break;
    case 838:
        wrapper->m_setParentView_implCallback = reinterpret_cast<
            KDDockWidgetsBindings_wrappersNS::FloatingWindow_wrapper::Callback_setParentView_impl>(
            callback);
        break;
    }
}
}
