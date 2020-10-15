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

        connect(removeDevice, SIGNAL(triggered()), SLOT(slotRemove()));
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
    connect(this, SIGNAL(fileRenamed(QString, QString)), getMyTab(), SLOT(renameFile(QString, QString)));
    connect(this, SIGNAL(fileRemoved(QString)), getMyTab(), SLOT(removeFile(QString)));
}

void myTree::mousePressEvent(QMouseEvent *event) {
    QString filePath;

    QTreeView::mousePressEvent(event);
    filePath = dirmodel->filePath(indexAt(event->pos()));
    if (event->button() == Qt::LeftButton) {
        QFileInfo info(filePath);

        if (info.exists() && info.isFile()) {
            getMyTab()->addFile(filePath);
        }
    }
    else if (event->button() == Qt::RightButton) {
        QFileInfo info(filePath);

        if (info.exists()) {
            QMenu* menu = new QMenu(this);
            QAction* renameFile = new QAction(("Rename"), this);
            QAction* deleteFile = new QAction(("Delete"), this);

            connect(renameFile, SIGNAL(triggered()), SLOT(slotRename()));
            connect(deleteFile, SIGNAL(triggered()), this, SLOT(slotRemove()));
            menu->addAction(renameFile);
            menu->addAction(deleteFile);
            if (info.isDir()) {
                QAction* newFile = new QAction(("New file"), this);
                QAction* newDir = new QAction(("New folder"), this);

                connect(newFile, SIGNAL(triggered()), this, SLOT(slotCreate()));
                connect(newDir, SIGNAL(triggered()), this, SLOT(slotCreateDir()));
                menu->addAction(newFile);
                menu->addAction(newDir);
            }
            menu->popup(this->mapToGlobal(event->pos()));
        }
    }
}

myTab* myTree::getMyTab(void) {
    return parent()->parent()->parent()->parent()->parent()->parent()->parent()->findChild<myTab *>();
}

void myTree::slotRename() {
    QString filePath = dirmodel->filePath(currentIndex());
    QString newName = QInputDialog::getText(this, "Rename", "Enter new file name", QLineEdit::Normal);
    QFileInfo info(filePath);

    if (QFile::rename(filePath, info.absolutePath() + "/" + newName)) {
        emit fileRenamed(filePath, info.absolutePath() + "/" + newName);
    }
}

void myTree::slotRemove() {
    QString filePath = dirmodel->filePath(currentIndex());

    if (QFile::remove(filePath)) {
        emit fileRemoved(filePath);
    }
}

void myTree::slotCreate() {
    QString dirPath = dirmodel->filePath(currentIndex());
    QString newName = QInputDialog::getText(this, "Create", "Enter new file name", QLineEdit::Normal);
    QFile file(dirPath + "/" + newName);

    file.open(QIODevice::ReadWrite);
}

void myTree::slotCreateDir() {
    QString dirPath = dirmodel->filePath(currentIndex());
    QString newName = QInputDialog::getText(this, "Create", "Enter new folder name", QLineEdit::Normal);
    QDir newDir;

    newDir.mkpath(dirPath + "/" + newName);
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
    if (event->mimeData()->urls().empty()) {
        return;
    }
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
