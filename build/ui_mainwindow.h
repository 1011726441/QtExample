/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *baseSettingLabel;
    QLabel *videoSettingLabel;
    QLabel *gifSettingLabel;
    QLabel *imgSettingLabel;
    QLabel *taskSettingLabel;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QLabel *basePoint;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QCheckBox *isAutoRun;
    QPushButton *addGif;
    QLabel *videoPoint;
    QPushButton *addVideo;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *gifPoint;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_7;
    QLabel *imgPoint;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_11;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_10;
    QSpinBox *intervalBox;
    QLabel *vloumeValue;
    QComboBox *taskBarPattern;
    QLabel *label_10;
    QLabel *label_15;
    QLabel *taskPoint;
    QSpacerItem *horizontalSpacer_13;
    QCheckBox *isStop;
    QSlider *volume;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *isSimpleExit;
    QComboBox *patternBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_11;
    QGridLayout *showVideos;
    QGridLayout *showImgs;
    QPushButton *apply;
    QPushButton *cancel;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(671, 521);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        baseSettingLabel = new QLabel(centralwidget);
        baseSettingLabel->setObjectName(QString::fromUtf8("baseSettingLabel"));

        verticalLayout->addWidget(baseSettingLabel);

        videoSettingLabel = new QLabel(centralwidget);
        videoSettingLabel->setObjectName(QString::fromUtf8("videoSettingLabel"));

        verticalLayout->addWidget(videoSettingLabel);

        gifSettingLabel = new QLabel(centralwidget);
        gifSettingLabel->setObjectName(QString::fromUtf8("gifSettingLabel"));

        verticalLayout->addWidget(gifSettingLabel);

        imgSettingLabel = new QLabel(centralwidget);
        imgSettingLabel->setObjectName(QString::fromUtf8("imgSettingLabel"));

        verticalLayout->addWidget(imgSettingLabel);

        taskSettingLabel = new QLabel(centralwidget);
        taskSettingLabel->setObjectName(QString::fromUtf8("taskSettingLabel"));

        verticalLayout->addWidget(taskSettingLabel);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 430, 425));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        basePoint = new QLabel(scrollAreaWidgetContents);
        basePoint->setObjectName(QString::fromUtf8("basePoint"));

        gridLayout_3->addWidget(basePoint, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 6, 1, 1, 1);

        isAutoRun = new QCheckBox(scrollAreaWidgetContents);
        isAutoRun->setObjectName(QString::fromUtf8("isAutoRun"));

        gridLayout_3->addWidget(isAutoRun, 1, 1, 1, 1);

        addGif = new QPushButton(scrollAreaWidgetContents);
        addGif->setObjectName(QString::fromUtf8("addGif"));

        gridLayout_3->addWidget(addGif, 10, 4, 1, 2);

        videoPoint = new QLabel(scrollAreaWidgetContents);
        videoPoint->setObjectName(QString::fromUtf8("videoPoint"));

        gridLayout_3->addWidget(videoPoint, 4, 0, 1, 1);

        addVideo = new QPushButton(scrollAreaWidgetContents);
        addVideo->setObjectName(QString::fromUtf8("addVideo"));

        gridLayout_3->addWidget(addVideo, 7, 1, 1, 2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_12, 10, 6, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 7, 0, 1, 1);

        gifPoint = new QLabel(scrollAreaWidgetContents);
        gifPoint->setObjectName(QString::fromUtf8("gifPoint"));

        gridLayout_3->addWidget(gifPoint, 9, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 5, 0, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_14, 12, 7, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(260, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 5, 2, 1, 6);

        imgPoint = new QLabel(scrollAreaWidgetContents);
        imgPoint->setObjectName(QString::fromUtf8("imgPoint"));

        gridLayout_3->addWidget(imgPoint, 11, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 6, 7, 1, 1);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 10, 0, 1, 1);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 10, 1, 1, 3);

        horizontalSpacer_10 = new QSpacerItem(233, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_10, 7, 3, 1, 5);

        intervalBox = new QSpinBox(scrollAreaWidgetContents);
        intervalBox->setObjectName(QString::fromUtf8("intervalBox"));
        intervalBox->setMinimum(1);
        intervalBox->setMaximum(300);

        gridLayout_3->addWidget(intervalBox, 12, 1, 1, 1);

        vloumeValue = new QLabel(scrollAreaWidgetContents);
        vloumeValue->setObjectName(QString::fromUtf8("vloumeValue"));

        gridLayout_3->addWidget(vloumeValue, 6, 5, 1, 2);

        taskBarPattern = new QComboBox(scrollAreaWidgetContents);
        taskBarPattern->addItem(QString());
        taskBarPattern->addItem(QString());
        taskBarPattern->addItem(QString());
        taskBarPattern->addItem(QString());
        taskBarPattern->addItem(QString());
        taskBarPattern->setObjectName(QString::fromUtf8("taskBarPattern"));

        gridLayout_3->addWidget(taskBarPattern, 14, 1, 1, 4);

        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 3, 0, 1, 1);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 12, 4, 1, 1);

        taskPoint = new QLabel(scrollAreaWidgetContents);
        taskPoint->setObjectName(QString::fromUtf8("taskPoint"));

        gridLayout_3->addWidget(taskPoint, 14, 0, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_13, 14, 7, 1, 1);

        isStop = new QCheckBox(scrollAreaWidgetContents);
        isStop->setObjectName(QString::fromUtf8("isStop"));

        gridLayout_3->addWidget(isStop, 5, 1, 1, 1);

        volume = new QSlider(scrollAreaWidgetContents);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setOrientation(Qt::Horizontal);
        volume->setTickInterval(0);

        gridLayout_3->addWidget(volume, 6, 2, 1, 3);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 12, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 6, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(233, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 3, 1, 5);

        isSimpleExit = new QCheckBox(scrollAreaWidgetContents);
        isSimpleExit->setObjectName(QString::fromUtf8("isSimpleExit"));

        gridLayout_3->addWidget(isSimpleExit, 2, 1, 1, 1);

        patternBox = new QComboBox(scrollAreaWidgetContents);
        patternBox->addItem(QString());
        patternBox->addItem(QString());
        patternBox->addItem(QString());
        patternBox->setObjectName(QString::fromUtf8("patternBox"));

        gridLayout_3->addWidget(patternBox, 3, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(233, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 3, 1, 5);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_11, 3, 3, 1, 5);

        showVideos = new QGridLayout();
        showVideos->setObjectName(QString::fromUtf8("showVideos"));

        gridLayout_3->addLayout(showVideos, 8, 0, 1, 8);

        showImgs = new QGridLayout();
        showImgs->setObjectName(QString::fromUtf8("showImgs"));

        gridLayout_3->addLayout(showImgs, 13, 0, 1, 8);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 2);

        apply = new QPushButton(centralwidget);
        apply->setObjectName(QString::fromUtf8("apply"));

        gridLayout->addWidget(apply, 1, 1, 1, 1);

        cancel = new QPushButton(centralwidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        gridLayout->addWidget(cancel, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 671, 23));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        baseSettingLabel->setText(QCoreApplication::translate("MainWindow", "\345\237\272\347\241\200\350\256\276\347\275\256", nullptr));
        videoSettingLabel->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
        gifSettingLabel->setText(QCoreApplication::translate("MainWindow", "\345\212\250\345\233\276", nullptr));
        imgSettingLabel->setText(QCoreApplication::translate("MainWindow", "\351\235\231\346\200\201", nullptr));
        taskSettingLabel->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\346\240\217", nullptr));
        basePoint->setText(QCoreApplication::translate("MainWindow", "\345\237\272\347\241\200\350\256\276\347\275\256", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\351\237\263\351\207\217", nullptr));
        isAutoRun->setText(QCoreApplication::translate("MainWindow", "\345\274\200\346\234\272\350\207\252\345\220\257", nullptr));
        addGif->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        videoPoint->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
        addVideo->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266/\346\226\207\344\273\266\345\244\271", nullptr));
        gifPoint->setText(QCoreApplication::translate("MainWindow", "\345\212\250\345\233\276", nullptr));
        imgPoint->setText(QCoreApplication::translate("MainWindow", "\351\235\231\346\200\201", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        vloumeValue->setText(QString());
        taskBarPattern->setItemText(0, QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\347\253\213\345\215\263\347\276\216\345\214\226(\344\270\215\346\243\200\346\265\213)", nullptr));
        taskBarPattern->setItemText(1, QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\347\253\213\345\215\263\347\276\216\345\214\226(\346\243\200\346\265\213)", nullptr));
        taskBarPattern->setItemText(2, QCoreApplication::translate("MainWindow", "\344\270\215\351\200\217\346\230\216(\346\214\211\350\256\276\347\275\256\347\232\204\351\242\234\350\211\262\346\235\245)", nullptr));
        taskBarPattern->setItemText(3, QCoreApplication::translate("MainWindow", "\346\257\233\347\216\273\347\222\203", nullptr));
        taskBarPattern->setItemText(4, QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\351\273\230\350\256\244(\344\270\213\346\254\241\344\270\200\345\256\232)", nullptr));

        label_10->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\346\250\241\345\274\217", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\347\247\222", nullptr));
        taskPoint->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\346\240\217", nullptr));
        isStop->setText(QCoreApplication::translate("MainWindow", "\351\273\230\350\256\244\346\232\202\345\201\234", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\351\227\264\351\232\224", nullptr));
        isSimpleExit->setText(QCoreApplication::translate("MainWindow", "\347\233\264\346\216\245\351\200\200\345\207\272", nullptr));
        patternBox->setItemText(0, QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
        patternBox->setItemText(1, QCoreApplication::translate("MainWindow", "\345\212\250\345\233\276", nullptr));
        patternBox->setItemText(2, QCoreApplication::translate("MainWindow", "\351\235\231\346\200\201", nullptr));

        apply->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
