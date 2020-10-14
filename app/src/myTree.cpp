#include "myTree.h"
#include <iostream>

myLabel::myLabel(QString text, QWidget *parent) :
                        QLabel(text, parent)
{
}

void myLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        QMenu* menu = new QMenu(this);
        QAction* removeDevice = new QAction(("Remove folder from workspace"), this);

        connect(removeDevice, SIGNAL(triggered()), this, SLOT(slotRemove()));
        menu->addAction(removeDevice);
        menu->popup(this->mapToGlobal(event->pos()));
    }
}

void myLabel::slotRemove() {
    delete parent();
}

myTreeScroll::myTreeScroll(QWidget *parent) :
                        QWidget(parent)
{
}

myTree::myTree(QWidget *parent) :
                        QTreeView(parent)
{
}

void myTree::mousePressEvent(QMouseEvent *event) {
    QTreeView::mousePressEvent(event);
    if (event->button() == Qt::LeftButton) {
        QString filePath = dirmodel->filePath(currentIndex());
        parent()->parent()->parent()->parent()->parent()->parent()->parent()->findChild<myTab *>()->addFile(filePath);
    }
}


myTreeWidget::myTreeWidget(QWidget *parent) :
                        QScrollArea(parent)
{
    setAcceptDrops(true);
    setMinimumSize(1, 400);
    setWidget(central);
    setWidgetResizable(true);
    central->setAccessibleName("treeWidget1");
}


void myTreeWidget::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void myTreeWidget::dropEvent(QDropEvent *event)
{
    QString filePath = event->mimeData()->urls()[0].toLocalFile();
    QFileInfo info(filePath);
    QList<myTreeScroll*> plist = central->findChildren<myTreeScroll*>();

    if (std::count_if(plist.begin(), plist.end(), [filePath](myTreeScroll* tab) {
            return tab->tree->absPath == filePath;
        })) {
        return;
    }

    if (info.isDir()) {
        myTreeScroll *tab = new myTreeScroll(central);

        tab->label = new myLabel(filePath, tab);
        tab->tree = new myTree(tab);

        tab->tree->dirmodel = new QFileSystemModel();
        tab->tree->dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
        tab->tree->dirmodel->setRootPath(filePath);

        tab->tree->absPath = filePath;
        tab->tree->setModel(tab->tree->dirmodel);
        tab->tree->setRootIndex(tab->tree->dirmodel->index(filePath));
        tab->tree->setHeaderHidden(true);
        tab->tree->hideDirModelCols(tab->tree->dirmodel);

        tab->mylayout->addWidget(tab->label);
        tab->mylayout->addWidget(tab->tree);
        tab->setMinimumSize(1, 150);

        central->mylayout->addWidget(tab);
    }
}

void myTreeWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(viewport());
    QPainter p(viewport());
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, viewport());
}

void myTreeScroll::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void myTree::hideDirModelCols(QFileSystemModel* dirmodel) {
    for (int i = 1; i < dirmodel->columnCount(); ++i) {
        hideColumn(i);
    }
}
