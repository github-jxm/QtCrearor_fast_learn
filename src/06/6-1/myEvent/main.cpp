#include <QApplication>
#include "widget.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    Widget w;
    w.show();

    return a.exec();
}
