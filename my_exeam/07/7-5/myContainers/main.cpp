#include <QtCore/QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString>list;
    list << "aa" << "bb" << "cc";
    if(list[1] == "bb") list[1] = "ab";
    list.replace(2,"bc");
    qDebug()<<"this list is :";
    for(int i = 0; i < list.size(); ++i){
        qDebug() << list.at(i);
    }
    list.append("dd");
    list.prepend("mm");
    QString str = list.takeAt(2);
    qDebug() << "at(2) item is:" << str;
    qDebug() << "the list is:";
    for(int i = 0; i < list.size(); ++i){
        qDebug() << list.at(i);
    }
    list.insert(2,"mm");
    list.swap(1,3);
    qDebug() << "the list is:";
    for(int i = 0; i < list.size(); ++i){
        qDebug() << list.at(i);
    }
    qDebug() << "contains mm?" << list.contains("mm");
    qDebug() << "the mm cont:" << list.count("mm");
    qDebug() << "the first mm index:" << list.indexOf("mm");
    qDebug() << "the second mm index:" << list.indexOf("mm",1);

    return a.exec();
}
