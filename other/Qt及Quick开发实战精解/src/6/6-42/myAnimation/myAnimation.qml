import QtQuick 1.0

Rectangle {
    id: rect
    width: 100; height: 100
    color: "red"

    MouseArea {
        anchors.fill: parent
        onClicked: rect.state = "moved"
    }

    states: State {
        name: "moved"
        PropertyChanges { target: rect; x: 50; y: 50 }
    }

    transitions: Transition {
        PropertyAnimation { properties: "x,y"; duration: 1000 }
    }
}
