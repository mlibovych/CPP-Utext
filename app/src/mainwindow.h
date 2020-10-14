#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>
#include <QSplitter>

#include "myTab.h"
#include "myTree.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    QSplitter *splitter;
    myTab*  tab;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
