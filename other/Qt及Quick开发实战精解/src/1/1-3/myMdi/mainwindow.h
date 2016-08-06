#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class MdiChild;
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered(); //新建文件菜单
    void updateMenus();           //更新菜单
    MdiChild *createMdiChild(); //创建子窗口

private:
    Ui::MainWindow *ui;
    QAction *actionSeparator;    //分隔符
    MdiChild *activeMdiChild(); //活动窗口
};

#endif // MAINWINDOW_H
