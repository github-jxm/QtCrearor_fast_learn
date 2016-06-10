#include <QApplication>
#include "mywidget.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    MyWidget w;
    w.show();

    return a.exec();
}
