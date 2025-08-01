#ifndef LIGHTTHEME_H
#define LIGHTTHEME_H

#include "Theme.h"

class LightTheme : public Theme {
public:
    QString styleSheet() const override;
};

#endif // LIGHTTHEME_H
