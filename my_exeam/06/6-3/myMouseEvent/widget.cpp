#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
//#include <QPixmap>
//#include <QCursor>
//#include <QApplication>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);
    setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos()- pos();
    }
    else if(event->button() == Qt::RightButton){
        QCursor cursor(QPixmap("./yafeilinux.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{

    if(event->buttons() & Qt::LeftButton){
        QPoint temp;
        temp = event->globalPos() - offset;
        move(temp);
    }
}
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QApplication::restoreOverrideCursor();
}
void Widget::mouseDoubleClickEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton){
        if(windowState() != Qt::WindowFullScreen){
            setWindowState(Qt::WindowFullScreen);
        }else{
            setWindowState(Qt::WindowNoState);
        }
    }
}

void Widget::wheelEvent(QWheelEvent * event)
{
    if(event->delta() > 0){
        ui->textEdit->zoomIn();
    }else{
        ui->textEdit->zoomOut();
    }
}
