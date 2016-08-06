import QtQuick 1.0

Rectangle {
    width: 200; height: 200

    ListModel {
        id: fruitModel
        property string language: "en"
        ListElement {
            name: "Apple"
            cost: 2.45
        }
        ListElement {
            name: "Orange"
            cost: 3.25
        }
        ListElement {
            name: "Banana"
            cost: 1.95
        }
    }

    Component {
        id: fruitDelegate
        Row {
            Text { text: " Fruit: " + name; color: ListView.view.fruit_color }
            Text { text: " Cost: $" + cost }
            Text { text: " Language: " + ListView.view.model.language }
        }
    }

    ListView {
        property color fruit_color: "green"
        model: fruitModel
        delegate: fruitDelegate
        anchors.fill: parent
    }
}
