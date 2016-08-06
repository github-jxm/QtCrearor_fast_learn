import QtQuick 1.0

Rectangle {
    width: animation.width; height: animation.height + 8

    AnimatedImage { id: animation; source: "animation.gif" }

    Rectangle {
        property int frames: animation.frameCount

        width: 4; height: 8
        x: (animation.width - width) * animation.currentFrame / frames
        y: animation.height
        color: "red"
    }
}
