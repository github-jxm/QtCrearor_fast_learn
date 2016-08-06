#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdichild.h"
#include <QMdiSubWindow>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeparator = new QAction(this); // 创建间隔器动作
    actionSeparator->setSeparator(true); // 在其中设置间隔器
    updateMenus();   // 更新菜单
    connect(ui->mdiArea,SIGNAL(subWindowActivated(QMdiSubWindow*)),this,
            SLOT(updateMenus()));  // 当有活动窗口时更新菜单
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()  // 新建文件菜单
{
    MdiChild *child = createMdiChild();   // 创建MdiChild
    child->newFile(); // 新建文件
    child->show();    // 显示子窗口
}

MdiChild * MainWindow::createMdiChild() // 创建子窗口部件
{
    MdiChild *child = new MdiChild;   // 创建MdiChild部件
    ui->mdiArea->addSubWindow(child); // 向多文档区域添加子窗口，child为中心部件

    // 根据QTextEdit类的是否可以复制信号设置剪切复制动作是否可用
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCut,
            SLOT(setEnabled(bool)));
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCopy,
            SLOT(setEnabled(bool)));

    // 根据QTextDocument类的是否可以撤销恢复信号设置撤销恢复动作是否可用
    connect(child->document(),SIGNAL(undoAvailable(bool)),
            ui->actionUndo,SLOT(setEnabled(bool)));
    connect(child->document(),SIGNAL(redoAvailable(bool)),
            ui->actionRedo,SLOT(setEnabled(bool)));

    return child;
}

void MainWindow::updateMenus() // 更新菜单
{
    bool hasMdiChild = (activeMdiChild() != 0); // 是否有活动窗口
    ui->actionSave->setEnabled(hasMdiChild);    // 设置各个动作是否可用
    ui->actionSaveAs->setEnabled(hasMdiChild);
    ui->actionPaste->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionCloseAll->setEnabled(hasMdiChild);
    ui->actionTile->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionNext->setEnabled(hasMdiChild);
    ui->actionPrevious->setEnabled(hasMdiChild);
    actionSeparator->setVisible(hasMdiChild);  // 设置间隔器是否显示

    bool hasSelection = (activeMdiChild()
                         && activeMdiChild()->textCursor().hasSelection());

    // 有活动窗口且有被选择的文本，剪切复制才可用
    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);

    ui->actionUndo->setEnabled(activeMdiChild() // 有活动窗口且文档有撤销操作
                          && activeMdiChild()->document()->isUndoAvailable());
    ui->actionRedo->setEnabled(activeMdiChild() // 有活动窗口且文档有恢复操作
                          && activeMdiChild()->document()->isRedoAvailable());
}

MdiChild * MainWindow::activeMdiChild() // 活动窗口
{
    // 如果有活动窗口，则将其内的中心部件转换为MdiChild类型
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0; // 没有活动窗口，直接返回0
}

void MainWindow::on_actionOpen_triggered() // 打开文件菜单
{
    QString fileName = QFileDialog::getOpenFileName(this); // 获取文件路径
    if (!fileName.isEmpty()) { // 如果路径不为空，则查看该文件是否已经打开
        QMdiSubWindow *existing = findMdiChild(fileName);
        if (existing) { // 如果已经存在，则将对应的子窗口设置为活动窗口
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }

        MdiChild *child = createMdiChild(); // 如果没有打开，则新建子窗口
        if (child->loadFile(fileName)) {
            ui->statusBar->showMessage(tr("打开文件成功"), 2000);
            child->show();
        } else {
            child->close();
        }
    }
}

QMdiSubWindow * MainWindow::findMdiChild(const QString &fileName) // 查找子窗口
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

    // 利用foreach语句遍历子窗口列表，如果其文件路径和要查找的路径相同，则返回该窗口
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
        MdiChild *mdiChild = qobject_cast<MdiChild *>(window->widget());
        if (mdiChild->currentFile() == canonicalFilePath)
            return window;
    }
    return 0;
}

void MainWindow::setActiveSubWindow(QWidget *window) // 设置活动子窗口
{
    if (!window) // 如果传递了窗口部件，则将其设置为活动窗口
        return;
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}


