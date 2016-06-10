#include <QtGui/QApplication>
#include "mywidget.h"
#include "mydialog.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    MyWidget w;
    MyDialog dialog;
    //dialog.show();

    if(dialog.exec() == QDialog::Accepted){
        w.show();
        return a.exec();
    }else{
        return 0;
    }
}
