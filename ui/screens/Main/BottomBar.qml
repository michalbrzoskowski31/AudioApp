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
            //Layout.preferredWidth: 200//root.width * 3/10
            implicitWidth: 200
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
                    width: 50
                    color: "white"
                    font.bold: true
                    id: title
                    text: musicPlayer.title
                    elide: Text.ElideRight
                }

                Text {
                    width: 50
                    color: "white"
                    id: author
                    text: musicPlayer.author
                    elide: Text.ElideRight
                }
            }
        }

        ColumnLayout {
            id: player
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: (parent.width - info.width - controls.width) * 0.6

            RowLayout {
                //spacing: 20
                Layout.preferredWidth: parent.width
                Button_m {
                    Layout.alignment: Qt.AlignLeft
                    id: random
                    implicitWidth: 50
                    text: qsTr("random")
                }
                Item {
                    id: prev
                    width: 48; height: 48
                    Layout.alignment: Qt.AlignLeft
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
                    property bool isPlaying: musicPlayer.get_player_isPlaying()
                    spacing: 100
                    Layout.alignment: Qt.AlignHCenter
                    //implicitWidth: 50
                    //text: qsTr(">/||")
                    Image {
                        source: !pause_play.isPlaying ? "qrc:/qml/ui/assets/play.png" : "qrc:/qml/ui/assets/pause.png"
                        anchors.centerIn: parent
                        antialiasing: true
                        scale: 0.8
                    }
                    onClicked: {
                        //console.log("play clicked")

                        if(musicPlayer.get_player_isPlaying() === false)
                        {
                            console.log("play");
                            pause_play.isPlaying = true;
                            musicPlayer.set_player_isPlaying(true);
                            musicPlayer.play();
                        }
                        else
                        {
                            console.log("pause");
                            pause_play.isPlaying = false;
                            musicPlayer.set_player_isPlaying(false);
                            musicPlayer.pause();
                        }
                    }
                }
                Item {
                    id: next
                    width: 48; height: 48
                    Layout.alignment: Qt.AlignRight
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
                    Layout.alignment: Qt.AlignRight
                    id: loop
                    implicitWidth: 50
                    text: qsTr("loop")
                }
            }
            Slider {
                id: progres
                implicitWidth: parent.width
                from: 0
                to: musicPlayer.getDuration()

                onMoved: {
                    console.log(progres.value);
                    musicPlayer.setPosition(progres.value);
                }

                Connections {
                    target: musicPlayer
                    onPositionChanged: {
                        console.log("position changed!");
                        console.log(musicPlayer.getDuration());
                        console.log(musicPlayer.getPosition());
                        progres.value = musicPlayer.getPosition();
                    }
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
                from: 0
                to: 100
                value: 100

                onMoved: {
                    console.log(volume.value);
                    var volumePercentage = volume.value / volume.to;
                    musicPlayer.setVolume(volumePercentage);
                }
            }
        }
    }
}
