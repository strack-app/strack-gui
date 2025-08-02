#include "Windows/MainWindow/MainWindow.h"
#include "Windows/MainWindow/Components/ApplicationMenuBar.h"
#include "Windows/MainWindow/Components/FileExplorerWidget.h"
#include "Windows/MainWindow/Components/ControlStripWidget.h"
#include "Windows/MainWindow/Components/ContentWidget/ContentWidget.h"
#include "Windows/SettingsWindow/SettingsWindow.h"
#include "Themes/Theme.h"

#include <QDockWidget>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QApplication>
#include <QSplitter>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    appMenuBar(new ApplicationMenuBar(this)),
    fileExplorer(new FileExplorerWidget(this)),
    contentWidget(new ContentWidget(this)),
    controlStrip(new ControlStripWidget(this))
{
    setMenuBar(appMenuBar);
    setupCentralLayout();
    connectSignals();
    setWindowTitle(tr("Strack"));
    resize(1024, 768);
}

void MainWindow::setTheme(std::unique_ptr<Theme> theme)
{
    currentTheme = std::move(theme);
    qApp->setStyleSheet(currentTheme->styleSheet());
}

void MainWindow::setupCentralLayout()
{
    auto* central = new QWidget(this);
    auto* layout = new QVBoxLayout(central);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    layout->addWidget(controlStrip);

    auto* splitter = new QSplitter(Qt::Horizontal, central);
    splitter->addWidget(fileExplorer);
    splitter->addWidget(contentWidget);
    splitter->setStretchFactor(1, 1);

    layout->addWidget(splitter);

    central->setLayout(layout);
    setCentralWidget(central);
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
            tr("Source Files (*.cpp *.h);Text Files (*.txt);All Files (*)")
        );
        if (!file.isEmpty()) {
            contentWidget->openFile(file);
            fileExplorer->setRootPath(QFileInfo(file).absolutePath());
        }
        });

    connect(appMenuBar, &ApplicationMenuBar::toggleFileExplorerRequested,
        this, &MainWindow::toggleExplorer);

    connect(appMenuBar, &ApplicationMenuBar::settingsRequested,
        this, &MainWindow::openSettingsDialog);

    connect(appMenuBar, &ApplicationMenuBar::aboutRequested,
        this, &MainWindow::showAboutDialog);

    connect(controlStrip, &ControlStripWidget::runClicked, []() {
        qDebug() << "Run clicked";
        });

    connect(controlStrip, &ControlStripWidget::addClicked, []() {
        qDebug() << "Add clicked";
        });

    connect(controlStrip, &ControlStripWidget::deleteClicked, []() {
        qDebug() << "Delete clicked";
        });
}

void MainWindow::onFileSelected(const QString& filePath)
{
    contentWidget->openFile(filePath);
}

void MainWindow::toggleExplorer()
{
    fileExplorer->setVisible(!fileExplorer->isVisible());
}

void MainWindow::openSettingsDialog()
{
    SettingsWindow dialog(this);
    dialog.exec();
}

void MainWindow::showAboutDialog()
{
    QMessageBox::information(this, tr("About"), tr("Strack\nA Qt-based modular IDE template."));
}

void MainWindow::setProjectPath(const QString& projectPath)
{
    fileExplorer->setRootPath(projectPath);
}
