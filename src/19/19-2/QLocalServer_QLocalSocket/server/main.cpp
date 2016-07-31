
///////////////////////////////////////////////////////////////////////
/// main.cpp
///////////////////////////////////////////////////////////////////////
//  http://tgstdj.blog.163.com/blog/static/74820040201243072238780/

#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include "server.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QLabel       text(" QLocalServer   tests");
    text.resize(600,400);

    Server       s;
    if (!s.init("localserver-test")){
        QMessageBox::information(&text, "info", "There is already exist one!"); // 初使化失败, 说明已经有一个在运行了
        return 1;
    }
    QObject::connect(&s, SIGNAL(newMessage(const QString &)),&text, SLOT(setText(const QString &)));
    text.show();
    return app.exec();
}



