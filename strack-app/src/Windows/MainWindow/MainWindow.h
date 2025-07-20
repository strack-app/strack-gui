#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./components/ApplicationMenuBar.h"
#include "./components/FileExplorerWidget.h"
#include "./components/CodeEditorWidget.h"
#include <memory>
#include "../../Themes/Theme.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    void setTheme(std::unique_ptr<Theme> theme);

private:
    ApplicationMenuBar* appMenuBar;
    FileExplorerWidget* fileExplorer;
    CodeEditorWidget* codeEditor;
    std::unique_ptr<Theme> currentTheme;

    void setupDockWidgets();
    void connectSignals();

private slots:
    void onFileSelected(const QString& filePath);
    void toggleExplorer();
    void openSettingsDialog();
    void showAboutDialog();
};

#endif // MAINWINDOW_H
