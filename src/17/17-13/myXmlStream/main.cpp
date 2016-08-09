#include <QCoreApplication>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("../myXmlStream/my2.xml");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "Error: cannot open file";
        return 1;
    }

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();   /* 添加  XML 说明:
                                                            <?xml version="1.0" encoding="UTF-8"?>
                                                            */
    stream.writeStartElement("bookmark");
    stream.writeAttribute("href", "http://qt.nokia.com/");
    stream.writeTextElement("title", "Qt Home");
    stream.writeEndElement();
    stream.writeEndDocument();

    file.close();

    qDebug() << "write finished!";

    return a.exec();
}
