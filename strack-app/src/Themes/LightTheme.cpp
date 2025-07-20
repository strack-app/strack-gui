#include "LightTheme.h"

QString LightTheme::styleSheet() const {
    return QString(R"(
        QWidget {
            background-color: #ffffff;
            color: #000000;
        }
        QMenuBar {
            background-color: #eaeaea;
        }
        QMenuBar::item:selected {
            background: #d4d4d4;
        }
    )");
}
