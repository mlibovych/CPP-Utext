#include "mainwindow.h"
#include "../Forms/ui_mainwindow.h"

#include "textArea.h"

MainWindow::MainWindow(QWidget *parent) :
                        QMainWindow(parent),
                        ui(new Ui::MainWindow)
{
    find = nullptr;
    tab = new myTab();
    tree = new myTreeWidget();

    ui->setupUi(this);

    splitter = new QSplitter(ui->centralwidget);
    ui->horizontalLayout_4->addWidget(splitter);
    splitter->addWidget(tree);
    splitter->addWidget(tab);
    splitter->setSizes({200, 700});
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tab;
    delete tree;
    delete splitter;
}
void MainWindow::on_actionsave_triggered()
{
    int index = tab->currentIndex();

    if (index == -1)
        return;

    QString filename = tab->getFilename(index);

    QTextDocument *doc = tab->getTextArea(filename)->document();

    QTextDocumentWriter writer(filename);
    if (!writer.write(doc))
        QMessageBox::critical(this, "Save failed", "I don't mean to upset you, dear user, but something went terribly wrong when I tried to save the file.\nChances are, it's your fault, not mine((\nCarbon-based lifeforms make stupid mistakes all the time, please don't be too upset, do something about it and try again.\nGLHF!\n");
    else
        tab->setTabText(index, filename);
}

void MainWindow::on_actionactionundo_triggered()
{
    TextArea *area = tab->getTextArea();

    area->undo();
}

void MainWindow::on_actionredo_triggered()
{
    TextArea *area = tab->getTextArea();

    area->redo();
}

void MainWindow::on_actionfind_triggered()
{
    if (find)
        delete find;

    find = new QWidget;
    find->setMinimumSize(250, 100);
    find->setMaximumSize(250, 100);

    QLineEdit *edit = new QLineEdit();
    edit->setPlaceholderText("Enter text or regex");

    QPushButton *button_find = new QPushButton("Find");
    QPushButton *button_replace = new QPushButton("Replace");
    button_replace->setEnabled(false);

    QGridLayout *l = new QGridLayout(find);
    l->addWidget(edit, 0, 0, 1, 2);
    l->addWidget(button_find, 1, 0, 1, 1);
    l->addWidget(button_replace, 1, 1, 1, 1);

    find->show();
}
