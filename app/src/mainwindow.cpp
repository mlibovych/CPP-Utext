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