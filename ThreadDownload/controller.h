#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QThread>

#include <QFileDialog>
#include <QList>
#include "download.h"
#include "fileInfo.h"
class Controller :public QThread
{
    Q_OBJECT
public:
    Controller();
    ~Controller();
    void startTask();
    void setThreadCount(int);
    void setUrl(QUrl);

    static fileInfo GetFileSize(QUrl);

private slots:
    void addFinshedCount();
    void onProcessChange(int index,qint64 now);
signals:
    void taskFinshed();
    void percentageCHanged(float);
private:
    QUrl url;
    int ThreadCount,finshedCount;
    QFile *file;
    QString fileName;
    Download *download;
    QString path;
    QList<qint64> process;
    fileInfo info;
};

#endif // CONTROLLER_H
