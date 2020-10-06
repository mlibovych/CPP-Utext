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

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);

    int getSize() {
        return text.size();
    }

public slots:
    void setText(const QString newText) {
        text += newText; update();
    }

    void setText(const QString newText, int pos) {
        text.insert(pos, newText);
        if (!newText.isEmpty()) {
            ++curPos;
        }
        update();
    }

    void backspace() {
        if (curPos > 0) {
            text.remove(--curPos, 1);
            update();
        }
    }

protected:
    void paintEvent(QPaintEvent *event) override;

    bool eventFilter(QObject* o, QEvent* e) override;

private:
    QString text;
    int curPos = 0;
};
