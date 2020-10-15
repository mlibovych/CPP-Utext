#pragma once

#include <string>
#include <iostream>
#include <map>

#include <QtWidgets>

#include "textArea.h"

class myTab : public QTabWidget
{
    Q_OBJECT
private:
    std::map<QString, TextArea *> tab_content;

public:
    explicit myTab(QWidget* parent = nullptr);

    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

    void addFile(QString filePath);

    TextArea *getTextArea();
    TextArea *getTextArea(const QString& filename);
    QString getFilename(int index);

public slots:
    void closeTab(int index);
    void updateTabName();
};
