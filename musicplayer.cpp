#include "musicplayer.h"
#include <QDebug>


MusicPlayer::MusicPlayer(QObject *parent)
    : QObject{parent}
{
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
}

MusicPlayer::~MusicPlayer()
{
    //this->player->pause();
    //this->player->setSource(QUrl());
    delete this->player;
    delete this->audioOutput;
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
