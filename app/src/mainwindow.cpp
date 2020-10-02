#include "mainwindow.h"
#include "../Forms/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
                        QMainWindow(parent),
                        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyWidget *myWidget = new MyWidget;

    ui->horizontalLayout_4->addWidget(myWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Midlight);
    setAutoFillBackground(true);

    QFont newFont = font();
    newFont.setPointSize(newFont.pointSize() + 20);
    setFont(newFont);

    // connect(this, SIGNAL(key(QString)), this, SLOT(setText(QString)));
    setFocusPolicy(Qt::StrongFocus);
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QFontMetrics metrics(font());
    int x = 0;
    int y = metrics.ascent() - metrics.descent();

    QPainter painter(this);
    for (int i = 0; i < text.size(); ++i) {
        painter.drawText(x, y,
                         QString(text[i]));
        x += metrics.horizontalAdvance(text[i]);
        if (x >= width()) {
            x = 0;
            y += (metrics.ascent() - metrics.descent());
        }
    }
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    QString text = event->text();
    setText(text);
    // emit key(text);
}