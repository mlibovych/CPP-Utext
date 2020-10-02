#pragma once

#include <string>

#include <QtWidgets>

#include <QMainWindow>
#include <QFileSystemModel>
#include <QLineEdit>
#include <QListView>
#include <QTableView>
#include <QMenu>
#include <QMessageBox>

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

private slots:
};

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);

public slots:
    void setText(/*const QString &newText*/) { text += "123"; update(); }
    void setText(const QString newText) { text += newText; update(); }

protected:
    void paintEvent(QPaintEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

private:
    QString text;
};
