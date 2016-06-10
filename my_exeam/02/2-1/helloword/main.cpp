#include <QtGui/QApplication>
#include <QTextCodec>
#include <QLabel>
#include "hellodialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloDialog w;
    w.show();
    
    return a.exec();
}
