import QtQuick 1.0

Rectangle {
    color: "blue"
    width: 100; height: 100
    Rectangle {
        color: "green"
        width: 25; height: 25
    }
    Rectangle {
        color: "red"
        x: 25; y: 25; width: 25; height: 25
        scale: 1.6
        transformOrigin: "TopLeft"
    }
}


