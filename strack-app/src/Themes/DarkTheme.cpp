#include "DarkTheme.h"

QString DarkTheme::styleSheet() const {
    return QString(R"(
        QWidget {
            background-color: #2b2b2b;
            color: #f0f0f0;
        }
        QMenuBar {
            background-color: #3c3f41;
        }
        QMenuBar::item {
            background: transparent;
        }
        QMenuBar::item:selected {
            background: #505354;
        }
        QDockWidget {
            titlebar-close-icon: url(:/icons/close.svg);
        }
    )");
}
