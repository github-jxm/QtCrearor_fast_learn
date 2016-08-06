#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QUdpSocket;

class TcpServer;
#include <QTextCharFormat>

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


    void hasPendingFile(QString userName, QString serverAddress,
                        QString clientAddress, QString fileName);

    bool saveFile(const QString& fileName);

    void closeEvent(QCloseEvent *);

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;

    QString fileName;
    TcpServer *server;

    QColor color;

private slots:
    void processPendingDatagrams();

    void on_sendButton_clicked();

    void getFileName(QString);
    void on_sendToolBtn_clicked();
    void on_fontComboBox_currentFontChanged(QFont f);
    void on_sizeComboBox_currentIndexChanged(QString );
    void on_boldToolBtn_clicked(bool checked);
    void on_italicToolBtn_clicked(bool checked);
    void on_underlineToolBtn_clicked(bool checked);
    void on_colorToolBtn_clicked();

    void currentFormatChanged(const QTextCharFormat &format);
    void on_saveToolBtn_clicked();
    void on_clearToolBtn_clicked();
    void on_exitButton_clicked();
};

#endif // WIDGET_H
