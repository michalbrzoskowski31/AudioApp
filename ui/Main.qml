import QtQuick
import QtQuick.Window
import QtQuick.Dialogs
import QtQuick.Controls
import QtQuick.Layouts

import "qrc:/qml/ui/themes/DefaultTheme.js" as DefaultTheme

import "assets/"
import "screens/"
import "styles/"
import "themes/"
import "./"

import FileHandler
import MusicPlayer

Window {
    id: root
    width: 700
    minimumWidth: 700
    height: 480
    minimumHeight: 480
    visible: true
    title: qsTr("Audio App")
    //color: "transparent"

    File {
        id: file
    }

    FileDialog {
        id: filedialog
        title: "Choose the file"
        visible: false

        onAccepted: {
            // Wykonaj akcje po zaakceptowaniu wybranego pliku
            console.log("Wybrany plik:", fileUrl)
        }

        onRejected: {
            // Wykonaj akcje po odrzuceniu wyboru pliku
            console.log("Wybór pliku został odrzucony")
        }
    }

    Background {
        id: bg
    }

    TopBar {
        id: topBar
    }


    StackView {
        id: stackView
        anchors {
            top: topBar.bottom
            left: bg.left
            right: bg.right
            bottom: bg.bottom
        }

        initialItem: "qrc:/qml/ui/screens/DragAndDrop/DragAndDrop_screen.qml"
    }
}
