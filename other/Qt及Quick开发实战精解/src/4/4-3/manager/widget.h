#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QDomDocument>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    enum DateTimeType{Time, Date, DateTime};
    QString getDateTime(DateTimeType type);

private slots:
    void on_sellTypeComboBox_currentIndexChanged(QString );

    void on_sellBrandComboBox_currentIndexChanged(QString );

    void on_sellNumSpinBox_valueChanged(int );

    void on_sellCancelBtn_clicked();

    void on_sellOkBtn_clicked();

private:
    Ui::Widget *ui;
    QDomDocument doc;

private:
    bool docRead();
    bool docWrite();
    void writeXml();
    void createNodes(QDomElement &date);
    void showDailyList();
};

#endif // WIDGET_H
