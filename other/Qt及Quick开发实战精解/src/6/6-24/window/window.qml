import QtQuick 1.0

Rectangle {
    id: window
    color: "white"; width: 240; height: 150

    Column {
        anchors.centerIn: parent; spacing: 15

        MyWidget {
            focus: true
            color: "lightblue"
        }
        MyWidget {
            color: "palegreen"
        }
    }
}

