#!/usr/bin/env python
# coding=utf-8

# include <QLocalServer>
# include <QLocalSocket>
from PyQt4.QtCore import QObject, SIGNAL, QTextStream, QString
from PyQt4.QtNetwork import QLocalServer, QLocalSocket


class Server(QObject):
    def __init__(self, parent=None):
        super(Server, self).__init__(parent)
        self.__m_server = None

    def __del__(self):
        if (self.__m_server != None):
            del self.__m_server

    def init(self, servername):

        if (self.__isServerRun(servername)):  #  如果已经有一个实例在运行了, 就返回0
            return  False

        self.__m_server = QLocalServer()

        """
          先移除原来存在的,
          如果不移除,那么如果 servername已经存在
          就会listen失败
        """

        QLocalServer.removeServer(servername)
        print "启动监听..."
        print self.__m_server.listen(servername)  # 进行监听

        self.connect(self.__m_server, SIGNAL("newConnection()"), self.__newConnection)
        return True

    def __newConnection(self):  #  有新的连接来了
        newsocket = self.__m_server.nextPendingConnection()
        self.connect(newsocket, SIGNAL("readyRead()"), self.readyRead)

    def readyRead(self):       #  可以读数据了
        local = self.sender()  #  取得是哪个localsocket可以读数据了
        if (local == None):
            return
        _in = QTextStream(local)
        readMsg = _in.readAll()
        print "recv Msg:",readMsg
        self.emit(SIGNAL("newMessage(QString)"), QString(readMsg))

    def __isServerRun(self, servername):  # 判断是否有一个同名的服务器在运行
        #  用一个localsocket去连一下,
        #  如果能连上就说明 有一个在运行了
        ls = QLocalSocket()

        ls.connectToServer(servername)
        if (ls.waitForConnected(1000)):
            ls.disconnectFromServer()  # // 说明已经在运行了
            ls.close()
            return  True
        return False
