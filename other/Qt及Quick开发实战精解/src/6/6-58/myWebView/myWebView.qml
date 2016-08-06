import QtQuick 1.0
import QtWebKit 1.0

Flickable {
    width: 400; height: 300
    contentWidth: webView.width; contentHeight: webView.height

    WebView {
        id: webView
        url: "http://www.baidu.com"
    }
}


