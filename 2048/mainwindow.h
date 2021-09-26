#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
#include <QMessageBox>

#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_restartBtn_clicked();
    void addTimeNum();
private:
    void keyReleaseEvent(QKeyEvent* ke);

    bool upClicked(int*);
    bool downClicked(int*);
    bool leftClicked(int*);
    bool rightClicked(int*);
    bool isFinshed();

    void updateItems();
    bool randItem();
    void resetGame();
    void calculateScore();
    void setStyle();

    QTimer *timer;
    int table[9];
    int score;
    int timeNum;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
