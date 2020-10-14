#include "myWidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QFont newFont = font();

    setBackgroundRole(QPalette::Midlight);
    setAutoFillBackground(true);
    setFocusPolicy(Qt::ClickFocus);
    installEventFilter(this);
    newFont.setPointSize(newFont.pointSize() + 20);
    setFont(newFont);

    // timer.start(400, this);
}


void MyWidget::paintEvent(QPaintEvent *)
{
    QFontMetrics metrics(font());
    int curPosX = 0;
    int curPosY = metrics.ascent() - metrics.descent();
    int x = 0;
    int y = metrics.ascent() - metrics.descent();

    QPainter painter(this);

    // auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < getSize(); ++i) {
        painter.drawText(x, y,
                         QString(text[i]));
        x += metrics.horizontalAdvance(text[i]);
        if (i < curPos) {
            curPosX += metrics.horizontalAdvance(text[i]);
            if (text[i] == '\n') {
                curPosX = 0;
                curPosY += (metrics.ascent() - metrics.descent());
            }
        }
        if (text[i] == '\n' || x >= width()) {
            x = 0;
            y += (metrics.ascent() - metrics.descent());
        }
    }
    // auto finish = std::chrono::steady_clock::now();
    // auto duration = finish - start;
    // std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;

    if (hasFocus() && draw) {
        painter.drawLine(curPosX, curPosY,
                         curPosX, curPosY - (metrics.ascent() - metrics.descent()));
    }
}

void MyWidget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId()) {
        draw ? draw = 0 : draw = 1;
        update();
    } else {
        QWidget::timerEvent(event);
    }
}

bool MyWidget::eventFilter(QObject* o, QEvent* e) {
	if (e->type() == QEvent::KeyPress) {
		QKeyEvent* k = static_cast<QKeyEvent*>(e);
        int key = k->key();
        QString newText = k->text();

        if (k->matches(QKeySequence::Paste)) {
            if (QClipboard* c = QApplication::clipboard() ) {
                if (const QMimeData* m = c->mimeData() ) {
                    if (m->hasText()) {
                        setText(m->text(), curPos);
                        return false;
                    }
                }
            }
        }
		else if (key == Qt::Key_Tab) {
            setText("\t", curPos);
            return true;
		}
        else if (key == Qt::Key_Return) {
            setText("\n", curPos);
            return true;
        }
        else if (key == Qt::Key_Backspace) {
            backspace();
            return true;
        }
        else if (key == Qt::Key_Left || key == Qt::Key_Right) {
            if (key == Qt::Key_Left) {
                if (curPos > 0) {
                    --curPos;
                }
            }
            else {
                if (curPos < getSize()) {
                    ++curPos;
                }
            }
            update();
            return true;
        }
        else {
            setText(newText, curPos);
            return false;
        }
	}
	return false;
}

void MyWidget::setText(const QString newText) {
    text += newText; update();
}

void MyWidget::setText(const QString newText, int pos) {
    // auto start = std::chrono::steady_clock::now();

    text.insert(pos, newText);

    // auto finish = std::chrono::steady_clock::now();
    // auto duration = finish - start;
    // std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;

    if (!newText.isEmpty()) {
        curPos += newText.size();
    }
    update();
}

void MyWidget::backspace() {
    if (curPos > 0) {
        text.remove(--curPos, 1);
        update();
    }
}

MyCursor::MyCursor(QWidget *parent)
                : QWidget(parent)
{
    setBackgroundRole(QPalette::Midlight);
    setAutoFillBackground(true);
};

void MyCursor::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
 }