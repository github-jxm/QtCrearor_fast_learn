#include "mdichild.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>
#include <QApplication>
#include <QFileDialog>
#include <QCloseEvent>
#include <QPushButton>
MdiChild::MdiChild(QWidget *parent) :
    QTextEdit(parent)
{
    setAttribute(Qt::WA_DeleteOnClose); // 这样可以在子窗口关闭时销毁这个类的对象
    isUntitled = true;                  // 初始isUntitled为true
}


void MdiChild::newFile() // 新建文件操作
{
    // 设置窗口编号，因为编号一直被保存，所以需要使用静态变量
    static int sequenceNumber = 1;


    isUntitled = true; // 新建的文档没有被保存过

    // 将当前文件命名为未命名文档加编号，编号先使用再加1
    curFile = tr("未命名文档%1.txt").arg(sequenceNumber++);

    // 设置窗口标题，使用[*]可以在文档被更改后在文件名称后显示”*“号
    setWindowTitle(curFile + "[*]" + tr(" - 多文档编辑器"));


    // 当文档被更改时发射contentsChanged()信号，
    // 执行我们的documentWasModified()槽函数
    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

}

void MdiChild::documentWasModified() // 文档被更改时，窗口显示更改状态标志
{
    // 根据文档的isModified()函数的返回值，判断我们编辑器内容是否被更改了
    // 如果被更改了，就要在设置了[*]号的地方显示“*”号，这里我们会在窗口标题中显示
    setWindowModified(document()->isModified());
}

bool MdiChild::loadFile(const QString &fileName) // 加载文件
{
    QFile file(fileName); // 新建QFile对象
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法读取文件 %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return false; // 只读方式打开文件，出错则提示，并返回false
    }

    QTextStream in(&file); // 新建文本流对象
    QApplication::setOverrideCursor(Qt::WaitCursor); // 设置鼠标状态为等待状态
    setPlainText(in.readAll());  // 读取文件的全部文本内容，并添加到编辑器中
    QApplication::restoreOverrideCursor(); // 恢复鼠标状态

    setCurrentFile(fileName); // 设置当前文件

    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

    return true;
}

void MdiChild::setCurrentFile(const QString &fileName) // 设置当前文件
{
    // canonicalFilePath()可以除去路径中的符号链接，“.”和“..”等符号
    curFile = QFileInfo(fileName).canonicalFilePath();

    isUntitled = false; // 文件已经被保存过了
    document()->setModified(false); // 文档没有被更改过
    setWindowModified(false); // 窗口不显示被更改标志

    // 设置窗口标题，userFriendlyCurrentFile()返回文件名
    setWindowTitle(userFriendlyCurrentFile() + "[*]");

}

QString MdiChild::userFriendlyCurrentFile() // 提取文件名
{
    return QFileInfo(curFile).fileName();  // 从文件路径中提取文件名
}

bool MdiChild::save() // 保存操作
{
    if (isUntitled) { // 如果文件未被保存过，则执行另存为操作
        return saveAs();
    } else {
        return saveFile(curFile); // 否则直接保存文件
    }
}

bool MdiChild::saveAs() // 另存为操作
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"),curFile);
    if (fileName.isEmpty()) // 获取文件路径，如果为空，则返回false
        return false;

    return saveFile(fileName); // 否则保存文件
}

bool MdiChild::saveFile(const QString &fileName) // 保存文件
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法写入文件 %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText(); // 以纯文本文件写入
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}


void MdiChild::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) { // 如果maybeSave()函数返回true，则关闭窗口
        event->accept();
    } else {   // 否则忽略该事件
        event->ignore();
    }
}


bool MdiChild::maybeSave()  // 是否需要保存
{
    if (document()->isModified()) { // 如果文档被更改过
        QMessageBox box;
        box.setWindowTitle(tr("多文档编辑器"));
        box.setText(tr("是否保存对“%1”的更改？")
                    .arg(userFriendlyCurrentFile()));
        box.setIcon(QMessageBox::Warning);

        // 添加按钮，QMessageBox::YesRole可以表明这个按钮的行为
        QPushButton *yesBtn = box.addButton(tr("是(&Y)"),QMessageBox::YesRole);

        box.addButton(tr("否(&N)"),QMessageBox::NoRole);
        QPushButton *cancelBtn = box.addButton(tr("取消"),
                                               QMessageBox::RejectRole);
        box.exec(); // 弹出对话框，让用户选择是否保存修改，或者取消关闭操作
        if (box.clickedButton() == yesBtn)// 如果用户选择是，则返回保存操作的结果
            return save();
        else if (box.clickedButton() == cancelBtn) // 如果选择取消，则返回false
            return false;
    }
    return true; // 如果文档没有更改过，则直接返回true
}



