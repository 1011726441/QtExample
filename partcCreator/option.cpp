#include "option.h"

Option::Option()
{
    QString baiduEngOption="{\"百度语音(在线)\":{\"voices\":[\"女声\",\"男声\",\"男声\",\"度逍遥\",\"度丫丫\"],\"language\":[\"中英混合\"]}}";
    QJsonDocument doc = QJsonDocument::fromJson(baiduEngOption.toUtf8());
    netEngs=doc.object();
}

QJsonValue Option::getNetEngLang(QString eng)
{
    return this->netEngs.value(eng).toObject().value("language");
}
QJsonValue Option::getNetEngVoices(QString eng)
{
    return this->netEngs.value(eng).toObject().value("voices");
}

QStringList Option::getNetEngs()
{
    return netEngs.keys();
}
