import QtQuick
import QtQuick.Controls

import "qrc:/qml/ui/themes/DefaultTheme.js" as DefaultTheme

Rectangle {
    id: rec
    width: 0.8 * dragAndDropScreen.width; height: 0.8 * dragAndDropScreen.height
    anchors.centerIn: dragAndDropScreen
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

        function changeColor(targetColor)
        {
            var colorAnimation = Qt.createQmlObject('import QtQuick 2.0; ColorAnimation {}', dropArea)
            colorAnimation.target = rec
            colorAnimation.property = "color"
            colorAnimation.to = targetColor
            colorAnimation.duration = 200
            colorAnimation.start()
        }

        onEntered: (drag) => {
            console.log("Plik został przeciągnięty na obszar")
            changeColor(DefaultTheme.fgUpColor)
            drag.accept(Qt.CopyAction)
        }

        onExited: {
            console.log("Plik został opuszczony z obszaru")
            changeColor(DefaultTheme.bgColor)
        }

        onDropped: (drop) => {
            console.log("Plik został upuszczony na obszar")
            console.log(drop.urls)

            filedialog.close()

            var filePath = musicPlayer.getFilePath(drop.urls);
            console.log("FILE PATH QML: " + filePath)
            musicPlayer.copyFile(filePath);
            musicPlayer.initFile();
            //musicPlayer.updateInfo();
            musicPlayer.onDropUpdateInfo();
            musicPlayer.check();

            stackView.push("qrc:/qml/ui/screens/Main/Main_screen.qml")
        }
    }
}
