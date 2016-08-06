#include <QApplication>
#include <QDeclarativeView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView view;
    view.setSource(QUrl("../myDeclarativeView/application.qml"));
    view.show();

    return app.exec();
}
