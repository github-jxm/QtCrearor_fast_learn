import QtQuick 1.0

Rectangle {
    width: 360
    height: 360
    XmlListModel {
        id: feedModel
        source: "http://rss.news.yahoo.com/rss/oceania"
        query: "/rss/channel/item"
        XmlRole { name: "title"; query: "title/string()" }
        XmlRole { name: "link"; query: "link/string()" }
        XmlRole { name: "description"; query: "description/string()" }
    }

    ListView {
        anchors.fill: parent
        model: feedModel
        delegate: Column {
            Text { text: "title: " + title }
            Text { text: "link: $" + link }
            Text { text: "description: $" + description }
        }
    }
}


