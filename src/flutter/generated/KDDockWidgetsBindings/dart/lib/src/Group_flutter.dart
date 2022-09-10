/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/
import 'dart:ffi' as ffi;
import 'package:ffi/ffi.dart';
import 'TypeHelpers.dart';
import '../Bindings.dart';
import '../FinalizerHelpers.dart';

var _dylib = Library.instance().dylib;

class Group_flutter extends View_flutter {
  Group_flutter.fromCppPointer(var cppPointer, [var needsAutoDelete = false])
      : super.fromCppPointer(cppPointer, needsAutoDelete) {}
  Group_flutter.init() : super.init() {}
  factory Group_flutter.fromCache(var cppPointer, [needsAutoDelete = false]) {
    if (View.isCached(cppPointer)) {
      var instance = View.s_dartInstanceByCppPtr[cppPointer.address];
      if (instance != null) return instance as Group_flutter;
    }
    return Group_flutter.fromCppPointer(cppPointer, needsAutoDelete);
  } //Group_flutter(KDDockWidgets::Controllers::Group * controller, KDDockWidgets::View * parent)
  Group_flutter(Group? controller, {required View? parent}) : super.init() {
    final voidstar_Func_voidstar_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_voidstar_FFI>>(
            'c_KDDockWidgets__Views__Group_flutter__constructor_Group_View')
        .asFunction();
    thisCpp = func(controller == null ? ffi.nullptr : controller.thisCpp,
        parent == null ? ffi.nullptr : parent.thisCpp);
    View.s_dartInstanceByCppPtr[thisCpp.address] = this;
    registerCallbacks();
  }
  static void activateWindow_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::activateWindow()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.activateWindow();
  }

  static int close_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::close()! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.close();
    return result ? 1 : 0;
  }

  static void createPlatformWindow_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::createPlatformWindow()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.createPlatformWindow();
  } // currentIndex() const

  int currentIndex() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            'c_KDDockWidgets__Views__Group_flutter__currentIndex')
        .asFunction();
    return func(thisCpp);
  } // dragRect() const

  QRect dragRect() {
    final voidstar_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<voidstar_Func_voidstar_FFI>>(
            cFunctionSymbolName(1063))
        .asFunction();
    ffi.Pointer<void> result = func(thisCpp);
    return QRect.fromCppPointer(result, true);
  }

  static ffi.Pointer<void> dragRect_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::dragRect() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.dragRect();
    return result.thisCpp;
  }

  static int flags_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::flags() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.flags();
    return result;
  }

  static void free_impl_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::free_impl()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.free_impl();
  }

  static ffi.Pointer<void> geometry_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::geometry() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.geometry();
    return result.thisCpp;
  }

  static void grabMouse_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::grabMouse()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.grabMouse();
  }

  static int hasFocus_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::hasFocus() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.hasFocus();
    return result ? 1 : 0;
  }

  static void hide_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::hide()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.hide();
  }

  static void init_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::init()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.init();
  }

  static int isActiveWindow_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::isActiveWindow() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.isActiveWindow();
    return result ? 1 : 0;
  }

  static int isMaximized_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::isMaximized() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.isMaximized();
    return result ? 1 : 0;
  }

  static int isMinimized_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::isMinimized() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.isMinimized();
    return result ? 1 : 0;
  }

  static int isNull_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::isNull() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.isNull();
    return result ? 1 : 0;
  }

  static int isRootView_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::isRootView() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.isRootView();
    return result ? 1 : 0;
  }

  static int isVisible_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::isVisible() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.isVisible();
    return result ? 1 : 0;
  }

  static ffi.Pointer<void> mapFromGlobal_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> globalPt) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::mapFromGlobal(QPoint globalPt) const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.mapFromGlobal(QPoint.fromCppPointer(globalPt));
    return result.thisCpp;
  }

  static ffi.Pointer<void> mapTo_calledFromC(ffi.Pointer<void> thisCpp,
      ffi.Pointer<void>? parent, ffi.Pointer<void> pos) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::mapTo(KDDockWidgets::View * parent, QPoint pos) const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.mapTo(
        View.fromCppPointer(parent), QPoint.fromCppPointer(pos));
    return result.thisCpp;
  }

  static ffi.Pointer<void> mapToGlobal_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> localPt) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::mapToGlobal(QPoint localPt) const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.mapToGlobal(QPoint.fromCppPointer(localPt));
    return result.thisCpp;
  }

  static ffi.Pointer<void> maxSizeHint_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::maxSizeHint() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.maxSizeHint();
    return result.thisCpp;
  }

  static ffi.Pointer<void> minSize_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::minSize() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.minSize();
    return result.thisCpp;
  }

  static int minimumHeight_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::minimumHeight() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.minimumHeight();
    return result;
  }

  static int minimumWidth_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::minimumWidth() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.minimumWidth();
    return result;
  }

  static void move_2_calledFromC(ffi.Pointer<void> thisCpp, int x, int y) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::move(int x, int y)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.move_2(x, y);
  } // nonContentsHeight() const

  int nonContentsHeight() {
    final int_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<int_Func_voidstar_FFI>>(
            cFunctionSymbolName(1064))
        .asFunction();
    return func(thisCpp);
  }

  static int nonContentsHeight_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::nonContentsHeight() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.nonContentsHeight();
    return result;
  }

  static ffi.Pointer<void> normalGeometry_calledFromC(
      ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::normalGeometry() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.normalGeometry();
    return result.thisCpp;
  }

  static ffi.Pointer<void> objectName_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::objectName() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.objectName();
    return result.thisCpp;
  }

  static void onChildAdded_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? childView) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::onChildAdded(KDDockWidgets::View * childView)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.onChildAdded(View.fromCppPointer(childView));
  }

  static void onChildRemoved_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? childView) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::onChildRemoved(KDDockWidgets::View * childView)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.onChildRemoved(View.fromCppPointer(childView));
  }

  static int onResize_2_calledFromC(ffi.Pointer<void> thisCpp, int w, int h) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::onResize(int w, int h)! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.onResize_2(w, h);
    return result ? 1 : 0;
  }

  static void raise_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::raise()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.raise();
  }

  static void raiseAndActivate_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::raiseAndActivate()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.raiseAndActivate();
  }

  static void releaseKeyboard_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::releaseKeyboard()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.releaseKeyboard();
  }

  static void releaseMouse_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::releaseMouse()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.releaseMouse();
  }

  static void setCursor_calledFromC(ffi.Pointer<void> thisCpp, int shape) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setCursor(Qt::CursorShape shape)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setCursor(shape);
  }

  static void setFixedHeight_calledFromC(ffi.Pointer<void> thisCpp, int h) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setFixedHeight(int h)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setFixedHeight(h);
  }

  static void setFixedWidth_calledFromC(ffi.Pointer<void> thisCpp, int w) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setFixedWidth(int w)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setFixedWidth(w);
  }

  static void setGeometry_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> geometry) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setGeometry(QRect geometry)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setGeometry(QRect.fromCppPointer(geometry));
  }

  static void setHeight_calledFromC(ffi.Pointer<void> thisCpp, int h) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setHeight(int h)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setHeight(h);
  }

  static void setMaximumSize_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> sz) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setMaximumSize(QSize sz)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setMaximumSize(QSize.fromCppPointer(sz));
  }

  static void setMinimumSize_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void> sz) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setMinimumSize(QSize sz)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setMinimumSize(QSize.fromCppPointer(sz));
  }

  static void setMouseTracking_calledFromC(
      ffi.Pointer<void> thisCpp, int enable) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setMouseTracking(bool enable)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setMouseTracking(enable != 0);
  }

  static void setObjectName_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? name) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setObjectName(const QString & name)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setObjectName(QString.fromCppPointer(name).toDartString());
  }

  static void setParent_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? parent) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setParent(KDDockWidgets::View * parent)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setParent(View.fromCppPointer(parent));
  }

  static void setSize_2_calledFromC(ffi.Pointer<void> thisCpp, int w, int h) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setSize(int w, int h)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setSize_2(w, h);
  }

  static void setVisible_calledFromC(ffi.Pointer<void> thisCpp, int visible) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setVisible(bool visible)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setVisible(visible != 0);
  }

  static void setWidth_calledFromC(ffi.Pointer<void> thisCpp, int w) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setWidth(int w)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setWidth(w);
  }

  static void setWindowOpacity_calledFromC(
      ffi.Pointer<void> thisCpp, double v) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setWindowOpacity(double v)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setWindowOpacity(v);
  }

  static void setWindowTitle_calledFromC(
      ffi.Pointer<void> thisCpp, ffi.Pointer<void>? title) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setWindowTitle(const QString & title)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setWindowTitle(QString.fromCppPointer(title).toDartString());
  }

  static void setZOrder_calledFromC(ffi.Pointer<void> thisCpp, int z) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::setZOrder(int z)! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.setZOrder(z);
  }

  static void show_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::show()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.show();
  }

  static void showMaximized_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::showMaximized()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.showMaximized();
  }

  static void showMinimized_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::showMinimized()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.showMinimized();
  }

  static void showNormal_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::showNormal()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.showNormal();
  }

  static ffi.Pointer<void> sizeHint_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::sizeHint() const! (${thisCpp.address})");
      throw Error();
    }
    final result = dartInstance.sizeHint();
    return result.thisCpp;
  }

  static void update_calledFromC(ffi.Pointer<void> thisCpp) {
    var dartInstance =
        View.s_dartInstanceByCppPtr[thisCpp.address] as Group_flutter;
    if (dartInstance == null) {
      print(
          "Dart instance not found for Group_flutter::update()! (${thisCpp.address})");
      throw Error();
    }
    dartInstance.update();
  }

  void release() {
    final void_Func_voidstar func = _dylib
        .lookup<ffi.NativeFunction<void_Func_voidstar_FFI>>(
            'c_KDDockWidgets__Views__Group_flutter__destructor')
        .asFunction();
    func(thisCpp);
  }

  String cFunctionSymbolName(int methodId) {
    switch (methodId) {
      case 905:
        return "c_KDDockWidgets__Views__Group_flutter__activateWindow";
      case 916:
        return "c_KDDockWidgets__Views__Group_flutter__close";
      case 919:
        return "c_KDDockWidgets__Views__Group_flutter__createPlatformWindow";
      case 1063:
        return "c_KDDockWidgets__Views__Group_flutter__dragRect";
      case 924:
        return "c_KDDockWidgets__Views__Group_flutter__flags";
      case 926:
        return "c_KDDockWidgets__Views__Group_flutter__free_impl";
      case 928:
        return "c_KDDockWidgets__Views__Group_flutter__geometry";
      case 930:
        return "c_KDDockWidgets__Views__Group_flutter__grabMouse";
      case 933:
        return "c_KDDockWidgets__Views__Group_flutter__hasFocus";
      case 935:
        return "c_KDDockWidgets__Views__Group_flutter__hide";
      case 938:
        return "c_KDDockWidgets__Views__Group_flutter__init";
      case 940:
        return "c_KDDockWidgets__Views__Group_flutter__isActiveWindow";
      case 941:
        return "c_KDDockWidgets__Views__Group_flutter__isMaximized";
      case 942:
        return "c_KDDockWidgets__Views__Group_flutter__isMinimized";
      case 943:
        return "c_KDDockWidgets__Views__Group_flutter__isNull";
      case 944:
        return "c_KDDockWidgets__Views__Group_flutter__isRootView";
      case 945:
        return "c_KDDockWidgets__Views__Group_flutter__isVisible";
      case 946:
        return "c_KDDockWidgets__Views__Group_flutter__mapFromGlobal_QPoint";
      case 947:
        return "c_KDDockWidgets__Views__Group_flutter__mapTo_View_QPoint";
      case 948:
        return "c_KDDockWidgets__Views__Group_flutter__mapToGlobal_QPoint";
      case 949:
        return "c_KDDockWidgets__Views__Group_flutter__maxSizeHint";
      case 950:
        return "c_KDDockWidgets__Views__Group_flutter__minSize";
      case 951:
        return "c_KDDockWidgets__Views__Group_flutter__minimumHeight";
      case 952:
        return "c_KDDockWidgets__Views__Group_flutter__minimumWidth";
      case 954:
        return "c_KDDockWidgets__Views__Group_flutter__move_int_int";
      case 1064:
        return "c_KDDockWidgets__Views__Group_flutter__nonContentsHeight";
      case 955:
        return "c_KDDockWidgets__Views__Group_flutter__normalGeometry";
      case 956:
        return "c_KDDockWidgets__Views__Group_flutter__objectName";
      case 1023:
        return "c_KDDockWidgets__Views__Group_flutter__onChildAdded_View";
      case 1024:
        return "c_KDDockWidgets__Views__Group_flutter__onChildRemoved_View";
      case 958:
        return "c_KDDockWidgets__Views__Group_flutter__onResize_int_int";
      case 961:
        return "c_KDDockWidgets__Views__Group_flutter__raise";
      case 962:
        return "c_KDDockWidgets__Views__Group_flutter__raiseAndActivate";
      case 964:
        return "c_KDDockWidgets__Views__Group_flutter__releaseKeyboard";
      case 965:
        return "c_KDDockWidgets__Views__Group_flutter__releaseMouse";
      case 969:
        return "c_KDDockWidgets__Views__Group_flutter__setCursor_CursorShape";
      case 970:
        return "c_KDDockWidgets__Views__Group_flutter__setFixedHeight_int";
      case 971:
        return "c_KDDockWidgets__Views__Group_flutter__setFixedWidth_int";
      case 972:
        return "c_KDDockWidgets__Views__Group_flutter__setGeometry_QRect";
      case 973:
        return "c_KDDockWidgets__Views__Group_flutter__setHeight_int";
      case 974:
        return "c_KDDockWidgets__Views__Group_flutter__setMaximumSize_QSize";
      case 975:
        return "c_KDDockWidgets__Views__Group_flutter__setMinimumSize_QSize";
      case 976:
        return "c_KDDockWidgets__Views__Group_flutter__setMouseTracking_bool";
      case 977:
        return "c_KDDockWidgets__Views__Group_flutter__setObjectName_QString";
      case 978:
        return "c_KDDockWidgets__Views__Group_flutter__setParent_View";
      case 980:
        return "c_KDDockWidgets__Views__Group_flutter__setSize_int_int";
      case 981:
        return "c_KDDockWidgets__Views__Group_flutter__setVisible_bool";
      case 982:
        return "c_KDDockWidgets__Views__Group_flutter__setWidth_int";
      case 983:
        return "c_KDDockWidgets__Views__Group_flutter__setWindowOpacity_double";
      case 984:
        return "c_KDDockWidgets__Views__Group_flutter__setWindowTitle_QString";
      case 985:
        return "c_KDDockWidgets__Views__Group_flutter__setZOrder_int";
      case 986:
        return "c_KDDockWidgets__Views__Group_flutter__show";
      case 987:
        return "c_KDDockWidgets__Views__Group_flutter__showMaximized";
      case 988:
        return "c_KDDockWidgets__Views__Group_flutter__showMinimized";
      case 989:
        return "c_KDDockWidgets__Views__Group_flutter__showNormal";
      case 991:
        return "c_KDDockWidgets__Views__Group_flutter__sizeHint";
      case 993:
        return "c_KDDockWidgets__Views__Group_flutter__update";
    }
    return super.cFunctionSymbolName(methodId);
  }

  static String methodNameFromId(int methodId) {
    switch (methodId) {
      case 905:
        return "activateWindow";
      case 916:
        return "close";
      case 919:
        return "createPlatformWindow";
      case 1063:
        return "dragRect";
      case 924:
        return "flags";
      case 926:
        return "free_impl";
      case 928:
        return "geometry";
      case 930:
        return "grabMouse";
      case 933:
        return "hasFocus";
      case 935:
        return "hide";
      case 938:
        return "init";
      case 940:
        return "isActiveWindow";
      case 941:
        return "isMaximized";
      case 942:
        return "isMinimized";
      case 943:
        return "isNull";
      case 944:
        return "isRootView";
      case 945:
        return "isVisible";
      case 946:
        return "mapFromGlobal";
      case 947:
        return "mapTo";
      case 948:
        return "mapToGlobal";
      case 949:
        return "maxSizeHint";
      case 950:
        return "minSize";
      case 951:
        return "minimumHeight";
      case 952:
        return "minimumWidth";
      case 954:
        return "move_2";
      case 1064:
        return "nonContentsHeight";
      case 955:
        return "normalGeometry";
      case 956:
        return "objectName";
      case 1023:
        return "onChildAdded";
      case 1024:
        return "onChildRemoved";
      case 958:
        return "onResize_2";
      case 961:
        return "raise";
      case 962:
        return "raiseAndActivate";
      case 964:
        return "releaseKeyboard";
      case 965:
        return "releaseMouse";
      case 969:
        return "setCursor";
      case 970:
        return "setFixedHeight";
      case 971:
        return "setFixedWidth";
      case 972:
        return "setGeometry";
      case 973:
        return "setHeight";
      case 974:
        return "setMaximumSize";
      case 975:
        return "setMinimumSize";
      case 976:
        return "setMouseTracking";
      case 977:
        return "setObjectName";
      case 978:
        return "setParent";
      case 980:
        return "setSize_2";
      case 981:
        return "setVisible";
      case 982:
        return "setWidth";
      case 983:
        return "setWindowOpacity";
      case 984:
        return "setWindowTitle";
      case 985:
        return "setZOrder";
      case 986:
        return "show";
      case 987:
        return "showMaximized";
      case 988:
        return "showMinimized";
      case 989:
        return "showNormal";
      case 991:
        return "sizeHint";
      case 993:
        return "update";
    }
    throw Error();
  }

  void registerCallbacks() {
    assert(thisCpp != null);
    final RegisterMethodIsReimplementedCallback registerCallback = _dylib
        .lookup<ffi.NativeFunction<RegisterMethodIsReimplementedCallback_FFI>>(
            'c_KDDockWidgets__Views__Group_flutter__registerVirtualMethodCallback')
        .asFunction();
    final callback905 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.activateWindow_calledFromC);
    registerCallback(thisCpp, callback905, 905);
    const callbackExcept916 = 0;
    final callback916 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        View_flutter.close_calledFromC, callbackExcept916);
    registerCallback(thisCpp, callback916, 916);
    final callback919 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View.createPlatformWindow_calledFromC);
    registerCallback(thisCpp, callback919, 919);
    final callback1063 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        Group_flutter.dragRect_calledFromC);
    registerCallback(thisCpp, callback1063, 1063);
    const callbackExcept924 = 0;
    final callback924 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        View_flutter.flags_calledFromC, callbackExcept924);
    registerCallback(thisCpp, callback924, 924);
    final callback926 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.free_impl_calledFromC);
    registerCallback(thisCpp, callback926, 926);
    final callback928 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        View_flutter.geometry_calledFromC);
    registerCallback(thisCpp, callback928, 928);
    final callback930 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.grabMouse_calledFromC);
    registerCallback(thisCpp, callback930, 930);
    const callbackExcept933 = 0;
    final callback933 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        View_flutter.hasFocus_calledFromC, callbackExcept933);
    registerCallback(thisCpp, callback933, 933);
    final callback935 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.hide_calledFromC);
    registerCallback(thisCpp, callback935, 935);
    final callback938 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        Group_flutter.init_calledFromC);
    registerCallback(thisCpp, callback938, 938);
    const callbackExcept940 = 0;
    final callback940 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        View_flutter.isActiveWindow_calledFromC, callbackExcept940);
    registerCallback(thisCpp, callback940, 940);
    const callbackExcept941 = 0;
    final callback941 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        View_flutter.isMaximized_calledFromC, callbackExcept941);
    registerCallback(thisCpp, callback941, 941);
    const callbackExcept942 = 0;
    final callback942 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        View_flutter.isMinimized_calledFromC, callbackExcept942);
    registerCallback(thisCpp, callback942, 942);
    const callbackExcept943 = 0;
    final callback943 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        View.isNull_calledFromC, callbackExcept943);
    registerCallback(thisCpp, callback943, 943);
    const callbackExcept944 = 0;
    final callback944 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        View_flutter.isRootView_calledFromC, callbackExcept944);
    registerCallback(thisCpp, callback944, 944);
    const callbackExcept945 = 0;
    final callback945 = ffi.Pointer.fromFunction<bool_Func_voidstar_FFI>(
        View_flutter.isVisible_calledFromC, callbackExcept945);
    registerCallback(thisCpp, callback945, 945);
    final callback946 =
        ffi.Pointer.fromFunction<voidstar_Func_voidstar_voidstar_FFI>(
            View_flutter.mapFromGlobal_calledFromC);
    registerCallback(thisCpp, callback946, 946);
    final callback947 =
        ffi.Pointer.fromFunction<voidstar_Func_voidstar_voidstar_voidstar_FFI>(
            View_flutter.mapTo_calledFromC);
    registerCallback(thisCpp, callback947, 947);
    final callback948 =
        ffi.Pointer.fromFunction<voidstar_Func_voidstar_voidstar_FFI>(
            View_flutter.mapToGlobal_calledFromC);
    registerCallback(thisCpp, callback948, 948);
    final callback949 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        Group_flutter.maxSizeHint_calledFromC);
    registerCallback(thisCpp, callback949, 949);
    final callback950 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        Group_flutter.minSize_calledFromC);
    registerCallback(thisCpp, callback950, 950);
    const callbackExcept951 = 0;
    final callback951 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        View.minimumHeight_calledFromC, callbackExcept951);
    registerCallback(thisCpp, callback951, 951);
    const callbackExcept952 = 0;
    final callback952 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        View.minimumWidth_calledFromC, callbackExcept952);
    registerCallback(thisCpp, callback952, 952);
    final callback954 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>(
            View_flutter.move_2_calledFromC);
    registerCallback(thisCpp, callback954, 954);
    const callbackExcept1064 = 0;
    final callback1064 = ffi.Pointer.fromFunction<int_Func_voidstar_FFI>(
        Group_flutter.nonContentsHeight_calledFromC, callbackExcept1064);
    registerCallback(thisCpp, callback1064, 1064);
    final callback955 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        View_flutter.normalGeometry_calledFromC);
    registerCallback(thisCpp, callback955, 955);
    final callback956 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        View_flutter.objectName_calledFromC);
    registerCallback(thisCpp, callback956, 956);
    final callback1023 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            View_flutter.onChildAdded_calledFromC);
    registerCallback(thisCpp, callback1023, 1023);
    final callback1024 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            View_flutter.onChildRemoved_calledFromC);
    registerCallback(thisCpp, callback1024, 1024);
    const callbackExcept958 = 0;
    final callback958 =
        ffi.Pointer.fromFunction<bool_Func_voidstar_ffi_Int32_ffi_Int32_FFI>(
            View_flutter.onResize_2_calledFromC, callbackExcept958);
    registerCallback(thisCpp, callback958, 958);
    final callback961 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.raise_calledFromC);
    registerCallback(thisCpp, callback961, 961);
    final callback962 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.raiseAndActivate_calledFromC);
    registerCallback(thisCpp, callback962, 962);
    final callback964 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.releaseKeyboard_calledFromC);
    registerCallback(thisCpp, callback964, 964);
    final callback965 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.releaseMouse_calledFromC);
    registerCallback(thisCpp, callback965, 965);
    final callback969 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_FFI>(
            View_flutter.setCursor_calledFromC);
    registerCallback(thisCpp, callback969, 969);
    final callback970 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_FFI>(
            View_flutter.setFixedHeight_calledFromC);
    registerCallback(thisCpp, callback970, 970);
    final callback971 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_FFI>(
            View_flutter.setFixedWidth_calledFromC);
    registerCallback(thisCpp, callback971, 971);
    final callback972 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            View_flutter.setGeometry_calledFromC);
    registerCallback(thisCpp, callback972, 972);
    final callback973 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_FFI>(
            View_flutter.setHeight_calledFromC);
    registerCallback(thisCpp, callback973, 973);
    final callback974 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            View_flutter.setMaximumSize_calledFromC);
    registerCallback(thisCpp, callback974, 974);
    final callback975 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            View_flutter.setMinimumSize_calledFromC);
    registerCallback(thisCpp, callback975, 975);
    final callback976 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int8_FFI>(
            View_flutter.setMouseTracking_calledFromC);
    registerCallback(thisCpp, callback976, 976);
    final callback977 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            View_flutter.setObjectName_calledFromC);
    registerCallback(thisCpp, callback977, 977);
    final callback978 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            View_flutter.setParent_calledFromC);
    registerCallback(thisCpp, callback978, 978);
    final callback980 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_ffi_Int32_FFI>(
            View_flutter.setSize_2_calledFromC);
    registerCallback(thisCpp, callback980, 980);
    final callback981 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int8_FFI>(
            View_flutter.setVisible_calledFromC);
    registerCallback(thisCpp, callback981, 981);
    final callback982 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_FFI>(
            View_flutter.setWidth_calledFromC);
    registerCallback(thisCpp, callback982, 982);
    final callback983 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Double_FFI>(
            View_flutter.setWindowOpacity_calledFromC);
    registerCallback(thisCpp, callback983, 983);
    final callback984 =
        ffi.Pointer.fromFunction<void_Func_voidstar_voidstar_FFI>(
            View_flutter.setWindowTitle_calledFromC);
    registerCallback(thisCpp, callback984, 984);
    final callback985 =
        ffi.Pointer.fromFunction<void_Func_voidstar_ffi_Int32_FFI>(
            View_flutter.setZOrder_calledFromC);
    registerCallback(thisCpp, callback985, 985);
    final callback986 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.show_calledFromC);
    registerCallback(thisCpp, callback986, 986);
    final callback987 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.showMaximized_calledFromC);
    registerCallback(thisCpp, callback987, 987);
    final callback988 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.showMinimized_calledFromC);
    registerCallback(thisCpp, callback988, 988);
    final callback989 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.showNormal_calledFromC);
    registerCallback(thisCpp, callback989, 989);
    final callback991 = ffi.Pointer.fromFunction<voidstar_Func_voidstar_FFI>(
        View_flutter.sizeHint_calledFromC);
    registerCallback(thisCpp, callback991, 991);
    final callback993 = ffi.Pointer.fromFunction<void_Func_voidstar_FFI>(
        View_flutter.update_calledFromC);
    registerCallback(thisCpp, callback993, 993);
  }
}
