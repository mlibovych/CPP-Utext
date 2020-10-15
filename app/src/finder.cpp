#include "finder.h"

Finder::Finder(TextArea *text_area) : area(text_area) {
    window = new QWidget;
    window->setMinimumSize(250, 120);
    window->setMaximumSize(250, 120);

    edit = new QLineEdit();
    edit->setPlaceholderText("Enter text or regex");

    button_find = new QPushButton("Find");
    button_replace = new QPushButton("Replace");
    button_replace_all = new QPushButton("Replace all");
    button_replace->setEnabled(false);
    button_replace_all->setEnabled(false);

    QIcon icon_prev(":/prev.png");
    prev = new QPushButton(icon_prev, "");
    QIcon icon_next(":/next.png");
    next = new QPushButton(icon_next, "");
    count = new QLabel("0 out of 0");

    next->setEnabled(false);
    prev->setEnabled(false);

    l = new QGridLayout(window);
    l->addWidget(edit, 0, 0, 1, 3);
    l->addWidget(button_find, 1, 0, 1, 1);
    l->addWidget(button_replace, 1, 1, 1, 1);
    l->addWidget(button_replace_all, 1, 2, 1, 1);
    l->addWidget(prev, 2, 0, 1, 1);
    l->addWidget(count, 2, 1, 1, 1);
    l->addWidget(next, 2, 2, 1, 1);

    QObject::connect(button_find, SIGNAL(clicked()), SLOT(findButtonClicked()));
    QObject::connect(prev, SIGNAL(clicked()), SLOT(prevButtonClicked()));
    QObject::connect(next, SIGNAL(clicked()), SLOT(nextButtonClicked()));

    window->show();
}

Finder::~Finder() {
    delete l;
    delete window;
}

void Finder::findButtonClicked() {
    if (!area)
        return;
    
    regex = QRegExp(edit->text());
    int counter = 0;

    area->moveCursor(QTextCursor::Start);
    while (area->find(regex))
        counter++;

    if (counter > 0) {
        matches = counter;
        current_match = 1;
        setText();
        button_replace->setEnabled(true);
        button_replace_all->setEnabled(true);

        area->moveCursor(QTextCursor::Start);
        area->find(regex);
    }
    if (counter > 1) {
        next->setEnabled(true);
        prev->setEnabled(true);
    }
}

void Finder::prevButtonClicked() {
    if (current_match == 1)
        return;

    int i = 0;
    area->moveCursor(QTextCursor::Start);
    while (i < current_match - 1 && area->find(regex))
        i++;

    --current_match;
    setText();
}

void Finder::nextButtonClicked() {
    if (current_match < matches && area->find(regex)) {
        ++current_match;
        setText();
    }
}

void Finder::setText() {
    count->setText(QString(std::to_string(current_match).c_str()) +
                   " out of " +
                   QString(std::to_string(matches).c_str()));
}