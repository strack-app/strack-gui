#ifndef STRACK_GUI_H
#define STRACK_GUI_H

#include <QDialog>

class StrackDialog : public QDialog {
    Q_OBJECT

public:
    explicit StrackDialog(QWidget* parent = nullptr);
};

#endif