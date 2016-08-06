import QtQuick 1.0

Item {
    width: 100; height: 100

    Rectangle {
        id: rect
        width: 100; height: 100
        color: "red"

        Behavior on x { PropertyAnimation { duration: 500 } }
        Behavior on y { PropertyAnimation { duration: 500 } }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: { rect.x = mouse.x; rect.y = mouse.y }
    }
}
