import QtQuick
import QtQuick.Controls

import "DefaultTheme.js" as DefaultTheme


Button {
    id: control
    text: qsTr("Button")

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? DefaultTheme.fgDownColor : DefaultTheme.fgUpColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle{
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        border.color: DefaultTheme.borderColor
        border.width: 1
        radius: 2
    }
}
