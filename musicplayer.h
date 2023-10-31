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

    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged FINAL);

    QString author() const;
    void setAuthor(const QString &newAuthor);

    Q_INVOKABLE void play();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void onDropUpdateInfo();
    Q_INVOKABLE void check();
    Q_INVOKABLE void initFile();
    Q_INVOKABLE void deleteFile();

    //filehandler begin
    Q_INVOKABLE int copyFile(QString filePath);
    Q_INVOKABLE QString getFilePath(QString url);
    Q_INVOKABLE QString getMusicFilePath();
    //Q_INVOKABLE void check();
    //filehandler end

    // states control begin
    Q_INVOKABLE bool get_file_isDropped() const;
    Q_INVOKABLE void set_file_isDropped(bool set);

    Q_INVOKABLE bool get_screen_isMain() const;
    Q_INVOKABLE void set_screen_isMain(bool set);

    Q_INVOKABLE bool get_player_isPlaying() const;
    Q_INVOKABLE void set_player_isPlaying(bool set);
    // states control end

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    QMediaMetaData metadata;

    int currentDuration;
    int totalDuration;

    QString m_title;
    QUrl m_source;
    QString m_author;

    //filehandler begin
    int initFolders(QDir root);
    void initVariables();
    void getMetaData();
    QDir exePath = QCoreApplication::applicationDirPath();
    QDir tempDirPath;
    QFile musicFile;
    QString musicFilePath;
    //filehandler end

    // states control begin
    bool file_isDropped;
    bool screen_isMain;
    bool player_isPlaying;
    // states control end

signals:
    void titleChanged();

    void sourceChanged();
    void authorChanged();
};

#endif // MUSICPLAYER_H
