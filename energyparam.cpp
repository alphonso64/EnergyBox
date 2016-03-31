#include "energyparam.h"

EnergyParam::EnergyParam()
{
    this->voltage_a =0;
    this->voltage_b = 0;
    this->voltage_c = 0;
    this->current_a = 0;
    this->current_b = 0;
    this->current_c = 0;

    this->power_factor = 0;
    this->frequency = 0;
    this->active_power = 0;
    this->reactive_power = 0;
    this->apparent_power = 0;

    this->env_temp = 0;
    this->env_humidity = 0;
    this->air_temp = 0;
    this->air_pressure = 0;
    this->flow_content = 0;
    this->time = 0;
    this->power = 0;
    this->vsp = 0;
    this->load_type = 0;
}

void EnergyParam::cpy(EnergyParam param)
{
    this->voltage_a = param.voltage_a;
    this->voltage_b = param.voltage_b;
    this->voltage_c = param.voltage_c;
    this->current_a = param.current_a;
    this->current_b = param.current_b;
    this->current_c = param.current_c;

    this->power_factor = param.power_factor;
    this->frequency = param.frequency;
    this->active_power = param.active_power;
    this->reactive_power = param.reactive_power;
    this->apparent_power = param.apparent_power;

    this->env_temp = param.env_temp;
    this->env_humidity = param.env_humidity;
    this->air_temp = param.air_temp;
    this->air_pressure = param.air_pressure;
    this->flow_content = param.flow_content;
	this->time = param.time;
    this->power  = param.power;
    this->vsp = param.vsp;
    this->load_type = param.load_type;
}

