#ifndef CODEEDITORWIDGET_H
#define CODEEDITORWIDGET_H

#include <QPlainTextEdit>

class CodeEditorWidget : public QPlainTextEdit {
    Q_OBJECT
public:
    explicit CodeEditorWidget(QWidget* parent = nullptr);

public slots:
    // Opens a file and displays its content
    void openFile(const QString& filePath);

private:
    void setupEditor();
};

#endif // CODEEDITORWIDGET_H
