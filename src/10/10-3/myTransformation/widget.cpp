#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);  // 保证不用按下鼠标按键，也能触发鼠标移动事件
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
//        QPainter painter(this);
//        painter.setWindow(-50,-50,100,100);
//        painter.setBrush(Qt::green);
//        painter.drawRect(0,0,20,20);

    QPainter painter(this);
    int side = qMin(width(), height());
//       int side = qMax(width(), height());
    int x = (width() / 2);
    int y = (height() / 2);
    //设置视口
    painter.setViewport(x, y, side, side);
    painter.setWindow(0, 0, 100, 100);
    painter.setBrush(Qt::green);
    painter.drawRect(0, 0, 20, 20);

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString("%1,%2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(), pos, this);
}

