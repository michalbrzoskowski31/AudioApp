import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "qrc:/qml/ui/themes/DefaultTheme.js" as DefaultTheme

import "qrc:/qml/ui/styles/"

Item {
    id: bottomBar
    anchors {
        right: parent.right
        left: parent.left
        bottom: parent.bottom
    }

    height: 100//parent.height / 8

    Rectangle {
        anchors.fill: parent
        color: DefaultTheme.barColor
    }

    RowLayout {
        id: root
        anchors.fill: parent
        RowLayout {
            id: info
            //anchors.fill: parent
            Layout.preferredWidth: 200//root.width * 3/10
            Layout.alignment: Qt.AlignLeft

            Item {
                id: cover

                width: bottomBar.height
                height: bottomBar.height


                Rectangle { // TODO: Image {} with a albumCover image
                    anchors.fill: parent
                    color: "grey"
                }
            }

            ColumnLayout {
                id: titleAndAuthor

                Text {
                    color: "white"
                    font.bold: true
                    id: title
                    text: qsTr("Automobile")
                }

                Text {
                    color: "white"
                    id: author
                    text: qsTr("KALEO")
                }
            }
        }

        ColumnLayout {
            id: player
            Layout.alignment: Qt.AlignHCenter

            RowLayout {
                Button_m {
                    id: random
                    implicitWidth: 50
                    text: qsTr("random")
                }
                Button_m {
                    id: prev
                    implicitWidth: 50
                    text: qsTr("prev")
                }
                RoundButton {
                    id: pause_play
                    //implicitWidth: 50
                    text: qsTr(">/||")
                }
                Button_m {
                    id: next
                    implicitWidth: 50
                    text: qsTr("next")
                }
                Button_m {
                    id: loop
                    implicitWidth: 50
                    text: qsTr("loop")
                }
            }
        }

        RowLayout {
            id: controls
            Layout.preferredWidth: 200//root.width * 3/10
            Layout.alignment: Qt.AlignRight

            Button_m {
                id: mute
                implicitWidth: 50
                text: qsTr("<)")
            }

            Slider {
                id: volume
            }
        }
    }
}
