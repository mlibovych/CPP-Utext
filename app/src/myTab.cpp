#include "myTab.h"

myTab::myTab(QWidget *parent) :
                        QTabWidget(parent)
{
    setAcceptDrops(true);
    setMovable(true);
    setTabsClosable(true);
    setUsesScrollButtons(true);
    QObject::connect(this, SIGNAL(tabCloseRequested(int)), SLOT(closeTab(int)));
}

void myTab::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void myTab::dropEvent(QDropEvent *event)
{
    QString filePath = event->mimeData()->urls()[0].toLocalFile();

    addFile(filePath);
}

void myTab::addFile(QString filePath) {
    if (tab_content.count(filePath)) {
        setCurrentIndex(indexOf(tab_content[filePath]));
        return;
    }

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
            emit currentChanged(currentIndex());
            setTabToolTip(currentIndex(), filePath);
            QObject::connect(area, SIGNAL(textChanged()), SLOT(updateTabName()));

            tab_content[filePath] = area;
        }
    }
}

void myTab::renameFile(QString oldPath, QString newPath) {
    if (tab_content.count(oldPath)) {
        tab_content[newPath] = tab_content[oldPath];
        tab_content.erase(oldPath);
        setTabText(indexOf(tab_content[newPath]), newPath);
        setTabToolTip(indexOf(tab_content[newPath]), newPath);
    }
}

void myTab::removeFile(QString filePath) {
    if (tab_content.count(filePath)) {
        emit tabCloseRequested(indexOf(tab_content[filePath]));
        tab_content.erase(filePath);
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

TextArea *myTab::getTextArea() {
    int index = currentIndex();

    if (index == -1)
        return nullptr;

    QString filename = getFilename(index);
    return tab_content[filename];
}

QString myTab::getFilename(int index) {
    QString filename = tabText(index);

    if (filename[filename.size() - 1] == '*') {
        std::string std_fname = filename.toStdString();
        std::string new_fname(std_fname.begin(), std_fname.end() - 1);
        return QString(new_fname.c_str());
    }

    return filename;
}