#include "background.h"
#include "ui_background.h"
#include <QtDebug>
#include<QMovie>
Background::Background(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Background)
{
    ui->setupUi(this);
    index = 0;
    findWorkerW();
    myHook.installHook();
    doubleClick = false;
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Background::resetImg);
    //设置标签和屏幕同大小
    QDesktopWidget desktop;
    QRect deskRect =desktop.screenGeometry(this);
    this->setGeometry(deskRect);
    ui->label->setGeometry(deskRect);
    ui->label->installEventFilter(this);
    myHook.setWinId((HWND) window()->winId());
    myHook.setBkId(this->winId());


}

Background::~Background()
{
    myHook.removeHook();
    delete ui;
}

void Background::findWorkerW()
{
    HWND hd = nullptr;
    HWND hDefView =nullptr;
    hd = FindWindowEx(nullptr, nullptr, L"WorkerW", nullptr);
    //通过遍历找到包含SHELLDLL_DefView的WorkerW
    while ((!hDefView) && hd)
    {
        hDefView = FindWindowEx(hd, nullptr, L"SHELLDLL_DefView", nullptr);
        myHook.workerWID=hd;//得到WorkerW
        hd = FindWindowEx(nullptr, hd, L"WorkerW", nullptr);
    }
}





void Background::togglePlayerStatus(bool flag, QString type)
{
    if(flag){

        if (type == "video")player->play();


    }else {
        if (type == "video")player->pause();

    }
}

bool Background::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG* msg = static_cast<MSG*>(message);
    switch (msg->message) {
    case WM_MOUSELEAVE:
//        qDebug()<<"test";
        return true;//这里是为了去掉本来不该存在的mouseleave消息（邪术）
    case WM_LBUTTONDBLCLK:
//        qDebug()<<"test1";
        return true;
    }

    return false;
}

void Background::initTaskBar()
{
    HWND hd = FindWindowA("Shell_TrayWnd",nullptr);

    swca::ACCENTPOLICY policy;
    swca::WINCOMPATTRDATA attributeData;

    win32 winApi;
    policy.nColor = winApi.GetWindowsThemeColor();
    policy.nFlags = 2;
    policy.nAnimationId = 0;
    attributeData.nAttribute =swca::WindowCompositionAttribute::WCA_ACCENT_POLICY;
    attributeData.pData =&policy;
    attributeData.ulDataSize = sizeof (policy);
    switch (taskPattern) {
    case 1:
        policy.nAccentState = swca::ACCENT::ACCENT_ENABLE_TRANSPARENTGRADIENT;
        winApi.setwinAttribute(hd,&attributeData);
        break;
    case 3:
        policy.nAccentState = swca::ACCENT::ACCENT_ENABLE_GRADIENT;
        winApi.setwinAttribute(hd,&attributeData);
        break;
    case 4:
        policy.nAccentState = swca::ACCENT::ACCENT_ENABLE_BLURBEHIND;
//        qDebug()<<"???";
        winApi.setwinAttribute(hd,&attributeData);
        break;
    }
}


bool Background::eventFilter(QObject *obj, QEvent *event)
{
     if (event->type() == QEvent::MouseButtonDblClick)
     {

         if(!doubleClick){
             SetParent((HWND)this->winId(),myHook.workerWID);
             doubleClick = !doubleClick;
         }else{
             HWND hd = FindWindowA("Progman", nullptr);
             doubleClick = !doubleClick;
             SetParent((HWND)this->winId(), hd);
         }

     }
     return QWidget::eventFilter(obj,event); // 注意这里一定要返回true，表示你要过滤该事件原本的实现
}

void Background::setImgBackground(QStringList srcs ,int second = 60)
{
    if(second != _second){
        timer->stop();
        timer->start(second*1000);
        _second = second;
    }
    imgList = srcs;

//    qDebug()<<srcs.length()<<"         "<<index<<"   "<<srcs.at(index);

    if(srcs.length()>0){
        QPixmap pixmap(srcs.at(index++));
        int with = ui->label->width();
        int height = ui->label->height();
        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
//        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放

        ui->label->setPixmap(fitpixmap);
//        qDebug()<<ui->label->text();
        if(!timer->isActive()){
            timer->start(_second*1000);
        }
        if(index >= srcs.length()) index = 0;
    }

    //ui->label->show();
}

void Background::setGifBackground(QString src)
{
    QMovie *gif = new QMovie;
    gif->setFileName(src);
    gif->setScaledSize(ui->label->size());
    ui->label->setMovie(gif);
    gif->start();
}

void Background::setVideoBackground(QStringList paths)
{

    QDesktopWidget desktop;
    QRect deskRect =desktop.screenGeometry(this);
    player = new QMediaPlayer(this);
    playerList = new QMediaPlaylist(this);
    foreach (QString value, paths) {
        playerList->addMedia(QUrl::fromLocalFile(value));
    }

    player->setPlaylist(playerList);
    vWiget = new QVideoWidget();
    vWiget->setParent(this);
    qDebug()<<deskRect;
    vWiget->setGeometry(deskRect);
    //vWiget->showFullScreen();
    /*

    设置播放视频的比例

    enum AspectRatioMode {

        IgnoreAspectRatio,

        KeepAspectRatio,

        KeepAspectRatioByExpanding

    };

     */
    vWiget->setAspectRatioMode(Qt::IgnoreAspectRatio);
    player->setVideoOutput(vWiget);
    player->play();
    vWiget->installEventFilter(this);

}

void Background::resetImg()
{
    setImgBackground(imgList,_second);

}

void Background::setCfg(Config *_cfg)
{
    myHook.setConfig(_cfg);
    if(_cfg->readCfg("global/pattern").toString() == "video")
        player->setVolume(_cfg->readCfg("video/volume").toInt());
    taskPattern = _cfg->readCfg("taskBar/taskBarPattern").toInt();
}
