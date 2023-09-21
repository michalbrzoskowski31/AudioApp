import QtQuick
import QtQuick.Controls.Imagine

import "qrc:/qml/ui/themes/DefaultTheme.js" as DefaultTheme


RoundButton {
    id: control
    property bool isPlaying
    //text: qsTr("Button")
    //hoverEnabled: true

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: "red"//DefaultTheme.textColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        //elide: Text.ElideRight
    }

    background: Rectangle {
        //implicitWidth: 40
        //implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        color: hovered ? DefaultTheme.fgUpColor : DefaultTheme.fgDownColor
        border.color: control.down ? DefaultTheme.fgUpColor : DefaultTheme.borderColor
        border.width: 2
        radius: 360
    }

}
