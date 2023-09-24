#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QDir>
#include <QFileInfo>
#include <QCoreApplication>
#include <QFile>
#include <QPointer>
#include <QMediaPlayer>
#include <QMediaMetaData>
//#include <QMediaPlayerControl>

class FileHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileHandler(QObject *parent = nullptr);
    ~FileHandler();

    Q_INVOKABLE int copyFile(QString filePath);
    Q_INVOKABLE QString getFilePath(QString url);
    Q_INVOKABLE QString getMusicFilePath();
    Q_INVOKABLE void check();

private:
    int initFolders(QDir root);
    QDir exePath = QCoreApplication::applicationDirPath();
    QDir tempDirPath;
    QFile musicFile;
    QString musicFilePath;

signals:


public slots:

};

#endif // FILEHANDLER_H
