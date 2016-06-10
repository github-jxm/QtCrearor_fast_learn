#include "myaction.h"
#include <QLineEdit>
#include <QSplitter>
#include <QLabel>

MyAction::MyAction(QObject *parent) :
    QWidgetAction(parent)
{
    lineEdit = new QLineEdit;
    connect(lineEdit,SIGNAL(returnPressed()),this,SLOT(sendText()));

}
QWidget * MyAction::createWidget(QWidget *parent)
{
    if(parent->inherits("QMenu") || parent->inherits("QToolBar")){
        QSplitter *splitter = new QSplitter(parent);
        QLabel *label = new QLabel;
        label->setText("插入文本");
        splitter->addWidget(label);
        splitter->addWidget(lineEdit);
        return splitter;
    }
    return 0;
}

void MyAction::sendText()
{
    emit getText(lineEdit->text());
    lineEdit->clear();
}

