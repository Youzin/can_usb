/********************************************************************************
** Form generated from reading UI file 'formcantx.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCANTX_H
#define UI_FORMCANTX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCanTx
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *chEnable;
    QLineEdit *leId;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leData0;
    QLineEdit *leData1;
    QLineEdit *leData2;
    QLineEdit *leData3;
    QLineEdit *leData4;
    QLineEdit *leData5;
    QLineEdit *leData6;
    QLineEdit *leData7;
    QLineEdit *leLength;
    QComboBox *cbFormat;
    QComboBox *cbType;
    QPushButton *btnSend;
    QPushButton *btnDelete;
    QCheckBox *checkBox;
    QSpinBox *sbInterval;

    void setupUi(QWidget *FormCanTx)
    {
        if (FormCanTx->objectName().isEmpty())
            FormCanTx->setObjectName(QStringLiteral("FormCanTx"));
        FormCanTx->resize(888, 50);
        FormCanTx->setMinimumSize(QSize(0, 40));
        FormCanTx->setMaximumSize(QSize(16777215, 50));
        verticalLayout = new QVBoxLayout(FormCanTx);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        chEnable = new QCheckBox(FormCanTx);
        chEnable->setObjectName(QStringLiteral("chEnable"));
        chEnable->setMinimumSize(QSize(10, 24));
        chEnable->setMaximumSize(QSize(20, 32));

        horizontalLayout_2->addWidget(chEnable);

        leId = new QLineEdit(FormCanTx);
        leId->setObjectName(QStringLiteral("leId"));
        leId->setMinimumSize(QSize(40, 24));
        leId->setMaximumSize(QSize(80, 32));
        leId->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(leId);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leData0 = new QLineEdit(FormCanTx);
        leData0->setObjectName(QStringLiteral("leData0"));
        leData0->setMinimumSize(QSize(20, 24));
        leData0->setMaximumSize(QSize(30, 32));
        leData0->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(leData0);

        leData1 = new QLineEdit(FormCanTx);
        leData1->setObjectName(QStringLiteral("leData1"));
        leData1->setMinimumSize(QSize(20, 24));
        leData1->setMaximumSize(QSize(30, 32));
        leData1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(leData1);

        leData2 = new QLineEdit(FormCanTx);
        leData2->setObjectName(QStringLiteral("leData2"));
        leData2->setMinimumSize(QSize(20, 24));
        leData2->setMaximumSize(QSize(30, 32));
        leData2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(leData2);

        leData3 = new QLineEdit(FormCanTx);
        leData3->setObjectName(QStringLiteral("leData3"));
        leData3->setMinimumSize(QSize(20, 24));
        leData3->setMaximumSize(QSize(30, 32));
        leData3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(leData3);

        leData4 = new QLineEdit(FormCanTx);
        leData4->setObjectName(QStringLiteral("leData4"));
        leData4->setMinimumSize(QSize(20, 24));
        leData4->setMaximumSize(QSize(30, 32));
        leData4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(leData4);

        leData5 = new QLineEdit(FormCanTx);
        leData5->setObjectName(QStringLiteral("leData5"));
        leData5->setMinimumSize(QSize(20, 24));
        leData5->setMaximumSize(QSize(30, 32));
        leData5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(leData5);

        leData6 = new QLineEdit(FormCanTx);
        leData6->setObjectName(QStringLiteral("leData6"));
        leData6->setMinimumSize(QSize(20, 24));
        leData6->setMaximumSize(QSize(30, 32));
        leData6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(leData6);

        leData7 = new QLineEdit(FormCanTx);
        leData7->setObjectName(QStringLiteral("leData7"));
        leData7->setMinimumSize(QSize(20, 24));
        leData7->setMaximumSize(QSize(30, 32));
        leData7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(leData7);


        horizontalLayout_2->addLayout(horizontalLayout);

        leLength = new QLineEdit(FormCanTx);
        leLength->setObjectName(QStringLiteral("leLength"));
        leLength->setMinimumSize(QSize(20, 24));
        leLength->setMaximumSize(QSize(30, 32));
        leLength->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(leLength);

        cbFormat = new QComboBox(FormCanTx);
        cbFormat->setObjectName(QStringLiteral("cbFormat"));
        cbFormat->setMinimumSize(QSize(40, 24));
        cbFormat->setMaximumSize(QSize(60, 32));

        horizontalLayout_2->addWidget(cbFormat);

        cbType = new QComboBox(FormCanTx);
        cbType->setObjectName(QStringLiteral("cbType"));
        cbType->setMinimumSize(QSize(60, 24));
        cbType->setMaximumSize(QSize(70, 24));

        horizontalLayout_2->addWidget(cbType);

        btnSend = new QPushButton(FormCanTx);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setMinimumSize(QSize(40, 24));
        btnSend->setMaximumSize(QSize(40, 32));

        horizontalLayout_2->addWidget(btnSend);

        btnDelete = new QPushButton(FormCanTx);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setMinimumSize(QSize(40, 24));
        btnDelete->setMaximumSize(QSize(40, 32));

        horizontalLayout_2->addWidget(btnDelete);

        checkBox = new QCheckBox(FormCanTx);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(40, 24));
        checkBox->setMaximumSize(QSize(40, 24));

        horizontalLayout_2->addWidget(checkBox);

        sbInterval = new QSpinBox(FormCanTx);
        sbInterval->setObjectName(QStringLiteral("sbInterval"));
        sbInterval->setMinimumSize(QSize(70, 24));
        sbInterval->setMaximumSize(QSize(70, 24));
        sbInterval->setMinimum(0);
        sbInterval->setMaximum(10000);
        sbInterval->setSingleStep(100);
        sbInterval->setValue(100);

        horizontalLayout_2->addWidget(sbInterval);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FormCanTx);

        QMetaObject::connectSlotsByName(FormCanTx);
    } // setupUi

    void retranslateUi(QWidget *FormCanTx)
    {
        FormCanTx->setWindowTitle(QApplication::translate("FormCanTx", "Form", Q_NULLPTR));
        chEnable->setText(QString());
        leId->setInputMask(QApplication::translate("FormCanTx", "HHHHHHHH", Q_NULLPTR));
        leId->setText(QApplication::translate("FormCanTx", "00000000", Q_NULLPTR));
        leData0->setInputMask(QApplication::translate("FormCanTx", "HH", Q_NULLPTR));
        leData0->setText(QApplication::translate("FormCanTx", "00", Q_NULLPTR));
        leData1->setInputMask(QApplication::translate("FormCanTx", "HH", Q_NULLPTR));
        leData1->setText(QApplication::translate("FormCanTx", "00", Q_NULLPTR));
        leData2->setInputMask(QApplication::translate("FormCanTx", "HH", Q_NULLPTR));
        leData2->setText(QApplication::translate("FormCanTx", "00", Q_NULLPTR));
        leData3->setInputMask(QApplication::translate("FormCanTx", "HH", Q_NULLPTR));
        leData3->setText(QApplication::translate("FormCanTx", "00", Q_NULLPTR));
        leData4->setInputMask(QApplication::translate("FormCanTx", "HH", Q_NULLPTR));
        leData4->setText(QApplication::translate("FormCanTx", "00", Q_NULLPTR));
        leData5->setInputMask(QApplication::translate("FormCanTx", "HH", Q_NULLPTR));
        leData5->setText(QApplication::translate("FormCanTx", "00", Q_NULLPTR));
        leData6->setInputMask(QApplication::translate("FormCanTx", "HH", Q_NULLPTR));
        leData6->setText(QApplication::translate("FormCanTx", "00", Q_NULLPTR));
        leData7->setInputMask(QApplication::translate("FormCanTx", "HH", Q_NULLPTR));
        leData7->setText(QApplication::translate("FormCanTx", "00", Q_NULLPTR));
        leLength->setInputMask(QApplication::translate("FormCanTx", "HH", Q_NULLPTR));
        leLength->setText(QApplication::translate("FormCanTx", "08", Q_NULLPTR));
        btnSend->setText(QApplication::translate("FormCanTx", "TX", Q_NULLPTR));
        btnDelete->setText(QApplication::translate("FormCanTx", "DEL", Q_NULLPTR));
        checkBox->setText(QApplication::translate("FormCanTx", "ms", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormCanTx: public Ui_FormCanTx {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCANTX_H
