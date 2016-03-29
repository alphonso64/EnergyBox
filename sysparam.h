#ifndef SYSPARAM_H
#define SYSPARAM_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>

class SysParam
{
public:
    SysParam();
    float radio;//变比
    float charge;//电费
    float power;//额定功率
    float gas;//额定功率
    float current_idle_max;//空载最大电流
    float current_down_max;//停机最大电流
    float unloading_pressure;//卸载压力
    float loading_pressure;//加载压力
    int save_type;//存储方式
    int wiring_type;//存储方式

    const static int TYPE_LOCAL= 0;
    const static int TYPE_UDISK= 1;

    bool initFlag;
public:
    void saveParam();
    bool loadParam();
    void setParam(float radio,float charge,float power,float gas,float current_idle_max,float current_down_max,float unloading_pressure,float loading_pressure,int save_type,int wiring_type);
    void setParam(SysParam param);
};

#endif // SYSPARAM_H
