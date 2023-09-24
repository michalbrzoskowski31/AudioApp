#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "filehandler.h"
#include "musicplayer.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<FileHandler> ("FileHandler", 1, 0, "File");
    qmlRegisterType<MusicPlayer> ("MusicPlayer", 1, 0, "Player");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qml/ui/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
