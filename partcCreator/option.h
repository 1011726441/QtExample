#ifndef OPTION_H
#define OPTION_H
#include<QObject>
#include <QJsonObject>
#include <QJsonArray>
#include<QJsonDocument>
class Option
{

public:
    explicit Option();

public:
    QJsonValue getNetEngLang(QString Eng);
    QStringList getNetEngs();
    QJsonValue getNetEngVoices(QString eng);
private:
    QJsonObject netEngs;
};

#endif // OPTION_H
