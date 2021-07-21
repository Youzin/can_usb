#ifndef CANTIMER_H
#define CANTIMER_H

#include <QObject>
#include "mainwindow.h"

class CanTimer
{

public:
    CanTimer(MainWindow::CanMsg *msg);
    ~CanTimer();

    MainWindow::CanMsg *msg;
    int timeout = 0;

};

#endif // CANTIMER_H
