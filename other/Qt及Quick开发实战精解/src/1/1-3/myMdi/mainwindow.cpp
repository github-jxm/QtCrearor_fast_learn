#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdichild.h"
#include <QMdiSubWindow>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeparator = new QAction(this); //创建间隔器动作
    actionSeparator->setSeparator(true); //在其中设置间隔器
    updateMenus();                       //更新菜单
    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            this, SLOT(updateMenus()));           //当有活动窗口时更新菜单
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()  //新建文件菜单
{
    MdiChild *child = createMdiChild();    //创建MdiChild
    child->newFile();                      //新建文件
    child->show();                         //显示子窗口
}

MdiChild * MainWindow::createMdiChild() //创建子窗口部件
{
    MdiChild *child = new MdiChild; //创建MdiChild部件
    ui->mdiArea->addSubWindow(child); //向多文档区域添加子窗口，child为中心部件
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCut,
            SLOT(setEnabled(bool)));

    // 根据QTextEdit类的是否可以复制信号设置剪切复制动作是否可用
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCopy,
            SLOT(setEnabled(bool)));

    // 根据QTextDocument类的是否可以撤销恢复信号设置撤销恢复动作是否可用
    connect(child->document(),SIGNAL(undoAvailable(bool)),
            ui->actionUndo,SLOT(setEnabled(bool)));
    connect(child->document(),SIGNAL(redoAvailable(bool)),
            ui->actionRedo,SLOT(setEnabled(bool)));

    return child;
}

void MainWindow::updateMenus() //更新菜单
{
    bool hasMdiChild = (activeMdiChild() != 0); //是否有活动窗口
    ui->actionSave->setEnabled(hasMdiChild);    //设置各个动作是否可用
    ui->actionSaveAs->setEnabled(hasMdiChild);
    ui->actionPaste->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionCloseAll->setEnabled(hasMdiChild);
    ui->actionTile->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionNext->setEnabled(hasMdiChild);
    ui->actionPrevious->setEnabled(hasMdiChild);
    actionSeparator->setVisible(hasMdiChild);   //设置间隔器是否显示

    bool hasSelection = (activeMdiChild()
                         && activeMdiChild()->textCursor().hasSelection());

    // 有活动窗口且有被选择的文本，剪切复制才可用
    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);

    // 有活动窗口且文档有撤销操作
    ui->actionUndo->setEnabled(activeMdiChild()
                          && activeMdiChild()->document()->isUndoAvailable());

    // 有活动窗口且文档有恢复操作
    ui->actionRedo->setEnabled(activeMdiChild()
                          && activeMdiChild()->document()->isRedoAvailable());
}

MdiChild * MainWindow::activeMdiChild() //活动窗口
{
    // 如果有活动窗口，则将其内的中心部件转换为MdiChild类型
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0; // 没有活动窗口，直接返回0
}
