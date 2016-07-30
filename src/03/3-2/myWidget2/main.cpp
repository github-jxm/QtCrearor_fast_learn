#include <QApplication>
#include <QWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    widget.resize(400, 300);     //设置窗口大小
    widget.move(200, 100);       //设置窗口位置
    widget.show();

    int x = widget.x();
    qDebug("x: %d", x);          //输出x的值
    int y = widget.y();
    qDebug("y: %d", y);         // 输出y的值

    QRect geometry = widget.geometry();
    QRect frame = widget.frameGeometry();
    qDebug() << "geometry: " << geometry << ":" << geometry.x() << geometry.y() << endl
                     << "frame: " << frame << ":" << frame.x() << frame.y();

    qDebug() << "pos:" << widget.pos() << endl        /* 坐标点 QPoint */
                     << "rect:" << widget.rect() << endl
                     << "size:" << widget.size() << endl       /* 大小 */
                     << "width:" << widget.width() << endl
                     << "height:" << widget.height()<<endl;

    return a.exec();
}
