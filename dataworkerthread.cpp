#include "dataworkerthread.h"
#include "util.h"

void DataWorkerThread::run()
{
    if ((fd = serialOpen ("/dev/ttyAMA0", 115200)) < 0)
    {
      return ;
    }
    int len = 128;
    char temp[len];
    serialFlush(fd);
	int errcnt = 0;
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
            if(*head == 0x5a6d)
            {
                parseResult(temp+4);
            }else
			{
				errcnt++;
			}
			if(errcnt == 10)
			{
				  serialFlush(fd);
				  errcnt =0;
            }
        }else if(val > len)
        {
            serialFlush(fd);
        }
		
        usleep(100000);
    }

}

void DataWorkerThread::parseParam(char *temp)
{
    mutex.lock();
    float *data = (float *)(temp);
    long *ltime = (long *)(temp);
    energyparam.voltage_ab = data[8];
    energyparam.voltage_bc = data[9];
    energyparam.voltage_ca = data[10];
    energyparam.voltage_a = data[5];
    energyparam.voltage_b = data[6];
    energyparam.voltage_c = data[7];
    energyparam.current_a = data[11];
    energyparam.current_b = data[12];
    energyparam.current_c = data[13];
    energyparam.power_factor = data[17];
    energyparam.frequency = data[18];
    energyparam.active_power = data[14]/1000.0;
    energyparam.reactive_power = data[15]/1000.0;
    energyparam.apparent_power = data[16]/1000.0;

    if(env_temp_type == 0)
    {
        energyparam.env_temp = data[19];
    }else if(env_temp_type == 1)
    {
        energyparam.env_temp  =  env_temp;
    }
    if(env_hum_type == 0)
    {
        energyparam.env_humidity = data[20];
    }else if(env_hum_type == 1)
    {
        energyparam.env_humidity  =  env_hum;
    }

    energyparam.air_temp = data[1];
    energyparam.air_pressure = data[2];
    //energyparam.flow_content = data[3]*flow_modify;
    energyparam.flow_content = data[3];
    energyparam.time = *ltime;
    time = energyparam.time ;
    energyparam.power = energyparam.active_power;//(energyparam.voltage_a*energyparam.current_a + energyparam.voltage_b*energyparam.current_b + energyparam.voltage_c*energyparam.current_c)/1000;
    if(energyparam.flow_content > -0.000001 && energyparam.flow_content <0.000001)
    {
        energyparam.vsp =0;
    }else
    {
        energyparam.vsp =energyparam.power /  energyparam.flow_content;
    }
//    {
//         energyparam.vsp = 1.2;
//         energyparam.power = 100;
//         energyparam.flow_content = 5;
//         energyparam.flow_content *= flow_modify;
//    }
//	Util::SysLogD("param %f %f\n",data[19],data[20]);
    mutex.unlock();
}

void DataWorkerThread::parseResult(char *temp)
{
    int *res = (int *)temp;
    emit setEcho(res[0]);
}

void DataWorkerThread::sendMsg(int cmd_a, int val_a, int cmd_b, int val_b, int cmd_c, int val_c)
{
    int *buf = (int *)sendBuf;
    sendBuf[0]= 0x6c;
    sendBuf[1] = 0x5a;
    sendBuf[2] = 0;
    sendBuf[3] = 3;
    buf[1] = val_a;
    buf[2] = val_b;
    buf[3] = val_c;
    for(int i=0;i<16;i++)
    {
        serialPutchar(fd,sendBuf[i]);
    }
}
