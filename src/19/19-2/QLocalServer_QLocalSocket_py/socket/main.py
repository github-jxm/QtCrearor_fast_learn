#coding=utf-8

from time import sleep
from PyQt4.QtCore import QTextStream,QString
from PyQt4.QtNetwork import QLocalSocket
import random
import os

if __name__ == "__main__":

    pid = os.getpid()
    ls = QLocalSocket()
    ls.connectToServer("localserver-test")
    if ls.waitForConnected():
        print "连接成功"
        while True:
            try:
                ts = QTextStream(ls)
                ts << QString.number(random.randrange(1000)) + "\nTTTTTTTTTT" + "\n PID = " + QString.number(pid) + "\n"
                ts.flush()
                print "werite :", ls.waitForBytesWritten()
                print pid
                sleep(1)
            except Exception as e:
                print e.message

