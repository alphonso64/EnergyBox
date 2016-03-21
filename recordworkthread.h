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
using namespace xlslib_core;
using namespace std;

class RecordWorkThread : public QThread
{
    Q_OBJECT
public:
    RecordWorkThread(QObject *parent = 0)
        : QThread(parent)
    {

    }
protected:
    void run()
    {
        recorderFlag = false;

        workbook wb;
        xf_t* xf = wb.xformat();
        worksheet* ws;
        ws = wb.sheet("sheet1");
        setTitle(ws,xf);
        int cnt = 0;
        while(!recorderFlag)
        {
            EnergyParam param = dataWoker->getEnergyParam();
            if(lastTime != param.time)
            {
                cnt++;
                ws->label(cnt,0,itos(param.time),xf);
                ws->label(cnt,1,itos(param.voltage_a),xf);
                ws->label(cnt,2,itos(param.voltage_b),xf);
                ws->label(cnt,3,itos(param.voltage_c),xf);
                ws->label(cnt,4,itos(param.current_a),xf);
                ws->label(cnt,5,itos(param.current_b),xf);
                ws->label(cnt,6,itos(param.current_c),xf);

                ws->label(cnt,7,itos(param.power_factor),xf);
                ws->label(cnt,8,itos(param.frequency),xf);
                ws->label(cnt,9,itos(param.active_power),xf);
                ws->label(cnt,10,itos(param.reactive_power),xf);
                ws->label(cnt,11,itos(param.apparent_power),xf);

                ws->label(cnt,12,itos(param.env_temp),xf);
                ws->label(cnt,13,itos(param.env_humidity),xf);
                ws->label(cnt,14,itos(param.air_temp),xf);
                ws->label(cnt,15,itos(param.air_pressure),xf);
                ws->label(cnt,16,itos(param.flow_content),xf);
                lastTime = param.time;
            }
            usleep(200000);
        }
        qDebug() << "save file : " << title ;
        string ss = title.toStdString();
        printf("save file : %s",ss.c_str());
        wb.Dump(ss);
    }
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
	}
	
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

public:
	DataWorkerThread *dataWoker;
    bool recorderFlag;
    QString title;
	long lastTime;
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
