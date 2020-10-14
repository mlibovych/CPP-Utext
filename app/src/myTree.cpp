#include "myTree.h"
#include <iostream>

myTreeScroll::myTreeScroll(QWidget *parent) :
                        QWidget(parent)
{
}

myTree::myTree(QWidget *parent) :
                        QTreeView(parent)
{
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
        QFileSystemModel* dirmodel = new QFileSystemModel();

        dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
        dirmodel->setRootPath(filePath);

        tab->label = new QLabel(filePath, tab);
        tab->tree = new myTree(tab);
        tab->tree->absPath = filePath;
        tab->tree->setModel(dirmodel);
        tab->tree->setRootIndex(dirmodel->index(filePath));
        tab->tree->setHeaderHidden(true);
        tab->tree->hideDirModelCols(dirmodel);

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
