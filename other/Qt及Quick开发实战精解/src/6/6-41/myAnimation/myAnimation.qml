import QtQuick 1.0

Rectangle {
    id: rect
    width: 100; height: 100
    color: "red"

    PropertyAnimation {
        id: animation
        target: rect
        properties: "x,y"
        duration: 1000
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            animation.to = 50;
            animation.running = true;
        }
    }
}
