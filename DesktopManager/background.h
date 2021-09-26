#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>
#include <QTimer>
#include <QDesktopWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QStringList>
#include <QMediaPlaylist>

#include "mousehook.h"

namespace Ui {
class Background;
}
class Background : public QWidget {
    Q_OBJECT
public:
    explicit Background(QWidget *parent = nullptr);
    ~Background();
    void findWorkerW();
    void togglePlayerStatus(bool flag, QString type);
    void setImgBackground(QStringList src, int second);
    void setGifBackground(QString src);
    void setVideoBackground(QStringList paths);
    void resetImg();
    void setCfg(Config *);
    void initTaskBar();
private slots:


private:
    QMovie *gif;
    QTimer *timer;
    HWND workerWID;
    bool doubleClick;
    MouseHook myHook;
    int _second,index,taskPattern;
    Ui::Background *ui;
    QMediaPlayer *player;
    QVideoWidget *vWiget;
    QMediaPlaylist *playerList;
    QStringList imgList;

    bool eventFilter(QObject * obj,QEvent *event);
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

};

#endif // BACKGROUND_H
