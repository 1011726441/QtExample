#include "mainwindow.h"

#include <QApplication>
/*
    projectName：多线程下载器
    author：纯真的电灯泡
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
