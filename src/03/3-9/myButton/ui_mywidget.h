/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created: Sun Dec 6 22:36:55 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QPushButton *pushBtn1;
    QPushButton *pushBtn3;
    QPushButton *pushBtn2;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(400, 300);
        pushBtn1 = new QPushButton(MyWidget);
        pushBtn1->setObjectName(QString::fromUtf8("pushBtn1"));
        pushBtn1->setGeometry(QRect(40, 30, 75, 23));
        pushBtn1->setAutoFillBackground(false);
        pushBtn1->setCheckable(true);
        pushBtn1->setFlat(false);
        pushBtn3 = new QPushButton(MyWidget);
        pushBtn3->setObjectName(QString::fromUtf8("pushBtn3"));
        pushBtn3->setGeometry(QRect(220, 30, 75, 23));
        pushBtn3->setContextMenuPolicy(Qt::DefaultContextMenu);
        pushBtn2 = new QPushButton(MyWidget);
        pushBtn2->setObjectName(QString::fromUtf8("pushBtn2"));
        pushBtn2->setGeometry(QRect(130, 30, 75, 23));
        pushBtn2->setFlat(true);
        groupBox = new QGroupBox(MyWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 100, 151, 181));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 40, 71, 16));
        checkBox->setTristate(true);
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 80, 71, 16));
        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 120, 71, 16));
        groupBox_2 = new QGroupBox(MyWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(199, 99, 171, 181));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(30, 40, 89, 16));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 80, 89, 16));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 120, 89, 16));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", 0, QApplication::UnicodeUTF8));
        pushBtn1->setText(QApplication::translate("MyWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushBtn3->setText(QApplication::translate("MyWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushBtn2->setText(QApplication::translate("MyWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MyWidget", "\345\244\215\351\200\211\346\241\206", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MyWidget", "\350\267\221\346\255\245", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MyWidget", "\350\270\242\347\220\203", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("MyWidget", "\346\270\270\346\263\263", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MyWidget", "\345\215\225\351\200\211\346\241\206", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MyWidget", "\345\276\210\345\245\275", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MyWidget", "\344\270\200\350\210\254", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MyWidget", "\344\270\215\345\245\275", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
