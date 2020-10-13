#include "mainwindow.h"
#include "../Forms/ui_mainwindow.h"

#include "textArea.h"

MainWindow::MainWindow(QWidget *parent) :
                        QMainWindow(parent),
                        ui(new Ui::MainWindow)
{
    tab = new myTab();
    myTreeWidget *tree = new myTreeWidget();

    ui->setupUi(this);
    ui->horizontalLayout_4->addWidget(tree);
    ui->horizontalLayout_4->addWidget(tab);
}

MainWindow::~MainWindow()
{
    delete ui;
}