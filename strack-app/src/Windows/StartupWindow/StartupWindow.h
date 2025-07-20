#ifndef STARTUP_WINDOW_H
#define STARTUP_WINDOW_H

#include <QDialog>
#include <QString>
#include <memory>
#include "Components/ProjectActionsWidget.h"
#include "Components/RecentProjectsWidget.h"

class StartupWindow : public QDialog {
    Q_OBJECT

public:
    explicit StartupWindow(QWidget* parent = nullptr);
    ~StartupWindow();

    QString selectedProjectPath() const;

private:
    std::unique_ptr<ProjectActionsWidget> actionsWidget;
    std::unique_ptr<RecentProjectsWidget> recentWidget;
    QString chosenPath;

private slots:
    void onOpenRequested();
    void onNewRequested();
    void onRecentProjectSelected(const QString& path);
    void setupUI();
    void setupConnections();
};

#endif // STARTUP_WINDOW_H
