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
    Util::writeInit(QString(FILE_PATH),QString("charge_type"),QString::number(charge_type));
    Util::writeInit(QString(FILE_PATH),QString("charge_peak"),QString("%1").arg(charge_peak));
    Util::writeInit(QString(FILE_PATH),QString("charge_valley"),QString("%1").arg(charge_valley));
    Util::writeInit(QString(FILE_PATH),QString("charge_normal"),QString("%1").arg(charge_normal));

    Util::writeInit(QString(FILE_PATH),QString("env_hum_type"),QString::number(env_hum_type));
    Util::writeInit(QString(FILE_PATH),QString("env_temp_type"),QString::number(env_temp_type));
    Util::writeInit(QString(FILE_PATH),QString("env_temp"),QString("%1").arg(env_temp));
    Util::writeInit(QString(FILE_PATH),QString("env_hum"),QString("%1").arg(env_hum));
    Util::writeInit(QString(FILE_PATH),QString("flow_modify"),QString("%1").arg(flow_modify));

    Util::writeInit(QString(FILE_PATH),QString("normal_period_1"),QString::number(normal_period[0]));
    Util::writeInit(QString(FILE_PATH),QString("normal_period_2"),QString::number(normal_period[1]));
    Util::writeInit(QString(FILE_PATH),QString("normal_period_3"),QString::number(normal_period[2]));
    Util::writeInit(QString(FILE_PATH),QString("normal_period_4"),QString::number(normal_period[3]));
    Util::writeInit(QString(FILE_PATH),QString("normal_period_5"),QString::number(normal_period[4]));
    Util::writeInit(QString(FILE_PATH),QString("normal_period_6"),QString::number(normal_period[5]));

    Util::writeInit(QString(FILE_PATH),QString("peak_period_1"),QString::number(peak_period[0]));
    Util::writeInit(QString(FILE_PATH),QString("peak_period_2"),QString::number(peak_period[1]));
    Util::writeInit(QString(FILE_PATH),QString("peak_period_3"),QString::number(peak_period[2]));
    Util::writeInit(QString(FILE_PATH),QString("peak_period_4"),QString::number(peak_period[3]));
    Util::writeInit(QString(FILE_PATH),QString("peak_period_5"),QString::number(peak_period[4]));
    Util::writeInit(QString(FILE_PATH),QString("peak_period_6"),QString::number(peak_period[5]));

    Util::writeInit(QString(FILE_PATH),QString("valley_period_1"),QString::number(valley_period[0]));
    Util::writeInit(QString(FILE_PATH),QString("valley_period_2"),QString::number(valley_period[1]));
    Util::writeInit(QString(FILE_PATH),QString("valley_period_3"),QString::number(valley_period[2]));
    Util::writeInit(QString(FILE_PATH),QString("valley_period_4"),QString::number(valley_period[3]));
    Util::writeInit(QString(FILE_PATH),QString("valley_period_5"),QString::number(valley_period[4]));
    Util::writeInit(QString(FILE_PATH),QString("valley_period_6"),QString::number(valley_period[5]));

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
    Util::writeInit(QString(FILE_PATH),QString("charge_type"),QString::number(charge_type));
    Util::writeInit(QString(FILE_PATH),QString("charge_peak"),QString("%1").arg(charge_peak));
    Util::writeInit(QString(FILE_PATH),QString("charge_valley"),QString("%1").arg(charge_valley));
    Util::writeInit(QString(FILE_PATH),QString("charge_normal"),QString("%1").arg(charge_normal));

    Util::writeInit(QString(FILE_PATH),QString("env_hum_type"),QString::number(env_hum_type));
    Util::writeInit(QString(FILE_PATH),QString("env_temp_type"),QString::number(env_temp_type));
    Util::writeInit(QString(FILE_PATH),QString("env_temp"),QString("%1").arg(env_temp));
    Util::writeInit(QString(FILE_PATH),QString("env_hum"),QString("%1").arg(env_hum));
    Util::writeInit(QString(FILE_PATH),QString("flow_modify"),QString("%1").arg(flow_modify));

    Util::writeInit(QString(FILE_PATH),QString("normal_period_1"),QString::number(normal_period[0]));
    Util::writeInit(QString(FILE_PATH),QString("normal_period_2"),QString::number(normal_period[1]));
    Util::writeInit(QString(FILE_PATH),QString("normal_period_3"),QString::number(normal_period[2]));
    Util::writeInit(QString(FILE_PATH),QString("normal_period_4"),QString::number(normal_period[3]));
    Util::writeInit(QString(FILE_PATH),QString("normal_period_5"),QString::number(normal_period[4]));
    Util::writeInit(QString(FILE_PATH),QString("normal_period_6"),QString::number(normal_period[5]));

    Util::writeInit(QString(FILE_PATH),QString("peak_period_1"),QString::number(peak_period[0]));
    Util::writeInit(QString(FILE_PATH),QString("peak_period_2"),QString::number(peak_period[1]));
    Util::writeInit(QString(FILE_PATH),QString("peak_period_3"),QString::number(peak_period[2]));
    Util::writeInit(QString(FILE_PATH),QString("peak_period_4"),QString::number(peak_period[3]));
    Util::writeInit(QString(FILE_PATH),QString("peak_period_5"),QString::number(peak_period[4]));
    Util::writeInit(QString(FILE_PATH),QString("peak_period_6"),QString::number(peak_period[5]));

    Util::writeInit(QString(FILE_PATH),QString("valley_period_1"),QString::number(valley_period[0]));
    Util::writeInit(QString(FILE_PATH),QString("valley_period_2"),QString::number(valley_period[1]));
    Util::writeInit(QString(FILE_PATH),QString("valley_period_3"),QString::number(valley_period[2]));
    Util::writeInit(QString(FILE_PATH),QString("valley_period_4"),QString::number(valley_period[3]));
    Util::writeInit(QString(FILE_PATH),QString("valley_period_5"),QString::number(valley_period[4]));
    Util::writeInit(QString(FILE_PATH),QString("valley_period_6"),QString::number(valley_period[5]));
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
    if(Util::readInit(QString(FILE_PATH), QString("charge_type"), val))
    {
        charge_type = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("charge_peak"), val))
    {
        charge_peak = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("charge_valley"), val))
    {
        charge_valley = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("charge_normal"), val))
    {
        charge_normal = val.toFloat();
    }

    if(Util::readInit(QString(FILE_PATH), QString("normal_period_1"), val))
    {
        normal_period[0] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("normal_period_2"), val))
    {
        normal_period[1] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("normal_period_3"), val))
    {
        normal_period[2] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("normal_period_4"), val))
    {
        normal_period[3] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("normal_period_5"), val))
    {
        normal_period[4] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("normal_period_6"), val))
    {
        normal_period[5] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("peak_period_1"), val))
    {
        peak_period[0] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("peak_period_2"), val))
    {
        peak_period[1] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("peak_period_3"), val))
    {
        peak_period[2] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("peak_period_4"), val))
    {
        peak_period[3] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("peak_period_5"), val))
    {
        peak_period[4] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("peak_period_6"), val))
    {
        peak_period[5] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("valley_period_1"), val))
    {
        valley_period[0] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("valley_period_2"), val))
    {
        valley_period[1] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("valley_period_3"), val))
    {
        valley_period[2] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("valley_period_4"), val))
    {
        valley_period[3] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("valley_period_5"), val))
    {
        valley_period[4] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("valley_period_6"), val))
    {
        valley_period[5] = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("env_hum"), val))
    {
        env_hum = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("env_temp"), val))
    {
        env_temp = val.toFloat();
    }
    if(Util::readInit(QString(FILE_PATH), QString("flow_modify"), val))
    {
        flow_modify = val.toFloat();
    }

    if(Util::readInit(QString(FILE_PATH), QString("env_temp_type"), val))
    {
        env_temp_type = val.toInt();
    }

    if(Util::readInit(QString(FILE_PATH), QString("env_hum_type"), val))
    {
        env_hum_type = val.toInt();
    }

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
    this->charge_type = param.charge_type;
    this->charge_normal = param.charge_normal;
    this->charge_valley = param.charge_valley;
    this->charge_peak = param.charge_peak;
    for(int i=0;i<PEROID_LENGTH;i++)
    {
        peak_period[i] = param.peak_period[i];
        normal_period[i] = param.normal_period[i];
        valley_period[i] = param.valley_period[i];
    }
    flow_modify = param.flow_modify;
    env_hum = param.env_hum;
    env_temp = param.env_temp;
    env_hum_type = param.env_hum_type;
    env_temp_type = param.env_temp_type;
    initFlag = true;
}



