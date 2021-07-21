/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *btnConnect;
    QComboBox *cbComBaud;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *btnCanGetBaudRate;
    QLineEdit *leBaudrate;
    QPushButton *btnCanBaudRate;
    QFrame *frameTx;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *btnAddTx;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSaveTx;
    QPushButton *btnLoadTx;
    QListWidget *listTx;
    QFrame *frameRx;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QPushButton *btnRxClear;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnSaveRx;
    QPushButton *btnLoadRx;
    QTableWidget *twRx;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 820);
        MainWindow->setMaximumSize(QSize(1000, 1400));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 24));
        label_3->setMaximumSize(QSize(60, 32));
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Sunken);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        btnConnect = new QPushButton(centralWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setMinimumSize(QSize(60, 24));
        btnConnect->setMaximumSize(QSize(140, 32));

        horizontalLayout->addWidget(btnConnect);

        cbComBaud = new QComboBox(centralWidget);
        cbComBaud->setObjectName(QStringLiteral("cbComBaud"));
        cbComBaud->setMinimumSize(QSize(60, 24));
        cbComBaud->setMaximumSize(QSize(140, 32));

        horizontalLayout->addWidget(cbComBaud);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 24));
        label_2->setMaximumSize(QSize(140, 32));
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        btnCanGetBaudRate = new QPushButton(centralWidget);
        btnCanGetBaudRate->setObjectName(QStringLiteral("btnCanGetBaudRate"));
        btnCanGetBaudRate->setMinimumSize(QSize(50, 24));
        btnCanGetBaudRate->setMaximumSize(QSize(70, 32));

        horizontalLayout_2->addWidget(btnCanGetBaudRate);

        leBaudrate = new QLineEdit(centralWidget);
        leBaudrate->setObjectName(QStringLiteral("leBaudrate"));
        leBaudrate->setMinimumSize(QSize(60, 24));
        leBaudrate->setMaximumSize(QSize(100, 32));
        leBaudrate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(leBaudrate);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        btnCanBaudRate = new QPushButton(centralWidget);
        btnCanBaudRate->setObjectName(QStringLiteral("btnCanBaudRate"));
        btnCanBaudRate->setMinimumSize(QSize(50, 24));
        btnCanBaudRate->setMaximumSize(QSize(70, 32));

        horizontalLayout_3->addWidget(btnCanBaudRate);


        verticalLayout_3->addLayout(horizontalLayout_3);

        frameTx = new QFrame(centralWidget);
        frameTx->setObjectName(QStringLiteral("frameTx"));
        frameTx->setMinimumSize(QSize(100, 0));
        frameTx->setMaximumSize(QSize(16777215, 300));
        frameTx->setFrameShape(QFrame::Panel);
        frameTx->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameTx);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(frameTx);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(100, 24));
        label_4->setMaximumSize(QSize(140, 32));
        label_4->setFrameShape(QFrame::Panel);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        btnAddTx = new QPushButton(frameTx);
        btnAddTx->setObjectName(QStringLiteral("btnAddTx"));
        btnAddTx->setMinimumSize(QSize(50, 24));
        btnAddTx->setMaximumSize(QSize(80, 32));
        btnAddTx->setSizeIncrement(QSize(0, 0));

        horizontalLayout_4->addWidget(btnAddTx);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        btnSaveTx = new QPushButton(frameTx);
        btnSaveTx->setObjectName(QStringLiteral("btnSaveTx"));
        btnSaveTx->setMinimumSize(QSize(50, 24));
        btnSaveTx->setMaximumSize(QSize(80, 32));
        btnSaveTx->setSizeIncrement(QSize(0, 0));

        horizontalLayout_4->addWidget(btnSaveTx);

        btnLoadTx = new QPushButton(frameTx);
        btnLoadTx->setObjectName(QStringLiteral("btnLoadTx"));
        btnLoadTx->setMinimumSize(QSize(50, 24));
        btnLoadTx->setMaximumSize(QSize(80, 32));
        btnLoadTx->setSizeIncrement(QSize(0, 0));

        horizontalLayout_4->addWidget(btnLoadTx);


        verticalLayout_2->addLayout(horizontalLayout_4);

        listTx = new QListWidget(frameTx);
        listTx->setObjectName(QStringLiteral("listTx"));

        verticalLayout_2->addWidget(listTx);


        verticalLayout_3->addWidget(frameTx);

        frameRx = new QFrame(centralWidget);
        frameRx->setObjectName(QStringLiteral("frameRx"));
        frameRx->setMinimumSize(QSize(0, 400));
        frameRx->setMaximumSize(QSize(1000, 900));
        frameRx->setFrameShape(QFrame::Panel);
        frameRx->setFrameShadow(QFrame::Raised);
        frameRx->setLineWidth(2);
        verticalLayout = new QVBoxLayout(frameRx);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(frameRx);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(100, 24));
        label_5->setMaximumSize(QSize(140, 32));
        label_5->setFrameShape(QFrame::Panel);
        label_5->setFrameShadow(QFrame::Sunken);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_5);

        btnRxClear = new QPushButton(frameRx);
        btnRxClear->setObjectName(QStringLiteral("btnRxClear"));
        btnRxClear->setMinimumSize(QSize(50, 24));
        btnRxClear->setMaximumSize(QSize(80, 32));
        btnRxClear->setSizeIncrement(QSize(0, 0));

        horizontalLayout_5->addWidget(btnRxClear);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        btnSaveRx = new QPushButton(frameRx);
        btnSaveRx->setObjectName(QStringLiteral("btnSaveRx"));
        btnSaveRx->setMinimumSize(QSize(50, 24));
        btnSaveRx->setMaximumSize(QSize(80, 32));
        btnSaveRx->setSizeIncrement(QSize(0, 0));

        horizontalLayout_5->addWidget(btnSaveRx);

        btnLoadRx = new QPushButton(frameRx);
        btnLoadRx->setObjectName(QStringLiteral("btnLoadRx"));
        btnLoadRx->setMinimumSize(QSize(50, 24));
        btnLoadRx->setMaximumSize(QSize(80, 32));
        btnLoadRx->setSizeIncrement(QSize(0, 0));

        horizontalLayout_5->addWidget(btnLoadRx);


        verticalLayout->addLayout(horizontalLayout_5);

        twRx = new QTableWidget(frameRx);
        twRx->setObjectName(QStringLiteral("twRx"));
        twRx->setColumnCount(0);
        twRx->horizontalHeader()->setDefaultSectionSize(60);
        twRx->horizontalHeader()->setMinimumSectionSize(20);
        twRx->horizontalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(twRx);


        verticalLayout_3->addWidget(frameRx);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "USB-CAN Tool", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "USB", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("MainWindow", "CONNECT", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "CAN BAUDRATE", Q_NULLPTR));
        btnCanGetBaudRate->setText(QApplication::translate("MainWindow", "GET", Q_NULLPTR));
        leBaudrate->setInputMask(QApplication::translate("MainWindow", "9999999", Q_NULLPTR));
        leBaudrate->setText(QApplication::translate("MainWindow", "500000", Q_NULLPTR));
        btnCanBaudRate->setText(QApplication::translate("MainWindow", "SET", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "CAN TX", Q_NULLPTR));
        btnAddTx->setText(QApplication::translate("MainWindow", "ADD", Q_NULLPTR));
        btnSaveTx->setText(QApplication::translate("MainWindow", "SAVE", Q_NULLPTR));
        btnLoadTx->setText(QApplication::translate("MainWindow", "LOAD", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "CAN RX", Q_NULLPTR));
        btnRxClear->setText(QApplication::translate("MainWindow", "CLEAR", Q_NULLPTR));
        btnSaveRx->setText(QApplication::translate("MainWindow", "SAVE", Q_NULLPTR));
        btnLoadRx->setText(QApplication::translate("MainWindow", "LOAD", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
