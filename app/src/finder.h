#pragma once

#include <QtWidgets>

#include "textArea.h"

class Finder : public QObject {

    Q_OBJECT

private:
    TextArea *area;
    QLineEdit *edit;
    QPushButton *button_find;
    QPushButton *button_replace;
    QPushButton *button_replace_all;
    QLabel *count;
    QPushButton *next;
    QPushButton *prev;
    QGridLayout *l;
    QWidget *window;

    int matches;
    int current_match;
    QRegExp regex;

public:
    Finder(TextArea *area);
    ~Finder();

private:
    void setText();

public slots:
    void findButtonClicked();
    void prevButtonClicked();
    void nextButtonClicked();
};