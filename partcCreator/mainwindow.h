#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtTextToSpeech>
#include <baiduVoice.h>
#include <option.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void initSpeech(QString s);
private slots:
    void on_languageSelect_currentIndexChanged(const QString &arg1);

    void on_enginesSelect_currentIndexChanged(const QString &arg1);

    void on_voicesSelect_currentIndexChanged(int index);

    void on_sayBtn_clicked();

    void on_volume_valueChanged(int value);

    void on_rate_valueChanged(int value);

    void btnStateChange(int state);

    void on_pauseBtn_clicked();

    void on_stopBtn_clicked();

    void on_resumeBtn_clicked();

private:
    Ui::MainWindow *ui;
    QTextToSpeech *speech;
    QVector<QVoice> _voices;
    QVector<QLocale> _locales;
    BaiduVoice *bVoice;
    QStringList netLang,engs;
    QString netWorkFlag;
    Option option;
    int voiceId;

};
#endif // MAINWINDOW_H
