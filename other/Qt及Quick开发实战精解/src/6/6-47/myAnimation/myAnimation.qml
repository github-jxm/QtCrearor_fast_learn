import QtQuick 1.0

Rectangle {
    id: redRect
    width: 100; height: 100
    color: "red"

    MouseArea { id: mouseArea; anchors.fill: parent }

    states: State {
        name: "pressed"; when: mouseArea.pressed
        PropertyChanges { target: redRect; color: "blue";
            y: mouseArea.mouseY; width: mouseArea.mouseX }
    }

    transitions: Transition {

        SequentialAnimation {
            ColorAnimation { duration: 200 }
            PauseAnimation { duration: 100 }

            ParallelAnimation {
                NumberAnimation {
                    duration: 500
                    easing.type: Easing.OutBounce
                    targets: redRect
                    properties: "y"
                }

                NumberAnimation {
                    duration: 800
                    easing.type: Easing.InOutQuad
                    targets: redRect
                    properties: "width"
                }
            }
        }
    }
}
