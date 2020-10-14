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
    friend class myTree;
    friend class myTab;

private:
    Ui::MainWindow *ui;

    QSplitter *splitter;
    myTab*  tab;
    myTreeWidget *tree;
    // QList<QString> open_files;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
