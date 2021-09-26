#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&InfoDialog,&SetInfoDialog::newTask,this,&MainWindow::newTask);
    TaskCount=0;

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    InfoDialog.show();

}

void MainWindow::newTask(QString url, int count)
{
    Controller *controller = new Controller();
    QProgressBar *pgb = new QProgressBar();
    pgb->setRange(0,100);
    connect(controller,&Controller::percentageCHanged,pgb,&QProgressBar::setValue);
    controller->setUrl(QUrl(url));
    controller->setThreadCount(count);
    fileInfo _info = Controller::GetFileSize(QUrl(url));
    QHBoxLayout *hbox =new QHBoxLayout();
    QLabel *label;
    label =new QLabel();
    label->setText(_info.fileName);
    label->setSizePolicy(ui->label_4->sizePolicy());
    hbox->addWidget(label);
    hbox->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    label =new QLabel();
    label->setText(QString::number((count)));
    label->setSizePolicy(ui->label_3->sizePolicy());
    hbox->addWidget(label);
    hbox->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    label =new QLabel();

    label->setText(QString::number(_info.fileSzie));
    label->setSizePolicy(ui->label_3->sizePolicy());
    hbox->addWidget(label);
    hbox->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    hbox->addWidget(pgb);
    ui->list->addLayout(hbox);
    controller->startTask();
}
