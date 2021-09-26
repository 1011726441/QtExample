#ifndef SETINFODIALOG_H
#define SETINFODIALOG_H

#include <QWidget>

namespace Ui {
class SetInfoDialog;
}

class SetInfoDialog : public QWidget
{
    Q_OBJECT
signals:
    void newTask(QString url,int thradCount);
public:
    explicit SetInfoDialog(QWidget *parent = nullptr);
    ~SetInfoDialog();

private slots:
    void on_comfirmBtn_clicked();

private:
    Ui::SetInfoDialog *ui;
};

#endif // SETINFODIALOG_H
