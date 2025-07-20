#include <QApplication>
#include "./Windows/MainWindow/MainWindow.h"
#include <memory>
#include "./Themes/LightTheme.h"
#include "./Themes/Theme.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    std::unique_ptr<Theme> theme = std::make_unique<LightTheme>();
    app.setStyleSheet(theme->styleSheet());

    MainWindow window;
    window.show();

    return app.exec();
}
