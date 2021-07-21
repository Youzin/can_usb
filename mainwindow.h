#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include    <QtWidgets>

#define MSG_HEAD    0xAA
#define MSG_CTRL    0xA5
#define MSG_TAIL    0x55

#define CAN_RESET_ID		0x01FFFEc0
#define CAN_ABOM_ID			0x01fffEb0
#define CAN_ART_ID			0x01fffEa0
#define CAN_FILTER_BASE_ID	0x01fffEe0
#define CAN_BAUD_ID			0x01fffEd0
#define CAN_INIT_FLASH_ID	0x01fffEff

#define CAN_CONFIG_CHANNEL	0xff

typedef enum {STANDARD_FORMAT = 0, EXTENDED_FORMAT} CAN_FORMAT;

/* Symbolic names for type of CAN message                                    */
typedef enum {DATA_FRAME = 0, REMOTE_FRAME}         CAN_FRAME;

namespace Ui {
class MainWindow;
}

class SerialCom;
class CanCom;
class FormCanTx;
class CanTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    struct CanMsg {
        uint32_t id;
        uint8_t data[8];
        uint8_t len;
        uint8_t ch;
        uint8_t format;
        uint8_t type;
        bool    repeat;
        int     interval;
    };

    CanMsg rxMsg, txMsg;

    int canRxCount = 0;
    int canTxCount = 0;
    int baudRate;

    int currentTime = 0;

    QList<CanTimer *> timerList;
    QTimer *rTimer;

public slots:
    void canTxData(FormCanTx *);
    void deleteTxData(FormCanTx *);
    void timerSlot();
    void enableTimer(MainWindow::CanMsg *msg);
    void disableTimer(MainWindow::CanMsg *msg);

private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();
    void handleError(QSerialPort::SerialPortError error);
    void on_cbComBaud_currentIndexChanged(int index);

    void on_btnConnect_clicked();

    void on_btnRxClear_clicked();

    void on_btnCanBaudRate_clicked();

    void on_btnCanGetBaudRate_clicked();

    void on_btnAddTx_clicked();
    void on_btnSaveTx_clicked();
    void on_btnLoadTx_clicked();
    void showRxData(QString, CanMsg *);


    void on_btnSaveRx_clicked();

    void on_btnLoadRx_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *status;
    SerialCom *comm;
    CanCom *can;

    QStringList colHeaders = { "TIME", "ID(32bit)", "[0]", "[1]","[2]","[3]",
                            "[4]","[5]","[6]","[7]",
                            "LEN", "CH", "FORMAT", "TYPE"};

    void showStatusMessage(const QString &message);

    bool    comOpen = false;
    QString portName;
    QStringList portList;

    void initListTx();
    void initTableRx();
    void rxCanMsg(CanMsg *msg);
    void addTxData();
    void addTxData(CanMsg *msg);
};

#endif // MAINWINDOW_H
