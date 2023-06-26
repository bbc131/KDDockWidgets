/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/
import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import '../TypeHelpers.dart';
import '../../Bindings.dart';
import '../../Bindings_KDDWBindingsCore.dart' as KDDWBindingsCore;
import '../../Bindings_KDDWBindingsFlutter.dart' as KDDWBindingsFlutter;
import '../../LibraryLoader.dart';

var _dylib = Library.instance().dylib;
final _finalizerFunc =
    _dylib.lookup<ffi.NativeFunction<ffi.Void Function(ffi.Pointer)>>(
        'c_KDDockWidgets__flutter__Window_Finalizer');
final _finalizer = ffi.NativeFinalizer(_finalizerFunc.cast());

class Window implements ffi.Finalizable {
  static var s_dartInstanceByCppPtr = Map<int, Window>();
  var _thisCpp = null;
  bool _needsAutoDelete = false;
  get thisCpp => _thisCpp;
  set thisCpp(var ptr) {
    _thisCpp = ptr;
    ffi.Pointer<ffi.Void> ptrvoid = ptr.cast<ffi.Void>();
    if (_needsAutoDelete) _finalizer.attach(this, ptrvoid);
  }

  static bool isCached(var cppPointer) {
    return s_dartInstanceByCppPtr.containsKey(cppPointer.address);
  }

  factory Window.fromCache(var cppPointer, [needsAutoDelete = false]) {
    return (s_dartInstanceByCppPtr[cppPointer.address] ??
        Window.fromCppPointer(cppPointer, needsAutoDelete)) as Window;
  }
  Window.fromCppPointer(var cppPointer, [this._needsAutoDelete = false]) {
    thisCpp = cppPointer;
  }
  Window.init() {} // destroy()
  destroy() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            cFunctionSymbolName(514))
        .asFunction();
    func(thisCpp);
  }

  static void destroy_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::destroy()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.destroy();
  } // frameGeometry() const

  QRect frameGeometry() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            cFunctionSymbolName(515))
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QRect.fromCppPointer(result, true);
  }

  static ffi.Pointer<void> frameGeometry_calledFromC(
      ffi.Pointer<void> thisCpp) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::frameGeometry() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.frameGeometry();
    return result.thisCpp;
  } // fromNativePixels(QPoint arg__1) const

  QPoint fromNativePixels(QPoint arg__1) {
    final voidstar_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(516))
        .asFunction();
    ffi.Pointer<void> result =
        func(thisCpp, arg__1 == null ? ffi.nullptr : arg__1.thisCpp);
    return QPoint.fromCppPointer(result, true);
  }

  static ffi.Pointer<void> fromNativePixels_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> arg__1) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::fromNativePixels(QPoint arg__1) const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.fromNativePixels(QPoint.fromCppPointer(arg__1));
    return result.thisCpp;
  } // geometry() const

  QRect geometry() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            cFunctionSymbolName(517))
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QRect.fromCppPointer(result, true);
  }

  static ffi.Pointer<void> geometry_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::geometry() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.geometry();
    return result.thisCpp;
  } // isActive() const

  bool isActive() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            cFunctionSymbolName(518))
        .asFunction();
    return func(thisCpp) != 0;
  }

  static int isActive_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::isActive() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.isActive();
    return result ? 1 : 0;
  } // isFullScreen() const

  bool isFullScreen() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            cFunctionSymbolName(519))
        .asFunction();
    return func(thisCpp) != 0;
  }

  static int isFullScreen_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::isFullScreen() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.isFullScreen();
    return result ? 1 : 0;
  } // isVisible() const

  bool isVisible() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            cFunctionSymbolName(520))
        .asFunction();
    return func(thisCpp) != 0;
  }

  static int isVisible_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::isVisible() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.isVisible();
    return result ? 1 : 0;
  } // mapFromGlobal(QPoint globalPos) const

  QPoint mapFromGlobal(QPoint globalPos) {
    final voidstar_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(521))
        .asFunction();
    ffi.Pointer<void> result =
        func(thisCpp, globalPos == null ? ffi.nullptr : globalPos.thisCpp);
    return QPoint.fromCppPointer(result, true);
  }

  static ffi.Pointer<void> mapFromGlobal_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> globalPos) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::mapFromGlobal(QPoint globalPos) const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.mapFromGlobal(QPoint.fromCppPointer(globalPos));
    return result.thisCpp;
  } // mapToGlobal(QPoint localPos) const

  QPoint mapToGlobal(QPoint localPos) {
    final voidstar_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(522))
        .asFunction();
    ffi.Pointer<void> result =
        func(thisCpp, localPos == null ? ffi.nullptr : localPos.thisCpp);
    return QPoint.fromCppPointer(result, true);
  }

  static ffi.Pointer<void> mapToGlobal_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> localPos) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::mapToGlobal(QPoint localPos) const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.mapToGlobal(QPoint.fromCppPointer(localPos));
    return result.thisCpp;
  } // maxSize() const

  QSize maxSize() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            cFunctionSymbolName(523))
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QSize.fromCppPointer(result, true);
  }

  static ffi.Pointer<void> maxSize_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::maxSize() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.maxSize();
    return result.thisCpp;
  } // minSize() const

  QSize minSize() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            cFunctionSymbolName(524))
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QSize.fromCppPointer(result, true);
  }

  static ffi.Pointer<void> minSize_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::minSize() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.minSize();
    return result.thisCpp;
  } // resize(int width, int height)

  resize(int width, int height) {
    final void_Func_voidstar_int_int func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>>(
            cFunctionSymbolName(525))
        .asFunction();
    func(thisCpp, width, height);
  }

  static void resize_calledFromC(
      ffi.Pointer<void> thisCpp, int width, int height) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::resize(int width, int height)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.resize(width, height);
  } // setFramePosition(QPoint targetPos)

  setFramePosition(QPoint targetPos) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(526))
        .asFunction();
    func(thisCpp, targetPos == null ? ffi.nullptr : targetPos.thisCpp);
  }

  static void setFramePosition_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> targetPos) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::setFramePosition(QPoint targetPos)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setFramePosition(QPoint.fromCppPointer(targetPos));
  } // setGeometry(QRect arg__1)

  setGeometry(QRect arg__1) {
    final void_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_voidstar_FFI>>(
            cFunctionSymbolName(527))
        .asFunction();
    func(thisCpp, arg__1 == null ? ffi.nullptr : arg__1.thisCpp);
  }

  static void setGeometry_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> arg__1) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::setGeometry(QRect arg__1)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setGeometry(QRect.fromCppPointer(arg__1));
  } // setVisible(bool arg__1)

  setVisible(bool arg__1) {
    final void_Func_voidstar_bool func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_ffi_Int8_FFI>>(
            cFunctionSymbolName(528))
        .asFunction();
    func(thisCpp, arg__1 ? 1 : 0);
  }

  static void setVisible_calledFromC(ffi.Pointer<void> thisCpp, int arg__1) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::setVisible(bool arg__1)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setVisible(arg__1 != 0);
  } // supportsHonouringLayoutMinSize() const

  bool supportsHonouringLayoutMinSize() {
    final bool_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<bool_Func_voidstar_FFI>>(
            cFunctionSymbolName(529))
        .asFunction();
    return func(thisCpp) != 0;
  }

  static int supportsHonouringLayoutMinSize_calledFromC(
      ffi.Pointer<void> thisCpp) {
    var dartInstance =
        KDDWBindingsFlutter.Window.s_dartInstanceByCppPtr[thisCpp.address];
    if (dartInstance == null) {
      print(
          "Dart instance not found for Window::supportsHonouringLayoutMinSize() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.supportsHonouringLayoutMinSize();
    return result ? 1 : 0;
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_KDDockWidgets__flutter__Window__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 514:
        return "c_KDDockWidgets__flutter__Window__destroy";
      case 515:
        return "c_KDDockWidgets__flutter__Window__frameGeometry";
      case 516:
        return "c_KDDockWidgets__flutter__Window__fromNativePixels_QPoint";
      case 517:
        return "c_KDDockWidgets__flutter__Window__geometry";
      case 518:
        return "c_KDDockWidgets__flutter__Window__isActive";
      case 519:
        return "c_KDDockWidgets__flutter__Window__isFullScreen";
      case 520:
        return "c_KDDockWidgets__flutter__Window__isVisible";
      case 521:
        return "c_KDDockWidgets__flutter__Window__mapFromGlobal_QPoint";
      case 522:
        return "c_KDDockWidgets__flutter__Window__mapToGlobal_QPoint";
      case 523:
        return "c_KDDockWidgets__flutter__Window__maxSize";
      case 524:
        return "c_KDDockWidgets__flutter__Window__minSize";
      case 525:
        return "c_KDDockWidgets__flutter__Window__resize_int_int";
      case 526:
        return "c_KDDockWidgets__flutter__Window__setFramePosition_QPoint";
      case 527:
        return "c_KDDockWidgets__flutter__Window__setGeometry_QRect";
      case 528:
        return "c_KDDockWidgets__flutter__Window__setVisible_bool";
      case 529:
        return "c_KDDockWidgets__flutter__Window__supportsHonouringLayoutMinSize";
    }
    return "";
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 514:
        return "destroy";
      case 515:
        return "frameGeometry";
      case 516:
        return "fromNativePixels";
      case 517:
        return "geometry";
      case 518:
        return "isActive";
      case 519:
        return "isFullScreen";
      case 520:
        return "isVisible";
      case 521:
        return "mapFromGlobal";
      case 522:
        return "mapToGlobal";
      case 523:
        return "maxSize";
      case 524:
        return "minSize";
      case 525:
        return "resize";
      case 526:
        return "setFramePosition";
      case 527:
        return "setGeometry";
      case 528:
        return "setVisible";
      case 529:
        return "supportsHonouringLayoutMinSize";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_KDDockWidgets__flutter__Window__registerVirtualMethodCallback')
        .asFunction();
    final callback514 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        KDDWBindingsFlutter.Window.destroy_calledFromC);
    registerCallback(thisCpp, callback514, 514);
    final callback515 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        KDDWBindingsFlutter.Window.frameGeometry_calledFromC);
    registerCallback(thisCpp, callback515, 515);
    final callback516 =
        ffi.Pointer.fromFunction<voidstar_Func_voidstar_voidstar_FFI>(
            KDDWBindingsFlutter.Window.fromNativePixels_calledFromC);
    registerCallback(thisCpp, callback516, 516);
    final callback517 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        KDDWBindingsFlutter.Window.geometry_calledFromC);
    registerCallback(thisCpp, callback517, 517);
    const callbackExcept518 = 0;
    final callback518 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        KDDWBindingsFlutter.Window.isActive_calledFromC, callbackExcept518);
    registerCallback(thisCpp, callback518, 518);
    const callbackExcept519 = 0;
    final callback519 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        KDDWBindingsFlutter.Window.isFullScreen_calledFromC, callbackExcept519);
    registerCallback(thisCpp, callback519, 519);
    const callbackExcept520 = 0;
    final callback520 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        KDDWBindingsFlutter.Window.isVisible_calledFromC, callbackExcept520);
    registerCallback(thisCpp, callback520, 520);
    final callback521 =
        ffi.Pointer.fromFunction<voidstar_Func_voidstar_voidstar_FFI>(
            KDDWBindingsFlutter.Window.mapFromGlobal_calledFromC);
    registerCallback(thisCpp, callback521, 521);
    final callback522 =
        ffi.Pointer.fromFunction<voidstar_Func_voidstar_voidstar_FFI>(
            KDDWBindingsFlutter.Window.mapToGlobal_calledFromC);
    registerCallback(thisCpp, callback522, 522);
    final callback523 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        KDDWBindingsFlutter.Window.maxSize_calledFromC);
    registerCallback(thisCpp, callback523, 523);
    final callback524 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        KDDWBindingsFlutter.Window.minSize_calledFromC);
    registerCallback(thisCpp, callback524, 524);
    final callback525 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>(
            KDDWBindingsFlutter.Window.resize_calledFromC);
    registerCallback(thisCpp, callback525, 525);
    final callback526 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            KDDWBindingsFlutter.Window.setFramePosition_calledFromC);
    registerCallback(thisCpp, callback526, 526);
    final callback527 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            KDDWBindingsFlutter.Window.setGeometry_calledFromC);
    registerCallback(thisCpp, callback527, 527);
    final callback528 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int8_FFI>(
            KDDWBindingsFlutter.Window.setVisible_calledFromC);
    registerCallback(thisCpp, callback528, 528);
    const callbackExcept529 = 0;
    final callback529 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        KDDWBindingsFlutter.Window.supportsHonouringLayoutMinSize_calledFromC,
        callbackExcept529);
    registerCallback(thisCpp, callback529, 529);
  }
}
