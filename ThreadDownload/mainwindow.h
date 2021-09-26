#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "download.h"
#include "controller.h"
#include "setinfodialog.h"
#include <QLabel>
#include <QProgressBar>
#include <QHBoxLayout>
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
    void on_pushButton_clicked();
    void newTask(QString url ,int count);
private:
    Ui::MainWindow *ui;

    SetInfoDialog InfoDialog;
    int TaskCount;
};
#endif // MAINWINDOW_H
