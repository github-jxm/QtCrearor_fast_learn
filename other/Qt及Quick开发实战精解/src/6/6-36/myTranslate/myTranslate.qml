import QtQuick 1.0

Row {
    Rectangle {
        width: 100; height: 100
        color: "blue"
        transform: Translate { y: 20 }
    }
    Rectangle {
        width: 100; height: 100
        color: "red"
        transform: Translate { y: -20 }
    }
}
