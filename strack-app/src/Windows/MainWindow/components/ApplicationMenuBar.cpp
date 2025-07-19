#include "ApplicationMenuBar.h"
#include <QApplication>

ApplicationMenuBar::ApplicationMenuBar(QWidget* parent)
    : QMenuBar(parent)
{
    createMenus();
}

void ApplicationMenuBar::createMenus()
{
    // File menu
    fileMenu = addMenu(tr("&File"));
    QAction* openAct = fileMenu->addAction(tr("&Open"));
    QAction* saveAct = fileMenu->addAction(tr("&Save"));
    fileMenu->addSeparator();
    QAction* exitAct = fileMenu->addAction(tr("E&xit"));

    connect(openAct, &QAction::triggered, this, &ApplicationMenuBar::openFileRequested);
    connect(saveAct, &QAction::triggered, this, &ApplicationMenuBar::saveFileRequested);
    connect(exitAct, &QAction::triggered, qApp, &QCoreApplication::quit);

    // Settings menu
    settingsMenu = addMenu(tr("&Settings"));
    QAction* prefAct = settingsMenu->addAction(tr("Preferences"));
    connect(prefAct, &QAction::triggered, this, &ApplicationMenuBar::settingsRequested);

    // Tools menu (empty for future extensions)
    toolsMenu = addMenu(tr("&Tools"));

    // View menu
    viewMenu = addMenu(tr("&View"));
    QAction* toggleExp = viewMenu->addAction(tr("Show/Hide Explorer"));
    connect(toggleExp, &QAction::triggered, this, &ApplicationMenuBar::toggleFileExplorerRequested);

    // Help menu
    helpMenu = addMenu(tr("&Help"));
    QAction* aboutAct = helpMenu->addAction(tr("About"));
    connect(aboutAct, &QAction::triggered, this, &ApplicationMenuBar::aboutRequested);
}
