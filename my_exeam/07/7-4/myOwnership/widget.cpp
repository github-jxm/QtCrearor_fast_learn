#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyButton * button = new MyButton(this);
    button->setText(tr("button"));
    //qDebug() << children();
}

Widget::~Widget()
{
    delete ui;
    qDebug() << "delete widget";
}
