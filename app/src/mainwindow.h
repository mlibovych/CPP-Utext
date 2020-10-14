#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>

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
    myTreeWidget *tree;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionsave_triggered();
    void on_actionactionundo_triggered();
    void on_actionredo_triggered();
};
