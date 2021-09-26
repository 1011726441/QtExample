#include "baiduVoice.h"
#include <QtDebug>
BaiduVoice::BaiduVoice()
{
    isInit =false;
    this->token = "";
    langs<<"zh"<<"en";
    myfile = new QFile(this);
    player = new QMediaPlayer();
    this->request = QNetworkRequest();
    this->manger = new QNetworkAccessManager();
    clientId = "whZNy4FraIuwQX2TG1RD2cfS";
    clienKey = "BdDqCt0uHGjSfYzZXC3YNpQkc0OaW3Ym";
    this->request.setUrl(QUrl(QString("http://openapi.baidu.com/oauth/2.0/token?grant_type=%1&client_id=%2&client_secret=%3")
                              .arg("client_credentials")
                              .arg(clientId)
                              .arg(clienKey)
                              ));
    this->reply = manger->get(request);
    connect(player,&QMediaPlayer::stateChanged,this,&BaiduVoice::playStateChanged);
    connect(reply,&QNetworkReply::readyRead,this,&BaiduVoice::doProcessReadyRead);                //可读
    connect(manger,&QNetworkAccessManager::finished,this,&BaiduVoice::doProcessFinished);                  //结束
    connect(reply,&QNetworkReply::downloadProgress,this,&BaiduVoice::doProcessDownloadProgress);  //大小
    connect(reply,QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), this,&BaiduVoice::doProcessError);         //异常
    connect(this,&BaiduVoice::downloadFinshed,this,&BaiduVoice::playMp3);
}

void BaiduVoice::voicePause()
{
    player->pause();
}

void BaiduVoice::voiceStop()
{
    player->stop();
}

void BaiduVoice::voiceResume()
{
    player->play();
}


void BaiduVoice::playMp3()
{

    player->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+"/data.mp3"));
    player->play();
}

void BaiduVoice::doProcessReadyRead()
{

    while(!reply->atEnd())
    {
        QByteArray ba = reply->readAll();
        if(token=="" || token == nullptr){
            QJsonDocument json = QJsonDocument::fromJson(ba) ;
            QJsonObject jsonObj= json.object();
            this->token = jsonObj.value("access_token").toString();

        }else{
            isInit = true;
            myfile->write(ba);
        }



    }


}

void BaiduVoice::doProcessFinished()
{
    if((token!="" || token != nullptr) && isInit==true){
        myfile->close();
        emit downloadFinshed();
    }
}

void BaiduVoice::doProcessDownloadProgress(qint64, qint64)
{

}

void BaiduVoice::doProcessError(QNetworkReply::NetworkError code)
{

}

void BaiduVoice::playStateChanged(int state)
{
    switch (state) {
    case 0:
        emit stateChange(state);
        player->setMedia(QUrl(""));
        break;
    case  1:
        emit stateChange(state);
        break;
    case 2:
        emit stateChange(state);
        break;


    }
}
void BaiduVoice::say(float volume, float rate, int voiceId, int lan, QString content)
{

    myfile->setFileName(QCoreApplication::applicationDirPath()+"/data.mp3");
    myfile->open(QIODevice::ReadWrite|QIODevice::Truncate);

    request.setUrl(QUrl(
                       QString("http://tsn.baidu.com/text2audio?tok=%1&cuid=%2&ctp=%3&lan=%4&tex=%5&vol=%6&spd=%7&per=%8")
                       .arg(token)
                       .arg("partCCreator")
                       .arg("1")
                       .arg(langs[lan])
                       .arg(content)
                       .arg(QString::number(volume))
                       .arg(QString::number(rate))
                       .arg(QString::number(voiceId))
                       ));

    this->reply = manger->get(request);
    connect(reply,&QNetworkReply::readyRead,this,&BaiduVoice::doProcessReadyRead);
}

