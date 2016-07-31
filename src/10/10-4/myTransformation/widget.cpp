#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);  //鼠标移动事件生效

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
    angle = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    angle += 10;
    if(angle == 360)
        angle = 0;
    int side = qMin(width(), height());
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QTransform transform;
    transform.translate(width()/2, height()/2);
    transform.scale(side/300.0, side/300.0);
    transform.rotate(angle);  // 坐标系统 旋转
    painter.setWorldTransform(transform);
    painter.drawEllipse(-120, -120, 240, 240);
    painter.drawLine(0, 0, 100, 0);
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString("%1,%2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(), pos, this);
}

