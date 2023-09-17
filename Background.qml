import QtQuick
import "DefaultTheme.js" as DefaultTheme

Rectangle {
    id: bg
    width: root.width; height: root.height
    color: DefaultTheme.bgColor
    anchors.fill: parent
}
