#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>

#include "textArea.h"

class myTree : public QTreeView
{
    Q_OBJECT
public:
    explicit myTree(QWidget* parent = nullptr);

};

class myTreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myTreeWidget(QWidget* parent = nullptr);

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void paintEvent(QPaintEvent *) override;

};
