#include "MainWindow.h"
#include <QDockWidget>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    appMenuBar(new ApplicationMenuBar(this)),
    fileExplorer(new FileExplorerWidget(this)),
    codeEditor(new CodeEditorWidget(this))
{
    setMenuBar(appMenuBar);
    setCentralWidget(codeEditor);
    setupDockWidgets();
    connectSignals();

    setWindowTitle(tr("Strack"));
    resize(1024, 768);
}

void MainWindow::setupDockWidgets()
{
    auto* dock = new QDockWidget(tr("Solution Explorer"), this);
    dock->setWidget(fileExplorer);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
}

void MainWindow::connectSignals()
{
    connect(fileExplorer, &FileExplorerWidget::fileSelected,
        this, &MainWindow::onFileSelected);

    connect(appMenuBar, &ApplicationMenuBar::openFileRequested, [this]() {
        QString file = QFileDialog::getOpenFileName(
            this,
            tr("Open File"),
            QDir::currentPath(),
            tr("Source Files (*.cpp *.h);;"
                "Text Files (*.txt);;"
                "All Files (*)")
        );
        if (!file.isEmpty()) {
            codeEditor->openFile(file);
            fileExplorer->setRootPath(QFileInfo(file).absolutePath());
        }
        });

    connect(appMenuBar, &ApplicationMenuBar::toggleFileExplorerRequested,
        this, &MainWindow::toggleExplorer);

    connect(appMenuBar, &ApplicationMenuBar::settingsRequested,
        this, &MainWindow::openSettingsDialog);

    connect(appMenuBar, &ApplicationMenuBar::aboutRequested,
        this, &MainWindow::showAboutDialog);
}

void MainWindow::onFileSelected(const QString& filePath)
{
    codeEditor->openFile(filePath);
}

void MainWindow::toggleExplorer()
{
    const auto docks = findChildren<QDockWidget*>();
    if (!docks.isEmpty()) {
        docks.first()->setVisible(!docks.first()->isVisible());
    }
}

void MainWindow::openSettingsDialog()
{
    QMessageBox::information(this, tr("Settings"),
        tr("Settings dialog can be implemented here."));
}

void MainWindow::showAboutDialog()
{
    QMessageBox::information(this, tr("About"),
        tr("Strack\nA Qt‑based modular IDE template."));
}
