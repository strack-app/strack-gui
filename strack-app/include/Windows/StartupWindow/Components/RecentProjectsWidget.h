#ifndef RECENTPROJECTS_WIDGET_H
#define RECENTPROJECTS_WIDGET_H

#include <QWidget>
#include <QListWidget>

class RecentProjectsWidget : public QWidget {
    Q_OBJECT
public:
    explicit RecentProjectsWidget(QWidget* parent = nullptr);
    void addProject(const QString& path);

signals:
    void projectSelected(const QString& path);

private:
    QListWidget* listWidget;
    void loadProjects();
    void saveProjects();
    QStringList projects() const;
    void setupUI();
    void setupConnections();
};

#endif // RECENTPROJECTS_WIDGET_H
