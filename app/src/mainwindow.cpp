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

    QString filename = tab->tabText(index);

    if (filename[filename.size() - 1] == '*') {
        std::string std_fname = filename.toStdString();
        std::string new_fname(std_fname.begin(), std_fname.end() - 1);
        filename = QString(new_fname.c_str());    
        tab->setTabText(index, filename);
    }

    std::cout << filename.toStdString() << std::endl;

    QTextDocument *doc = tab->getTextArea(filename)->document();

    QTextDocumentWriter writer(filename);
    if (!writer.write(doc))
        QMessageBox::critical(this, "Save failed", "I don't mean to upset you, dear user, but something went terribly wrong when I tried to save the file.\nChances are, it's your fault, not mine((\nCarbon-based lifeforms make stupid mistakes all the time, please don't be too upset, do something about it and try again.\nGLHF!\n");
}
