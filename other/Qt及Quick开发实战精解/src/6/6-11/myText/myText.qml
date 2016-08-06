import QtQuick 1.0

Column {
    spacing: 20

    Text {
        width: 200;
        text: "使文本在单行中对于超出部分不要进行省略"
    }
    Text {
        width: 200; elide: Text.ElideLeft;
        text: "使文本在单行中对于超出部分从左边进行省略"
    }
    Text {
        width: 200; elide: Text.ElideMiddle;
        text: "使文本在单行中对于超出部分从中间进行省略"
    }
    Text {
        width: 200; elide: Text.ElideRight;
        text: "使文本在单行中对于超出部分从右边进行省略"
    }
}

