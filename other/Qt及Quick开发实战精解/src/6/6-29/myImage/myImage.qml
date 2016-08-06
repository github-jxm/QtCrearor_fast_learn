import QtQuick 1.0

Image {
    id: image
    width: 120; height: 120
    fillMode: Image.Tile
    source: "http://www.baidu.com/img/baidu_sylogo1.gif"

    onStatusChanged: {
        if (image.status == Image.Ready) console.log('Loaded')
        else if (image.status == Image.Loading) console.log('Loading')
    }
}
