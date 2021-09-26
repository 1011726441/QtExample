#ifndef THUMBNAILIMG_H
#define THUMBNAILIMG_H

#include <QThread>
#include <QObject>
#include <QProcess>
#include <QRegExp>
#include <QApplication>
#include <QVariant>


class ThumbnailImg: public QThread
{
    Q_OBJECT
signals:
    //void finished(QObject *);
    void returnPath(const QString path);
private slots:
    void sltOnReadOutput();
    void onFinished(int, QProcess::ExitStatus);
private:
    QProcess * myProcess;
    QString path;
    bool isFinished;
public:
    ~ThumbnailImg();
    ThumbnailImg();
    void run();
    void setPath(QString path);
};

#endif // THUMBNAILIMG_H
