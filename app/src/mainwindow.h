#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};

// class MyWidget : public QWidget
// {
//     Q_OBJECT

// public:
//     MyWidget(QWidget *parent = nullptr);

// public slots:
//     void setText(/*const QString &newText*/) { text += "123"; update(); }
//     void setText(const QString newText) { text += newText; update(); }

// protected:
//     void paintEvent(QPaintEvent *event) override;

//     bool eventFilter(QObject* o, QEvent* e) override;

// private:
//     QString text;
// };
