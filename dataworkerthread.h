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

    }
protected:
    void run()
    {
        int fd ;
        if ((fd = serialOpen ("/dev/ttyAMA0", 115200)) < 0)
        {
//          fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
          return ;
        }
        char temp[100];
        while(1)
        {

            int val = serialDataAvail (fd);
            if(val == 100)
            {
                for(int i=0;i<100;i++)
                {
                    temp[i] = serialGetchar(fd);
                }
                if(temp[0] == 0x55 && temp[1] == 0x5a)
                {
                    parseParam(temp+2);
                }
                printf("read size %d\n",val);
            }else if(val > 100)
            {
                serialFlush(fd);
            }

        }

    }

    void parseParam(char *temp)
    {
        mutex.lock();
        float *data = (float *)temp;
        energyparam.voltage_a = data[0];
        energyparam.voltage_b = data[1];
        energyparam.voltage_c = data[2];
        energyparam.current_a = data[3];
        energyparam.current_b = data[4];
        energyparam.current_c = data[5];

        energyparam.power_factor = data[6];
        energyparam.frequency = data[7];
        energyparam.active_power = data[8];
        energyparam.reactive_power = data[9];
        energyparam.apparent_power = data[10];

        energyparam.env_temp = data[11];
        energyparam.env_humidity = data[12];
        energyparam.air_temp = data[13];
        energyparam.air_pressure = data[14];
        energyparam.flow_content = data[15];
        energyparam.time = data[16];
        energyparam.power = (energyparam.voltage_a*energyparam.current_a + energyparam.voltage_b*energyparam.current_b + energyparam.voltage_c*energyparam.current_c)/1000;
        if(energyparam.flow_content > -0.000001 && energyparam.flow_content <0.000001)
        {
            energyparam.vsp =0;
        }else
        {
            energyparam.vsp =energyparam.power /  energyparam.flow_content;
        }
        printf("param: %f %f\n",energyparam.voltage_a,energyparam.flow_content);
        mutex.unlock();
    }
public:
    EnergyParam getEnergyParam()
    {
        mutex.lock();
        EnergyParam param;
        param.cpy(energyparam);
        mutex.unlock();
        return param;
    }

private:
    EnergyParam energyparam;
    QMutex mutex;



};

#endif // DATAWORKERTHREAD_H
