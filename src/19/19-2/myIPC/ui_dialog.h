/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Sun Dec 6 23:41:54 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *loadFromFileButton;
    QPushButton *loadFromSharedMemoryButton;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        loadFromFileButton = new QPushButton(Dialog);
        loadFromFileButton->setObjectName(QString::fromUtf8("loadFromFileButton"));
        loadFromFileButton->setGeometry(QRect(30, 20, 151, 23));
        loadFromSharedMemoryButton = new QPushButton(Dialog);
        loadFromSharedMemoryButton->setObjectName(QString::fromUtf8("loadFromSharedMemoryButton"));
        loadFromSharedMemoryButton->setGeometry(QRect(220, 20, 141, 23));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 110, 311, 141));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        loadFromFileButton->setText(QApplication::translate("Dialog", "\344\273\216\346\226\207\344\273\266\344\270\255\345\212\240\350\275\275\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        loadFromSharedMemoryButton->setText(QApplication::translate("Dialog", "\344\273\216\345\205\261\344\272\253\345\206\205\345\255\230\346\230\276\347\244\272\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "\345\205\261\344\272\253\345\206\205\345\255\230\345\256\236\344\276\213\357\274\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
