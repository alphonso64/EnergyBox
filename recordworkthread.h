#ifndef RECORDWORKTHREAD_H
#define RECORDWORKTHREAD_H

#include <QThread>
#include <QString>
#include <stdlib.h>
#include <stdio.h>
#include <QDebug>
#include <xlslib/xlslib.h>
#include <pthread.h>
#include "dataworkerthread.h"
#include "energyparam.h"
#include <iostream>
#include <sstream>
#include "analyzeresult.h"
#include "const_define.h"
#include <QMutex>
using namespace xlslib_core;
using namespace std;

#define STAGE_LOAD 2
#define STAGE_UNLOAD 1
#define STAGE_STANDBY 0

struct CurrentStaus
{
    int state ;  //2--load //1--unload //0-standby
    long duration;
    long lastTime;
    float lastPower;
    float lastFlow;
    long acc_vsp_cnt;
};

class RecordWorkThread : public QThread
{
    Q_OBJECT
public:
    RecordWorkThread(QObject *parent = 0)
        : QThread(parent)
    {

    }
     AnalyzeResult getAnares();
protected:
    void run();
signals:
    void recordoverflow(int cmd);

private:
    void setTitle(worksheet* ws,xf_t* xf);

    void writeParam(worksheet* ws,xf_t* xf,EnergyParam param,int cnt);

    void updateResult(CurrentStaus *stas,EnergyParam* param);

    void initStatus(CurrentStaus *stas,EnergyParam *param);

	string itos(float val){
		stringstream ss;
		ss<<val;
		return ss.str();
	}
	
	string itos(long val){
		stringstream ss;
		ss<<val;
		return ss.str();
	}

    bool overflow;   
    QMutex mutex;

public:    
	DataWorkerThread *dataWoker;
    bool recorderFlag;
    QString title;
    AnalyzeResult anares;
    AnalyzeResult anares_cpy;
    int max_cur_standby;
    int max_cur_unload;
    float power_charge;
    float power_charge_valley;
    float power_charge_peak;
    float power_charge_normal;
    int charge_type;
    int normal_period[PEROID_LENGTH];
    int peak_period[PEROID_LENGTH];
    int valley_period[PEROID_LENGTH];


    string path_pre;
    float acc_power;
    float acc_flow;
    float load_radio;
};

//class DataWorkerThread
//{
//public:
//    DataWorkerThread()
//    {

//    }

//	void run();

//public:

//};

#endif // RECORDWORKTHREAD_H
