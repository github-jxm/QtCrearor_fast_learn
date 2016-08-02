#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /* 1. 创建　模型 model  */

    QFileSystemModel model;// 创建文件系统模型
    model.setRootPath(QDir::currentPath());// 指定要监视的目录


    /* 2. 创建　视图 view  */

    QTreeView tree;            // 创建树型视图
    tree.setModel(&model);// 为视图指定模型
    tree.setRootIndex(model.index(QDir::currentPath() ));// 指定根索引

    QListView list;               // 创建列表视图
    list.setModel(&model);// 为视图指定模型
    list.setRootIndex(model.index(QDir::currentPath()));// 指定根索引

    /*   3. 窗口　显示 */

    tree.show();
    list.show();

    return app.exec();
}

