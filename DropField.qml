import QtQuick

DropArea {
    width: 0.8 * parent.width; height: 0.8 * parent.height
    anchors {
        centerIn: parent
    }

    Rectangle {
        anchors.fill: parent
        color: parent.containsDrag ? "#161622" : bg.color

        border {
            color: "white"
            width: 1
        }

        //visible: parent.containsDrag

    }
}
