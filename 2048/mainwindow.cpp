#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    timer = new QTimer(this); //this 为parent类, 表示当前窗口

    connect(timer, &QTimer::timeout, this, &MainWindow::addTimeNum); // SLOT填入一个槽函数

    timer->start(1000);


    resetGame();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyReleaseEvent(QKeyEvent *ke)
{
    bool isMoved = false;
    switch (ke->key()) {
        case Qt::Key_Up:{
            isMoved = upClicked(table);
        }break;
        case Qt::Key_Down:{
            isMoved = downClicked(table);
        }break;
        case Qt::Key_Left:{
            isMoved = leftClicked(table);
        }break;
        case Qt::Key_Right:{
            isMoved = rightClicked(table);
        }break;
    }
    if(isMoved){
        updateItems();
    }
    else{
        if(isFinshed()){
            int isOk = QMessageBox::information(this,"游戏失败","游戏失败，是否重来",QMessageBox::No|QMessageBox::Ok);
            if(isOk == QMessageBox::Ok){
                resetGame();
            }
        }
    }
}

bool MainWindow::upClicked(int* _table)
{
    bool isMoved = false;
    for (int i = 0;i<3; i++) {
        if(_table[i] == _table[i+3] && _table[i]!=-1){
            _table[i] +=_table[i+3];
            _table[i+3] = -1;
            isMoved = true;
        }
        else if(_table[i]==-1 && _table[i+3] != -1){
            _table[i] = _table[i+3];
            _table[i+3] = -1;
            isMoved = true;
        }
        if(_table[i+6] == _table[i+3] && _table[i+3]!=-1){
            _table[i+3] +=_table[i+6];
            _table[i+6] = -1;
            isMoved = true;
        }
        else if(_table[i]==-1 && _table[i+3]==-1){
            _table[i] = _table[i+6];
            _table[i+6] = -1;
            isMoved = true;
        }
        else if(_table[i+3]==-1 && _table[i+6]!=-1){
            qDebug()<<_table[i+6];
            _table[i+3] = _table[i+6];
            _table[i+6] = -1;
            isMoved = true;
        }
        if(_table[i] == _table[i+3] && _table[i]!=-1){
            _table[i] +=_table[i+3];
            _table[i+3] = -1;
            isMoved = true;
        }
    }
    return isMoved;

}

bool MainWindow::downClicked(int* _table)
{
    bool isMoved = false;
    for (int i = 0;i<3; i++) {


        if(_table[i+6] == _table[i+3] && _table[i+6]!=-1){
            _table[i+6] +=_table[i+3];
            _table[i+3] = -1;
            isMoved = true;
        }
        else if(_table[i+6]==-1 && _table[i+3]!=-1){
            _table[i+6] = _table[i+3];
            _table[i+3] = -1;
            isMoved = true;
        }
        if(_table[i] == _table[i+3] && _table[i+3]!=-1){
            _table[i+3] +=_table[i];
            _table[i] = -1;
            isMoved = true;
        }
        else if(_table[i+6]==-1 && _table[i+3]==-1){
            _table[i+6] = _table[i];
            _table[i] = -1;
            isMoved = true;
        }
        else if(_table[i+3]==-1 && _table[i]!=-1){
            _table[i+3] = _table[i];
            _table[i] = -1;
            isMoved = true;
        }
        if(_table[i+6] == _table[i+3] && _table[i+6]!=-1){
            _table[i+6] +=table[i+3];
            _table[i+3] = -1;
            isMoved = true;
        }

    }
    return  isMoved;
}

bool MainWindow::leftClicked(int* _table)
{
    bool isMoved = false;
    for (int i = 0;i<9; i+=3) {
        if(_table[i] == _table[i+1] && _table[i]!=-1){
            _table[i] +=_table[i+1];
            _table[i+1] = -1;
            isMoved = true;
        }
        else if(_table[i]==-1 && _table[i+1] != -1){
            _table[i] = _table[i+1];
            _table[i+1] = -1;
            isMoved = true;
        }
        if(_table[i+2] == _table[i+1] && _table[i+1]!=-1){
            _table[i+1] +=_table[i+2];
            _table[i+2] = -1;
            isMoved = true;
        }
        else if(_table[i] == -1 && _table[i+1] == -1){
            _table[i]=_table[i+2];
            _table[i+2] = -1;
            isMoved = true;
        }
        else if(_table[i+1]==-1 && _table[i+2] != -1){
            _table[i+1] = _table[i+2];
            _table[i+2] = -1;
            isMoved = true;
        }
        if(_table[i] == _table[i+1] && _table[i]!=-1){
            _table[i] +=_table[i+1];
            _table[i+1] = -1;
            isMoved = true;
        }
    }
    return isMoved;
}

bool MainWindow::rightClicked(int* _table)
{
    bool isMoved = false;
    for (int i = 0;i<9; i+=3) {


        if(_table[i+2] == _table[i+1] && _table[i+2]!=-1){
            _table[i+2] +=_table[i+1];
            _table[i+1] = -1;
            isMoved = true;
        }
        else if(_table[i+2]==-1  && _table[i+1] != -1){
            _table[i+2] = _table[i+1];
            _table[i+1] = -1;
            isMoved = true;
        }
        if(_table[i] == _table[i+1] && _table[i+1]!=-1){
            _table[i+1] +=_table[i];
            _table[i] = -1;
            isMoved = true;
        }
        else if(_table[i+2] == -1 && _table[i+1] == -1) {
            _table[i+2]=_table[i];
            _table[i] = -1;
            isMoved = true;
        }
        else if(_table[i+1]==-1  && _table[i] != -1){
            _table[i+1] = _table[i];
            _table[i] = -1;
            isMoved = true;
        }
        if(_table[i+2] == _table[i+1] && _table[i+2]!=-1){
            _table[i+2] +=_table[i+1];
            _table[i+1] = -1;
            isMoved = true;
        }

    }
    return isMoved;
}

bool MainWindow::isFinshed()
{
    int cpyTable[9] ={-1};
    for (int i = 0;i <9; i++) {
        cpyTable[i] = table[i];
    }
    if(upClicked(cpyTable) || downClicked(cpyTable) || rightClicked(cpyTable) || leftClicked(cpyTable))
        return false;
    return true;
}

void MainWindow::updateItems()
{
    if(!randItem()) QMessageBox::information(this,"游戏结束","你失败了");
    QLabel *item ;
    for (int i = 0;i<9;i++) {
        item = this->findChild<QLabel*>("item"+QString::number(i+1));
        if(table[i] == -1){
            item->setText("");
            continue;
        }
        item->setNum(table[i]);
    }
    calculateScore();
    ui->scoreLabel->setNum(score);
    setStyle();
}

bool MainWindow::randItem()
{
    int randPlace = qrand()%9;
    bool isFinshed = true;
    while (table[randPlace] != -1 ) {
        for (int i = 0;i<9;i++) {
            if(table[i] == -1){

                isFinshed = false;
            }
        }
        if(isFinshed) return false;
        randPlace = qrand()%9;

    }

    table[randPlace] = (qrand() % 9 == 1)?4:2;
    return true;
}

void MainWindow::resetGame()
{
    for (int i = 0;i <9; i++) {
        table[i] = -1;
    }
    randItem();
    timeNum = 0;
    score = 0;

    updateItems();
}

void MainWindow::calculateScore()
{
    score = 0;
    for (int var = 0; var < 9; ++var) {
        if(table[var]!=-1) score += table[var];
    }

}

void MainWindow::setStyle()
{
    QLabel *item;
    for (int i = 0;i<9;i++) {
        item = this->findChild<QLabel*>("item"+QString::number(i+1));
        switch (table[i]) {
            case -1: {
                item->setStyleSheet("background-color:rgba(238, 228, 218, 0.35);");
            }
            break;
            case  2: {
                item->setStyleSheet("background:#eee4da;");
            }
            break;
            case  4:{
                item->setStyleSheet("background:#eee1c9");
            }break;
            case  8:{
                item->setStyleSheet("background:#f3b27a;");
            }break;
            case  16:{
                item->setStyleSheet("background:#f69664;");
            }break;
            case  32:{
                item->setStyleSheet("background:#f77c5f");
            }break;
            case  64:{
                item->setStyleSheet("background:#f75f3b");
            }break;
            case  128:{
                item->setStyleSheet("background:#edd073");
            }break;
            case  256:{
                item->setStyleSheet("background:#edcc62");
            }break;
            case  512:{
                item->setStyleSheet("background:#edc950");

            }break;
            case 1024:{
                item->setStyleSheet("background:#D7B327");
            }break;
            case  2048:{
                item->setStyleSheet("background:#EBBF21");

            }break;
        }

    }
}




void MainWindow::on_restartBtn_clicked()
{
    resetGame();
    updateItems();
}

void MainWindow::addTimeNum()
{
    timeNum++;
    int hour = timeNum /3600;
    int minutes = (timeNum - hour*3600)/60;
    int second = timeNum - hour*3600 -minutes*60;
    ui->timeLabel->setText(
        QString("%1:%2:%3")
                .arg(hour)
                .arg(minutes)
                .arg(second)

    );
}
