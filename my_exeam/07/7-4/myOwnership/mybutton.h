#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QDebug>
class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);
    ~MyButton()
    {
        qDebug() << "delete button";
    }
    
signals:
    
public slots:
    
};

#endif // MYBUTTON_H
