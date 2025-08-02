#include "Windows/MainWindow/Components/ContentWidget/ContentWidget.h"
#include "Windows/MainWindow/Components/ContentWidget/Components/CodeEditorView.h"
#include <QVBoxLayout>
#include <QFileInfo>

ContentWidget::ContentWidget(QWidget* parent)
    : QWidget(parent),
    tabWidget(new QTabWidget(this))
{
    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(tabWidget);
    setLayout(layout);

    tabWidget->setTabsClosable(true);
    connect(tabWidget, &QTabWidget::tabCloseRequested, this, [this](int index) {
        QWidget* widget = tabWidget->widget(index);
        QString key = openFiles.key(static_cast<ContentView*>(widget));
        openFiles.remove(key);
        tabWidget->removeTab(index);
        delete widget;
        });
}

void ContentWidget::openFile(const QString& filePath)
{
    if (openFiles.contains(filePath)) {
        tabWidget->setCurrentWidget(openFiles[filePath]);
        return;
    }

    ContentView* view = new CodeEditorView(this);
    view->openFile(filePath);

    QString tabName = fileNameFromPath(filePath);
    tabWidget->addTab(view, tabName);
    tabWidget->setCurrentWidget(view);

    openFiles[filePath] = view;
}

QString ContentWidget::fileNameFromPath(const QString& path) const
{
    return QFileInfo(path).fileName();
}
