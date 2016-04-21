#include "sysparam.h"
#include "util.h"
#include <QSettings>
char* FILE_PATH="/home/sysparam.ini";
SysParam::SysParam()
{
    initFlag = false;
}

void SysParam::saveParam()
{
//      QStringList param;
//      param.push_back("radio");
//      param.push_back("charge");
//      param.push_back("power");
//      param.push_back("gas");
//      param.push_back("current_idle_max");
//      param.push_back("current_down_max");
//      param.push_back("loading_pressure");
//      param.push_back("unloading_pressure");
//      param.push_back("save_type");
//      param.push_back("configure_type");
//      param.push_back("unloading_pressure");
//      param.push_back("save_type");
//      param.push_back("charge_type");
//      param.push_back("charge_normal");

//      param.push_back("env_hum_type");
//      param.push_back("env_temp_type");
//      param.push_back("env_temp");
//      param.push_back("flow_modify");
//      param.push_back("current_idle_max");
//      param.push_back("current_down_max");
//      param.push_back("loading_pressure");
//      param.push_back("unloading_pressure");
//      param.push_back("save_type");
//      param.push_back("configure_type");
//      param.push_back("unloading_pressure");
//      param.push_back("save_type");
//      param.push_back("charge_type");
//      param.push_back("charge_normal");

//    Util::writeInit(QString(FILE_PATH),QString("radio"),QString("%1").arg(radio));
//    Util::writeInit(QString(FILE_PATH),QString("charge"),QString("%1").arg(charge));
//    Util::writeInit(QString(FILE_PATH),QString("power"),QString("%1").arg(power));
//    Util::writeInit(QString(FILE_PATH),QString("gas"),QString("%1").arg(gas));
//    Util::writeInit(QString(FILE_PATH),QString("current_idle_max"),QString("%1").arg(current_idle_max));
//    Util::writeInit(QString(FILE_PATH),QString("current_down_max"),QString("%1").arg(current_down_max));
//    Util::writeInit(QString(FILE_PATH),QString("loading_pressure"),QString("%1").arg(loading_pressure));
//    Util::writeInit(QString(FILE_PATH),QString("unloading_pressure"),QString("%1").arg(unloading_pressure));
//    Util::writeInit(QString(FILE_PATH),QString("save_type"),QString::number(save_type));
//    Util::writeInit(QString(FILE_PATH),QString("configure_type"),QString::number(1));
//    Util::writeInit(QString(FILE_PATH),QString("wiring_type"),QString::number(wiring_type));
//    Util::writeInit(QString(FILE_PATH),QString("charge_type"),QString::number(charge_type));
//    Util::writeInit(QString(FILE_PATH),QString("charge_peak"),QString("%1").arg(charge_peak));
//    Util::writeInit(QString(FILE_PATH),QString("charge_valley"),QString("%1").arg(charge_valley));
//    Util::writeInit(QString(FILE_PATH),QString("charge_normal"),QString("%1").arg(charge_normal));

//    Util::writeInit(QString(FILE_PATH),QString("env_hum_type"),QString::number(env_hum_type));
//    Util::writeInit(QString(FILE_PATH),QString("env_temp_type"),QString::number(env_temp_type));
//    Util::writeInit(QString(FILE_PATH),QString("env_temp"),QString("%1").arg(env_temp));
//    Util::writeInit(QString(FILE_PATH),QString("env_hum"),QString("%1").arg(env_hum));
//    Util::writeInit(QString(FILE_PATH),QString("flow_modify"),QString("%1").arg(flow_modify));

//    Util::writeInit(QString(FILE_PATH),QString("normal_period_1"),QString::number(normal_period[0]));
//    Util::writeInit(QString(FILE_PATH),QString("normal_period_2"),QString::number(normal_period[1]));
//    Util::writeInit(QString(FILE_PATH),QString("normal_period_3"),QString::number(normal_period[2]));
//    Util::writeInit(QString(FILE_PATH),QString("normal_period_4"),QString::number(normal_period[3]));
//    Util::writeInit(QString(FILE_PATH),QString("normal_period_5"),QString::number(normal_period[4]));
//    Util::writeInit(QString(FILE_PATH),QString("normal_period_6"),QString::number(normal_period[5]));

//    Util::writeInit(QString(FILE_PATH),QString("peak_period_1"),QString::number(peak_period[0]));
//    Util::writeInit(QString(FILE_PATH),QString("peak_period_2"),QString::number(peak_period[1]));
//    Util::writeInit(QString(FILE_PATH),QString("peak_period_3"),QString::number(peak_period[2]));
//    Util::writeInit(QString(FILE_PATH),QString("peak_period_4"),QString::number(peak_period[3]));
//    Util::writeInit(QString(FILE_PATH),QString("peak_period_5"),QString::number(peak_period[4]));
//    Util::writeInit(QString(FILE_PATH),QString("peak_period_6"),QString::number(peak_period[5]));

//    Util::writeInit(QString(FILE_PATH),QString("valley_period_1"),QString::number(valley_period[0]));
//    Util::writeInit(QString(FILE_PATH),QString("valley_period_2"),QString::number(valley_period[1]));
//    Util::writeInit(QString(FILE_PATH),QString("valley_period_3"),QString::number(valley_period[2]));
//    Util::writeInit(QString(FILE_PATH),QString("valley_period_4"),QString::number(valley_period[3]));
//    Util::writeInit(QString(FILE_PATH),QString("valley_period_5"),QString::number(valley_period[4]));
//    Util::writeInit(QString(FILE_PATH),QString("valley_period_6"),QString::number(valley_period[5]));
//    Util::fileSync(FILE_PATH);

    return;
}

void SysParam::saveLocalParam()
{
    QSettings *config = new QSettings(FILE_PATH, QSettings::IniFormat);
    config->beginGroup("config");

    config->setValue(QString("charge"),QString("%1").arg(charge));
    config->setValue(QString("power"),QString("%1").arg(power));
    config->setValue(QString("gas"),QString("%1").arg(gas));
    config->setValue(QString("current_idle_max"),QString("%1").arg(current_idle_max));
    config->setValue(QString("current_down_max"),QString("%1").arg(current_down_max));
    config->setValue(QString("loading_pressure"),QString("%1").arg(loading_pressure));
    config->setValue(QString("unloading_pressure"),QString("%1").arg(unloading_pressure));
    config->setValue(QString("save_type"),QString::number(save_type));
    config->setValue(QString("configure_type"),QString::number(1));
    config->setValue(QString("charge_type"),QString::number(charge_type));
    config->setValue(QString("charge_peak"),QString("%1").arg(charge_peak));
    config->setValue(QString("charge_valley"),QString("%1").arg(charge_valley));
    config->setValue(QString("charge_normal"),QString("%1").arg(charge_normal));

    config->setValue(QString("env_hum_type"),QString::number(env_hum_type));
    config->setValue(QString("env_temp_type"),QString::number(env_temp_type));
    config->setValue(QString("env_temp"),QString("%1").arg(env_temp));
    config->setValue(QString("env_hum"),QString("%1").arg(env_hum));
    config->setValue(QString("flow_modify"),QString("%1").arg(flow_modify));

    config->setValue(QString("normal_period_1"),QString::number(normal_period[0]));
    config->setValue(QString("normal_period_2"),QString::number(normal_period[1]));
    config->setValue(QString("normal_period_3"),QString::number(normal_period[2]));
    config->setValue(QString("normal_period_4"),QString::number(normal_period[3]));
    config->setValue(QString("normal_period_5"),QString::number(normal_period[4]));
    config->setValue(QString("normal_period_6"),QString::number(normal_period[5]));

    config->setValue(QString("peak_period_1"),QString::number(peak_period[0]));
    config->setValue(QString("peak_period_2"),QString::number(peak_period[1]));
    config->setValue(QString("peak_period_3"),QString::number(peak_period[2]));
    config->setValue(QString("peak_period_4"),QString::number(peak_period[3]));
    config->setValue(QString("peak_period_5"),QString::number(peak_period[4]));
    config->setValue(QString("peak_period_6"),QString::number(peak_period[5]));

    config->setValue(QString("valley_period_1"),QString::number(valley_period[0]));
    config->setValue(QString("valley_period_2"),QString::number(valley_period[1]));
    config->setValue(QString("valley_period_3"),QString::number(valley_period[2]));
    config->setValue(QString("valley_period_4"),QString::number(valley_period[3]));
    config->setValue(QString("valley_period_5"),QString::number(valley_period[4]));
    config->setValue(QString("valley_period_6"),QString::number(valley_period[5]));

    config->endGroup();
    Util::fileSync(FILE_PATH);
    return;
}

void SysParam::saveRemoveParam()
{
    QSettings *config = new QSettings(FILE_PATH, QSettings::IniFormat);
    config->beginGroup("config");
    radio = radio_temp;
    wiring_type = wiring_type_temp;
    config->setValue(QString("radio"),QString("%1").arg(radio_temp));
    config->setValue(QString("wiring_type"),QString::number(wiring_type_temp));
    config->endGroup();
    Util::fileSync(FILE_PATH);
    return;
}


bool SysParam::loadParam()
{

    QSettings *config = new QSettings(FILE_PATH, QSettings::IniFormat);

    QString val;

    val = config->value(QString("config/") + "configure_type").toString();
    int type = val.toInt();
    if(type != 1)
    {
        return false;
    }

    val = config->value(QString("config/") + "radio").toString();
    radio = val.toFloat();
    val = config->value(QString("config/") + "charge").toString();
    charge = val.toFloat();
    val = config->value(QString("config/") + "power").toString();
    power = val.toFloat();
    val = config->value(QString("config/") + "gas").toString();
    gas = val.toFloat();

    val = config->value(QString("config/") + "current_down_max").toString();
    current_down_max = val.toFloat();
    val = config->value(QString("config/") + "current_idle_max").toString();
    current_idle_max = val.toFloat();
    val = config->value(QString("config/") + "loading_pressure").toString();
    loading_pressure = val.toFloat();
    val = config->value(QString("config/") + "unloading_pressure").toString();
    unloading_pressure = val.toFloat();
    val = config->value(QString("config/") + "save_type").toString();
    save_type = val.toInt();
    val = config->value(QString("config/") + "wiring_type").toString();
    wiring_type = val.toInt();

    val = config->value(QString("config/") + "charge_type").toString();
    charge_type = val.toInt();
    val = config->value(QString("config/") + "charge_peak").toString();
    charge_peak = val.toFloat();
    val = config->value(QString("config/") + "charge_valley").toString();
    charge_valley = val.toFloat();
    val = config->value(QString("config/") + "charge_normal").toString();
    charge_normal = val.toFloat();

    val = config->value(QString("config/") + "normal_period_1").toString();
    normal_period[0] = val.toInt();
    val = config->value(QString("config/") + "normal_period_2").toString();
    normal_period[1]  = val.toInt();
    val = config->value(QString("config/") + "normal_period_3").toString();
    normal_period[2] = val.toInt();
    val = config->value(QString("config/") + "normal_period_4").toString();
    normal_period[3] = val.toInt();
    val = config->value(QString("config/") + "normal_period_5").toString();
    normal_period[4]  = val.toInt();
    val = config->value(QString("config/") + "normal_period_6").toString();
    normal_period[5] = val.toInt();

    val = config->value(QString("config/") + "peak_period_1").toString();
    peak_period[0] = val.toInt();
    val = config->value(QString("config/") + "peak_period_2").toString();
    peak_period[1]  = val.toInt();
    val = config->value(QString("config/") + "peak_period_3").toString();
    peak_period[2] = val.toInt();
    val = config->value(QString("config/") + "peak_period_4").toString();
    peak_period[3] = val.toInt();
    val = config->value(QString("config/") + "peak_period_5").toString();
    peak_period[4]  = val.toInt();
    val = config->value(QString("config/") + "peak_period_6").toString();
    peak_period[5] = val.toInt();

    val = config->value(QString("config/") + "valley_period_1").toString();
    valley_period[0] = val.toInt();
    val = config->value(QString("config/") + "valley_period_2").toString();
    valley_period[1]  = val.toInt();
    val = config->value(QString("config/") + "valley_period_3").toString();
    valley_period[2] = val.toInt();
    val = config->value(QString("config/") + "valley_period_4").toString();
    valley_period[3] = val.toInt();
    val = config->value(QString("config/") + "valley_period_5").toString();
    valley_period[4]  = val.toInt();
    val = config->value(QString("config/") + "valley_period_6").toString();
    valley_period[5] = val.toInt();

    val = config->value(QString("config/") + "env_hum").toString();
    env_hum  = val.toFloat();
    val = config->value(QString("config/") + "env_temp").toString();
    env_temp = val.toFloat();
    val = config->value(QString("config/") + "flow_modify").toString();
    flow_modify = val.toFloat();
    val = config->value(QString("config/") + "env_temp_type").toString();
    env_temp_type  = val.toInt();
    val = config->value(QString("config/") + "env_hum_type").toString();
    env_hum_type = val.toInt();

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



