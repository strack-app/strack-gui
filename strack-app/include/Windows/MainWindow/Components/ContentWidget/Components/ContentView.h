#pragma once

#include <QWidget>
#include <QString>

class ContentView : public QWidget
{
    Q_OBJECT

public:
    explicit ContentView(QWidget* parent = nullptr) : QWidget(parent) {}
    virtual ~ContentView() = default;

    virtual void openFile(const QString& filePath) = 0;
};
