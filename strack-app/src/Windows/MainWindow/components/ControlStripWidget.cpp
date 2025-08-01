#include "Windows/MainWindow/Components/ControlStripWidget.h"

ControlStripWidget::ControlStripWidget(QWidget* parent)
    : QWidget(parent),
    runButton(new QPushButton(tr("Run"), this)),
    addButton(new QPushButton(tr("Add"), this)),
    deleteButton(new QPushButton(tr("Delete"), this))
{
    setupUI();
    setupConnections();
}

void ControlStripWidget::setupUI()
{
    auto* layout = new QHBoxLayout(this);
    layout->addStretch();
    layout->addWidget(runButton);
    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    setLayout(layout);
    setFixedHeight(40);
}

void ControlStripWidget::setupConnections()
{
    connect(runButton, &QPushButton::clicked, this, &ControlStripWidget::runClicked);
    connect(addButton, &QPushButton::clicked, this, &ControlStripWidget::addClicked);
    connect(deleteButton, &QPushButton::clicked, this, &ControlStripWidget::deleteClicked);
}
