#include "Windows/StartupWindow/StartupWindow.h"
#include "Windows/StartupWindow/Components/ProjectActionsWidget.h"
#include "Windows/StartupWindow/Components/RecentProjectsWidget.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>

StartupWindow::~StartupWindow() = default;

StartupWindow::StartupWindow(QWidget* parent)
    : QDialog(parent),
    actionsWidget(std::make_unique<ProjectActionsWidget>(this)),
    recentWidget(std::make_unique<RecentProjectsWidget>(this))
{
    setWindowTitle(tr("Select Project"));
    resize(400, 300);
    setupUI();
    setupConnections();
}

void StartupWindow::setupUI()
{
    auto* layout = new QVBoxLayout(this);
    layout->addWidget(actionsWidget.get());
    layout->addWidget(recentWidget.get());
    setLayout(layout);
}

void StartupWindow::setupConnections()
{
    connect(actionsWidget.get(), &ProjectActionsWidget::openProjectRequested,
        this, &StartupWindow::onOpenRequested);
    connect(actionsWidget.get(), &ProjectActionsWidget::newProjectRequested,
        this, &StartupWindow::onNewRequested);
    connect(recentWidget.get(), &RecentProjectsWidget::projectSelected,
        this, &StartupWindow::onRecentProjectSelected);
}

void StartupWindow::onOpenRequested()
{
    const QString path = QFileDialog::getExistingDirectory(
        this, tr("Existing Project Folder"), QDir::homePath());
    if (path.isEmpty())
        return;
    chosenPath = path;
    recentWidget->addProject(path);
    accept();
}

void StartupWindow::onNewRequested()
{
    const QString parentDir = QFileDialog::getExistingDirectory(
        this, tr("Select Location for New Project"), QDir::homePath());
    if (parentDir.isEmpty())
        return;
    bool ok = false;
    const QString name = QInputDialog::getText(
        this, tr("Project Name"), tr("New project name:"), QLineEdit::Normal, {}, &ok);
    if (!ok || name.isEmpty())
        return;
    const QString newDir = QDir(parentDir).filePath(name);
    QDir dir;
    if (!dir.mkpath(newDir)) {
        QMessageBox::warning(this, tr("Error"),
            tr("Project could not be created: %1").arg(newDir));
        return;
    }
    chosenPath = newDir;
    recentWidget->addProject(newDir);
    accept();
}

void StartupWindow::onRecentProjectSelected(const QString& path)
{
    chosenPath = path;
    accept();
}

QString StartupWindow::selectedProjectPath() const
{
    return chosenPath;
}
