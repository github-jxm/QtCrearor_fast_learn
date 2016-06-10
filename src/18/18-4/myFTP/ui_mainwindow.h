/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Dec 6 23:51:08 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *ftpServerLineEdit;
    QLabel *label_3;
    QLineEdit *userNameLineEdit;
    QLabel *label_4;
    QLineEdit *passWordLineEdit;
    QPushButton *connectButton;
    QTreeWidget *fileList;
    QProgressBar *progressBar;
    QPushButton *cdToParentButton;
    QPushButton *downloadButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(510, 363);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 280, 371, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 61, 16));
        ftpServerLineEdit = new QLineEdit(centralWidget);
        ftpServerLineEdit->setObjectName(QString::fromUtf8("ftpServerLineEdit"));
        ftpServerLineEdit->setGeometry(QRect(80, 20, 351, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 54, 12));
        userNameLineEdit = new QLineEdit(centralWidget);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));
        userNameLineEdit->setGeometry(QRect(80, 50, 141, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 50, 54, 12));
        passWordLineEdit = new QLineEdit(centralWidget);
        passWordLineEdit->setObjectName(QString::fromUtf8("passWordLineEdit"));
        passWordLineEdit->setGeometry(QRect(310, 50, 121, 20));
        passWordLineEdit->setEchoMode(QLineEdit::Password);
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(450, 50, 51, 23));
        fileList = new QTreeWidget(centralWidget);
        fileList->setObjectName(QString::fromUtf8("fileList"));
        fileList->setGeometry(QRect(10, 80, 491, 161));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 250, 391, 23));
        progressBar->setValue(24);
        cdToParentButton = new QPushButton(centralWidget);
        cdToParentButton->setObjectName(QString::fromUtf8("cdToParentButton"));
        cdToParentButton->setGeometry(QRect(414, 250, 81, 23));
        downloadButton = new QPushButton(centralWidget);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));
        downloadButton->setGeometry(QRect(414, 280, 81, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 510, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "FTP\345\256\242\346\210\267\347\253\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "FTP\346\234\215\345\212\241\345\231\250\357\274\232", 0, QApplication::UnicodeUTF8));
        ftpServerLineEdit->setText(QApplication::translate("MainWindow", "ftp.qt-project.org", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        userNameLineEdit->setToolTip(QApplication::translate("MainWindow", "\351\273\230\350\256\244\347\224\250\346\210\267\345\220\215\350\257\267\344\275\277\347\224\250\357\274\232anonymous \357\274\214\346\255\244\346\227\266\345\257\206\347\240\201\344\273\273\346\204\217\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        userNameLineEdit->setText(QApplication::translate("MainWindow", "anonymous", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        passWordLineEdit->setText(QApplication::translate("MainWindow", "123456", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = fileList->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("MainWindow", "\344\277\256\346\224\271\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "\346\211\200\345\261\236\347\273\204", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "\346\213\245\346\234\211\350\200\205", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        cdToParentButton->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236\344\270\212\347\272\247\347\233\256\345\275\225", 0, QApplication::UnicodeUTF8));
        downloadButton->setText(QApplication::translate("MainWindow", "\344\270\213\350\275\275", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
