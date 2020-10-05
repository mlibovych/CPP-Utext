#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>

class TextArea : public QPlainTextEdit
{
    Q_OBJECT

private:

public:
    explicit TextArea(QWidget *parent = nullptr);
    ~TextArea();

    QString toPlainText() const;
};