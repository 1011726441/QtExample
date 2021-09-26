#ifndef BAIDUVOICE_H
#define BAIDUVOICE_H
#include <QtNetwork>
#include <QMediaPlayer>
#include <QApplication>
class BaiduVoice :public QObject
{
    Q_OBJECT
public:
    BaiduVoice();
    void voicePause();
    void voiceStop();
    void voiceResume();
private slots:
    void playMp3();
    void doProcessReadyRead();
    void doProcessFinished();
    void doProcessDownloadProgress(qint64,qint64);
    void doProcessError(QNetworkReply::NetworkError code);
    void playStateChanged(int);
signals:
    void receToken();
    void downloadFinshed();
    void stateChange(int);
    //    void Playing
public:
    void say(float volume,float rate,int voiceId,int lan,QString content);
protected:
    QNetworkReply *reply;
    QNetworkRequest request;
    QNetworkAccessManager *manger;
    QString apiUrl,token,clientId,clienKey;
    QStringList langs;
    QMediaPlayer *player;
    QFile *myfile;
    bool isInit;
    void play();

};

#endif // BAIDUVOICE_H
