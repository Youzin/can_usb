#ifndef CANCOM_H
#define CANCOM_H

#include <QObject>
#include "mainwindow.h"

class   SerialCom;


class CanCom : public QObject
{
    Q_OBJECT

public:
    CanCom(QObject *parent, SerialCom *comm);
    ~CanCom();

    void setBaudrate(int baud);
    void getBaudrate();
    void sendPacket(MainWindow::CanMsg *msg);
private:
    SerialCom   *comm;
    int baudrate;



};

#endif // CANCOM_H
