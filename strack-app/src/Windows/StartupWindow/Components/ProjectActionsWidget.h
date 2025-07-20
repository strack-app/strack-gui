#ifndef PROJECTACTIONS_WIDGET_H
#define PROJECTACTIONS_WIDGET_H

#include <QWidget>
#include <QPushButton>

class ProjectActionsWidget : public QWidget {
    Q_OBJECT
public:
    explicit ProjectActionsWidget(QWidget* parent = nullptr);

signals:
    void openProjectRequested();
    void newProjectRequested();

private:
    QPushButton* openButton;
    QPushButton* newButton;
    void setupUI();
    void setupConnections();
};

#endif // PROJECTACTIONS_WIDGET_H
