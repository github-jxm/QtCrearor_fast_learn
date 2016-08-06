import QtQuick 1.0

Rectangle {
    width: 100; height: 100
    color: "red"

    PropertyAnimation on x { to: 50; duration: 1000;
        easing.type: Easing.OutBounce }
    PropertyAnimation on y { to: 50; duration: 1000;
        easing.type: Easing.OutBounce }
}
