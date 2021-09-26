#include "config.h"
#include <QtDebug>
Config::Config()
{ 
    QFile file("./manager.cfg");
    if(file.exists()){
        config = new QSettings("./manager.cfg", QSettings::IniFormat);

        if(config->value("global/isInit","false").toString()!="true"){
            qDebug()<<"no init";
            initCfg();
        }
    }else{
        initCfg();
    }
}

QVariant Config::readCfg(QString key)
{

    return config->value(key);
}

void Config::writeCfg(QString key,QVariant value)
{
    config->setValue(key,value);
    qDebug()<<"key:"<<key<<"              value："<<value;
}


void Config::initCfg()
{
    QFile file("./manager.cfg");
    file.open(QFileDevice::ReadWrite);
    file.close();
    qDebug()<<"is not exists";
    config = new QSettings("./manager.cfg", QSettings::IniFormat);
    config->setValue("global/isInit",true);
    config->setValue("global/autoRun",false);


    config->setValue("video/volume",0);//0-100
    config->setValue("video/src",NULL);
    config->setValue("gif/animationStatus","start");//start stop pause
    config->setValue("gif/src",NULL);
    config->setValue("img/src",NULL);
    config->setValue("taskBar/taskBarPattern",1);//1 不检测 2 检测 3 颜色 4无
    config->setValue("global/pattern",QString("gif"));//video gif img
}
