#ifndef FORMCANTX_H
#define FORMCANTX_H

#include <QtCore/QtGlobal>
#include <QtWidgets>
#include "mainwindow.h"

namespace Ui {
class FormCanTx;
}

class FormCanTx : public QWidget
{
    Q_OBJECT

public:
    FormCanTx(QWidget *parent, QListWidgetItem *item);
    ~FormCanTx();

    MainWindow::CanMsg msg;
    QListWidgetItem *txItem;
    MainWindow::CanMsg *getTxMsg();
    void setTxMsg(MainWindow::CanMsg *);

signals:
    void send(FormCanTx *);
    void remove(FormCanTx *);
    void enableTimer(MainWindow::CanMsg *);
    void disableTimer(MainWindow::CanMsg *);

private slots:
    void on_btnSend_clicked();
    void on_btnDelete_clicked();

    void on_checkBox_clicked(bool checked);
    void on_sbInterval_valueChanged(int arg1);

    void on_leData7_textChanged(const QString &arg1);

    void on_leData0_textChanged(const QString &arg1);

    void on_leData1_textChanged(const QString &arg1);

    void on_leData2_textChanged(const QString &arg1);

    void on_leData3_textChanged(const QString &arg1);

    void on_leData4_textChanged(const QString &arg1);

    void on_leData5_textChanged(const QString &arg1);

    void on_leData6_textChanged(const QString &arg1);

private:
    Ui::FormCanTx *ui;

    QStringList formats = { "STD", "EXT" };
    QStringList types = {"DATA", "REMOTE"};
};

#endif // FORMCANTX_H
