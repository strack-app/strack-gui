#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

#include <QDialog>

class QTabWidget;

class SettingsWindow : public QDialog {
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget* parent = nullptr);
    ~SettingsWindow();

private:
    QTabWidget* tabWidget;

    void setupUI();
    void addThemeTab();
};

#endif // SETTINGS_WINDOW_H
