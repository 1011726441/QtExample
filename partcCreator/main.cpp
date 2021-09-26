#include "mainwindow.h"

#include <QApplication>
/*
    projectName：英语听说partC生成器
    theory:text to speech
    author：纯真的电灯泡
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
