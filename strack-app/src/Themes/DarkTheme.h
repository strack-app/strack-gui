#ifndef DARKTHEME_H
#define DARKTHEME_H

#include "Theme.h"

class DarkTheme : public Theme {
public:
    QString styleSheet() const override;
};

#endif // DARKTHEME_H
