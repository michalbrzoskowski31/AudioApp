#include "musicplayer.h"
#include <QDebug>


MusicPlayer::MusicPlayer(QObject *parent)
    : QObject{parent}
{
    initFolders(exePath);
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
    if (this->player->metaData()[QMediaMetaData::Author].toString() == newAuthor)
        return;

    this->m_author = newAuthor;
    this->player->metaData().insert(QMediaMetaData::Author, QVariant(newAuthor));

    emit authorChanged();
}


void MusicPlayer::play()
{
    this->player->play();

    //this->getMetaData();
}

void MusicPlayer::pause()
{
    this->player->pause();
    //this->player->setSource(QUrl());
}

void MusicPlayer::onDropUpdateInfo()
{
    this->metadata = this->player->metaData();
    this->setTitle(this->metadata.stringValue(QMediaMetaData::Title));
}

void MusicPlayer::check()
{
    qDebug() << "Title: " << this->m_title;
    qDebug() << "Source: " << this->m_source;
    qDebug() << "Author: " << this->m_author;
}

void MusicPlayer::initFile()
{
    player->setSource(m_source);
    player->setAudioOutput(this->audioOutput);
    audioOutput->setVolume(20);

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

//void MusicPlayer::check()
//{
//    qDebug() << "musicFile.fileName(): " << this->musicFile.fileName();
//    qDebug() << "musicFilePath: " << this->musicFilePath;
//    qDebug() << "tempDirPath: " << this->tempDirPath;
//    qDebug() << "exePath: " << this->exePath;
//}
//filehandler end
