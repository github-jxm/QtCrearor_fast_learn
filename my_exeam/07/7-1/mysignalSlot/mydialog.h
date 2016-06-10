#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class myDialog;
}

class myDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit myDialog(QWidget *parent = 0);
    ~myDialog();
signals:
    void dlgReturn(int);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::myDialog *ui;
};

#endif // MYDIALOG_H
