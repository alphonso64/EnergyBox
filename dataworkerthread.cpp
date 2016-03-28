#include "dataworkerthread.h"
#include "util.h"

void DataWorkerThread::run()
{
    int fd ;
    if ((fd = serialOpen ("/dev/ttyAMA0", 115200)) < 0)
    {
//          fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
      return ;
    }
    int len = 128;
    char temp[len];
    serialFlush(fd);
    while(1)
    {

        int val = serialDataAvail (fd);
        if(val == len)
        {
            for(int i=0;i<len;i++)
            {
                temp[i] = serialGetchar(fd);
            }
            int *head = (int *)temp;
            if(*head == 0x5a6c)
            {
                parseParam(temp+4);
            }
            Util::SysLogD("receive: %x \n",*head);
        }else if(val > len)
        {
            serialFlush(fd);
        }

    }

}

void DataWorkerThread::parseParam(char *temp)
{
    mutex.lock();
    float *data = (float *)(temp);
    long *ltime = (long *)(temp);
    energyparam.voltage_a = data[5];
    energyparam.voltage_b = data[6];
    energyparam.voltage_c = data[7];
    energyparam.current_a = data[11];
    energyparam.current_b = data[12];
    energyparam.current_c = data[13];

    energyparam.power_factor = data[17];
    energyparam.frequency = data[18];
    energyparam.active_power = data[14];
    energyparam.reactive_power = data[15];
    energyparam.apparent_power = data[16];

    energyparam.env_temp = data[19];
    energyparam.env_humidity = data[20];
    energyparam.air_temp = data[1];
    energyparam.air_pressure = data[2];
    energyparam.flow_content = data[3];
    energyparam.time = *ltime;
    time = energyparam.time ;
    energyparam.power = (energyparam.voltage_a*energyparam.current_a + energyparam.voltage_b*energyparam.current_b + energyparam.voltage_c*energyparam.current_c)/1000;
    if(energyparam.flow_content > -0.000001 && energyparam.flow_content <0.000001)
    {
        energyparam.vsp =0;
    }else
    {
        energyparam.vsp =energyparam.power /  energyparam.flow_content;
    }
    Util::SysLogD("param: %d %d\n",energyparam.time, energyparam.time);
    mutex.unlock();
}


