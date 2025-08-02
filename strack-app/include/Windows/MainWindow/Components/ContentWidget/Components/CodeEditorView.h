#pragma once

#include "ContentView.h"
#include <QPlainTextEdit>

class CodeEditorView : public ContentView
{
    Q_OBJECT

public:
    explicit CodeEditorView(QWidget* parent = nullptr);
    void openFile(const QString& filePath) override;

private:
    QPlainTextEdit* textEdit;
};
