import QtQuick 1.0

Rectangle {
    width: 100; height: 100
    focus: true

    Keys.onPressed: {
        if (event.key == Qt.Key_A) {
            console.log('Key A was pressed');
            event.accepted = true;
        }
    }
}
