#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMenu>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QFileDialog>
#include <QScrollBar>
#include <QContextMenuEvent>
#include <QLabel>
#include <QList>
#include <QThread>
#include <QProcess>

#include "win32.h"
#include "config.h"
#include "mousehook.h"
#include "background.h"
#include "thumbnailimg.h"


#include <QtDebug>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow {
    Q_OBJECT
public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void setting(bool);
    void quit();
    void getImgFinished(QString);
    void palyerToggle(bool);

    void onAddImgsBtnClick();
    void on_cancel_clicked();
    void on_addVideo_clicked();
    void on_addGif_clicked();
    void on_apply_clicked();
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason);
    void on_volume_valueChanged(int value);


signals:
    void threadStart();
    void reDrawViewDisplay(QString);
private:
    win32 win32;
    QMenu *myMenu;
    HWND workerWID;
    Config *config;

    Ui::MainWindow *ui;
    QList<QLabel *> imgs,videos;
    QThread *getImgThread;
    Background *background;
    ThumbnailImg *thumbail;
    QMediaPlaylist playList;
    QString gifPath,pattern;
    QPushButton *addImgsBtn;
    QSystemTrayIcon *trayIcon;   
    QStringList imgPaths,videoPaths;
    uchar playerStatus,taskbarPatterns;
    QAction *playerAct,*exitMe,*settingAct;
    QList<QThread *> threadList ;


    void initBk();
    void initTray();
    void loadCfg();
    void drawImgDisplay();
    void closeEvent(QCloseEvent *e);
    bool eventFilter(QObject * obj,QEvent *event);


};
#endif // MAINWINDOW_H
