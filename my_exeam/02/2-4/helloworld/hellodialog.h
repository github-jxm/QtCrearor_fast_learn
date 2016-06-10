#ifndef HELLODIALOG_H
#define HELLODIALOG_H

#include <QDialog>

namespace Ui{
    class helloDialog;
}

class helloDialog : public QDialog
{
    Q_OBJECT
public:
    explicit helloDialog(QWidget *parent = 0);
    
signals:
    
public slots:
    Ui::helloDialog *ui;
    
};

#endif // HELLODIALOG_H
