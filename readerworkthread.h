#ifndef READERWORKTHREAD_H
#define READERWORKTHREAD_H

#include <QThread>
#include <QString>
#include <stdlib.h>
#include <stdio.h>
#include "XlsReader.h"

#include <string>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include "analyzeresult.h"
using namespace xls;
using namespace std;

struct CalTmp
{
    float cur_a;
    float power;
    float vsp;
//    float cur_b;
//    float cur_c;
//    float vol_a;
//    float vol_b;
//    float vol_c;
    long time;
    long status;//1--load //0--unload //2-standby
    float cur_a_ave;
};

struct CalRes
{
    long loadTime;
    long unloadTime;
    long loadCnt;
    long unloadCnt;
    float loadCharge;
    float Charge;
    float loadPower;
    float unloadPower;
};

struct CalStatus
{
    long status;//1--load //0--unload //2-standby
    float last_cur_a;
};


class ReaderWorkThread : public QThread
{
    Q_OBJECT
public:
    ReaderWorkThread(QObject *parent = 0)
        : QThread(parent)
    {

    }

signals:
    void result();

protected:
    template <class Type>
    Type stringToNum(const string& str)
    {
        istringstream iss(str);
        Type num;
        iss >> num;
        return num;
    }

    void run();

private:
void clear(CalTmp *temp,int len);

void computeEnergy(CalTmp *temp,int len,CalStatus *status,AnalyzeResult *res);

public:
    QString path;
    AnalyzeResult res;
    std::string start_time;
    std::string meassure_time;
};

#endif // READERWORKTHREAD_H
