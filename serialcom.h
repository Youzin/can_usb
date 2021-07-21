#ifndef SERIALCOM_H
#define SERIALCOM_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

class SerialCom : public QObject
{
    Q_OBJECT

public:
    explicit SerialCom(QObject *parent = 0);
    ~SerialCom();

    struct ComStatus {
        QString portName;
        bool    open;
        int     baudrate;
    } status;

    bool open(QString portName);
    SerialCom::ComStatus close();
    void writeData(const QByteArray &data);
    QByteArray readData();
    void readyData();
    QStringList scanPorts();
    struct ComStatus  getStatus();
    QString errorString();
    void sendPacket(QByteArray packet, int len);

signals:
    void    readyRead();

public slots:

private:
    QSerialPort *serial;
    QStringList portList;
    void handleError(QSerialPort::SerialPortError error);
};

#endif // SERIALCOM_H
