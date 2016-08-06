#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QUdpSocket;

namespace Ui {
class Widget;
}

// 枚举变量标志信息的类型，分别为消息，新用户加入，用户退出，文件名，拒绝接受文件
enum MessageType{Message, NewParticipant, ParticipantLeft, FileName, Refuse};


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void newParticipant(QString userName,
                        QString localHostName, QString ipAddress);
    void participantLeft(QString userName,
                         QString localHostName, QString time);
    void sendMessage(MessageType type, QString serverAddress="");

    QString getIP();
    QString getUserName();
    QString getMessage();

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;

private slots:
    void processPendingDatagrams();

    void on_sendButton_clicked();
};

#endif // WIDGET_H
