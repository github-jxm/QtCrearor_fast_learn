#include <QApplication>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include "applicationdata.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView view;

    ApplicationData data;
    view.rootContext()->setContextProperty("applicationData", &data);

    view.setSource(QUrl::fromLocalFile("../myDeclarativeContext/MyItem.qml"));
    view.show();

    return app.exec();
}
