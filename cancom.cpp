#include "serialcom.h"
#include "mainwindow.h"
#include "cancom.h"


CanCom::CanCom(QObject *parent, SerialCom *pcomm):comm(pcomm)
{


}

CanCom::~CanCom()
{

}


void CanCom::sendPacket(MainWindow::CanMsg *msg)
{
    uint8_t checkSum = 0, pindex;
    QByteArray packet, txBuf;
    unsigned char *msgBuf = (unsigned char *)msg;

    packet[0] = MSG_HEAD;
    packet[1] = MSG_HEAD;
    pindex = 2;
    for (int i=0; i < 16; i++ ) {
        if ( msgBuf[i]== MSG_HEAD || msgBuf[i]== MSG_CTRL || msgBuf[i]== MSG_TAIL) {
            packet[pindex++] = MSG_CTRL;
            qDebug() << "MSG CTRL" << msgBuf[i];
        }
        packet[pindex++] = msgBuf[i];
        checkSum += msgBuf[i];
    }

    if ( checkSum == MSG_HEAD || checkSum== MSG_CTRL || checkSum == MSG_TAIL) {
        packet[pindex++] = MSG_CTRL;
    }
    packet[pindex++] = checkSum;
    packet[pindex++] = MSG_TAIL;
    packet[pindex++] = MSG_TAIL;

    comm->writeData(packet);
    qDebug() << "CAN TX:" << packet;
}

void CanCom::getBaudrate()
{
    qDebug() << "CAN get baudrate" ;

    MainWindow::CanMsg *msg;
    char msgBuf[16];

    msg = (MainWindow::CanMsg *) msgBuf;
    msg->id = CAN_BAUD_ID;
    *((uint32_t *) msg->data) = 0;
    *((uint32_t *) &msg->data[4]) = 0;
    msg->len = 0x08;
    msg->ch = CAN_CONFIG_CHANNEL;
    msg->format = 0;
    msg->type = REMOTE_FRAME;

    sendPacket(msg);

}

void CanCom::setBaudrate(int baud)
{
    qDebug() << "CAN Set baudrate" << baud;

    uint8_t checkSum = 0, pindex;

    MainWindow::CanMsg *msg;
    char msgBuf[16];

    msg = (MainWindow::CanMsg *) msgBuf;
    msg->id = CAN_BAUD_ID;
    *((uint32_t *) msg->data) = baud;
    *((uint32_t *) &msg->data[4]) = 0;
    msg->len = 0x08;
    msg->ch = CAN_CONFIG_CHANNEL;
    msg->format = 0;
    msg->type = DATA_FRAME;

    sendPacket(msg);
}
