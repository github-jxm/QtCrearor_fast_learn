import QtQuick 1.0

Rectangle {
    width: 100; height: 100
    color: "blue"
    transform: Rotation { origin.x: 30; origin.y: 30; axis { x: 0; y: 1; z: 0 } angle: 72 }
}
