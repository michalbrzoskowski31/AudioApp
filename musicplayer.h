#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QAudioOutput>

//filehandler begin
#include <QString>
#include <QUrl>
#include <QDir>
#include <QFileInfo>
#include <QCoreApplication>
#include <QFile>
#include <QPointer>
//filehandler end

class MusicPlayer : public QObject
{
    Q_OBJECT
public:
    explicit MusicPlayer(QObject *parent = nullptr);
    ~MusicPlayer();

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL);

    QString title() const;
    void setTitle(const QString &newTitle);

    Q_PROPERTY(QString source READ source WRITE setSource_m NOTIFY sourceChanged FINAL);

    QString source() const;
    void setSource_m(const QString &newSource);


    Q_INVOKABLE void play();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void check();

    //filehandler begin
    Q_INVOKABLE int copyFile(QString filePath);
    Q_INVOKABLE QString getFilePath(QString url);
    Q_INVOKABLE QString getMusicFilePath();
    //Q_INVOKABLE void check();
    //filehandler end

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;


    QString m_title;
    QUrl m_source;

    //filehandler begin
    int initFolders(QDir root);
    QDir exePath = QCoreApplication::applicationDirPath();
    QDir tempDirPath;
    QFile musicFile;
    QString musicFilePath;
    //filehandler end

signals:
    void titleChanged();

    void sourceChanged();
};

#endif // MUSICPLAYER_H
