#ifndef CONFIG_H
#define CONFIG_H
#include <QFile>
#include <QSettings>

class Config
{
public:
    Config();
    QVariant readCfg(QString);
    void writeCfg(QString key, QVariant value);
private:
    QSettings *config;
    void initCfg();
};

#endif // CONFIG_H
