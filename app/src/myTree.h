#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>

#include "textArea.h"
#include "myTab.h"

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QString text, QWidget* parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;

public slots:
    void slotRemove();

};

class myTree : public QTreeView
{
    Q_OBJECT
public:
    explicit myTree(QWidget* parent = nullptr);

    void hideDirModelCols(QFileSystemModel* dirmodel);
    void mousePressEvent(QMouseEvent *event) override;
    myTab* getMyTab(void);

    QString absPath;
    QString dirName;
    QFileSystemModel* dirmodel;

public slots:
    void slotRename();

signals:
    void fileRenamed(QString oldPath, QString newPath);
};

class myTreeScroll : public QWidget
{
    Q_OBJECT
public:
    explicit myTreeScroll(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *) override;

    myLabel *label;
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
