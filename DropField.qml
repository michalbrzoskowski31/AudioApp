import QtQuick
import QtQuick.Controls

import "DefaultTheme.js" as DefaultTheme

Rectangle {
    id: rec
    width: 0.8 * parent.width; height: 0.8 * parent.height
    anchors.centerIn: parent
    color: DefaultTheme.bgColor

    border {
        color: "white"
        width: 1
    }
    Text {
        text: "Drag & Drop"
        color: DefaultTheme.textColor
        anchors.centerIn: parent
        font.pointSize: 30
        font.family: "Cascadia Mono"
    }

    DropArea {
        id: dropArea
        anchors {
            centerIn: parent
            fill: parent
        }

        onEntered: {
            console.log("Plik został przeciągnięty na obszar")
            var colorAnimation = Qt.createQmlObject('import QtQuick 2.0; ColorAnimation {}', dropArea)
            colorAnimation.target = rec
            colorAnimation.property = "color"
            colorAnimation.to = DefaultTheme.fgUpColor
            colorAnimation.duration = 200
            colorAnimation.start()
        }

        onExited: {
            console.log("Plik został opuszczony z obszaru")
            var colorAnimation = Qt.createQmlObject('import QtQuick 2.0; ColorAnimation {}', dropArea)
            colorAnimation.target = rec
            colorAnimation.property = "color"
            colorAnimation.to = DefaultTheme.bgColor
            colorAnimation.duration = 200
            colorAnimation.start()
        }

        onDropped: {
            console.log("Plik został upuszczony na obszar")
            if (drag.mimeData) {
                console.log(drag.mimeData)
            }
        }
    }
}
