#ifndef CONTROLSTRIPWIDGET_H
#define CONTROLSTRIPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class ControlStripWidget : public QWidget {
    Q_OBJECT
public:
    explicit ControlStripWidget(QWidget* parent = nullptr);

signals:
    void runClicked();
    void addClicked();
    void deleteClicked();

private:
    QPushButton* runButton;
    QPushButton* addButton;
    QPushButton* deleteButton;

    void setupUI();
    void setupConnections();
};

#endif // CONTROLSTRIPWIDGET_H
