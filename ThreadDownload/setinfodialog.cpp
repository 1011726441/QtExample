#include "setinfodialog.h"
#include "ui_setinfodialog.h"

SetInfoDialog::SetInfoDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetInfoDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("新建下载任务");
}

SetInfoDialog::~SetInfoDialog()
{
    delete ui;
}

void SetInfoDialog::on_comfirmBtn_clicked()
{
    this->close();
    emit newTask(ui->urlEdit->text(),ui->threadSpin->value());
}
