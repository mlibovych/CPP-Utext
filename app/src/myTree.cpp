#include "myTree.h"

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
        myTree* tree = new myTree();
        QFileSystemModel* dirmodel = new QFileSystemModel();

        dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
        dirmodel->setRootPath(filePath);
        tree->setModel(dirmodel);
        tree->setRootIndex(dirmodel->index(filePath));
        tree->setHeaderHidden(true);
        tree->hideDirModelCols(dirmodel);
        layout->addWidget(tree);
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