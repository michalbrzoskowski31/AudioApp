#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QAudioOutput>

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

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;


    QString m_title;
    QUrl m_source;

signals:
    void titleChanged();

    void sourceChanged();
};

#endif // MUSICPLAYER_H
