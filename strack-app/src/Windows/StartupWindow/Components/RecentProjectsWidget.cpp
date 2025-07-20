#include "RecentProjectsWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSettings>
#include <QDir>
#include <QFileInfo>
#include <QListWidgetItem>

RecentProjectsWidget::RecentProjectsWidget(QWidget* parent)
    : QWidget(parent),
    listWidget(new QListWidget(this))
{
    setupUI();
    setupConnections();
    loadProjects();
}

void RecentProjectsWidget::setupUI()
{
    auto* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel(tr("Recent Projects:"), this));
    layout->addWidget(listWidget);
    setLayout(layout);
}

void RecentProjectsWidget::setupConnections()
{
    connect(listWidget, &QListWidget::itemActivated, this, [this](QListWidgetItem* item) {
        emit projectSelected(item->data(Qt::UserRole).toString());
        });
}

QStringList RecentProjectsWidget::projects() const
{
    QSettings settings;
    return settings.value("recentProjects").toStringList();
}

void RecentProjectsWidget::loadProjects()
{
    listWidget->clear();
    for (const QString& p : projects()) {
        auto* item = new QListWidgetItem(QFileInfo(p).fileName(), listWidget);
        item->setToolTip(p);
        item->setData(Qt::UserRole, p);
        listWidget->addItem(item);
    }
}

void RecentProjectsWidget::saveProjects()
{
    QSettings settings;
    settings.setValue("recentProjects", projects());
}

void RecentProjectsWidget::addProject(const QString& path)
{
    QStringList recs = projects();
    recs.removeAll(path);
    recs.prepend(path);
    while (recs.size() > 5)
        recs.removeLast();
    QSettings settings;
    settings.setValue("recentProjects", recs);
    loadProjects();
}
