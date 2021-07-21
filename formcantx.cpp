#include "formcantx.h"
#include "ui_formcantx.h"

#include "mainwindow.h"

FormCanTx::FormCanTx(QWidget *parent, QListWidgetItem *item) :
    QWidget(parent),
    ui(new Ui::FormCanTx), txItem(item)
{
    ui->setupUi(this);

    ui->cbFormat->addItem(formats[0]);
    ui->cbFormat->addItem(formats[1]);
    ui->cbType->addItem(types[0]);
    ui->cbType->addItem(types[1]);

    ui->leId->setText("00000000");

    getTxMsg();

    connect(this, SIGNAL(send(FormCanTx *)), parent, SLOT(canTxData(FormCanTx *)) );
    connect(this, SIGNAL(remove(FormCanTx *)), parent, SLOT(deleteTxData(FormCanTx *)));
    connect(this, SIGNAL(enableTimer(MainWindow::CanMsg *)), parent, SLOT(enableTimer(MainWindow::CanMsg *)));
    connect(this, SIGNAL(disableTimer(MainWindow::CanMsg *)), parent, SLOT(disableTimer(MainWindow::CanMsg *)));
}

FormCanTx::~FormCanTx()
{
    delete ui;
}

MainWindow::CanMsg *FormCanTx::getTxMsg()
{
    bool bStatus = false;
    uint32_t no;

    no = ui->leId->text().toUInt(&bStatus,16);
    msg.id  = no; //((no >> 24) & 0xff ) + (( no >> 8) & 0xff00) + ((no << 8) & 0xff0000) + ((no << 24)& 0xff000000);
    msg.data[0] = ui->leData0->text().toUInt(&bStatus,16);
    msg.data[1] = ui->leData1->text().toUInt(&bStatus,16);
    msg.data[2] = ui->leData2->text().toUInt(&bStatus,16);
    msg.data[3] = ui->leData3->text().toUInt(&bStatus,16);
    msg.data[4] = ui->leData4->text().toUInt(&bStatus,16);
    msg.data[5] = ui->leData5->text().toUInt(&bStatus,16);
    msg.data[6] = ui->leData6->text().toUInt(&bStatus,16);
    msg.data[7] = ui->leData7->text().toUInt(&bStatus,16);
    msg.ch = 0;
    msg.len = ui->leLength->text().toUInt(&bStatus,16);
    msg.format = ui->cbFormat->currentIndex();
    msg.type = ui->cbType->currentIndex();
    msg.interval = ui->sbInterval->value();

    return &msg;
}

void FormCanTx::setTxMsg(MainWindow::CanMsg *pmsg)
{
    msg = *pmsg;

    ui->leId->setText(QString::number(msg.id, 16));
    ui->leData0->setText(QString::number(msg.data[0], 16));
    ui->leData1->setText(QString::number(msg.data[1], 16));
    ui->leData2->setText(QString::number(msg.data[2], 16));
    ui->leData3->setText(QString::number(msg.data[3], 16));
    ui->leData4->setText(QString::number(msg.data[4], 16));
    ui->leData5->setText(QString::number(msg.data[5], 16));
    ui->leData6->setText(QString::number(msg.data[6], 16));
    ui->leData7->setText(QString::number(msg.data[7], 16));

    msg.ch = 0;
    ui->leLength->setText(QString::number(msg.len, 16));
    ui->cbFormat->setCurrentIndex(msg.format);
    ui->cbType->setCurrentIndex(msg.type);
    ui->sbInterval->setValue(msg.interval);
}


void FormCanTx::on_btnSend_clicked()
{

    getTxMsg();

    qDebug()<< "ID:" << QString::number(msg.id, 16);
    emit send(this);
}

void FormCanTx::on_btnDelete_clicked()
{
    emit remove(this);
}

void FormCanTx::on_checkBox_clicked(bool checked)
{
    if ( checked ) {
        emit enableTimer(&this->msg);
    }
    else {
        emit disableTimer(&this->msg);
    }
}

void FormCanTx::on_sbInterval_valueChanged(int arg1)
{
        msg.interval = arg1;
}


void FormCanTx::on_leData0_textChanged(const QString &arg1)
{
   bool bStatus = false;
    msg.data[0] = ui->leData0->text().toUInt(&bStatus,16);
}

void FormCanTx::on_leData1_textChanged(const QString &arg1)
{
   bool bStatus = false;
    msg.data[1] = ui->leData1->text().toUInt(&bStatus,16);
}

void FormCanTx::on_leData2_textChanged(const QString &arg1)
{
        bool bStatus = false;
    msg.data[2] = ui->leData2->text().toUInt(&bStatus,16);
}

void FormCanTx::on_leData3_textChanged(const QString &arg1)
{
        bool bStatus = false;
    msg.data[3] = ui->leData3->text().toUInt(&bStatus,16);
}

void FormCanTx::on_leData4_textChanged(const QString &arg1)
{
        bool bStatus = false;
    msg.data[4] = ui->leData4->text().toUInt(&bStatus,16);
}

void FormCanTx::on_leData5_textChanged(const QString &arg1)
{
        bool bStatus = false;
     msg.data[5] = ui->leData5->text().toUInt(&bStatus,16);
}

void FormCanTx::on_leData6_textChanged(const QString &arg1)
{
        bool bStatus = false;
     msg.data[6] = ui->leData6->text().toUInt(&bStatus,16);
}

void FormCanTx::on_leData7_textChanged(const QString &arg1)
{
        bool bStatus = false;
    msg.data[7] = ui->leData7->text().toUInt(&bStatus,16);
}
