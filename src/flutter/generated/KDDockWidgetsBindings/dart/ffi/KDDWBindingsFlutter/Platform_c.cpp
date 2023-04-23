/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/
#include "Platform_c.h"


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
namespace KDDWBindingsFlutter {
Platform_wrapper::Platform_wrapper()
    : ::KDDockWidgets::flutter::Platform()
{
}
QString Platform_wrapper::applicationName() const
{
    if (m_applicationNameCallback) {
        const void *thisPtr = this;
        return *m_applicationNameCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::flutter::Platform::applicationName();
    }
}
QString Platform_wrapper::applicationName_nocallback() const
{
    return ::KDDockWidgets::flutter::Platform::applicationName();
}
KDDockWidgets::Core::ViewFactory *Platform_wrapper::createDefaultViewFactory()
{
    if (m_createDefaultViewFactoryCallback) {
        const void *thisPtr = this;
        return m_createDefaultViewFactoryCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::flutter::Platform::createDefaultViewFactory();
    }
}
KDDockWidgets::Core::ViewFactory *Platform_wrapper::createDefaultViewFactory_nocallback()
{
    return ::KDDockWidgets::flutter::Platform::createDefaultViewFactory();
}
KDDockWidgets::Core::MainWindow *Platform_wrapper::createMainWindow(const QString &uniqueName, KDDockWidgets::Core::CreateViewOptions arg__2, QFlags<KDDockWidgets::MainWindowOption> options, KDDockWidgets::Core::View *parent, Qt::WindowFlags arg__5) const
{
    if (m_createMainWindowCallback) {
        const void *thisPtr = this;
        return m_createMainWindowCallback(const_cast<void *>(thisPtr), uniqueName, &arg__2, options, parent, arg__5);
    } else {
        return ::KDDockWidgets::flutter::Platform::createMainWindow(uniqueName, arg__2, options, parent, arg__5);
    }
}
KDDockWidgets::Core::MainWindow *Platform_wrapper::createMainWindow_nocallback(const QString &uniqueName, KDDockWidgets::Core::CreateViewOptions arg__2, QFlags<KDDockWidgets::MainWindowOption> options, KDDockWidgets::Core::View *parent, Qt::WindowFlags arg__5) const
{
    return ::KDDockWidgets::flutter::Platform::createMainWindow(uniqueName, arg__2, options, parent, arg__5);
}
KDDockWidgets::Core::View *Platform_wrapper::createView(KDDockWidgets::Core::Controller *controller, KDDockWidgets::Core::View *parent) const
{
    if (m_createViewCallback) {
        const void *thisPtr = this;
        return m_createViewCallback(const_cast<void *>(thisPtr), controller, parent);
    } else {
        return ::KDDockWidgets::flutter::Platform::createView(controller, parent);
    }
}
KDDockWidgets::Core::View *Platform_wrapper::createView_nocallback(KDDockWidgets::Core::Controller *controller, KDDockWidgets::Core::View *parent) const
{
    return ::KDDockWidgets::flutter::Platform::createView(controller, parent);
}
QPoint Platform_wrapper::cursorPos() const
{
    if (m_cursorPosCallback) {
        const void *thisPtr = this;
        return *m_cursorPosCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::flutter::Platform::cursorPos();
    }
}
QPoint Platform_wrapper::cursorPos_nocallback() const
{
    return ::KDDockWidgets::flutter::Platform::cursorPos();
}
void Platform_wrapper::dumpManagedBacktrace()
{
    if (m_dumpManagedBacktraceCallback) {
        const void *thisPtr = this;
        m_dumpManagedBacktraceCallback(const_cast<void *>(thisPtr));
    } else {
        ::KDDockWidgets::flutter::Platform::dumpManagedBacktrace();
    }
}
void Platform_wrapper::dumpManagedBacktrace_nocallback()
{
    ::KDDockWidgets::flutter::Platform::dumpManagedBacktrace();
}
bool Platform_wrapper::hasActivePopup() const
{
    if (m_hasActivePopupCallback) {
        const void *thisPtr = this;
        return m_hasActivePopupCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::flutter::Platform::hasActivePopup();
    }
}
bool Platform_wrapper::hasActivePopup_nocallback() const
{
    return ::KDDockWidgets::flutter::Platform::hasActivePopup();
}
bool Platform_wrapper::inDisallowedDragView(QPoint globalPos) const
{
    if (m_inDisallowedDragViewCallback) {
        const void *thisPtr = this;
        return m_inDisallowedDragViewCallback(const_cast<void *>(thisPtr), &globalPos);
    } else {
        return ::KDDockWidgets::flutter::Platform::inDisallowedDragView(globalPos);
    }
}
bool Platform_wrapper::inDisallowedDragView_nocallback(QPoint globalPos) const
{
    return ::KDDockWidgets::flutter::Platform::inDisallowedDragView(globalPos);
}
void Platform_wrapper::init()
{
    ::KDDockWidgets::flutter::Platform::init();
}
void Platform_wrapper::installMessageHandler()
{
    if (m_installMessageHandlerCallback) {
        const void *thisPtr = this;
        m_installMessageHandlerCallback(const_cast<void *>(thisPtr));
    } else {
        ::KDDockWidgets::flutter::Platform::installMessageHandler();
    }
}
void Platform_wrapper::installMessageHandler_nocallback()
{
    ::KDDockWidgets::flutter::Platform::installMessageHandler();
}
bool Platform_wrapper::isLeftMouseButtonPressed() const
{
    if (m_isLeftMouseButtonPressedCallback) {
        const void *thisPtr = this;
        return m_isLeftMouseButtonPressedCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::flutter::Platform::isLeftMouseButtonPressed();
    }
}
bool Platform_wrapper::isLeftMouseButtonPressed_nocallback() const
{
    return ::KDDockWidgets::flutter::Platform::isLeftMouseButtonPressed();
}
bool Platform_wrapper::isProcessingAppQuitEvent() const
{
    if (m_isProcessingAppQuitEventCallback) {
        const void *thisPtr = this;
        return m_isProcessingAppQuitEventCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::flutter::Platform::isProcessingAppQuitEvent();
    }
}
bool Platform_wrapper::isProcessingAppQuitEvent_nocallback() const
{
    return ::KDDockWidgets::flutter::Platform::isProcessingAppQuitEvent();
}
const char *Platform_wrapper::name() const
{
    if (m_nameCallback) {
        const void *thisPtr = this;
        return m_nameCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::flutter::Platform::name();
    }
}
const char *Platform_wrapper::name_nocallback() const
{
    return ::KDDockWidgets::flutter::Platform::name();
}
void Platform_wrapper::onFloatingWindowCreated(KDDockWidgets::Core::FloatingWindow *arg__1)
{
    if (m_onFloatingWindowCreatedCallback) {
        const void *thisPtr = this;
        m_onFloatingWindowCreatedCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        ::KDDockWidgets::flutter::Platform::onFloatingWindowCreated(arg__1);
    }
}
void Platform_wrapper::onFloatingWindowCreated_nocallback(KDDockWidgets::Core::FloatingWindow *arg__1)
{
    ::KDDockWidgets::flutter::Platform::onFloatingWindowCreated(arg__1);
}
void Platform_wrapper::onFloatingWindowDestroyed(KDDockWidgets::Core::FloatingWindow *arg__1)
{
    if (m_onFloatingWindowDestroyedCallback) {
        const void *thisPtr = this;
        m_onFloatingWindowDestroyedCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        ::KDDockWidgets::flutter::Platform::onFloatingWindowDestroyed(arg__1);
    }
}
void Platform_wrapper::onFloatingWindowDestroyed_nocallback(KDDockWidgets::Core::FloatingWindow *arg__1)
{
    ::KDDockWidgets::flutter::Platform::onFloatingWindowDestroyed(arg__1);
}
QString Platform_wrapper::organizationName() const
{
    if (m_organizationNameCallback) {
        const void *thisPtr = this;
        return *m_organizationNameCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::flutter::Platform::organizationName();
    }
}
QString Platform_wrapper::organizationName_nocallback() const
{
    return ::KDDockWidgets::flutter::Platform::organizationName();
}
KDDockWidgets::flutter::Platform *Platform_wrapper::platformFlutter()
{
    return ::KDDockWidgets::flutter::Platform::platformFlutter();
}
void Platform_wrapper::restoreMouseCursor()
{
    if (m_restoreMouseCursorCallback) {
        const void *thisPtr = this;
        m_restoreMouseCursorCallback(const_cast<void *>(thisPtr));
    } else {
        ::KDDockWidgets::flutter::Platform::restoreMouseCursor();
    }
}
void Platform_wrapper::restoreMouseCursor_nocallback()
{
    ::KDDockWidgets::flutter::Platform::restoreMouseCursor();
}
int Platform_wrapper::screenNumberFor(KDDockWidgets::Core::View *arg__1) const
{
    if (m_screenNumberForCallback) {
        const void *thisPtr = this;
        return m_screenNumberForCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        return ::KDDockWidgets::flutter::Platform::screenNumberFor(arg__1);
    }
}
int Platform_wrapper::screenNumberFor_nocallback(KDDockWidgets::Core::View *arg__1) const
{
    return ::KDDockWidgets::flutter::Platform::screenNumberFor(arg__1);
}
QSize Platform_wrapper::screenSizeFor(KDDockWidgets::Core::View *arg__1) const
{
    if (m_screenSizeForCallback) {
        const void *thisPtr = this;
        return *m_screenSizeForCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        return ::KDDockWidgets::flutter::Platform::screenSizeFor(arg__1);
    }
}
QSize Platform_wrapper::screenSizeFor_nocallback(KDDockWidgets::Core::View *arg__1) const
{
    return ::KDDockWidgets::flutter::Platform::screenSizeFor(arg__1);
}
void Platform_wrapper::setCursorPos(QPoint arg__1)
{
    if (m_setCursorPosCallback) {
        const void *thisPtr = this;
        m_setCursorPosCallback(const_cast<void *>(thisPtr), &arg__1);
    } else {
        ::KDDockWidgets::flutter::Platform::setCursorPos(arg__1);
    }
}
void Platform_wrapper::setCursorPos_nocallback(QPoint arg__1)
{
    ::KDDockWidgets::flutter::Platform::setCursorPos(arg__1);
}
void Platform_wrapper::setMouseCursor(Qt::CursorShape arg__1)
{
    if (m_setMouseCursorCallback) {
        const void *thisPtr = this;
        m_setMouseCursorCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        ::KDDockWidgets::flutter::Platform::setMouseCursor(arg__1);
    }
}
void Platform_wrapper::setMouseCursor_nocallback(Qt::CursorShape arg__1)
{
    ::KDDockWidgets::flutter::Platform::setMouseCursor(arg__1);
}
int Platform_wrapper::startDragDistance_impl() const
{
    if (m_startDragDistance_implCallback) {
        const void *thisPtr = this;
        return m_startDragDistance_implCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::flutter::Platform::startDragDistance_impl();
    }
}
int Platform_wrapper::startDragDistance_impl_nocallback() const
{
    return ::KDDockWidgets::flutter::Platform::startDragDistance_impl();
}
KDDockWidgets::Core::View *Platform_wrapper::tests_createFocusableView(KDDockWidgets::Core::CreateViewOptions arg__1, KDDockWidgets::Core::View *parent)
{
    if (m_tests_createFocusableViewCallback) {
        const void *thisPtr = this;
        return m_tests_createFocusableViewCallback(const_cast<void *>(thisPtr), &arg__1, parent);
    } else {
        return ::KDDockWidgets::flutter::Platform::tests_createFocusableView(arg__1, parent);
    }
}
KDDockWidgets::Core::View *Platform_wrapper::tests_createFocusableView_nocallback(KDDockWidgets::Core::CreateViewOptions arg__1, KDDockWidgets::Core::View *parent)
{
    return ::KDDockWidgets::flutter::Platform::tests_createFocusableView(arg__1, parent);
}
KDDockWidgets::Core::View *Platform_wrapper::tests_createNonClosableView(KDDockWidgets::Core::View *parent)
{
    if (m_tests_createNonClosableViewCallback) {
        const void *thisPtr = this;
        return m_tests_createNonClosableViewCallback(const_cast<void *>(thisPtr), parent);
    } else {
        return ::KDDockWidgets::flutter::Platform::tests_createNonClosableView(parent);
    }
}
KDDockWidgets::Core::View *Platform_wrapper::tests_createNonClosableView_nocallback(KDDockWidgets::Core::View *parent)
{
    return ::KDDockWidgets::flutter::Platform::tests_createNonClosableView(parent);
}
KDDockWidgets::Core::View *Platform_wrapper::tests_createView(KDDockWidgets::Core::CreateViewOptions arg__1, KDDockWidgets::Core::View *parent)
{
    if (m_tests_createViewCallback) {
        const void *thisPtr = this;
        return m_tests_createViewCallback(const_cast<void *>(thisPtr), &arg__1, parent);
    } else {
        return ::KDDockWidgets::flutter::Platform::tests_createView(arg__1, parent);
    }
}
KDDockWidgets::Core::View *Platform_wrapper::tests_createView_nocallback(KDDockWidgets::Core::CreateViewOptions arg__1, KDDockWidgets::Core::View *parent)
{
    return ::KDDockWidgets::flutter::Platform::tests_createView(arg__1, parent);
}
void Platform_wrapper::tests_deinitPlatform_impl()
{
    if (m_tests_deinitPlatform_implCallback) {
        const void *thisPtr = this;
        m_tests_deinitPlatform_implCallback(const_cast<void *>(thisPtr));
    } else {
        ::KDDockWidgets::flutter::Platform::tests_deinitPlatform_impl();
    }
}
void Platform_wrapper::tests_deinitPlatform_impl_nocallback()
{
    ::KDDockWidgets::flutter::Platform::tests_deinitPlatform_impl();
}
void Platform_wrapper::tests_doubleClickOn(QPoint globalPos, KDDockWidgets::Core::View *receiver)
{
    if (m_tests_doubleClickOnCallback) {
        const void *thisPtr = this;
        m_tests_doubleClickOnCallback(const_cast<void *>(thisPtr), &globalPos, receiver);
    } else {
        ::KDDockWidgets::flutter::Platform::tests_doubleClickOn(globalPos, receiver);
    }
}
void Platform_wrapper::tests_doubleClickOn_nocallback(QPoint globalPos, KDDockWidgets::Core::View *receiver)
{
    ::KDDockWidgets::flutter::Platform::tests_doubleClickOn(globalPos, receiver);
}
void Platform_wrapper::tests_initPlatform_impl()
{
    if (m_tests_initPlatform_implCallback) {
        const void *thisPtr = this;
        m_tests_initPlatform_implCallback(const_cast<void *>(thisPtr));
    } else {
        ::KDDockWidgets::flutter::Platform::tests_initPlatform_impl();
    }
}
void Platform_wrapper::tests_initPlatform_impl_nocallback()
{
    ::KDDockWidgets::flutter::Platform::tests_initPlatform_impl();
}
void Platform_wrapper::tests_wait(int ms)
{
    if (m_tests_waitCallback) {
        const void *thisPtr = this;
        m_tests_waitCallback(const_cast<void *>(thisPtr), ms);
    } else {
        ::KDDockWidgets::flutter::Platform::tests_wait(ms);
    }
}
void Platform_wrapper::tests_wait_nocallback(int ms)
{
    ::KDDockWidgets::flutter::Platform::tests_wait(ms);
}
void Platform_wrapper::ungrabMouse()
{
    if (m_ungrabMouseCallback) {
        const void *thisPtr = this;
        m_ungrabMouseCallback(const_cast<void *>(thisPtr));
    } else {
        ::KDDockWidgets::flutter::Platform::ungrabMouse();
    }
}
void Platform_wrapper::ungrabMouse_nocallback()
{
    ::KDDockWidgets::flutter::Platform::ungrabMouse();
}
void Platform_wrapper::uninstallMessageHandler()
{
    if (m_uninstallMessageHandlerCallback) {
        const void *thisPtr = this;
        m_uninstallMessageHandlerCallback(const_cast<void *>(thisPtr));
    } else {
        ::KDDockWidgets::flutter::Platform::uninstallMessageHandler();
    }
}
void Platform_wrapper::uninstallMessageHandler_nocallback()
{
    ::KDDockWidgets::flutter::Platform::uninstallMessageHandler();
}
bool Platform_wrapper::usesFallbackMouseGrabber() const
{
    if (m_usesFallbackMouseGrabberCallback) {
        const void *thisPtr = this;
        return m_usesFallbackMouseGrabberCallback(const_cast<void *>(thisPtr));
    } else {
        return ::KDDockWidgets::flutter::Platform::usesFallbackMouseGrabber();
    }
}
bool Platform_wrapper::usesFallbackMouseGrabber_nocallback() const
{
    return ::KDDockWidgets::flutter::Platform::usesFallbackMouseGrabber();
}
Platform_wrapper::~Platform_wrapper()
{
}

}
}
static KDDockWidgets::flutter::Platform *fromPtr(void *ptr)
{
    return reinterpret_cast<KDDockWidgets::flutter::Platform *>(ptr);
}
static KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper *>(ptr);
}
extern "C" {
void c_KDDockWidgets__flutter__Platform_Finalizer(void *, void *cppObj, void *)
{
    delete reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper *>(cppObj);
}
void *c_KDDockWidgets__flutter__Platform__constructor()
{
    auto ptr = new KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// applicationName() const
void *c_KDDockWidgets__flutter__Platform__applicationName(void *thisObj)
{
    return new Dartagnan::ValueWrapper<QString> { [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->applicationName_nocallback();} else {    return targetPtr->applicationName();} }() };
}
// createDefaultViewFactory()
void *c_KDDockWidgets__flutter__Platform__createDefaultViewFactory(void *thisObj)
{
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createDefaultViewFactory_nocallback();} else {    return targetPtr->createDefaultViewFactory();} }();
}
// createMainWindow(const QString & uniqueName, KDDockWidgets::Core::CreateViewOptions arg__2, QFlags<KDDockWidgets::MainWindowOption> options, KDDockWidgets::Core::View * parent, Qt::WindowFlags arg__5) const
void *c_KDDockWidgets__flutter__Platform__createMainWindow_QString_CreateViewOptions_MainWindowOptions_View_WindowFlags(void *thisObj, const char *uniqueName_, void *arg__2_, int options_, void *parent_, int arg__5)
{
    const auto uniqueName = QString::fromUtf8(uniqueName_);
    assert(arg__2_);
    auto &arg__2 = *reinterpret_cast<KDDockWidgets::Core::CreateViewOptions *>(arg__2_);
    auto options = static_cast<QFlags<KDDockWidgets::MainWindowOption>>(options_);
    auto parent = reinterpret_cast<KDDockWidgets::Core::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createMainWindow_nocallback(uniqueName,arg__2,options,parent,static_cast<Qt::WindowFlags>(arg__5));} else {    return targetPtr->createMainWindow(uniqueName,arg__2,options,parent,static_cast<Qt::WindowFlags>(arg__5));} }();
}
// createView(KDDockWidgets::Core::Controller * controller, KDDockWidgets::Core::View * parent) const
void *c_KDDockWidgets__flutter__Platform__createView_Controller_View(void *thisObj, void *controller_, void *parent_)
{
    auto controller = reinterpret_cast<KDDockWidgets::Core::Controller *>(controller_);
    auto parent = reinterpret_cast<KDDockWidgets::Core::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createView_nocallback(controller,parent);} else {    return targetPtr->createView(controller,parent);} }();
}
// cursorPos() const
void *c_KDDockWidgets__flutter__Platform__cursorPos(void *thisObj)
{
    return new Dartagnan::ValueWrapper<QPoint> { [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->cursorPos_nocallback();} else {    return targetPtr->cursorPos();} }() };
}
// dumpManagedBacktrace()
void c_KDDockWidgets__flutter__Platform__dumpManagedBacktrace(void *thisObj)
{
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->dumpManagedBacktrace_nocallback();} else {    return targetPtr->dumpManagedBacktrace();} }();
}
// hasActivePopup() const
bool c_KDDockWidgets__flutter__Platform__hasActivePopup(void *thisObj)
{
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->hasActivePopup_nocallback();} else {    return targetPtr->hasActivePopup();} }();
}
// inDisallowedDragView(QPoint globalPos) const
bool c_KDDockWidgets__flutter__Platform__inDisallowedDragView_QPoint(void *thisObj, void *globalPos_)
{
    assert(globalPos_);
    auto &globalPos = *reinterpret_cast<QPoint *>(globalPos_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->inDisallowedDragView_nocallback(globalPos);} else {    return targetPtr->inDisallowedDragView(globalPos);} }();
}
// init()
void c_KDDockWidgets__flutter__Platform__init(void *thisObj)
{
    fromWrapperPtr(thisObj)->init();
}
// installMessageHandler()
void c_KDDockWidgets__flutter__Platform__installMessageHandler(void *thisObj)
{
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->installMessageHandler_nocallback();} else {    return targetPtr->installMessageHandler();} }();
}
// isLeftMouseButtonPressed() const
bool c_KDDockWidgets__flutter__Platform__isLeftMouseButtonPressed(void *thisObj)
{
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->isLeftMouseButtonPressed_nocallback();} else {    return targetPtr->isLeftMouseButtonPressed();} }();
}
// isProcessingAppQuitEvent() const
bool c_KDDockWidgets__flutter__Platform__isProcessingAppQuitEvent(void *thisObj)
{
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->isProcessingAppQuitEvent_nocallback();} else {    return targetPtr->isProcessingAppQuitEvent();} }();
}
// name() const
const char *c_KDDockWidgets__flutter__Platform__name(void *thisObj)
{
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->name_nocallback();} else {    return targetPtr->name();} }();
}
// onFloatingWindowCreated(KDDockWidgets::Core::FloatingWindow * arg__1)
void c_KDDockWidgets__flutter__Platform__onFloatingWindowCreated_FloatingWindow(void *thisObj, void *arg__1_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::FloatingWindow *>(arg__1_);
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->onFloatingWindowCreated_nocallback(arg__1);} else {    return targetPtr->onFloatingWindowCreated(arg__1);} }();
}
// onFloatingWindowDestroyed(KDDockWidgets::Core::FloatingWindow * arg__1)
void c_KDDockWidgets__flutter__Platform__onFloatingWindowDestroyed_FloatingWindow(void *thisObj, void *arg__1_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::FloatingWindow *>(arg__1_);
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->onFloatingWindowDestroyed_nocallback(arg__1);} else {    return targetPtr->onFloatingWindowDestroyed(arg__1);} }();
}
// organizationName() const
void *c_KDDockWidgets__flutter__Platform__organizationName(void *thisObj)
{
    return new Dartagnan::ValueWrapper<QString> { [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->organizationName_nocallback();} else {    return targetPtr->organizationName();} }() };
}
// platformFlutter()
void *c_static_KDDockWidgets__flutter__Platform__platformFlutter()
{
    return KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::platformFlutter();
}
// restoreMouseCursor()
void c_KDDockWidgets__flutter__Platform__restoreMouseCursor(void *thisObj)
{
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->restoreMouseCursor_nocallback();} else {    return targetPtr->restoreMouseCursor();} }();
}
// screenNumberFor(KDDockWidgets::Core::View * arg__1) const
int c_KDDockWidgets__flutter__Platform__screenNumberFor_View(void *thisObj, void *arg__1_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::View *>(arg__1_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->screenNumberFor_nocallback(arg__1);} else {    return targetPtr->screenNumberFor(arg__1);} }();
}
// screenSizeFor(KDDockWidgets::Core::View * arg__1) const
void *c_KDDockWidgets__flutter__Platform__screenSizeFor_View(void *thisObj, void *arg__1_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::View *>(arg__1_);
    return new Dartagnan::ValueWrapper<QSize> { [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->screenSizeFor_nocallback(arg__1);} else {    return targetPtr->screenSizeFor(arg__1);} }() };
}
// setCursorPos(QPoint arg__1)
void c_KDDockWidgets__flutter__Platform__setCursorPos_QPoint(void *thisObj, void *arg__1_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<QPoint *>(arg__1_);
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->setCursorPos_nocallback(arg__1);} else {    return targetPtr->setCursorPos(arg__1);} }();
}
// setMouseCursor(Qt::CursorShape arg__1)
void c_KDDockWidgets__flutter__Platform__setMouseCursor_CursorShape(void *thisObj, int arg__1)
{
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->setMouseCursor_nocallback(static_cast<Qt::CursorShape>(arg__1));} else {    return targetPtr->setMouseCursor(static_cast<Qt::CursorShape>(arg__1));} }();
}
// startDragDistance_impl() const
int c_KDDockWidgets__flutter__Platform__startDragDistance_impl(void *thisObj)
{
    return fromWrapperPtr(thisObj)->startDragDistance_impl_nocallback();
}
// tests_createFocusableView(KDDockWidgets::Core::CreateViewOptions arg__1, KDDockWidgets::Core::View * parent)
void *c_KDDockWidgets__flutter__Platform__tests_createFocusableView_CreateViewOptions_View(void *thisObj, void *arg__1_, void *parent_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<KDDockWidgets::Core::CreateViewOptions *>(arg__1_);
    auto parent = reinterpret_cast<KDDockWidgets::Core::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->tests_createFocusableView_nocallback(arg__1,parent);} else {    return targetPtr->tests_createFocusableView(arg__1,parent);} }();
}
// tests_createNonClosableView(KDDockWidgets::Core::View * parent)
void *c_KDDockWidgets__flutter__Platform__tests_createNonClosableView_View(void *thisObj, void *parent_)
{
    auto parent = reinterpret_cast<KDDockWidgets::Core::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->tests_createNonClosableView_nocallback(parent);} else {    return targetPtr->tests_createNonClosableView(parent);} }();
}
// tests_createView(KDDockWidgets::Core::CreateViewOptions arg__1, KDDockWidgets::Core::View * parent)
void *c_KDDockWidgets__flutter__Platform__tests_createView_CreateViewOptions_View(void *thisObj, void *arg__1_, void *parent_)
{
    assert(arg__1_);
    auto &arg__1 = *reinterpret_cast<KDDockWidgets::Core::CreateViewOptions *>(arg__1_);
    auto parent = reinterpret_cast<KDDockWidgets::Core::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->tests_createView_nocallback(arg__1,parent);} else {    return targetPtr->tests_createView(arg__1,parent);} }();
}
// tests_deinitPlatform_impl()
void c_KDDockWidgets__flutter__Platform__tests_deinitPlatform_impl(void *thisObj)
{
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->tests_deinitPlatform_impl_nocallback();} else {    return targetPtr->tests_deinitPlatform_impl();} }();
}
// tests_doubleClickOn(QPoint globalPos, KDDockWidgets::Core::View * receiver)
void c_KDDockWidgets__flutter__Platform__tests_doubleClickOn_QPoint_View(void *thisObj, void *globalPos_, void *receiver_)
{
    assert(globalPos_);
    auto &globalPos = *reinterpret_cast<QPoint *>(globalPos_);
    auto receiver = reinterpret_cast<KDDockWidgets::Core::View *>(receiver_);
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->tests_doubleClickOn_nocallback(globalPos,receiver);} else {    return targetPtr->tests_doubleClickOn(globalPos,receiver);} }();
}
// tests_initPlatform_impl()
void c_KDDockWidgets__flutter__Platform__tests_initPlatform_impl(void *thisObj)
{
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->tests_initPlatform_impl_nocallback();} else {    return targetPtr->tests_initPlatform_impl();} }();
}
// tests_wait(int ms)
void c_KDDockWidgets__flutter__Platform__tests_wait_int(void *thisObj, int ms)
{
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->tests_wait_nocallback(ms);} else {    return targetPtr->tests_wait(ms);} }();
}
// ungrabMouse()
void c_KDDockWidgets__flutter__Platform__ungrabMouse(void *thisObj)
{
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->ungrabMouse_nocallback();} else {    return targetPtr->ungrabMouse();} }();
}
// uninstallMessageHandler()
void c_KDDockWidgets__flutter__Platform__uninstallMessageHandler(void *thisObj)
{
    [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->uninstallMessageHandler_nocallback();} else {    return targetPtr->uninstallMessageHandler();} }();
}
// usesFallbackMouseGrabber() const
bool c_KDDockWidgets__flutter__Platform__usesFallbackMouseGrabber(void *thisObj)
{
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->usesFallbackMouseGrabber_nocallback();} else {    return targetPtr->usesFallbackMouseGrabber();} }();
}
void c_KDDockWidgets__flutter__Platform__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_KDDockWidgets__flutter__Platform__registerVirtualMethodCallback(void *ptr, void *callback, int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 697:
        wrapper->m_applicationNameCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_applicationName>(callback);
        break;
    case 698:
        wrapper->m_createDefaultViewFactoryCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_createDefaultViewFactory>(callback);
        break;
    case 699:
        wrapper->m_createMainWindowCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_createMainWindow>(callback);
        break;
    case 700:
        wrapper->m_createViewCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_createView>(callback);
        break;
    case 701:
        wrapper->m_cursorPosCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_cursorPos>(callback);
        break;
    case 702:
        wrapper->m_dumpManagedBacktraceCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_dumpManagedBacktrace>(callback);
        break;
    case 704:
        wrapper->m_hasActivePopupCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_hasActivePopup>(callback);
        break;
    case 705:
        wrapper->m_inDisallowedDragViewCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_inDisallowedDragView>(callback);
        break;
    case 706:
        wrapper->m_installMessageHandlerCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_installMessageHandler>(callback);
        break;
    case 708:
        wrapper->m_isLeftMouseButtonPressedCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_isLeftMouseButtonPressed>(callback);
        break;
    case 709:
        wrapper->m_isProcessingAppQuitEventCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_isProcessingAppQuitEvent>(callback);
        break;
    case 713:
        wrapper->m_nameCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_name>(callback);
        break;
    case 714:
        wrapper->m_onFloatingWindowCreatedCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_onFloatingWindowCreated>(callback);
        break;
    case 715:
        wrapper->m_onFloatingWindowDestroyedCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_onFloatingWindowDestroyed>(callback);
        break;
    case 716:
        wrapper->m_organizationNameCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_organizationName>(callback);
        break;
    case 717:
        wrapper->m_restoreMouseCursorCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_restoreMouseCursor>(callback);
        break;
    case 718:
        wrapper->m_screenNumberForCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_screenNumberFor>(callback);
        break;
    case 719:
        wrapper->m_screenSizeForCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_screenSizeFor>(callback);
        break;
    case 720:
        wrapper->m_setCursorPosCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_setCursorPos>(callback);
        break;
    case 721:
        wrapper->m_setMouseCursorCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_setMouseCursor>(callback);
        break;
    case 723:
        wrapper->m_startDragDistance_implCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_startDragDistance_impl>(callback);
        break;
    case 724:
        wrapper->m_tests_createFocusableViewCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_tests_createFocusableView>(callback);
        break;
    case 725:
        wrapper->m_tests_createNonClosableViewCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_tests_createNonClosableView>(callback);
        break;
    case 726:
        wrapper->m_tests_createViewCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_tests_createView>(callback);
        break;
    case 728:
        wrapper->m_tests_deinitPlatform_implCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_tests_deinitPlatform_impl>(callback);
        break;
    case 729:
        wrapper->m_tests_doubleClickOnCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_tests_doubleClickOn>(callback);
        break;
    case 731:
        wrapper->m_tests_initPlatform_implCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_tests_initPlatform_impl>(callback);
        break;
    case 733:
        wrapper->m_tests_waitCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_tests_wait>(callback);
        break;
    case 740:
        wrapper->m_ungrabMouseCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_ungrabMouse>(callback);
        break;
    case 741:
        wrapper->m_uninstallMessageHandlerCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_uninstallMessageHandler>(callback);
        break;
    case 742:
        wrapper->m_usesFallbackMouseGrabberCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::KDDWBindingsFlutter::Platform_wrapper::Callback_usesFallbackMouseGrabber>(callback);
        break;
    }
}
}