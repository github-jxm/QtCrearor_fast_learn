#include <QApplication>
#include "stringlistmodel.h"
#include <QListView>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStringList list;
    list << "a" << "b" << "c";
    StringListModel model(list);

    QListView listView;
    listView.setModel(&model);
    listView.show();

    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    // 插入删除行
    model.insertRows(3, 2);
    model.removeRows(0, 1);

    // 启用拖放功能
    listView.setSelectionMode(QAbstractItemView::ExtendedSelection);  // 设置拖放为移动，　默认为复制
    listView.setDragEnabled(true);  // 启用拖动
    listView.setAcceptDrops(true);  // 设置接受拖放
    listView.setDropIndicatorShown(true); // 设置显示将要被放置的位置

    return app.exec();
}
