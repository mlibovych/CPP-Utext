#include "myTab.h"

myTab::myTab(QWidget *parent) :
                        QTabWidget(parent)
{
    setAcceptDrops(true);
    setMovable(true);
    setTabsClosable(true);
    QObject::connect(this, SIGNAL(tabCloseRequested(int)), SLOT(closeTab(int)));
}


void myTab::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void myTab::dropEvent(QDropEvent *event)
{
    QString filePath = event->mimeData()->urls()[0].toLocalFile();
    QFileInfo info(filePath);

    if (info.isFile()) {
        TextArea* area = new TextArea();
        QFile *file = new QFile(filePath);

        if (file->open(QIODevice::ReadWrite)) {
            QTextStream in(file);
            QTextDocument *txtDoc = new QTextDocument(area);

            txtDoc->setDocumentLayout(new QPlainTextDocumentLayout(txtDoc));
            txtDoc->setPlainText(in.readAll());
            area->setDocument(txtDoc);
            setCurrentIndex(addTab(area, filePath));
        }
    }
}

void myTab::closeTab(int index)
{
    removeTab(index);
}