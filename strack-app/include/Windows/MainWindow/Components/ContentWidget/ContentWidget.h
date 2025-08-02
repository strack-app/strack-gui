#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QMap>

class ContentView;

class ContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ContentWidget(QWidget* parent = nullptr);
    void openFile(const QString& filePath);

private:
    QTabWidget* tabWidget;
    QMap<QString, ContentView*> openFiles;

    QString fileNameFromPath(const QString& path) const;
};
