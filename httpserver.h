#ifndef HTTPSERVER_H
#define HTTPSERVER_H
#include <qhttpserver.h>
#include <qhttprequest.h>
#include <qhttpresponse.h>
#include <QObject>
#include <QQmlParserStatus>

class HttpServer : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
public:
    int port;
    QHttpServer *server;
    HttpServer();
    void classBegin();
    void componentComplete();
    void listen(int port);

signals:
    void started();
    void newMessageReceived(const QString msg);
    void openResourceFailed(const QString & error);

public slots:
    void get_data(const QByteArray &data);
    void handler(QHttpRequest *req, QHttpResponse *resp);
};

#endif // HTTPSERVER_H
