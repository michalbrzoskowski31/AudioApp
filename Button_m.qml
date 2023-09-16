import QtQuick
import QtQuick.Controls.Imagine

import "DefaultTheme.js" as DefaultTheme


Button {
    id: control
    text: qsTr("Button")
    //hoverEnabled: true

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: DefaultTheme.textColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        color: hovered ? DefaultTheme.fgUpColor : DefaultTheme.fgDownColor
        border.color: control.down ? DefaultTheme.fgUpColor : DefaultTheme.borderColor
        border.width: 2
        radius: 2
    }

}
