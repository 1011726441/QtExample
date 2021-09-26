#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    HANDLE m_hMutex  =  CreateMutex(nullptr, FALSE,  L"fortest_abc123" );
    //  检查错误代码
    if  (GetLastError()  ==  ERROR_ALREADY_EXISTS)  {
        //  如果已有互斥量存在则释放句柄并复位互斥量
        CloseHandle(m_hMutex);
        m_hMutex  =  nullptr;
        //  程序退出
        exit(1);
    }



    this->hide();
    ui->setupUi(this);
    playerStatus = true;
    config = new Config();
    addImgsBtn = nullptr;
    background = nullptr;
    ui->baseSettingLabel->installEventFilter(this);
    ui->videoSettingLabel->installEventFilter(this);
    ui->gifSettingLabel->installEventFilter(this);
    ui->imgSettingLabel->installEventFilter(this);
    ui->taskSettingLabel->installEventFilter(this);
    connect(this,&MainWindow::reDrawViewDisplay,this,&MainWindow::getImgFinished);
    //getImgThread = new QThread(this);
    config->writeCfg("global/running",true);
    setWindowTitle("灯泡桌面");

    loadCfg();
    initTray();

    this->close();
}

MainWindow::~MainWindow() {
    delete ui;
    background->deleteLater();
    config->writeCfg("global/running",false);
}

void MainWindow::setting(bool)
{
    this->show();
}

void MainWindow::on_activatedSysTrayIcon(
    QSystemTrayIcon::ActivationReason reason) {
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        //单击托盘图标
        break;
    case QSystemTrayIcon::DoubleClick:
        //双击托盘图标
        //双击后显示主程序窗口
        this->show();
        break;
    default:
        break;
    }
}


void MainWindow::initBk()
{
    if(background != nullptr){
        qDebug()<<"delaterlate";
        background->deleteLater();
    }
    background = new Background();

    qDebug()<<background;

    workerWID=win32.GetWorkerW();

    background->setWindowFlags(Qt::Dialog);
    background->setWindowFlags(Qt::FramelessWindowHint);
    HWND hd = FindWindowA("Progman", nullptr);
    SetParent((HWND)background->winId(), hd);
    if(pattern=="video"){
        background->setVideoBackground(videoPaths);
    }else if (pattern == "gif") {

        background->setGifBackground(gifPath);
    }else if (pattern == "img"){
        background->setImgBackground(imgPaths,config->readCfg("img/second").toInt());
    }

    background->showFullScreen();
    qDebug()<<"显示窗口";

}

void MainWindow::initTray()
{
    this->trayIcon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/img/myIcon");
    this->trayIcon->setIcon(icon);
    this->trayIcon->setToolTip(tr("Bulb's Desktop Manager"));
    trayIcon->setObjectName("minManager");
    myMenu = new QMenu(this);

    playerAct = new QAction("暂停视频");
    myMenu->addAction(playerAct);



    settingAct = new QAction("设置");
    myMenu->addAction(settingAct);

    exitMe = new QAction("退出");
    myMenu->addAction(exitMe);

    connect(playerAct,&QAction::triggered,this,&MainWindow::palyerToggle);
    connect(settingAct,&QAction::triggered,this,&MainWindow::setting);
    connect(exitMe,&QAction::triggered,this,&MainWindow::quit);


    trayIcon->setContextMenu(myMenu);
    this->trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::loadCfg()
{
    pattern = config->readCfg("global/pattern").toString();
    QString path;
    path = config->readCfg("video/src").toString();

    videoPaths = path.split("|||");
    videoPaths.pop_back();
    videoPaths = videoPaths.toSet().toList();
    gifPath = config->readCfg("gif/src").toString();
    path = config->readCfg("img/src").toString();

    imgPaths = path.split("|||");
    imgPaths.pop_back();
    imgPaths = imgPaths.toSet().toList();

    ui->volume->setValue(config->readCfg("video/volume").toInt());
    qDebug()<<"simpleExit"<<config->readCfg("simpleExit").toBool();
    if(config->readCfg("global/simpleExit").toBool()){
        ui->isSimpleExit->setChecked(true);
    }


    if(pattern == "video"){
        ui->patternBox->setCurrentIndex(0);
    }else if(pattern == "gif"){
        ui->patternBox->setCurrentIndex(1);
        ui->lineEdit->setText(gifPath);
    }else if(pattern == "img"){
        ui->patternBox->setCurrentIndex(2);
    }

    foreach (QString value, videoPaths) {
        thumbail = new ThumbnailImg();
        thumbail->setPath(value);

        //connect(thumbail,&ThumbnailImg::returnPath,this,&MainWindow::getImgFinished);
        connect(thumbail,&QThread::finished,thumbail,&ThumbnailImg::deleteLater);
        threadList.append(thumbail);
        thumbail->start();
    }
    bool isThreadPoolFinished  = false;
    while (!isThreadPoolFinished) {
        isThreadPoolFinished = true;
        for (int i = 0;i<threadList.length();i++) {
            if(threadList.at(i)->isRunning()) isThreadPoolFinished = false;
            else threadList.removeAt(i);
        }
    }
    threadList.clear();
    getImgFinished("");
    drawImgDisplay();



    initBk();
    background->setCfg(config);
    qDebug()<<"重载背景窗口";
    background->initTaskBar();
}

void MainWindow::drawImgDisplay()
{
    foreach (QLabel *value, imgs) {
        value->deleteLater();
    }
    imgs.clear();
    if (addImgsBtn!=nullptr){
        //disconnect(addImgsBtn,&QPushButton::clicked,this,&MainWindow::onAddImgsBtnClick);
        addImgsBtn->deleteLater();
    }
    short int row = 0;
    short int column = 0;
    ui->showImgs->setRowStretch(0,3);
    ui->showImgs->setColumnStretch(1,1);
    short int i = 0;
    foreach (QString value, imgPaths) {
        if (column>=4){

            row++;
            column = 0;
        }
        QLabel *img = new QLabel();
        img->setObjectName("imgDisplay"+QString::number(i++));
        img->installEventFilter(this);
        QPixmap pixmap(value);
        QSize size(64,64);
        img->setMaximumSize(size);
        int with = img->width();
        int height = img->height();
        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        img->setPixmap(fitpixmap);

        ui->showImgs->addWidget(img,row,column);


        imgs.append(img);
        column ++;
    }
    if (column>=4){

        row++;
        column = 0;
    }

    addImgsBtn = new QPushButton();
    addImgsBtn->setMinimumSize(64,64);
    addImgsBtn->setText("添加图片");
    ui->showImgs->addWidget(addImgsBtn);
    connect(addImgsBtn,&QPushButton::clicked,this,&MainWindow::onAddImgsBtnClick);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if(!config->readCfg("global/simpleExit").toBool())
        e->accept();
    else
        QApplication::quit();
}
void MainWindow::getImgFinished(QString path)
{

    qDebug()<<"finished";

    foreach (QLabel *value, videos) {
        value->deleteLater();
    }
    videos.clear();
    short int row = 0;
    short int column = 0;
    ui->showVideos->setRowStretch(0,3);
    ui->showVideos->setColumnStretch(1,1);
    short int i = 0;
    foreach (QString value, videoPaths) {
        if (column>=4){

            row++;
            column = 0;
        }
        QLabel *video = new QLabel();
        video->setObjectName("videoDisplay"+QString::number(i++));
        video->installEventFilter(this);
        QRegExp re(".mp4");
        qDebug()<<"/temp/"+value.split("/").last().replace(re,".jpg").simplified();
        QPixmap pixmap("./temp/"+value.split("/").last().replace(re,".jpg").simplified());
        QSize size(64,64);
        video->setMaximumSize(size);
        int with = video->width();
        int height = video->height();
        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        video->setPixmap(fitpixmap);

        ui->showVideos->addWidget(video,row,column);
        qDebug()<<ui->showVideos->children();
        videos.append(video);
        column ++;
    }


}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{

    if(obj->objectName().contains("imgDisplay",Qt::CaseSensitive) and event->type() == QEvent::MouseButtonPress){
        imgPaths.removeAt(obj->objectName().remove(0,10).toInt());
        drawImgDisplay();

    }else if(obj->objectName().contains("videoDisplay",Qt::CaseSensitive) and event->type() == QEvent::MouseButtonPress){
        videoPaths.removeAt(obj->objectName().remove(0,12).toInt());

        emit reDrawViewDisplay("");

    }else if(obj->objectName() == "baseSettingLabel" and event->type() == QEvent::MouseButtonPress){

        ui->scrollArea->verticalScrollBar()->setValue(ui->basePoint->y());

    }else if(obj->objectName() == "videoSettingLabel" and event->type() == QEvent::MouseButtonPress){/*记得加active颜色*/
        ui->scrollArea->verticalScrollBar()->setValue(ui->videoPoint->y());
    }else if(obj->objectName() == "gifSettingLabel" and event->type() == QEvent::MouseButtonPress){
        ui->scrollArea->verticalScrollBar()->setValue(ui->gifPoint->y());
    }else if(obj->objectName() == "imgSettingLabel" and event->type() == QEvent::MouseButtonPress){
        ui->scrollArea->verticalScrollBar()->setValue(ui->imgPoint->y());
    }else if(obj->objectName() == "taskSettingLabel" and event->type() == QEvent::MouseButtonPress){
        ui->scrollArea->verticalScrollBar()->setValue(ui->taskPoint->y());
    }


}
void MainWindow::on_cancel_clicked()
{
    this->close();
}

void MainWindow::on_addVideo_clicked()
{
    videoPaths.append(
        QFileDialog::getOpenFileNames(this,"请选择图片文件",nullptr,"Mp4 Files(*.mp4);;AVI Files(*.avi)",nullptr,nullptr)
        );
}

void MainWindow::on_addGif_clicked()
{

    gifPath = QFileDialog::getOpenFileName(this,"请选择gif文件",nullptr,"(*.gif)",nullptr,nullptr);

}

void MainWindow::on_apply_clicked()
{
    config->writeCfg("global/autoRun",ui->isAutoRun->isChecked());
    config->writeCfg("global/simpleExit",ui->isSimpleExit->isChecked());
    switch (ui->patternBox->currentIndex()) {
    case 0:
        config->writeCfg("global/pattern","video");
        break;
    case 1:
        config->writeCfg("global/pattern","gif");
        break;
    case 2:
        config->writeCfg("global/pattern","img");
        break;
    }

    if(ui->isStop->isChecked())config->writeCfg("video/volume",0);
    QString path;
    videoPaths = videoPaths.toSet().toList();
    foreach (QString value, videoPaths) {
        path+=value+"|||";
    }
    config->writeCfg("video/src",path);
    config->writeCfg("video/volume",ui->volume->value());
    config->writeCfg("gif/src",gifPath);
    path = "";
    imgPaths = imgPaths.toSet().toList();
    foreach (QString value, imgPaths) {
        path+=value+"|||";
    }
    config->writeCfg("img/src",path);
    config->writeCfg("img/second",ui->intervalBox->value());
    config->writeCfg("taskBar/taskBarPattern",ui->taskBarPattern->currentIndex()+1);
    loadCfg();

}


void MainWindow::onAddImgsBtnClick()
{
    imgPaths.append(
        QFileDialog::getOpenFileNames(this,"请选择图片文件",nullptr,"JPEG Files(*.jpg);;PNG Files(*.png);;PGM Files(*.pgm)",NULL,NULL)
        );
    drawImgDisplay();

}
void MainWindow::quit()
{
    this->trayIcon->hide();
    QApplication::quit();
}


void MainWindow::palyerToggle(bool flag)
{
    playerStatus = !(bool) playerStatus;
    if(playerStatus==0){
        playerAct->setText("开始视频");
    }else{
        playerAct->setText("暂停视频");
    }
    background->togglePlayerStatus(playerStatus,pattern);

}

void MainWindow::on_volume_valueChanged(int value)
{
    ui->vloumeValue->setText(QString("%1 %").arg(QString::number(ui->volume->value())));
}

