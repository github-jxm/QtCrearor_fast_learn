#include <QApplication>
#include "myview.h"
#include <QTextCodec>
#include <QTime>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    // 设置随机数的初始值
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    MyView view;
    view.show();

    return app.exec();
}
