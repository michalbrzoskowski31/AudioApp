#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "musicplayer.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<MusicPlayer> ("MusicPlayer", 1, 0, "MusicPlayer");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qml/ui/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
