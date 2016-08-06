import QtQuick 1.0

Text {
    textFormat: Text.RichText
    text: "The main website is at <a href=\"http://qt.nokia.com\">Nokia Qt DF</a>."
    onLinkActivated: console.log(link + " link activated")
}

