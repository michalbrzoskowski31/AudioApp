import QtQuick
import QtQuick.Controls

import "DefaultTheme.js" as DefaultTheme

Rectangle {
    anchors {
        right: parent.right
        left: parent.left
        bottom: parent.bottom
    }

    height: 60//parent.height / 8
    color: DefaultTheme.bottomBar
}
