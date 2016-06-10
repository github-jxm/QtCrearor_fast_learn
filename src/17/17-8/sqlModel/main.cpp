#include <QApplication>
#include "mainwindow.h"
#include "connection.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 这行代码要写在创建连接之前
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    if (!createConnection()) return 1;
    MainWindow w;
    w.show();

    return a.exec();
}
