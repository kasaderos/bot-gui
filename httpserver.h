#ifndef HTTPSERVER_H
#define HTTPSERVER_H
#include <qhttpserver.h>
#include <qhttprequest.h>
#include <qhttpresponse.h>
#include <QObject>

class HttpServer : QObject
{
    Q_OBJECT
public:
    QHttpServer *server;
    HttpServer();
    void listen(int port);

signals:
    void started();

public slots:
    void handler(QHttpRequest *req, QHttpResponse *resp);

};

#endif // HTTPSERVER_H
