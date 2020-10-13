#include "myTree.h"

myTree::myTree(QWidget *parent) :
                        QTreeView(parent)
{
}


myTreeWidget::myTreeWidget(QWidget *parent) :
                        QWidget(parent)
{
    setAcceptDrops(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMinimumSize(160, 400);
    setMaximumSize(160, 16777215);
}


void myTreeWidget::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void myTreeWidget::dropEvent(QDropEvent *event)
{
    QString filePath = event->mimeData()->urls()[0].toLocalFile();
    QFileInfo info(filePath);

    if (info.isDir()) {
        std::cout << "aaa" << std::endl;
    }
}

void myTreeWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
 }