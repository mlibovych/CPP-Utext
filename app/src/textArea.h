#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>
#include <QTextCursor>

class TextArea : public QPlainTextEdit
{
    Q_OBJECT

private:
    QString plainText;
public:
    explicit TextArea(QWidget *parent = nullptr);
    ~TextArea();
};