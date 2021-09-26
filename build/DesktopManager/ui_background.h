/********************************************************************************
** Form generated from reading UI file 'background.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKGROUND_H
#define UI_BACKGROUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Background
{
public:
    QLabel *label;

    void setupUi(QWidget *Background)
    {
        if (Background->objectName().isEmpty())
            Background->setObjectName(QString::fromUtf8("Background"));
        Background->resize(400, 300);
        label = new QLabel(Background);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 54, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        retranslateUi(Background);

        QMetaObject::connectSlotsByName(Background);
    } // setupUi

    void retranslateUi(QWidget *Background)
    {
        Background->setWindowTitle(QCoreApplication::translate("Background", "Form", nullptr));
        label->setText(QCoreApplication::translate("Background", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Background: public Ui_Background {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKGROUND_H
