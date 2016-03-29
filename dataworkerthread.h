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
        time = -1;
    }
protected:
    void run();

    void parseParam(char *temp);

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

private:
    EnergyParam energyparam;
    QMutex mutex;
    unsigned char sendBuf[28];
     int fd ;
};

#endif // DATAWORKERTHREAD_H
