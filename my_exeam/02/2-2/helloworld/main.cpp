
#include <QApplication>
#include <QDialog>
#include <QTextCodec>
#include <QLabel>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QDialog w;
    w.resize(400,300);
    QLabel label(&w);
    label.move(120,120);
    label.setText(QObject::tr("Hello World! 你好QT!"));
    w.show();
    return app.exec();
}
