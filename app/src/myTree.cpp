#include "myTree.h"
#include <iostream>

myTree::myTree(QWidget *parent) :
                        QTreeView(parent)
{
}


myTreeWidget::myTreeWidget(QWidget *parent) :
                        QWidget(parent)
{
    setAcceptDrops(true);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    setMinimumSize(160, 400);
    setMaximumSize(260, 16777215);
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
        QTabWidget *tab = new QTabWidget(this);
        myTree* tree = new myTree();
        std::cout << info.baseName().toStdString() << std::endl;
        tab->addTab(tree, info.baseName());
        QFileSystemModel* dirmodel = new QFileSystemModel();

        dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
        dirmodel->setRootPath(filePath);
        tree->setModel(dirmodel);
        tree->setRootIndex(dirmodel->index(filePath));
        tree->setHeaderHidden(true);
        tree->hideDirModelCols(dirmodel);
        layout->addWidget(tab);
    }
}

void myTreeWidget::paintEvent(QPaintEvent *)
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