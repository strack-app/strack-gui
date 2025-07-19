#include "strack-gui.h"
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>

StrackDialog::StrackDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Hello Dialog");

    auto* layout = new QVBoxLayout(this);
    auto* label = new QLabel("Hello, World!", this);
    layout->addWidget(label);

    setLayout(layout);
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    StrackDialog dialog;
    dialog.show();
    return app.exec();
}