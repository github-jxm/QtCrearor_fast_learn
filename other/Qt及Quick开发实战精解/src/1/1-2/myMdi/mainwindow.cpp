#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdichild.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 新建文件菜单
void MainWindow::on_actionNew_triggered()
{
    // 创建MdiChild
    MdiChild *child = new MdiChild;
    // 多文档区域添加子窗口
    ui->mdiArea->addSubWindow(child);
    // 新建文件
    child->newFile();
    // 显示子窗口
    child->show();
}
