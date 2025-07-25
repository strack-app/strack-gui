#include "SettingsWindow.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLabel>

SettingsWindow::SettingsWindow(QWidget* parent)
    : QDialog(parent),
    tabWidget(new QTabWidget(this))
{
    setWindowTitle("Settings");
    resize(400, 300);
    setupUI();
}

SettingsWindow::~SettingsWindow() = default;

void SettingsWindow::setupUI()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(tabWidget);
    setLayout(layout);

    addThemeTab();
}

void SettingsWindow::addThemeTab()
{
    QWidget* themeTab = new QWidget(this);
    QVBoxLayout* themeLayout = new QVBoxLayout(themeTab);
    themeLayout->addWidget(new QLabel("Theme settings will be available here.", themeTab));
    themeTab->setLayout(themeLayout);

    tabWidget->addTab(themeTab, "Theme");
}
