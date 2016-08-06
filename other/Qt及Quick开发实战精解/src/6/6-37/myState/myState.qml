import QtQuick 1.0

Rectangle {
    id: myRect
    width: 200; height: 200
    color: "red"

    MouseArea {
        anchors.fill: parent
        onClicked: myRect.state = 'moved'
    }

    states: [
        State {
            name: "moved"
            PropertyChanges { target: myRect; x: 50; y: 50 }
        }
    ]
}


