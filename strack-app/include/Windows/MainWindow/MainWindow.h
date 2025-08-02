#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class ApplicationMenuBar;
class FileExplorerWidget;
class ControlStripWidget;
class ContentWidget;
class Theme;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    void setTheme(std::unique_ptr<Theme> theme);
    void setProjectPath(const QString& projectPath);

private:
    ApplicationMenuBar* appMenuBar;
    FileExplorerWidget* fileExplorer;
    ContentWidget* contentWidget;
    ControlStripWidget* controlStrip;
    std::unique_ptr<Theme> currentTheme;

    void setupCentralLayout();
    void connectSignals();

    void onFileSelected(const QString& filePath);
    void toggleExplorer();
    void openSettingsDialog();
    void showAboutDialog();
};
#endif // MAINWINDOW_H
