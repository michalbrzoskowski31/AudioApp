import QtQuick
import QtQuick.Window
//import "Background"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Audio App")
    color: "blue"

    Background {

        Text {
            text: "Hello World!"
            color: "white"
            anchors.centerIn: parent
            font {
                pointSize: 40
                bold: true
            }
        }
    }
}
