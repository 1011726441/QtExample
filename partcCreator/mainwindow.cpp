#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->bVoice=new BaiduVoice();
    this->setWindowTitle("Part C Creator（你硬要当做变声器我也没办法）");
    connect(this,&MainWindow::initSpeech,this,&MainWindow::on_enginesSelect_currentIndexChanged);
    engs=QTextToSpeech::availableEngines();
    engs.append(option.getNetEngs());
    foreach (QString engine,engs) {
        ui->enginesSelect->addItem(engine);
    }
    emit initSpeech("NULL");
    connect(bVoice,&BaiduVoice::stateChange,this,&MainWindow::btnStateChange);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_languageSelect_currentIndexChanged(const QString &arg1)
{
    this->speech->setLocale(QLocale(arg1.toLocal8Bit()));
}

void MainWindow::on_enginesSelect_currentIndexChanged(const QString &arg1)
{
    ui->rate->setRange(0,200);
    ui->volume->setRange(0,200);
    if(arg1=="NULL"){
        this->speech = new QTextToSpeech(this);
        this->netWorkFlag="";
    }
    else if (!option.getNetEngs().filter(arg1).isEmpty()) {
        this->netWorkFlag = arg1;
        ui->rate->setRange(0,15);
        ui->volume->setRange(0,15);
    }
    else{
        this->speech = new QTextToSpeech(arg1,this);
        this->netWorkFlag="";
    }
    connect(speech,&QTextToSpeech::stateChanged,this,&MainWindow::btnStateChange);
    this->ui->voicesSelect->clear();
    this->ui->languageSelect->clear();
    if(netWorkFlag==""){
        this->_locales = this->speech->availableLocales();
        foreach (const QLocale &locale, this->_locales) {
            QString name(QString("%1 (%2)")
                         .arg(QLocale::languageToString(locale.language()))
                         .arg(QLocale::countryToString(locale.country()))
                         );
            QVariant localeVariant(locale);
            ui->languageSelect->addItem(name,localeVariant);

        }
        this->_voices = this->speech->availableVoices();
        foreach (const QVoice &voice, this->_voices) {
            ui->voicesSelect->addItem(QString("%1-%2-%3")
                                      .arg(voice.name())
                                      .arg(QVoice::ageName(voice.age()))
                                      .arg(QVoice::genderName(voice.gender())
                                           )
                                      );
        }

    }else{
        foreach (QJsonValue val, option.getNetEngVoices(netWorkFlag).toArray()) {
            this->ui->voicesSelect->addItem(val.toString());
        }
        foreach (QJsonValue val, option.getNetEngLang(netWorkFlag).toArray()) {
            ui->languageSelect->addItem(val.toString());
        }
    }
}
void MainWindow::on_voicesSelect_currentIndexChanged(int index)
{
    if(netWorkFlag=="" && index>=0)
        this->speech->setVoice(this->_voices.at(index));
    else
        this->voiceId = index;
}

void MainWindow::on_sayBtn_clicked()
{
    if(netWorkFlag==""){
        this->speech->setRate(ui->rate->value()/100.0-1.0);
        this->speech->setVolume(ui->volume->value()/100.0-1.0);
        this->speech->say(ui->textEdit->toPlainText());
    }else {
        bVoice->say(ui->volume->value(),ui->rate->value(),ui->voicesSelect->currentIndex(),ui->languageSelect->currentIndex(),ui->textEdit->toPlainText());
    }
}

void MainWindow::on_volume_valueChanged(int value)
{
    ui->showVolume->setNum(value);
}

void MainWindow::on_rate_valueChanged(int value)
{
    ui->showRate->setNum(value);
}

void MainWindow::btnStateChange(int state)
{
    switch (state) {
    case 0:
        this->ui->sayBtn->setEnabled(true);
        this->ui->resumeBtn->setEnabled(false);
        this->ui->pauseBtn->setEnabled(false);
        this->ui->stopBtn->setEnabled(false);
        break;
    case 1:
        this->ui->sayBtn->setEnabled(false);
        this->ui->resumeBtn->setEnabled(true);
        this->ui->pauseBtn->setEnabled(true);
        this->ui->stopBtn->setEnabled(true);
        break;
    case 2:
        this->ui->sayBtn->setEnabled(false);
        this->ui->resumeBtn->setEnabled(true);
        this->ui->pauseBtn->setEnabled(true);
        this->ui->stopBtn->setEnabled(true);
    }
}

void MainWindow::on_pauseBtn_clicked()
{
    if(netWorkFlag=="")
        speech->pause();
    else
        bVoice->voicePause();
}

void MainWindow::on_stopBtn_clicked()
{
    if(netWorkFlag=="")
        speech->stop();
    else
        bVoice->voiceStop();
}

void MainWindow::on_resumeBtn_clicked()
{
    if(netWorkFlag=="")
        speech->resume();
    else
        bVoice->voiceResume();
}
