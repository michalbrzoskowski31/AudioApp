#include "filehandler.h"
#include <QDebug>
#include <QString>


FileHandler::FileHandler(QObject *parent)
    : QObject{parent}
{
    initFolders(exePath);
}

FileHandler::~FileHandler()
{
    if(this->musicFile.exists())
    {
        this->musicFile.close();
        if(QFile::remove(this->musicFile.fileName()))
        {
            qDebug() << "music file deleted";
        }
    }
}

int FileHandler::copyFile(QString filePath)
{
    QFileInfo fileInfo(filePath);
    //QString tempFilePath = QString(this->tempDirPath.absolutePath()) + "/" + fileInfo.fileName();
    musicFilePath = this->tempDirPath.absoluteFilePath(fileInfo.fileName());

    qDebug() << "Temporary file path: " << musicFilePath;

    QFile sourceFile(filePath);
    if(sourceFile.copy(musicFilePath))
    {
        this->musicFile.setFileName(musicFilePath);
        return 0;
    }
    return 1;
}

int FileHandler::initFolders(QDir root)
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

QString FileHandler::getFilePath(QString url)
{
    qDebug() << "URL: " << url;
    QUrl realUrl = QUrl::fromUserInput(url);
    QString filePath = realUrl.toLocalFile();
    qDebug() << "File path: " << filePath;
    qDebug() << QDir::currentPath();

    return filePath;
}

QString FileHandler::getMusicFilePath()
{
    return this->musicFilePath;
}

void FileHandler::check()
{
    qDebug() << "musicFile.fileName(): " << this->musicFile.fileName();
    qDebug() << "musicFilePath: " << this->musicFilePath;
    qDebug() << "tempDirPath: " << this->tempDirPath;
    qDebug() << "exePath: " << this->exePath;
}
