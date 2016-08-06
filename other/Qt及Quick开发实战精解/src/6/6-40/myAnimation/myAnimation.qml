import QtQuick 1.0

Rectangle {
    id: rect
    width: 100; height: 100
    color: "red"

    MouseArea {
        anchors.fill: parent
        onClicked: PropertyAnimation { target: rect; properties: "x,y"; to: 50; duration: 1000 }
    }
}
