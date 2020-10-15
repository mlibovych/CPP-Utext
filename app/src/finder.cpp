#include "finder.h"

Finder::Finder(TextArea *text_area) : area(text_area) {
    setupGUI();
}

Finder::~Finder() {
    delete l;
    delete window;
}

void Finder::setupGUI() {
    window = new QWidget;
    window->setMinimumSize(250, 160);
    window->setMaximumSize(250, 160);

    find_edit = new QLineEdit();
    find_edit->setPlaceholderText("Enter text or regex");
    replace_edit = new QLineEdit();
    replace_edit->setPlaceholderText("Enter replacement text");
    replace_edit->setEnabled(false);

    button_find = new QPushButton("Find");
    button_replace = new QPushButton("Replace");
    button_replace_all = new QPushButton("Replace all");
    button_replace->setEnabled(false);
    button_replace_all->setEnabled(false);

    QIcon icon_prev(":/prev.png");
    button_prev = new QPushButton(icon_prev, "");
    QIcon icon_next(":/next.png");
    button_next = new QPushButton(icon_next, "");
    count = new QLabel("0 out of 0");

    button_next->setEnabled(false);
    button_prev->setEnabled(false);

    l = new QGridLayout(window);
    l->addWidget(find_edit, 0, 0, 1, 3);
    l->addWidget(replace_edit, 1, 0, 1, 3);
    l->addWidget(button_find, 2, 0, 1, 1);
    l->addWidget(button_replace, 2, 1, 1, 1);
    l->addWidget(button_replace_all, 2, 2, 1, 1);
    l->addWidget(button_prev, 3, 0, 1, 1);
    l->addWidget(count, 3, 1, 1, 1);
    l->addWidget(button_next, 3, 2, 1, 1);

    QObject::connect(button_find, SIGNAL(clicked()), SLOT(find()));
    QObject::connect(button_prev, SIGNAL(clicked()), SLOT(prev()));
    QObject::connect(button_next, SIGNAL(clicked()), SLOT(next()));
    QObject::connect(button_replace, SIGNAL(clicked()), SLOT(replace()));
    QObject::connect(button_replace_all, SIGNAL(clicked()), SLOT(replaceAll()));

    window->show();
}

void Finder::find() {
    if (!area)
        return;
    
    regex = QRegExp(find_edit->text());
    int counter = 0;
    matches = 0;
    current_match = 0;

    area->moveCursor(QTextCursor::Start);
    while (area->find(regex))
        counter++;

    if (counter > 0) {
        matches = counter;
        current_match = 1;
        button_replace->setEnabled(true);
        button_replace_all->setEnabled(true);
        replace_edit->setEnabled(true);

        area->moveCursor(QTextCursor::Start);
        area->find(regex);
    }

    setText();

    if (counter > 1) {
        button_next->setEnabled(true);
        button_prev->setEnabled(true);
    }
}

void Finder::prev() {
    if (current_match == 1)
        return;

    int i = 0;
    area->moveCursor(QTextCursor::Start);
    while (i < current_match - 1 && area->find(regex))
        i++;

    --current_match;
    setText();
}

void Finder::next() {
    if (current_match < matches && area->find(regex)) {
        ++current_match;
        setText();
    }
}

void Finder::replace() {
    QTextCursor cursor = area->textCursor();

    if (cursor.hasSelection())
        cursor.insertText(replace_edit->text());
}

void Finder::replaceAll() {
    area->moveCursor(QTextCursor::Start);
    while (area->find(regex))
        replace(); 
}

void Finder::setText() {
    count->setText(QString(std::to_string(current_match).c_str()) +
                   " out of " +
                   QString(std::to_string(matches).c_str()));
}