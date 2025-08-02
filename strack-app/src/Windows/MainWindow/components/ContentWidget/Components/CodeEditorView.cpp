#include "Windows/MainWindow/Components/ContentWidget/Components/CodeEditorView.h"
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QMessageBox>

CodeEditorView::CodeEditorView(QWidget* parent)
    : ContentView(parent),
    textEdit(new QPlainTextEdit(this))
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(textEdit);
    setLayout(layout);

    QFont font("Courier", 10);
    textEdit->setFont(font);
    textEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
}

void CodeEditorView::openFile(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Cannot Open File"),
            tr("Cannot open file: %1").arg(filePath));
        return;
    }

    QTextStream in(&file);
    textEdit->setPlainText(in.readAll());
    file.close();
}
