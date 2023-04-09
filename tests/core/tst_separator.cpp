/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#include "../main.h"
#include "kddockwidgets/core/Separator.h"

TEST_CASE("Separator Ctor")
{
    auto hostView = Core::Platform::instance()->createView(nullptr);

    {
        Core::Separator separator(hostView);
        CHECK(separator.view()->is(Core::ViewType::Separator));
        CHECK(separator.view()->asWrapper()->is(Core::ViewType::Separator));
    }

    delete hostView;
}
