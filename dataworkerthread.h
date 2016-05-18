#ifndef DATAWORKERTHREAD_H
#define DATAWORKERTHREAD_H

#include <QThread>
#include <QString>
#include <stdlib.h>
#include <stdio.h>
#include <QDebug>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <unistd.h>
#include "energyparam.h"
#include <QMutex>
using namespace std;

class DataWorkerThread : public QThread
{
    Q_OBJECT
public:
    DataWorkerThread(QObject *parent = 0)
        : QThread(parent)
    {
        time = 0;
    }
protected:
    void run();

    void parseParam(char *temp);

    void parseResult(char *temp);

signals:
    void setEcho(int res);

public:
    EnergyParam getEnergyParam()
    {
        mutex.lock();
        EnergyParam param;
        param.cpy(energyparam);
        mutex.unlock();
        return param;
    }

    long time;

    void sendMsg(int cmd_a,int val_a,int cmd_b,int val_b,int cmd_e,int val_c);

    int env_temp_type;
    float env_temp;
    int env_hum_type;
    float env_hum;
    float flow_modify;
    float power_modify;

private:
    EnergyParam energyparam;
    QMutex mutex;
    unsigned char sendBuf[28];
     int fd ;
};

#endif // DATAWORKERTHREAD_H
