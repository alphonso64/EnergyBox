#include "sysparam.h"
#include "util.h"
char* FILE_PATH="/home/sysparam.ini";
SysParam::SysParam()
{
    initFlag = false;
}

void SysParam::saveParam()
{

    Util::writeInit(QString(FILE_PATH),QString("radio"),QString("%1").arg(radio));
    Util::writeInit(QString(FILE_PATH),QString("charge"),QString("%1").arg(charge));
    Util::writeInit(QString(FILE_PATH),QString("power"),QString("%1").arg(power));
    Util::writeInit(QString(FILE_PATH),QString("gas"),QString("%1").arg(gas));
    Util::writeInit(QString(FILE_PATH),QString("current_idle_max"),QString("%1").arg(current_idle_max));
    Util::writeInit(QString(FILE_PATH),QString("current_down_max"),QString("%1").arg(current_down_max));
    Util::writeInit(QString(FILE_PATH),QString("loading_pressure"),QString("%1").arg(loading_pressure));
    Util::writeInit(QString(FILE_PATH),QString("unloading_pressure"),QString("%1").arg(unloading_pressure));
    Util::writeInit(QString(FILE_PATH),QString("save_type"),QString::number(save_type));
    Util::writeInit(QString(FILE_PATH),QString("configure_type"),QString::number(1));
    Util::writeInit(QString(FILE_PATH),QString("wiring_type"),QString::number(wiring_type));

    return;
}

void SysParam::saveLocalParam()
{
    Util::writeInit(QString(FILE_PATH),QString("charge"),QString("%1").arg(charge));
    Util::writeInit(QString(FILE_PATH),QString("power"),QString("%1").arg(power));
    Util::writeInit(QString(FILE_PATH),QString("gas"),QString("%1").arg(gas));
    Util::writeInit(QString(FILE_PATH),QString("current_idle_max"),QString("%1").arg(current_idle_max));
    Util::writeInit(QString(FILE_PATH),QString("current_down_max"),QString("%1").arg(current_down_max));
    Util::writeInit(QString(FILE_PATH),QString("loading_pressure"),QString("%1").arg(loading_pressure));
    Util::writeInit(QString(FILE_PATH),QString("unloading_pressure"),QString("%1").arg(unloading_pressure));
    Util::writeInit(QString(FILE_PATH),QString("save_type"),QString::number(save_type));
    Util::writeInit(QString(FILE_PATH),QString("configure_type"),QString::number(1));

    return;
}

void SysParam::saveRemoveParam()
{
    radio = radio_temp;
    wiring_type = wiring_type_temp;
    Util::writeInit(QString(FILE_PATH),QString("radio"),QString("%1").arg(radio_temp));
    Util::writeInit(QString(FILE_PATH),QString("wiring_type"),QString::number(wiring_type_temp));
    return;
}


bool SysParam::loadParam()
{
    QString val;
    if(Util::readInit(QString(FILE_PATH), QString("configure_type"), val))
    {
        int type = val.toInt();
        if(type != 1)
        {
            return false;
        }
    }else{
        return false;
    }
    if(Util::readInit(QString(FILE_PATH), QString("radio"), val))
    {
        radio = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("charge"), val))
    {
        charge = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("power"), val))
    {
        power = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("gas"), val))
    {
        gas = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("current_down_max"), val))
    {
        current_down_max = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("current_idle_max"), val))
    {
        current_idle_max = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("loading_pressure"), val))
    {
        loading_pressure = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("unloading_pressure"), val))
    {
        unloading_pressure = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("save_type"), val))
    {
        save_type = val.toInt();
    }
    if(Util::readInit(QString(FILE_PATH), QString("wiring_type"), val))
    {
        wiring_type = val.toInt();
    }
    printf("%f %f %f %f %f %f %f %f %d\n",radio,charge,power,gas,current_idle_max,current_down_max,unloading_pressure,loading_pressure,wiring_type);
    initFlag = true;
    return true;
}

void SysParam::setParam(float radio, float charge, float power,
                        float gas, float current_idle_max, float current_down_max, float unloading_pressure, float loading_pressure, int save_type,int wiring_type)
{
    this->charge = charge;
    this->radio_temp = radio;
    this->power = power;
    this->gas = gas;
    this->current_down_max = current_down_max;
    this->current_idle_max = current_idle_max;
    this->unloading_pressure = unloading_pressure;
    this->loading_pressure = loading_pressure;
    this->save_type = save_type;
    this->wiring_type_temp = wiring_type;
    initFlag = true;

}

void SysParam::setParam(SysParam param)
{
    this->charge = param.charge;
    this->radio_temp = param.radio;
    this->power = param.power;
    this->gas = param.gas;
    this->current_down_max = param.current_down_max;
    this->current_idle_max = param.current_idle_max;
    this->unloading_pressure = param.unloading_pressure;
    this->loading_pressure = param.loading_pressure;
    this->save_type = param.save_type;
    this->wiring_type_temp = param.wiring_type;
    initFlag = true;
}



