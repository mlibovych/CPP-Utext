#include <iostream>

#include "textArea.h"

TextArea::TextArea(QWidget *parent) :
                        QPlainTextEdit(parent)
{
    setAcceptDrops(false);
}

TextArea::~TextArea()
{
}