#pragma once

#include <string>
#include <iostream>

#include <QtWidgets>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);

    int getSize() {
        return text.size();
    }

public slots:
    void setText(const QString newText);

    void setText(const QString newText, int pos);

    void backspace();

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    bool eventFilter(QObject* o, QEvent* e) override;

private:
    QBasicTimer timer;
    QString text;
    int curPos = 0;
    bool draw = 1;
};

class MyCursor : public QWidget
{
    Q_OBJECT

public:
    MyCursor(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *) override;

private:
    // QBasicTimer timer;
};