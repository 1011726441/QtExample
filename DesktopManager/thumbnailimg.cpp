#include "thumbnailimg.h"
#include <QDebug>
#include <QThread>
void ThumbnailImg::sltOnReadOutput()
{

}

void ThumbnailImg::onFinished(int, QProcess::ExitStatus)
{

}

ThumbnailImg::~ThumbnailImg()
{
 qDebug()<<"thread destory";
}

ThumbnailImg::ThumbnailImg()
{
    isFinished = false;
}

void ThumbnailImg::run()
{

    myProcess = new QProcess();
    QRegExp re(".mp4");
    myProcess->setProcessChannelMode(QProcess::MergedChannels);
    QString cmd = QString(QApplication::applicationDirPath()+ "/bin/ffmpeg.exe -i %1 -ss 1 -f image2 %2")
                      .arg(path)
                      .arg("./temp/"+path.split("/").last().replace(re,".jpg").simplified())
        ;

    myProcess->start(cmd);
    myProcess->waitForStarted();
    myProcess->write("y\r\n");
    //myProcess->waitForFinished(3000);
    myProcess->waitForFinished(-1);
    myProcess->close();
    myProcess->deleteLater();
    QString str = "/../temp/"+path.split("/").last().replace(re,".jpg");
    emit returnPath(str);
    return;
}

void ThumbnailImg::setPath(QString _path)
{
    this->path = _path;
}

