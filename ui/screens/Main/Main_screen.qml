import QtQuick
import QtMultimedia

import MusicPlayer

Item {
    id: mainScreen

    Player {
        id: mediaPlayer
        source: file.getMusicFilePath()
    }

    BottomBar {

    }
}
