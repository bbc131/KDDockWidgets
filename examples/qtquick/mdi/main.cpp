/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2020 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sergio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/


#include <kddockwidgets/Config.h>
#include <kddockwidgets/qtquick/views/DockWidget.h>
#include <kddockwidgets/qtquick/views/MainWindowMDI.h>
#include <kddockwidgets/qtquick/Platform.h>
#include <kddockwidgets/core/DockRegistry.h>
#include <kddockwidgets/core/DockWidget.h>
#include "kddockwidgets/core/MainWindow.h"
#include <kddockwidgets/qtquick/ViewFactory.h>
#include "kddockwidgets/core/MDILayout.h"
#include <kddockwidgets/qtquick/ViewFactory.h>

#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QCommandLineParser>

// Custom factory which returns our null-sized titlebar
class CustomViewFactory : public KDDockWidgets::QtQuick::ViewFactory
{
public:
    ~CustomViewFactory() override;

    QUrl titleBarFilename() const override
    {
        return QUrl("qrc:/MyTitleBar.qml");
    }
};

CustomViewFactory::~CustomViewFactory() = default;

int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN
    QGuiApplication::setAttribute(Qt::AA_UseOpenGLES);
#endif
    QGuiApplication app(argc, argv);
    KDDockWidgets::initFrontend(KDDockWidgets::FrontendType::QtQuick);

    auto &config = KDDockWidgets::Config::self();

    // For our custom titlebar
    config.setViewFactory(new CustomViewFactory());

    // No click to raise
    config.setMDIFlags(KDDockWidgets::Config::MDIFlag_NoClickToRaise);

    QCommandLineParser parser;
    parser.setApplicationDescription("KDDockWidgets example application");
    parser.addHelpOption();

    QQmlApplicationEngine appEngine;
    KDDockWidgets::QtQuick::Platform::instance()->setQmlEngine(&appEngine);
    appEngine.load((QUrl("qrc:/main.qml")));

    auto dw1 = new KDDockWidgets::QtQuick::DockWidget("Dock #1");
    dw1->setGuestItem(QStringLiteral("qrc:/Guest1.qml"));


    auto dw2 = new KDDockWidgets::QtQuick::DockWidget("Dock #2");
    dw2->setGuestItem(QStringLiteral("qrc:/Guest2.qml"));

    auto mainAreaView = KDDockWidgets::DockRegistry::self()->mainDockingAreas().constFirst();
    auto mainAreaMDI = static_cast<KDDockWidgets::QtQuick::MainWindowMDI *>(mainAreaView);

    /// HACK: Hack to disable resize. Needs better API. And needs to be done before addDockWidget()
    const QSize size1 = { 300, 600 };
    const QSize size2 = { 400, 400 };
    dw1->setFixedSize(size1);
    dw2->setFixedSize(size2);

    mainAreaMDI->addDockWidget(dw1, QPoint(10, 10));
    mainAreaMDI->addDockWidget(dw2, QPoint(50, 50));

    // Example of changing Z manually:
    dw2->setMDIZ(30);
    dw1->setMDIZ(300);

    // Change MDI position within
    dw1->setMDIPosition({ 70, 90 });

    // Same sizes as the fixed size, while we're fixing the API
    dw1->setMDISize(size1);
    dw2->setMDISize(size2);

    return app.exec();
}
