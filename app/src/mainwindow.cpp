#include "mainwindow.h"
#include "../Forms/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
                        QMainWindow(parent),
                        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // MyWidget *myWidget = new MyWidget;

    // ui->horizontalLayout_4->addWidget(myWidget);
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

    setFocusPolicy(Qt::ClickFocus);
    installEventFilter(this);
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
        if (text[i] == '\n') {
            x = 0;
            y += (metrics.ascent() - metrics.descent());
        }
    }
}

bool MyWidget::eventFilter(QObject* o, QEvent* e) {
	if (e->type() == QEvent::KeyPress) {
		QKeyEvent* k = static_cast<QKeyEvent*>(e);
        int key = k->key();
        QString text = k->text();

		if (key == Qt::Key_Tab) {
			setText("    ");
            return true;
		}
        else if (key == Qt::Key_Return) {
            text = "\n";
        }
        setText(text);
        return false;
	}
	return false;
}