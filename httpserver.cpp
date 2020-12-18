#include "httpserver.h"

HttpServer::HttpServer()
{
    server = new QHttpServer;
    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
            this, SLOT(handler(QHttpRequest*, QHttpResponse*)));
    QHostAddress addr("127.0.0.1");
    port = 8080;
    server->listen(addr, port);
}

void HttpServer::classBegin(){}

void HttpServer::componentComplete() {
    if (port) {
        emit newMessageReceived("started " + QString::number(port));
    } else {
        emit newMessageReceived("server not started");
    }
}

void HttpServer::handler(QHttpRequest *req, QHttpResponse *resp){
    connect(req, SIGNAL(data(const QByteArray &)),
            this, SLOT(get_data(const QByteArray &)));
    resp->writeHead(resp->STATUS_OK);
}

void HttpServer::get_data(const QByteArray &data) {
    //qDebug() << "received " << data;
    emit newMessageReceived(QString(data));
}


