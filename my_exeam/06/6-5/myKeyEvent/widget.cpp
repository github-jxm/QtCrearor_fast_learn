#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),keyUp(false),
    keyLeft(false),move(false)
{
    ui->setupUi(this);
    setFocus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        if(event->isAutoRepeat())return;
        keyUp = true;
    }
    else if(event->key() == Qt::Key_Left){
        if(event->isAutoRepeat())return;
        keyLeft = true;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        if(event->isAutoRepeat())return;
        keyUp = false;
        if(move){
            move = false;
            return;
        }
        if(keyLeft){
            ui->pushButton->move(30,80);
            move = true;
        }else{
            ui->pushButton->move(120,80);
        }
    }
    else if (event->key() == Qt::Key_Left){
        if(event->isAutoRepeat())return;
        keyLeft = false;
        if(move){
            move = false;
            return;
        }
        if(keyUp){
            ui->pushButton->move(30,80);
            move = true;
        }else{
            ui->pushButton->move(30,120);
        }
    }
    else if(event->key() == Qt::Key_Down){
        ui->pushButton->move(120,120);
    }
}
