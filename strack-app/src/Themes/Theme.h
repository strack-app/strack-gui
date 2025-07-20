#ifndef THEME_H
#define THEME_H

#include <QString>

class Theme {
public:
    virtual ~Theme() = default;
    virtual QString styleSheet() const = 0;
};

#endif // THEME_H
