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
        
            QObject::connect(area, SIGNAL(textChanged()), SLOT(updateTabName()));

            tab_content[filePath] = area;
        }
    }
}

void myTab::closeTab(int index)
{
    tab_content.erase(tabText(index));
    removeTab(index);
}

void myTab::updateTabName() {
    int index = currentIndex();

    if (index == -1)
        return;

    QString tab_text = tabText(index);

    if (tab_text[tab_text.size() - 1] == '*')
        return;

    setTabText(index, tab_text + "*");

}

TextArea *myTab::getTextArea(const QString& filename) {
    return tab_content[filename];
}