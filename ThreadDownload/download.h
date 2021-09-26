#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QObject>
#include <QUrl>
#include <QFile>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QtDebug>
class Download : public QObject
{
    Q_OBJECT
public:
    explicit Download(QObject *parent = nullptr);
    void setIndex(int index);
    void start();
    void setRange(qint64 start,qint64 end);
    void setHeader(QJsonObject);
    void setUrl(QString url);
    void setFile(QFile *file);

private:
    int index;
    QUrl url;
    qint64 _start,_end,now;
    QJsonObject header;
    QNetworkAccessManager manager;
    QNetworkRequest request;
    QNetworkReply *reply;
    QFile *file;
    bool error;

signals:
    void finshedThread();
    void processChage(int index,qint64 now);
public slots:
    void readyRead();
    void Finshed();
    void doProcessDownloadProgress(qint64,qint64);
    void doProcessError(QNetworkReply::NetworkError code);
};

#endif // DOWNLOAD_H
