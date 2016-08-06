#include <QtGui/QApplication>
#include "widget.h"
#include <QTextCodec>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 必须在创建数据库之前使用，不然无法在数据库中使用中文
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    if(!createConnection() || !createXml()) return 0;

    Widget w;
    w.show();

    return a.exec();
}

