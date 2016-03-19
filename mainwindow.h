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
#include "dataworkerthread.h"
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

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

private:
    void setInfo();
    void setInfo_detail();
    QString itos(int val);


private:
    Ui::MainWindow *ui;
    int pageIndex;
    int startFlag;
    QTimer *timer;
    QApplication *app;
    SysParam sysparam;
    DataWorkerThread *datath;
    QString record_start_time;
    QString record_end_time;
};

#endif // MAINWINDOW_H
