#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QPalette>
#include <QInputDialog>

#include <QProgressDialog>
#include <QErrorMessage>

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

void MyWidget::on_pushButton_clicked()
{
#if 0
    //QColor color = QColorDialog::getColor(Qt::green,this,tr("颜色对话框"));
    QColor color = QColorDialog::getColor(Qt::green,this,tr("颜色对话框"),QColorDialog::ShowAlphaChannel);
    qDebug()<< "color"<< color;
#else
    QColorDialog dialog(Qt::red,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();
  //  QPalette pe;
  //  pe.setColor(QPalette::Button,color);
   // ui->pushButton->setPalette(pe);
    qDebug() << "color: " << color << endl;
#endif
}

void MyWidget::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("文本对话框"),
                                                    "",tr("图片文件(*png *jpg)"));
    qDebug() << "fileName:" << filename << endl;
}

void MyWidget::on_pushButton_3_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok){
       ui ->pushButton_3->setFont(font);
    }else{
        qDebug() << tr("没有选择字体");
    }
}

void MyWidget::on_pushButton_4_clicked()
{
    bool ok;
    QString string = QInputDialog::getText(this,tr("输入字符串对话框"),tr("请输入姓名："),QLineEdit::Normal,tr("admin"),&ok);
    if(ok){
        qDebug() << "string" << string ;
    }
    int value1 = QInputDialog::getInt(this,tr("输入整数对话框"),
                                      tr("请输入-1000到1000之间的数"),100,-1000,1000,10,&ok);
    if(ok){
        qDebug() << "value1:" << value1;
    }

    double value2 = QInputDialog::getDouble(this,tr("输入浮点数对话框"),
                                             tr("请输入-1000到1000之间的数"),0.00,-1000,1000,2,&ok);
    if(ok){
        qDebug() << "value2:" << value2;
    }

    QStringList items;
    items << tr("条目1") << tr("条目2");
    // 获取条目
    QString item = QInputDialog::getItem(this,tr("输入条目对话框"),
                                         tr("请输入下一个条目"),items,0,true,&ok);
    if(ok){
        qDebug() << "item:" << item;
    }
}

void MyWidget::on_pushButton_6_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"),tr("取消"),0,50000,this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int i = 0; i < 50000; i ++){
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled()){
            break;
        }
    }
    dialog.setValue(50000);
    qDebug ()<< tr("复制结束!");
}

void MyWidget::on_pushButton_7_clicked()
{
    QErrorMessage *dialog = new QErrorMessage(this);
    dialog->setWindowTitle(tr("错误信息对话框"));
    dialog->showMessage(tr("这是出错信息！"));
}

//====================
QWizardPage * MyWidget::createPage1()
{
    QWizardPage * page = new QWizardPage;
    page->setTitle(tr("介绍"));
    return page;
}

QWizardPage * MyWidget::createPage2()
{
    QWizardPage * page = new QWizardPage;
    page->setTitle(tr("用户选择信息"));
    return page;
}

QWizardPage * MyWidget::createPage3()
{
    QWizardPage * page = new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}
void MyWidget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}
