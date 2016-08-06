import QtQuick 1.0

Item {
    width: 300; height: 300

    Rectangle {
        width: 100; height: 100; anchors.centerIn: parent
        color: "red"

        RotationAnimation on rotation { to: 90; direction: RotationAnimation.Clockwise }
    }
}
