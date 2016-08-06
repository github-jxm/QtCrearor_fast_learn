#include <QApplication>
#include "myview.h"
#include <QTextCodec>
#include <QTime>
// 在2-5中添加的代码
#include <QSplashScreen>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    // 设置随机数的初始值
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));


    // 在2-5中添加的代码
    QPixmap pix(":/images/logo.png");
    QSplashScreen splash(pix);
    splash.resize(pix.size());
    splash.show();
    app.processEvents();

    MyView view;
    view.show();

    // 在2-5中添加的代码
    splash.finish(&view);

    return app.exec();
}
