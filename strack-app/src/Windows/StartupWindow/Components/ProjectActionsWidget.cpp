#include "Windows/StartupWindow/Components/ProjectActionsWidget.h"
#include <QVBoxLayout>

ProjectActionsWidget::ProjectActionsWidget(QWidget* parent)
    : QWidget(parent),
    openButton(new QPushButton(tr("Open Existing Project..."), this)),
    newButton(new QPushButton(tr("Create New Project..."), this))
{
    setupUI();
    setupConnections();
}

void ProjectActionsWidget::setupUI()
{
    auto* layout = new QVBoxLayout(this);
    layout->addWidget(openButton);
    layout->addWidget(newButton);
    layout->addStretch();
    setLayout(layout);
}

void ProjectActionsWidget::setupConnections()
{
    connect(openButton, &QPushButton::clicked, this, &ProjectActionsWidget::openProjectRequested);
    connect(newButton, &QPushButton::clicked, this, &ProjectActionsWidget::newProjectRequested);
}
