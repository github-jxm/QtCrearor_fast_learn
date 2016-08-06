import QtQuick 1.0

Rectangle {
    width: 100; height: 100
    color: "green"

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if (mouse.button == Qt.RightButton)
                parent.color = 'blue';
            else if ((mouse.button == Qt.LeftButton)
                     && (mouse.modifiers & Qt.ShiftModifier))
                parent.color = 'green';
            else
                parent.color = 'red';
        }
    }
}

