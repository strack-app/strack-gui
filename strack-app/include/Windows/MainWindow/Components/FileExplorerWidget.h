#ifndef FILEEXPLORERWIDGET_H
#define FILEEXPLORERWIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>

class FileExplorerWidget : public QWidget {
    Q_OBJECT
public:
    explicit FileExplorerWidget(QWidget* parent = nullptr);

    // Returns the current root directory
    QString currentPath() const;

public slots:
    // Sets a new root directory
    void setRootPath(const QString& path);

signals:
    // Emitted when user double-clicks a file
    void fileSelected(const QString& filePath);

private:
    QTreeView* treeView;
    QFileSystemModel* model;

    void setupUI();
    void setupConnections();
};

#endif // FILEEXPLORERWIDGET_H
