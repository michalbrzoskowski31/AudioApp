import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "qrc:/qml/ui/themes/DefaultTheme.js" as DefaultTheme

import "../../styles/"

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
                //spacing: 20
                Button_m {
                    id: random
                    implicitWidth: 50
                    text: qsTr("random")
                }
                Item {
                    id: prev
                    width: 48; height: 48
                    Image {
                        source: "qrc:/qml/ui/assets/prev.png"
                        anchors.centerIn: parent
                        antialiasing: true
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log("prev clicked")
                        }
                    }
                }
                RoundButton {
                    id: pause_play
                    property bool isPlaying: true
                    spacing: 100
                    //implicitWidth: 50
                    //text: qsTr(">/||")
                    Image {
                        source: pause_play.isPlaying ? "qrc:/qml/ui/assets/play.png" : "qrc:/qml/ui/assets/pause.png"
                        anchors.centerIn: parent
                        antialiasing: true
                        scale: 0.8
                    }
                    onClicked: {
                        console.log("play clicked")
                        pause_play.isPlaying = !pause_play.isPlaying
                    }
                }
                Item {
                    id: next
                    width: 48; height: 48
                    Image {
                        source: "qrc:/qml/ui/assets/next.png"
                        anchors.centerIn: parent
                        antialiasing: true
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log("next clicked")
                        }
                    }
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
