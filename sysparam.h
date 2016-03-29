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
    float radio;//���
    float charge;//���
    float power;//�����
    float gas;//�����
    float current_idle_max;//����������
    float current_down_max;//ͣ��������
    float unloading_pressure;//ж��ѹ��
    float loading_pressure;//����ѹ��
    int save_type;//�洢��ʽ
    int wiring_type;//�洢��ʽ

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
