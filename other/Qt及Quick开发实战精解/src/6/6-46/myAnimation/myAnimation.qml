import QtQuick 1.0

Rectangle {
    id: rect
    width: 120; height: 200

    Image {
        id: img
        source: "qt.png"
        anchors.horizontalCenter: parent.horizontalCenter
        y: 0

        SequentialAnimation on y {
            loops: Animation.Infinite
            NumberAnimation { to: rect.height - img.height;
                easing.type: Easing.OutBounce; duration: 2000 }
            PauseAnimation { duration: 1000 }
            NumberAnimation { to: 0; easing.type: Easing.OutQuad;
                duration: 1000 }
        }
    }
}
