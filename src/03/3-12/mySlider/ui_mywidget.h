/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created: Sun Dec 6 23:14:05 2015
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
#include <QtGui/QDial>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollBar>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QDial *dial;
    QScrollBar *verticalScrollBar;
    QScrollBar *horizontalScrollBar;
    QSpinBox *spinBox;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(400, 300);
        horizontalSlider = new QSlider(MyWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 60, 291, 21));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(10);
        verticalSlider = new QSlider(MyWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(50, 20, 21, 251));
        verticalSlider->setTracking(true);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setTickPosition(QSlider::NoTicks);
        verticalSlider->setTickInterval(0);
        dial = new QDial(MyWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(160, 110, 121, 71));
        dial->setOrientation(Qt::Horizontal);
        dial->setInvertedAppearance(false);
        dial->setInvertedControls(false);
        dial->setWrapping(false);
        dial->setNotchesVisible(true);
        verticalScrollBar = new QScrollBar(MyWidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(20, 20, 16, 251));
        verticalScrollBar->setOrientation(Qt::Vertical);
        horizontalScrollBar = new QScrollBar(MyWidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(90, 20, 271, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        horizontalScrollBar->setInvertedControls(false);
        spinBox = new QSpinBox(MyWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(190, 230, 91, 22));

        retranslateUi(MyWidget);
        QObject::connect(dial, SIGNAL(sliderMoved(int)), verticalScrollBar, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(sliderMoved(int)), verticalSlider, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(sliderMoved(int)), horizontalScrollBar, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(sliderMoved(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(sliderMoved(int)), spinBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
