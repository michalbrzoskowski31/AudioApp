#include "filehandler.h"
#include <QDebug>


FileHandler::FileHandler(QObject *parent)
    : QObject{parent}
{
    initFolders(exePath);
}

FileHandler::~FileHandler()
{

}

int FileHandler::copyFile(QString filePath)
{
    QFileInfo fileInfo(filePath);
    //QString tempFilePath = QString(this->tempDirPath.absolutePath()) + "/" + fileInfo.fileName();
    QString tempFilePath = this->tempDirPath.absoluteFilePath(fileInfo.fileName());

    qDebug() << "Temporary file path: " << tempFilePath;

    QFile sourceFile(filePath);
    if(sourceFile.copy(tempFilePath))
    {
        this->musicFile.setFileName(tempFilePath);
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


