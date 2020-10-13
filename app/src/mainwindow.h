#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>

#include "myTab.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    myTab*  tab;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
