import QtQuick
import QtQuick.Window
import QtQuick.Dialogs
import QtQuick.Controls

import "DefaultTheme.js" as DefaultTheme

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Audio App")
    color: "blue"

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
        Button_m {
            text: "test"
            onClicked: {
                filedialog.open()
            }
            anchors {
                horizontalCenter: parent.horizontalCenter
                top: parent.top
            }
        }

        DropField {
            id: df
        }
    }

    Rectangle {
        x: 10; y: 10
        width: 20; height: 20
        color: "red"

        Drag.active: dragArea.drag.active
        Drag.hotSpot.x: 10
        Drag.hotSpot.y: 10

        MouseArea {
            id: dragArea
            anchors.fill: parent

            drag.target: parent
        }
    }
}
