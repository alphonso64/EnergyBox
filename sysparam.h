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
#include "const_define.h"

class SysParam
{
public:
    SysParam();
    float radio;//���
    float charge;//���
    float charge_peak;//��ʱ���
    float charge_valley;//��ʱ���
    float charge_normal;//ƽʱ���
    float power;//�����
    float gas;//�����
    float current_idle_max;//����������
    float current_down_max;//ͣ��������
    float unloading_pressure;//ж��ѹ��
    float loading_pressure;//����ѹ��
    int save_type;//�洢��ʽ
    int wiring_type;//���߷�ʽ
    int charge_type;//�Ʒѷ�ʽ
    int env_temp_type;//�Ʒѷ�ʽ
    int env_hum_type;//�Ʒѷ�ʽ
    float env_temp;
    float env_hum;
    float flow_modify;

    int normal_period[PEROID_LENGTH];

    int peak_period[PEROID_LENGTH];

    int valley_period[PEROID_LENGTH];

    const static int TYPE_LOCAL= 0;
    const static int TYPE_UDISK= 1;
    bool initFlag;
    float radio_temp;
    int wiring_type_temp;
public:
    void saveParam();
    bool loadParam();
    void setParam(float radio,float charge,float power,float gas,float current_idle_max,float current_down_max,float unloading_pressure,float loading_pressure,int save_type,int wiring_type);
    void setParam(SysParam param);
    void saveLocalParam();
    void saveRemoveParam();
};

#endif // SYSPARAM_H
