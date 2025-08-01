#include "Windows/MainWindow/Components/FileExplorerWidget.h"
#include <QVBoxLayout>
#include <QDir>

FileExplorerWidget::FileExplorerWidget(QWidget* parent)
    : QWidget(parent),
    treeView(new QTreeView(this)),
    model(new QFileSystemModel(this))
{
    setupUI();
    setupConnections();
}

void FileExplorerWidget::setupUI()
{
    model->setRootPath(QDir::currentPath());
    model->setNameFilters(QStringList() << "*.cpp" << "*.h" << "*.txt");
    model->setNameFilterDisables(false);

    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::currentPath()));
    treeView->setHeaderHidden(true);

    auto* layout = new QVBoxLayout(this);
    layout->addWidget(treeView);
    setLayout(layout);
}

void FileExplorerWidget::setupConnections()
{
    connect(treeView, &QTreeView::doubleClicked,
        this, [this](const QModelIndex& idx) {
            const QString path = model->filePath(idx);
            emit fileSelected(path);
        });
}

QString FileExplorerWidget::currentPath() const
{
    return model->rootPath();
}

void FileExplorerWidget::setRootPath(const QString& path)
{
    const QModelIndex idx = model->setRootPath(path);
    treeView->setRootIndex(idx);
}
