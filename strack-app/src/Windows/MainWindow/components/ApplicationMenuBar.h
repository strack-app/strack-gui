#ifndef APPLICATIONMENUBAR_H
#define APPLICATIONMENUBAR_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class ApplicationMenuBar : public QMenuBar {
    Q_OBJECT
public:
    explicit ApplicationMenuBar(QWidget* parent = nullptr);

signals:
    void openFileRequested();
    void saveFileRequested();
    void settingsRequested();
    void toggleFileExplorerRequested();
    void aboutRequested();

private:
    void createMenus();

    QMenu* fileMenu;
    QMenu* settingsMenu;
    QMenu* toolsMenu;
    QMenu* viewMenu;
    QMenu* helpMenu;
};

#endif // APPLICATIONMENUBAR_H
