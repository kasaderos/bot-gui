#ifndef HTTP_H
#define HTTP_H

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>

class Http : public QObject
{
    Q_OBJECT
    QNetworkAccessManager *mgr;
public:
    Http();

    void get(QUrl url);
signals:
    void newMessage(QString msg);

public slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // HTTP_H
