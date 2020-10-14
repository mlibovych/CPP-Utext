#include "mainwindow.h"
#include "../Forms/ui_mainwindow.h"

#include "textArea.h"

MainWindow::MainWindow(QWidget *parent) :
                        QMainWindow(parent),
                        ui(new Ui::MainWindow)
{
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
    tab->setTabText(index, filename);

    QTextDocument *doc = tab->getTextArea(filename)->document();

    QTextDocumentWriter writer(filename);
    if (!writer.write(doc))
        QMessageBox::critical(this, "Save failed", "I don't mean to upset you, dear user, but something went terribly wrong when I tried to save the file.\nChances are, it's your fault, not mine((\nCarbon-based lifeforms make stupid mistakes all the time, please don't be too upset, do something about it and try again.\nGLHF!\n");
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
