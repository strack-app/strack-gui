#include "CodeEditorWidget.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

CodeEditorWidget::CodeEditorWidget(QWidget* parent)
    : QPlainTextEdit(parent)
{
    setupEditor();
}

void CodeEditorWidget::setupEditor()
{
    QFont font("Courier", 10);
    this->setFont(font);
    this->setLineWrapMode(QPlainTextEdit::NoWrap);
}

void CodeEditorWidget::openFile(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this,
            tr("Cannot Open File"),
            tr("Cannot open file: %1").arg(filePath));
        return;
    }
    QTextStream in(&file);
    this->setPlainText(in.readAll());
    file.close();
}
