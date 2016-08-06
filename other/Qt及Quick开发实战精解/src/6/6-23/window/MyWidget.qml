import QtQuick 1.0

Rectangle {
    id: widget
    color: "lightsteelblue"; width: 175; height: 25; radius: 10; smooth: true
    Text { id: label; anchors.centerIn: parent}
    focus: true
    Keys.onPressed: {
        if (event.key == Qt.Key_A)
            label.text = 'Key A was pressed'
        else if (event.key == Qt.Key_B)
            label.text = 'Key B was pressed'
        else if (event.key == Qt.Key_C)
            label.text = 'Key C was pressed'
    }
}
