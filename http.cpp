#include "http.h"

Http::Http()
{
    mgr = new QNetworkAccessManager(this);
}

void Http::get(QUrl url) {
    connect(mgr, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished(QNetworkReply*)));
    mgr->get(QNetworkRequest(url));
}

void Http::replyFinished (QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        const char *msg = reply->readAll().toStdString().c_str();
        QString qmsg(msg);
        emit newMessage(qmsg);
    }
    reply->deleteLater();
}
