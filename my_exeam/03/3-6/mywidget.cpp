#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>  //包含头文件

#include "mydialog.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_showChildButton_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}


void MyWidget::on_pushButton_clicked()
{
    close();
    MyDialog dlg;
    dlg.setWindowTitle(tr("第二个 Dialog"));
    if(dlg.exec() == QDialog::Accepted){
        show();
    }
}
