#include "httpserver.h"

HttpServer::HttpServer()
{
    server = new QHttpServer;
    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
            this, SLOT(handler(QHttpRequest*, QHttpResponse*)));
    // let's go

}

void HttpServer::listen(int port) {
    QHostAddress addr("127.0.0.1");
    server->listen(addr, port);
    emit started();
}

void HttpServer::handler(QHttpRequest *req, QHttpResponse *resp){

}


