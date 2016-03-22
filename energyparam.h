#ifndef ENERGYPARAM_H
#define ENERGYPARAM_H

class EnergyParam
{
public:
    EnergyParam();
    float voltage_a;
    float voltage_b;
    float voltage_c;
    float current_a;
    float current_b;
    float current_c;

    float power_factor;
    float frequency;
    float active_power;
    float reactive_power;
    float apparent_power;

    float env_temp;
    float env_humidity;
    float air_temp;
    float air_pressure;
    float flow_content;
    long time;
    float power;
    float vsp;
    void cpy(EnergyParam param);

};

#endif // ENERGYPARAM_H
