#include <QCoreApplication>
#include <QList>
#include <QMap>
#include <QMultiMap>
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc,argv);
	QList<QString> list;
	list.insert(0,"A");
	list.insert(1,"B");
	list.insert(2,"C");
	qDebug() << "this list is : ";
	foreach(QString str, list){
		qDebug () << str;
	}

	QMap<QString,int> map;
	map.insert("first",1);
	map.insert("second",2);
	map.insert("thirt",3);
	qDebug () << endl << "the map is :" ;
	foreach (QString str, map.keys()){
		qDebug () << str << ":" << map.value(str);	
	}

	QMultiMap<QString, int> map2;
	map2.insert ("first",1);
	map2.insert ("first",2);
	map2.insert ("first",3);
	map2.insert ("second",2);
	qDebug () << endl << "the map2 is :" ;
	QList<QString> keys = map2.uniqueKeys();
#if 1 
	foreach (QString str,keys){
		foreach(int i, map2.values(str)){
			qDebug () << str << ":" << i;
		}
	}
#endif
	return a.exec();
}
