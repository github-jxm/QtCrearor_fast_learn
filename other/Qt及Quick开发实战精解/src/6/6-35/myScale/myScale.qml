import QtQuick 1.0

Rectangle {
    width: 100; height: 100
    color: "blue"
    Rectangle {
        width: 50; height: 50; x: 20; y: 20
        color: "red"
        transform: Scale { origin.x: 25; origin.y: 25; xScale: 3}
    }
}
