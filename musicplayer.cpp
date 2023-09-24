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
    //this->player->pause();
    //this->player->setSource(QUrl());
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
    return m_title;
}

void MusicPlayer::setTitle(const QString &newTitle)
{
    if (this->player->metaData()[QMediaMetaData::Title].toString() == newTitle)
        return;

    //QMediaMetaData metaData;
    //metaData.insert(QMediaMetaData::Title, QVariant(newTitle));
    this->player->metaData().insert(QMediaMetaData::Title, QVariant(newTitle));

    //this->player->metaData()[QMediaMetaData::Title] = QVariant(newTitle);

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

void MusicPlayer::play()
{
    player->setSource(m_source);
    player->setAudioOutput(this->audioOutput);
    audioOutput->setVolume(20);
    this->player->play();
}

void MusicPlayer::pause()
{
    this->player->pause();
    this->player->setSource(QUrl());
}

void MusicPlayer::check()
{
    qDebug() << "Title: " << this->player->metaData()[QMediaMetaData::Title];
    qDebug() << "Source: " << this->player->source();
    qDebug() << "ERRORS: " << this->player->errorString();
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
