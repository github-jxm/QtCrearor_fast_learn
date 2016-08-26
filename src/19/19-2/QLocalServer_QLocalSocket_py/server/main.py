#!/usr/bin/env python
#coding=utf-8

#  http://tgstdj.blog.163.com/blog/static/74820040201243072238780/
from PyQt4.QtCore import QObject, SIGNAL, SLOT, pyqtSlot

from server import Server

from PyQt4.QtGui import  QLabel

class Label(QLabel):
    def __init__(self, text):
        super(Label, self).__init__(text)

    # @pyqtSlot("PyQt_PyObject")
    @pyqtSlot("QString")
    def setText__2(self,msg):
        # print "setText__2"
        self.setText(msg)


if __name__ == "__main__":
    from PyQt4.QtGui import QApplication, QLabel, QMessageBox
    import  sys
    import os
    print  os.getpid()

    app = QApplication(sys.argv)
    text = QLabel(" QLocalServer   tests")
    # text = Label(" QLocalServer   tests")
    text.resize(600,400)

    s = Server()

    if (s.init("localserver-test")==False):
        QMessageBox.information(text,"info", "There is already exist one!") #// 初使化失败, 说明已经有一个在运行了
        sys.exit(-1)

    # QObject.connect(s,SIGNAL("newMessage(PyQt_PyObject)"),text, SLOT("setText__2(PyQt_PyObject)"))
    # QObject.connect(s,SIGNAL("newMessage(QString)"),text, SLOT("setText__2(QString)"))
    QObject.connect(s,SIGNAL("newMessage(QString)"),text, SLOT("setText(QString)"))

    text.show()
    sys.exit(app.exec_())




