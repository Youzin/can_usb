#include "serialcom.h"

#include <QtSerialPort/QSerialPortInfo>

SerialCom::SerialCom(QObject *parent)
{
    serial = new QSerialPort(this);
    portList = scanPorts();

    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &SerialCom::handleError);
    connect(serial, &QSerialPort::readyRead, this, &SerialCom::readyData);
}

SerialCom::~SerialCom()
{

}

QStringList SerialCom::scanPorts()
{
    QStringList list;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        list.append(info.portName());
    }

   // qDebug() << "SCAN ports" << list;
    return list;
}

SerialCom::ComStatus   SerialCom::getStatus()
{
    return status;
}

bool SerialCom::open(QString portName)
{
    status.portName = portName;
    status.baudrate = QSerialPort::Baud115200;

    serial->setPortName(status.portName);
    serial->setBaudRate(status.baudrate );
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        status.open = true;

    } else {
        status.open = false;
    }

    return status.open;
}

SerialCom::ComStatus SerialCom::close()
{
    if (serial->isOpen())  serial->close();
    status.open = false;

    return status;
}

void SerialCom::writeData(const QByteArray &data)
{
    serial->write(data);
}

QByteArray SerialCom::readData()
{
    QByteArray data = serial->readAll();
    return data;
}

void SerialCom::readyData()
{
    emit readyRead();
}

QString SerialCom::errorString()
{
    return serial->errorString();

}

void SerialCom::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        //QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        close();
    }
}

void SerialCom::sendPacket(QByteArray packet, int len)
{

}


