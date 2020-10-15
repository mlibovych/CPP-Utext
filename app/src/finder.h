#pragma once

#include <QtWidgets>

#include "textArea.h"

class Finder : public QObject {

    Q_OBJECT

private:
    TextArea *area;

    QLineEdit *find_edit;
    QLineEdit *replace_edit;
    QPushButton *button_find;
    QPushButton *button_replace;
    QPushButton *button_replace_all;
    QLabel *count;
    QPushButton *button_next;
    QPushButton *button_prev;
    QGridLayout *l;
    QWidget *window;

    int matches;
    int current_match;
    QRegExp regex;

public:
    Finder(TextArea *area);
    ~Finder();

private:
    void setupGUI();
    void setText();

public slots:
    void find();
    void prev();
    void next();
    void replace();
    void replaceAll();
};