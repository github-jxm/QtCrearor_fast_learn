#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>
//MyLineEdit::MyLineEdit(QObject *parent) :
MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("MyLineEdit 键盘按下事件--");
    // 执行QLineEdit类的默认事件处理
    QLineEdit::keyPressEvent(event);
    // 忽略该事件
    event->ignore();
}
