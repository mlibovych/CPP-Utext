#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>

#include "textArea.h"
#include "myTreeList.h"

class myTree : public QTreeView
{
    Q_OBJECT
public:
    explicit myTree(QWidget* parent = nullptr);

    void hideDirModelCols(QFileSystemModel* dirmodel);

    QString absPath;
    QString dirName;
};

class myTreeScroll : public QWidget
{
    Q_OBJECT
public:
    explicit myTreeScroll(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *) override;

    QLabel *label;
    myTree *tree;
    QGridLayout* mylayout = new QGridLayout(this);

};

class myTreeWidget : public QScrollArea
{
    Q_OBJECT
private:
    myTreeScroll* central = new myTreeScroll(this);
public:
    explicit myTreeWidget(QWidget* parent = nullptr);

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void paintEvent(QPaintEvent *) override;

};
