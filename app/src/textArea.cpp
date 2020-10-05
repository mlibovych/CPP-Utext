#include "textArea.h"

TextArea::TextArea(QWidget *parent) :
                        QPlainTextEdit(parent)
{
}

TextArea::~TextArea()
{
}

QString TextArea::toPlainText() const {
    return "aaaa";
}