#include <QApplication>
#include <QCoreApplication>
#include <memory>
#include "./Themes/LightTheme.h"
#include "./Themes/Theme.h"
#include "./Windows/StartupWindow/StartupWindow.h"
#include "./Windows/MainWindow/MainWindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("StrackAppOrg");
    QCoreApplication::setApplicationName("StrackApp");

    std::unique_ptr<Theme> theme = std::make_unique<LightTheme>();
    app.setStyleSheet(theme->styleSheet());

    StartupWindow startup;
    if (startup.exec() != QDialog::Accepted) {
        return 0;
    }
    const QString projectPath = startup.selectedProjectPath();

    MainWindow window;
    window.setProjectPath(projectPath);
    window.show();

    return app.exec();
}
