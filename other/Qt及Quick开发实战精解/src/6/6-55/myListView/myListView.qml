import QtQuick 1.0

//Rectangle {
//    width: 180; height: 200

//    Component {
//        id: contactDelegate
//        Item {
//            width: 180; height: 40
//            Column {
//                Text { text: '<b>Name:</b> ' + name }
//                Text { text: '<b>Number:</b> ' + number }
//            }
//        }
//    }

//    ListView {
//        anchors.fill: parent
//        model: ContactModel {}
//        delegate: contactDelegate
//        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
//        focus: true
//    }


//}

ListView {
    width: 180; height: 200

    Component {
        id: contactsDelegate
        Rectangle {
            id: wrapper
            width: 180
            height: contactInfo.height
            color: ListView.isCurrentItem ? "black" : "red"
            Text {
                id: contactInfo
                text: name + ": " + number
                color: wrapper.ListView.isCurrentItem ? "red" : "black"
            }
        }
    }

    model: ContactModel {}
    delegate: contactsDelegate
    focus: true
}
