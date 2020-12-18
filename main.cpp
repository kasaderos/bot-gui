#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "httpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<HttpServer>("Server", 1,0, "HttpServer");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    //HttpServer *server = qobject_cast<>;
    // server.listen(8080);
    //emit server.newMessageReceived("Message");
    return app.exec();
}
