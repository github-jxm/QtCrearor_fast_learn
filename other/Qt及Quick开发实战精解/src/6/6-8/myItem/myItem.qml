import QtQuick 1.0

//Item {
//    Rectangle {
//        color: "red"
//        width: 100; height: 100
//    }
//    Rectangle {
//        color: "blue"
//        x: 50; y: 50; width: 100; height: 100
//    }
//}

Item {
    Rectangle {
        z: 1
        color: "red"
        width: 100; height: 100
    }
    Rectangle {
        color: "blue"
        x: 50; y: 50; width: 100; height: 100
    }
}


