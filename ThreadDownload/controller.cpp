#include "controller.h"

Controller::Controller()
{
    download = new Download(this);
    file = new QFile(this);
    QFileDialog dialog;
    dialog.setWindowTitle("选择下载目录");
    path = dialog.getExistingDirectory();
    finshedCount = 0;
}

Controller::~Controller()
{

}

void Controller::startTask()
{

    qint64 _end=0;
    qint64 _start=0;
    file->setFileName(path+"/"+info.fileName);
    file->open(QFileDevice::WriteOnly);
    for(int i=0; i<this->ThreadCount; i++){
            //先算出每段的开头和结尾（HTTP协议所需要的信息）
        _start = info.fileSzie*i/this->ThreadCount;
        _end = info.fileSzie*(i+1)/this->ThreadCount;
        if( i != 0 )
            _start--;
        process.append(0);
        Download *download = new Download(this);
        connect(download,&Download::finshedThread,this,&Controller::addFinshedCount);
        connect(download,&Download::processChage,this,&Controller::onProcessChange);
        download->setUrl(this->url.toString());
        download->setIndex(i);
        download->setRange(_start,_end);
        download->setFile(file);
        download->start();
    }
}

void Controller::setThreadCount(int count)
{
    this->ThreadCount = count;
}

void Controller::setUrl(QUrl url)
{
    this->url = url;
    info = Controller::GetFileSize(this->url);
}



fileInfo Controller::GetFileSize(QUrl url)
{
    QNetworkAccessManager manager;
    qDebug() << ";Getting the file size...";
    QEventLoop loop;
    //发出请求，获取目标地址的头部信息
    QNetworkReply *reply = manager.head(QNetworkRequest(url));
    connect(reply,SIGNAL(finished()),  & loop, SLOT(quit()), Qt::DirectConnection);
    loop.exec();
    QVariant var = reply->header(QNetworkRequest::ContentLengthHeader);
    QString strDisposition = reply->rawHeader("Content-Disposition");
    int index = strDisposition.indexOf("filename=");
    QString fileName = strDisposition.mid(index + 9);
    if (fileName.isEmpty())
    {
        QFileInfo fileInfo(url.path());
        fileName += fileInfo.fileName();
    }
    delete reply;
    qint64 size = var.toLongLong();
    fileInfo _info;
    _info.fileName =fileName;
    _info.fileSzie = size;
    qDebug() << "The file size is: "<< size<<"The file name is: "<< fileName;
    return _info;
}

void Controller::addFinshedCount()
{
    this->finshedCount++;
    if(finshedCount == ThreadCount){
        this->file->close();
        emit taskFinshed();
    }
}

void Controller::onProcessChange(int index, qint64 now)
{
    process.replace(index,now);
    qint64 totalNow=0;
    for(int i=0; i<process.size(); ++i){
        totalNow+=process.at(i);
    }

    emit percentageCHanged((totalNow*100.0/(info.fileSzie*1.0))*1.0);
}
