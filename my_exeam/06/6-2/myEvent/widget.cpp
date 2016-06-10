#include "widget.h"
#include "ui_widget.h"
#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    lineEdit = new MyLineEdit(this);
    lineEdit->move(100,100);

    lineEdit->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::keyPressEvent(QKeyEvent *event)
{   event = event;
    qDebug()<< tr("Widget 键盘按下事件");
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == lineEdit){
        if(event->type() == QEvent::KeyPress){
            qDebug() << tr("Widget 的事件过滤器");
        }
    }
    return QWidget::eventFilter(obj,event);
}
