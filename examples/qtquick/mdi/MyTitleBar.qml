/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2020-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sergio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

import QtQuick 2.6

// Will be moved to a plugin in the future, if there's enough demand
import "qrc:/kddockwidgets/qtquick/views/qml/" as KDDW

KDDW.TitleBarBase {
    id: root
    border.width: 2
    heightWhenVisible: 0
}
