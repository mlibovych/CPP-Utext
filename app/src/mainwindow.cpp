#include "mainwindow.h"
#include "../Forms/ui_mainwindow.h"

#include "textArea.h"

MainWindow::MainWindow(QWidget *parent) :
                        QMainWindow(parent),
                        ui(new Ui::MainWindow)
{
    tab = new myTab();

    ui->setupUi(this);
    ui->horizontalLayout_4->addWidget(tab);
}

MainWindow::~MainWindow()
{
    delete ui;
}