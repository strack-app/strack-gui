#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./Components/ApplicationMenuBar.h"
#include "./Components/FileExplorerWidget.h"
#include "./Components/CodeEditorWidget.h"
#include "./Components/ControlStripWidget.h"
#include <memory>
#include "../../Themes/Theme.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    void setTheme(std::unique_ptr<Theme> theme);
    void setProjectPath(const QString& projectPath);

private:
    ApplicationMenuBar* appMenuBar;
    FileExplorerWidget* fileExplorer;
    CodeEditorWidget* codeEditor;
    ControlStripWidget* controlStrip;
    std::unique_ptr<Theme> currentTheme;

    void setupCentralLayout();
    void connectSignals();

private slots:
    void onFileSelected(const QString& filePath);
    void toggleExplorer();
    void openSettingsDialog();
    void showAboutDialog();
};

#endif // MAINWINDOW_H
