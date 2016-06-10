#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sound = new QSound("../mySound/sound.wav", this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{ // 播放按钮
    sound->play();
}

void MainWindow::on_pushButton_2_clicked()
{ // 停止按钮
    sound->stop();
}

void MainWindow::on_spinBox_valueChanged(int value)
{
    sound->setLoops(value);
}
