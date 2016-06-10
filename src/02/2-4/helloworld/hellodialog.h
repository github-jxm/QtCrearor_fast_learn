#ifndef HELLODIALOG_H
#define HELLODIALOG_H

#include <QDialog>

#if 1
#include "ui_hellodialog.h"
#else
namespace Ui {                  //我们
    class HelloDialog;          //新添
}                               //内容
#endif

class HelloDialog : public QDialog
{
    Q_OBJECT
public:
    explicit HelloDialog(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    Ui::HelloDialog *ui;       //新添内容
};

#endif // HELLODIALOG_H
