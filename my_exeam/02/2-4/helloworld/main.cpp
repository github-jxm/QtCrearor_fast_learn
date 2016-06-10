#include <QApplication>
#include "hellodialog.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    helloDialog w;
    w.show();
    return app.exec();
}
