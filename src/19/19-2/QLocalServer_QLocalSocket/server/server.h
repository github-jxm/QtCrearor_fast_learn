
////////////////////////////////////////////////////////////////////////////////
// server.h
/////////////////////////////////////////////////////////////////////////////////
#ifndef SERVER_H
#define SERVER_H

#include <QLocalServer>
#include <QLocalSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    Server()
    {
        m_server = 0;
    } 
    ~Server()
    {
        if (m_server)  {
            delete m_server;
          }
     }

    int init(const QString & servername)
    {

            if (isServerRun(servername)) {  /* 如果已经有一个实例在运行了, 就返回0*/
                return 0;
            }
            m_server = new QLocalServer;

            /* 先移除原来存在的,如果不移除,那么如果
             servername已经存在就会listen失败 */
            QLocalServer::removeServer(servername);

            m_server->listen(servername); // 进行监听
            connect(m_server, SIGNAL(newConnection()), this, SLOT(newConnection()));
            return 1;
   }
private slots:
    void newConnection()   // 有新的连接来了
    {
            QLocalSocket *newsocket = m_server->nextPendingConnection();
            connect(newsocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    }  

    void readyRead() // 可以读数据了
    {
            QLocalSocket *local = static_cast<QLocalSocket *>(sender());// 取得是哪个localsocket可以读数据了
            if (!local)
                    return;
            QTextStream in(local);
            QString     readMsg;
            readMsg = in.readAll();// 读出数据
            emit newMessage(readMsg);// 发送收到数据信号
    }
private:
    int isServerRun(const QString & servername)// 判断是否有一个同名的服务器在运行
    {
            /* 用一个localsocket去连一下,
                 如果能连上就说明 有一个在运行了 */
            QLocalSocket ls;

            ls.connectToServer(servername);
            if (ls.waitForConnected(1000)){
                    ls.disconnectFromServer();// 说明已经在运行了
                    ls.close();
                    return 1;
        }
        return 0;
    }
signals:
    void newMessage(const QString &msg);
private:
    QLocalServer *m_server;
};
#endif // SERVER_H
