#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*  在代码中可以使用中文字符串 */
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    // 新建QWidget类对象，默认parent参数是0，所以它是个窗口
    // QWidget *widget = new QWidget();
    //QWidget *widget = new QWidget(0,Qt::Dialog);
    QWidget *widget = new QWidget(0,Qt::Dialog|Qt::FramelessWindowHint);
    widget->setWindowTitle(QObject::tr("我是widget"));


    // 新建QLabel对象，默认parent参数是0，所以它是个窗口
    //QLabel *label = new QLabel();
    //QLabel *label = new QLabel(0,Qt::SplashScreen);
    QLabel *label = new QLabel(0,Qt::SplashScreen|Qt::WindowStaysOnTopHint);
    label->setWindowTitle(QObject::tr("我是label"));
    label->setText(QObject::tr("label:我是个窗口"));
    label->resize(180, 20);// 改变部件大小，以便能显示出完整的内容

    // label2指定了父窗口为widget，所以不是窗口
    QLabel *label2 = new QLabel(widget);
    label2->setText(QObject::tr("label2:我不是独立窗口，只是widget的子部件"));
    label2->resize(350, 20);

    // 在屏幕上显示出来
    label->show();
    widget->show();

    int ret = a.exec();
    delete label;
    delete widget;
    return ret;
}

