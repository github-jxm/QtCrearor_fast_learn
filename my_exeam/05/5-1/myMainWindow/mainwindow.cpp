#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //-----------------------------------------------------------
    QMenu * editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    QAction * action_open = editMenu->addAction(
                QIcon(":/myImage/images/open.png"),tr("打开文件(&O)"));
    action_open->setShortcut(QKeySequence("Ctrl + O"));
    ui->mainToolBar->addAction(action_open);
    //---------------------------------------------------
    QActionGroup *group = new QActionGroup(this);
    QAction * action_L = group->addAction(tr("左对齐(&L)"));
    action_L->setCheckable(true);
    QAction * action_R = group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction * action_C = group->addAction(tr("右对齐(&C)"));
    action_C->setCheckable(true);

    action_L->setChecked(true);
    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);
    //-----------------------------------------------
    QToolButton * toolBtn = new QToolButton(this);
    toolBtn->setText(tr("颜色"));
    QMenu *colorMenu=new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolBtn);

    QSpinBox *spinBox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinBox);
    //------------------------------------------------------
    ui->statusBar->showMessage(tr("欢迎使用多文档编辑器"),2000);
    QLabel * permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.yafeilinux.com");
    ui->statusBar->addPermanentWidget(permanent);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_triggered()
{
    QTextEdit *edit = new QTextEdit(this);
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();
}

void MainWindow::on_action_Dock_triggered()
{
    ui->dockWidget->show();
}
