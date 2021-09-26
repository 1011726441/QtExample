#include "download.h"



Download::Download(QObject *parent)
{
}

void Download::setIndex(int index)
{
    this->index = index;
    this->now = 0;
}

void Download::start()
{
    //if(error) qDebug()<<"restart::  "<<index;
    error = false;
    reply = manager.get(request);
    connect(reply,&QNetworkReply::readyRead,this,&Download::readyRead);
    connect(reply,&QNetworkReply::finished,this,&Download::Finshed);
    connect(reply,&QNetworkReply::downloadProgress,this,&Download::doProcessDownloadProgress);
    connect(reply,QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), this,&Download::doProcessError);
}

void Download::setRange(qint64 start, qint64 end)
{
    this->_start = start;
    this->_end = end;
    qDebug()<<"Index:  "<<index<<"start:  "<<_start<<"end:  "<<_end;
    QString range = QString("bytes=%1-%2").arg(_start).arg(_end);
    request.setRawHeader("Range", range.toLocal8Bit());
}

void Download::setHeader(QJsonObject)
{

}

void Download::setUrl(QString _url)
{
    this->url = QUrl(_url);
    request.setUrl(this->url);
}

void Download::readyRead()
{
    while (!this->reply->atEnd()) {
        QByteArray data = reply->readAll();
        //qDebug()<<"index:  "<<index<<endl;
        file->seek(_start+now);
        file->write(data);
        now+=data.size();
        emit processChage(index,now);
    }
}

void Download::Finshed()
{
    //
    file->flush();
    //qDebug()<<"Finshed::   ";

    disconnect(reply,&QNetworkReply::readyRead,this,&Download::readyRead);
    disconnect(reply,&QNetworkReply::finished,this,&Download::Finshed);
    disconnect(reply,&QNetworkReply::downloadProgress,this,&Download::doProcessDownloadProgress);
    disconnect(reply,QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), this,&Download::doProcessError);
    reply = nullptr;
    if(error){
        this->start();
    }
    if (!error && now>=(_end-_start)){
        file = nullptr;
        qDebug()<<"Finshed::   "<<now<<"isError::  "<<error<<"index::  "<<index;
        emit processChage(index,now);
        emit finshedThread();
        reply->deleteLater();
        this->deleteLater();
    }

}

void Download::doProcessDownloadProgress(qint64 now, qint64 total)
{
    emit processChage(index,now);

    //qDebug()<<now*100.0/total<<endl;
}

void Download::doProcessError(QNetworkReply::NetworkError code)
{
    //qDebug()<<"error::  "<<code;
    this->now = 0;
    error=true;

}

void Download::setFile(QFile *file)
{
    this->file = file;
}
