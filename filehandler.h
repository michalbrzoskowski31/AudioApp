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

class FileHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileHandler(QObject *parent = nullptr);
    ~FileHandler();

    Q_INVOKABLE int copyFile(QString filePath);

private:
    int initFolders(QDir root);
    QDir exePath = QCoreApplication::applicationDirPath();
    QDir tempDirPath;
    QFile musicFile;

signals:

public slots:
    QString getFilePath(QString url);
};

#endif // FILEHANDLER_H
