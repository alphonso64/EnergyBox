#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <iostream>
#include <sstream>
#include <QDateTime>
#include <QTextCodec>
#include "sysparam.h"
#include "recordworkthread.h"
#include "dataworkerthread.h"
#include "commondial.h"
#include "custommessagebox.h"
#include "filewidget.h"
#include "readerworkthread.h"
#include "chargeform.h"
#include <QPalette>
#include "filecopyer.h"
#include "aboutwidget.h"
using namespace std;
namespace Ui {
class MainWindow;
}

template <class Type>
Type stringToNum(const string& str)
{
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_5_pressed();

    void on_pushButton_6_pressed();

    void on_pushButton_7_pressed();

    void on_pushButton_8_pressed();

    void on_pushButton_9_pressed();

    void show_time();

    void check_status();

    void on_overflow(int cmd);

    void on_setEcho(int res);

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_pressed();

    void on_pushButton_13_pressed();

    void on_pushButton_14_pressed();

    void on_analysis(QString);

    void on_result();

    void on_setPeriod(int);

    void on_copyDone(int);

    void on_pushButton_15_pressed();

    void on_pushButton_16_pressed();

    void on_pushButton_17_pressed();

    void on_pushButton_18_pressed();

    void on_pushButton_18_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_pressed();

    void on_pushButton_19_pressed();

    void on_pushButton_25_clicked();

    void on_pushButton_25_pressed();

    void on_pushButton_26_pressed();

    void on_pushButton_27_pressed();

    void on_pushButton_28_pressed();

    void on_pushButton_29_pressed();

    void on_comboBox_env_temp_currentIndexChanged(int index);

    void on_comboBox_env_hum_currentIndexChanged(int index);

    void on_cusMsg_return(int flag);

private:
    void setInfo(EnergyParam param);
    void setInfo_detail(EnergyParam param);
    QString itos(int val);
    void clearAnalyzeView();
    QPalette colorTheme( const QColor & ) const;

private:
    Ui::MainWindow *ui;
    int pageIndex;
    int startFlag;
    QTimer *timer;
    QTimer *timer_check;
    QApplication *app;
    SysParam sysparam;
    RecordWorkThread *recorder;
    DataWorkerThread *dataWoker;
    ReaderWorkThread *reader;
    FileCopyer *copyer;
    QString record_start_time;
    QString record_end_time;
    CommonDial *flowDial;
    CommonDial *powerDial;
    CustomMessageBox *cusMsg;
    QDateTime  startTime;
    FileWidget *file;
    ChargeForm *chargeform;
    AboutWidget *aboutwidget;
    bool timeStampFlag;
    bool saveState;
};

#endif // MAINWINDOW_H
