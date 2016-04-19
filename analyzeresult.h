#ifndef ANALYZERESULT_H
#define ANALYZERESULT_H

class AnalyzeResult
{
public:
    AnalyzeResult();
    float acc_power;
    float acc_flow;
    float acc_charge;
    float ave_cost;
    float acc_charge_peak;
    float acc_charge_normal;
    float acc_charge_valley;
    float first_order_energy_efficiency;
    float permanent_magnet_frequency_conversion;

    long load_time;
    long unload_time;
    long load_cnt;
    long unload_cnt;
    long max_load_time;
    long max_unload_time;
    float load_power;
    float unload_power;
    float load_charge;
    float unload_chargd;
    float load_radio;
    float unload_radio;
    float load_charge_radio;
    float unload_charge_radio;

    long start_measure_time;
    long end_measure_time;
    long worktime;
    long stanby_time;
    float ave_vsp;


    void clear();

};

#endif // ANALYZERESULT_H
