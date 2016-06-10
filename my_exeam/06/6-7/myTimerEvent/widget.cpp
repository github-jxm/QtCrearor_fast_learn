#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>
#include <QTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(3000);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    //QTimer::singleShot(30000,this,SLOT(close()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1){
        qDebug() << "timer1";
    }
    else if(event->timerId() == id2){
        qDebug() << "timer2";
    }else {
        qDebug() << "timer3";
    }
}

void Widget::timerUpdate()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if((time.second() % 2) == 0) text[2] = ' ';
    ui->lcdNumber->display(text);

    int rand = qrand() % 300;
    ui->lcdNumber->move(rand,rand);
}
