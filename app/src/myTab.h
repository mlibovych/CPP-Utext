#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>

#include "textArea.h"

class myTab : public QTabWidget
{
    Q_OBJECT
public:
    explicit myTab(QWidget* parent = nullptr);

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

public slots:

    void closeTab(int index);

};
