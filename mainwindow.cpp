#include "mainwindow.h"
#include "ui_mainwindow.h"

#include    "SerialCom.h"
#include    "CanCom.h"
#include    "formcantx.h"
#include    "CanTimer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    comm = new SerialCom(this);
    can = new CanCom(this, comm);

    status = new QLabel;
    ui->statusBar->addWidget(status);

    connect(comm, SIGNAL(readyRead()), this, SLOT(readData()));

    int i;

    portList = comm->scanPorts();
    ui->cbComBaud->addItems(portList);

    initListTx();
    initTableRx();

    rTimer = new QTimer(this);
    connect(rTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    rTimer->start(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerSlot()
{
    CanTimer *ctimer;

    currentTime++;
    for (int i= 0; i < timerList.length(); i++) {
        ctimer = timerList[i];
        if ( ctimer->timeout <= currentTime )  {
            if ( ctimer->msg->interval != 0 ) can->sendPacket(ctimer->msg);
            ctimer->timeout = currentTime + ctimer->msg->interval;
            qDebug() << "TIMEOUT: " << ctimer->msg->interval << currentTime;
        }
    }
}

void MainWindow::enableTimer(CanMsg *msg)
{
    CanTimer *timer = new CanTimer(msg);

    timer->timeout = currentTime + msg->interval;
    timerList.append(timer);
}

void MainWindow::disableTimer(CanMsg *msg)
{
    CanTimer *timer;

    for ( int i=0; i < timerList.length();i++) {
        if ( timerList[i]->msg == msg ) {
            timer = timerList[i];
            timerList.removeAt(i);
            qDebug() << "DEL TIMER:" << timer;
            delete timer;
            break;
        }
    }
}

void MainWindow::addTxData()
{
    QListWidgetItem *txItem = new QListWidgetItem();
    FormCanTx *formTx = new FormCanTx(this, txItem);

    txItem->setSizeHint(formTx->sizeHint());

    ui->listTx->addItem( txItem);
    ui->listTx->setItemWidget(txItem, formTx);
    qDebug() << "CAN TX DATA: " << ui->listTx->count();
}

void MainWindow::addTxData(CanMsg *msg)
{
    QListWidgetItem *txItem = new QListWidgetItem();
    FormCanTx *formTx = new FormCanTx(this, txItem);

    formTx->setTxMsg(msg);
    txItem->setSizeHint(formTx->sizeHint());

    ui->listTx->addItem( txItem);
    ui->listTx->setItemWidget(txItem, formTx);
    qDebug() << "CAN TX DATA: " << ui->listTx->count();
}

void MainWindow::deleteTxData(FormCanTx * tx)
{

    int row = ui->listTx->currentRow();
    QListWidgetItem *item = tx->txItem;
     //ui->listTx->takeItem(row);
     ui->listTx->removeItemWidget(item);
    // delete tx;
     delete item; // Qt documentation warnings you to destroy item to effectively remove it from QListWidget.

    qDebug() << "DELETE TX:" << row;
    ui->listTx->scrollToTop();
}

void MainWindow::canTxData(FormCanTx * tx)
{
    qDebug() << "CAN TX:" << tx->msg.id;
    can->sendPacket(&tx->msg);
}

void MainWindow::initListTx()
{
    addTxData();
}

void MainWindow::initTableRx()
{
    ui->twRx->setColumnCount(colHeaders.length());
    ui->twRx->setHorizontalHeaderLabels(colHeaders);
    ui->twRx->setColumnWidth(0, 100);
       ui->twRx->setColumnWidth(1, 100);

    for (int i= 2; i <= 9; i++) {
        ui->twRx->setColumnWidth(i, 40);
    }
    ui->twRx->setColumnWidth(10, 40);
    ui->twRx->setColumnWidth(11, 60);
    ui->twRx->setColumnWidth(12, 80);
    ui->twRx->setColumnWidth(13, 60);
}

void MainWindow::openSerialPort()
{
    if (comm->open(portName)) {
        comOpen = true;
        showStatusMessage(tr("Connected to %1 : %2")
                          .arg(portName).arg("115200"));
    } else {
        comOpen = false;
        QMessageBox::critical(this, tr("Error"), comm->errorString());
        showStatusMessage(tr("Open error"));
    }
}

void MainWindow::closeSerialPort()
{
    comm->close();
    comOpen = false;
    showStatusMessage(tr("Disconnected"));
}

void MainWindow::writeData(const QByteArray &data)
{
    comm->writeData(data);
}


void MainWindow::readData()
{
    QByteArray rxRaw = comm->readData();
    QByteArray rxData;

    qint64 timeStamp = QDateTime::currentMSecsSinceEpoch() - QDateTime(QDate::currentDate()).toMSecsSinceEpoch();
    qDebug() << "RCV:" << QString::number(rxRaw[0], 16);
    //ui->lwRx->addItem(rxRaw.toHex());

    bool esc = false;
    int j = 0;
    for ( int i =0; i < rxRaw.length(); i++) {
        if ( !esc && rxRaw[i] == 0xA5 ) {
            if ( rxRaw[i+1] == 0xAA || rxRaw[i+1] ==0xA5 || rxRaw[i+1] ==0x55) {
                esc = true;
                continue;
            }
        }
        esc = false;
        rxData[j++] = rxRaw[i];
    }

    CanMsg *msg;
    msg = (CanMsg *) ( rxData.data() + 2);

    QTableWidgetItem *colList[14];
    char  hex[10];

    int msec, sec, min, hour;
    msec = timeStamp % 1000;
    sec = (timeStamp / 1000) % 60;
    min = (timeStamp / 60000 ) % 60;
    hour = (timeStamp / (1000 * 60 * 60) ) % 24;

    char time[20];
    sprintf(time, "%02d:%02d:%02d:%03d", hour, min, sec, msec);
    colList[0] = new QTableWidgetItem(time);

    if (msg->format == 0 && msg->id < 0x800) {
        sprintf(hex, "%03X", msg->id);
    }
    else sprintf(hex, "%08X", msg->id);
    colList[1] = new QTableWidgetItem(hex);
    for (int i = 0; i < 8; i++ ) {
        sprintf(hex, "%02X", msg->data[i]);
        colList[2+i] = new QTableWidgetItem(hex);
    }
    sprintf(hex, "%02X", msg->len);
    colList[10] = new QTableWidgetItem(hex);

    sprintf(hex, "%02X", msg->ch);
    colList[11] = new QTableWidgetItem(hex);

    if ( msg->format == 0 ) strcpy(hex, "STD");
    else if ( msg->format == 1 ) strcpy(hex, "EXT");
    else sprintf(hex, "%02X", msg->format);
    colList[12] = new QTableWidgetItem(hex);

    if ( msg->type == 0 ) strcpy(hex, "DATA");
    else if ( msg->type == 1 ) strcpy(hex, "REMOTE");
    else sprintf(hex, "%02X", msg->type);
    colList[13] = new QTableWidgetItem(hex);

    ui->twRx->setRowCount(canRxCount+1);
    for ( int i = 0; i < 14; i++) {
        colList[i]->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->twRx->setItem(canRxCount, i, colList[i]);
    }

    ui->twRx->scrollToBottom();
    canRxCount++;

    rxCanMsg(msg);
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), portName);
        comm->close();
    }
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

void MainWindow::rxCanMsg(CanMsg *msg)
{
    if (msg->ch != CAN_CONFIG_CHANNEL ) return;


    switch (msg->id)  {
        case CAN_INIT_FLASH_ID:
        break;
        case CAN_RESET_ID:
            break;
        case CAN_ABOM_ID:
            break;
        case CAN_ART_ID:
            break;
        case CAN_FILTER_BASE_ID:
            break;
        case CAN_BAUD_ID:
        {   int baud = *((int *)msg->data);
            ui->leBaudrate->setText(QString::number(baud));
            qDebug() << "CAN BAUD RATE:" << baud;
        }
        break;
        default:
            break;
    }

}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}

void MainWindow::on_cbComBaud_currentIndexChanged(int index)
{
    portName = portList.at(index);
    qDebug() << "COM: " << portName;
}

void MainWindow::on_btnConnect_clicked()
{
    if ( comOpen == false ) {
        openSerialPort();
        if ( comOpen ) {
            ui->btnConnect->setText("DISCONNECT");
            return;
        }
    }
    else {
        closeSerialPort();
         ui->btnConnect->setText("CONNECT");
    }

}

void MainWindow::on_btnRxClear_clicked()
{
    canRxCount = 0;
    ui->twRx->setRowCount(0);
}

void MainWindow::on_btnCanBaudRate_clicked()
{
    int baudrate = ui->leBaudrate->text().toInt();
    can->setBaudrate(baudrate);
}


void MainWindow::on_btnCanGetBaudRate_clicked()
{
     can->getBaudrate();
}

void MainWindow::on_btnAddTx_clicked()
{
    addTxData();
}



void MainWindow::on_btnSaveTx_clicked()
{
    int txSize;

    baudRate = ui->leBaudrate->text().toInt();
    txSize = ui->listTx->count();
    qDebug() << "TX size =" << txSize;

    QListWidgetItem *txItem;
    FormCanTx *txForm;
    CanMsg *msg;

    QString fname = QFileDialog::getSaveFileName(nullptr, "Save Tx Message", ".", "CTX(*.ctx)" );
       qDebug() << "name is : " << fname;
    QFile file(fname);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    out << "#CAN TX MESSAGES "<< endl;
    out << baudRate << ", " << txSize << endl;
    for (int i=0; i < txSize; i++) {
        txItem = ui->listTx->item(i);
        txForm = (FormCanTx *) ui->listTx->itemWidget(txItem);
        msg = txForm->getTxMsg();

        qDebug() << i << msg->id << msg->data[0];
        out << msg->id << ", ";
        for ( int j = 0; j < 8; j++) {
            out << msg->data[j] << ", ";
        }
        out << msg->ch<< ", ";
        out << msg->len<< ", ";
        out << msg->format<< ", ";
        out << msg->type << ", ";
        out << msg->interval << endl;

    }
    // optional, as QFile destructor will already do it:
    file.close();
    can->setBaudrate(baudRate);
}

void MainWindow::on_btnLoadTx_clicked()
{
    CanMsg msg;
    QString line;
    int msgSize;

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open CAN MESSAGES"), "",
        tr("CTX(*.ctx);;All Files (*)"));

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }
    QTextStream in(&file);
    qDebug() << in.readLine();
    line  = in.readLine();
    QTextStream(&line) >> baudRate >> msgSize;
    qDebug() << baudRate << msgSize;

    QStringList list;
   while (!in.atEnd())
   {
        line = in.readLine();
        list = line.split(QRegExp("(\\s|,)+"));
        qDebug() << "list" << list;
        msg.id = list[0].toInt();
        qDebug() << msg.id;
        for ( int i = 0; i < 8; i ++ ) {
          msg.data[i] = list[i+1].toInt();
          qDebug() << list[i+1] << msg.data[i];
        }
        msg.ch = list[9].toInt();
        msg.len = list[10].toInt();
        msg.format = list[11].toInt();
        msg.type = list[12].toInt();
        msg.interval = list[13].toInt();
        qDebug() << msg.ch << msg.len << msg.format << msg.type << endl;

       addTxData(&msg);
   }
   file.close();

}

void MainWindow::on_btnSaveRx_clicked()
{
    QTableWidgetItem *item;
    QString line;
    int size ;

    size = ui->twRx->rowCount();
    qDebug() << "RX Size:" << size;


    QString fname = QFileDialog::getSaveFileName(nullptr, "Save Rx Message", ".", "CRX(*.crx)" );
    qDebug() << "RX FILE : " << fname;
    QFile file(fname);
    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(this, tr("Unable to open file"),
        file.errorString());
        return;
    }
    QTextStream out(&file);

    out << "#CAN RX MESSAGES "<< endl;
    out << baudRate << ", " << size << endl;

    for ( int row = 0; row < size; row++) {
        line ="";
        for ( int col = 0; col < 14; col++ ) {
            item = ui->twRx->item(row, col);
            line.append(item->text());
            if ( col < 13) line.append(", ");
        }
        line.append("\n");
        out << line;
        qDebug() << line;
    }
    file.close();
}


void MainWindow::showRxData(QString time, CanMsg *msg)
{
    QTableWidgetItem *colList[14];
    char  hex[10];

    colList[0] = new QTableWidgetItem(time);

    if (msg->format == 0 && msg->id < 0x800) {
        sprintf(hex, "%03X", msg->id);
    }
    else sprintf(hex, "%08X", msg->id);
    colList[1] = new QTableWidgetItem(hex);
    for (int i = 0; i < 8; i++ ) {
        sprintf(hex, "%02X", msg->data[i]);
        colList[2+i] = new QTableWidgetItem(hex);
    }
    sprintf(hex, "%02X", msg->len);
    colList[10] = new QTableWidgetItem(hex);

    sprintf(hex, "%02X", msg->ch);
    colList[11] = new QTableWidgetItem(hex);

    if ( msg->format == 0 ) strcpy(hex, "STD");
    else if ( msg->format == 1 ) strcpy(hex, "EXT");
    else sprintf(hex, "%02X", msg->format);
    colList[12] = new QTableWidgetItem(hex);

    if ( msg->type == 0 ) strcpy(hex, "DATA");
    else if ( msg->type == 1 ) strcpy(hex, "REMOTE");
    else sprintf(hex, "%02X", msg->type);
    colList[13] = new QTableWidgetItem(hex);

    ui->twRx->setRowCount(canRxCount+1);
    for ( int i = 0; i < 14; i++) {
        colList[i]->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->twRx->setItem(canRxCount, i, colList[i]);
    }

    ui->twRx->scrollToBottom();
    canRxCount++;

    rxCanMsg(msg);
}

void MainWindow::on_btnLoadRx_clicked()
{
    CanMsg msg;
    QString line;
    int msgSize;

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open CAN MESSAGES"), "",
        tr("CRX(*.crx);;All Files (*)"));

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }
    QTextStream in(&file);
    qDebug() << in.readLine();
    line  = in.readLine();
    QTextStream(&line) >> baudRate >> msgSize;
    qDebug() << baudRate << msgSize;

    QStringList list;
    QString time;
   while (!in.atEnd())
   {
        line = in.readLine();
        list = line.split(QRegExp("(\\s|,)+"));
        qDebug() << "list" << list;
        time = list[0];
        msg.id = list[1].toInt();
        qDebug() << msg.id;
        for ( int i = 0; i < 8; i ++ ) {
          msg.data[i] = list[i+2].toInt();
          qDebug() << list[i+1] << msg.data[i];
        }
        msg.ch = list[10].toInt();
        msg.len = list[11].toInt();
        if ( list[12] == "STD" ) msg.format = 0;
        else msg.format = 1;
        msg.type = list[13].toInt();
       // msg.interval = list[13].toInt();
        qDebug() << msg.ch << msg.len << msg.format << msg.type << endl;

       showRxData(time, &msg);
   }
   file.close();

}
