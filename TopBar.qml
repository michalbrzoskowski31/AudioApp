import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import "DefaultTheme.js" as DefaultTheme

Rectangle {
    id: topBar
    anchors {
        top: parent.top
        right: parent.right
        left: parent.left
    }
    implicitHeight: grid.height
    color: DefaultTheme.barColor

    RowLayout {
        id: grid
        width: parent.width

        Button_m {
            id: prev
            implicitWidth: 100
            implicitHeight: 40
            text: "<"
            onClicked: {
                stackView.pop()
            }
            Layout.alignment: Qt.AlignLeft
        }

        Button_m {
            id: fdBUtton
            implicitWidth: 100
            implicitHeight: 40
            text: "Browse files"
            onClicked: {
                filedialog.open()
            }
            Layout.alignment: Qt.AlignHCenter
        }

        Button_m {
            id: next
            implicitWidth: 100
            implicitHeight: 40
            text: ">"
            onClicked: {
        
                stackView.push("Main_screen.qml")
            }
            Layout.alignment: Qt.AlignRight
        }

    }
}
