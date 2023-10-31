#include "musicplayer.h"
#include <QDebug>


MusicPlayer::MusicPlayer(QObject *parent)
    : QObject{parent}
{
    initFolders(exePath);
    initVariables();
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;

}

MusicPlayer::~MusicPlayer()
{
    delete this->player;
    delete this->audioOutput;

    if(this->musicFile.exists())
    {
        this->musicFile.close();
        if(QFile::remove(this->musicFile.fileName()))
        {
            qDebug() << "music file deleted";
        }
    }
}

QString MusicPlayer::title() const
{
    return this->m_title;
}

void MusicPlayer::setTitle(const QString &newTitle)
{
    this->m_title = newTitle;

    if(newTitle == "") {
        QFileInfo fileinfo(this->musicFile.fileName());
        this->m_title = fileinfo.fileName();
    }

    emit titleChanged();
}

QString MusicPlayer::source() const
{
    return this->player->source().toString();
}

void MusicPlayer::setSource_m(const QString &newSource)
{
    if (this->player->source() == newSource)
        return;

    this->m_source = QUrl::fromLocalFile(newSource);
    this->player->setSource(QUrl::fromLocalFile(newSource));
    //this->player->setSource(QUrl::fromLocalFile("C:/Users/Micha/Desktop/Programowanie/Qt/AudioApp/build-AudioApp-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/.temp/Hardbass_1_.mp3"));

    emit sourceChanged();
}

QString MusicPlayer::author() const
{
    //return m_author;
    QString author = this->player->metaData()[QMediaMetaData::Author].toString(); // [13]
    return author;
}

void MusicPlayer::setAuthor(const QString &newAuthor)
{
    this->m_author = newAuthor;

    emit authorChanged();
}


void MusicPlayer::play()
{
    this->player_isPlaying = true;
    this->player->play();

    //this->getMetaData();
}

void MusicPlayer::pause()
{
    this->player_isPlaying = false;
    this->player->pause();
}

void MusicPlayer::onDropUpdateInfo()
{
    //this->setSource_m(this->)
    this->metadata = this->player->metaData();
    this->setTitle(this->metadata.stringValue(QMediaMetaData::Title));
    this->setAuthor(this->metadata.stringValue(QMediaMetaData::Author));
}

void MusicPlayer::check()
{
    //qDebug() << "musicPlayer::check(): " << this->m_file_isDropped;
}

void MusicPlayer::initFile()
{
    player->setSource(m_source);
    player->setAudioOutput(this->audioOutput);
    audioOutput->setVolume(20);

}

void MusicPlayer::deleteFile()
{
    // Destructor
    this->pause();
    delete this->player;
    delete this->audioOutput;

    if(this->musicFile.exists())
    {
        this->musicFile.close();
        if(QFile::remove(this->musicFile.fileName()))
        {
            qDebug() << "music file deleted";
        }
    }
    // Destructor

    // Constructor
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    // Constructor
}

//filehandler begin
int MusicPlayer::copyFile(QString filePath)
{
    QFileInfo fileInfo(filePath);
    //QString tempFilePath = QString(this->tempDirPath.absolutePath()) + "/" + fileInfo.fileName();
    musicFilePath = this->tempDirPath.absoluteFilePath(fileInfo.fileName());

    qDebug() << "Temporary file path: " << musicFilePath;

    QFile sourceFile(filePath);
    if(sourceFile.copy(musicFilePath))
    {
        this->musicFile.setFileName(musicFilePath);
        this->setSource_m(this->musicFilePath);
        return 0;
    }
    return 1;
}

int MusicPlayer::initFolders(QDir root)
{
    QString tempFolderName{".temp"};

    if(root.exists(tempFolderName))
    {
        //qWarning() << "Folder Already Exist";
        this->tempDirPath = QDir(tempFolderName);
        return 0;
    }

    if(root.mkdir(tempFolderName))
    {
        this->tempDirPath = QDir(tempFolderName);
        qInfo() << "Directory created: " << tempDirPath.absolutePath();
        return 0;
    }
    return 1;
}

void MusicPlayer::initVariables()
{
    this->file_isDropped = false;
    this->screen_isMain = false;
    this->player_isPlaying = false;
}

void MusicPlayer::getMetaData()
{
    QMediaMetaData metadata = player->metaData();
    QString tit = metadata.stringValue(QMediaMetaData::Title);
    QString au = metadata.stringValue(QMediaMetaData::ContributingArtist);
    qDebug() << "IMPORTANT: " << tit << " " << au;
}

QString MusicPlayer::getFilePath(QString url)
{
    qDebug() << "URL: " << url;
    QUrl realUrl = QUrl::fromUserInput(url);
    QString filePath = realUrl.toLocalFile();
    qDebug() << "File path: " << filePath;
    qDebug() << QDir::currentPath();

    return filePath;
}

QString MusicPlayer::getMusicFilePath()
{
    return this->musicFilePath;
}

bool MusicPlayer::get_file_isDropped() const
{
    return this->file_isDropped;
}

void MusicPlayer::set_file_isDropped(bool set)
{
    this->file_isDropped = set;
}

bool MusicPlayer::get_screen_isMain() const
{
    return this->screen_isMain;
}

void MusicPlayer::set_screen_isMain(bool set)
{
    this->screen_isMain = set;
}

bool MusicPlayer::get_player_isPlaying() const
{
    return this->player_isPlaying;
}

void MusicPlayer::set_player_isPlaying(bool set)
{
    this->player_isPlaying = set;
}
