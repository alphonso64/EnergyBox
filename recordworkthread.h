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
protected:
    void run();
signals:
    void recordoverflow(int cmd);

private:
    void setTitle(worksheet* ws,xf_t* xf)
    {
        ws->label(0,0,"记录时间",xf);
        ws->label(0,1,"A相电压",xf);
        ws->label(0,2,"B相电压",xf);
        ws->label(0,3,"C相电压",xf);
        ws->label(0,4,"A相电流",xf);
        ws->label(0,5,"B相电流",xf);
        ws->label(0,6,"C相电流",xf);

        ws->label(0,7,"频率",xf);
        ws->label(0,8,"有功功率",xf);
        ws->label(0,9,"无功功率",xf);
        ws->label(0,10,"视在功率",xf);
        ws->label(0,11,"功率因素",xf);

        ws->label(0,12,"环境温度",xf);
        ws->label(0,13,"环境湿度",xf);
        ws->label(0,14,"排气温度",xf);
        ws->label(0,15,"排气压力",xf);
        ws->label(0,16,"流量",xf);
        ws->label(0,17,"功率",xf);
        ws->label(0,18,"比功率",xf);
		ws->label(0,19,"加卸载状态",xf);
    }

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

public:
	DataWorkerThread *dataWoker;
    bool recorderFlag;
    QString title;
    AnalyzeResult anares;
    int max_cur_standby;
    int max_cur_unload;
    float power_charge;
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
