#include "analyzeresult.h"

AnalyzeResult::AnalyzeResult()
{
    this->acc_flow = 0;
    this->acc_power =0;
    this->ave_vsp = 0;
    this->end_measure_time = 0;
    this->worktime = 0;
    this->stanby_time = 0;
    this->start_measure_time = 0;
    this->load_charge = 0;
    this->load_charge_radio = 0;
    this->load_cnt = 0;
    this->load_power = 0;
    this->load_radio = 0;
    this->load_time = 0;
    this->unload_chargd = 0;
    this->unload_charge_radio = 0;
    this->unload_power = 0;
    this->unload_cnt = 0;
    this->unload_radio = 0;
    this->unload_time = 0;
    this->max_load_time = 0;
    this->max_unload_time  = 0;
    acc_charge  =0;
    ave_cost = 0;
    permanent_magnet_frequency_conversion = 0;
    first_order_energy_efficiency = 0;

    first_order_energy_efficiency_day = 0;
    first_order_energy_efficiency_month = 0;
    first_order_energy_efficiency_year = 0;
    permanent_magnet_frequency_conversion_day = 0;
    permanent_magnet_frequency_conversion_month = 0;
    permanent_magnet_frequency_conversion_year = 0;

    acc_charge_normal = 0;
    acc_charge_peak = 0;
    acc_charge_valley = 0;
    vsp_cnt = 0;
}


void AnalyzeResult::clear()
{
    this->acc_flow = 0;
    this->acc_power =0;
    this->ave_vsp = 0;
    this->end_measure_time = 0;
    this->worktime = 0;
    this->stanby_time = 0;
    this->start_measure_time = 0;
    this->load_charge = 0;
    this->load_charge_radio = 0;
    this->load_cnt = 0;
    this->load_power = 0;
    this->load_radio = 0;
    this->load_time = 0;
    this->unload_chargd = 0;
    this->unload_charge_radio = 0;
    this->unload_power = 0;
    this->unload_cnt = 0;
    this->unload_radio = 0;
    this->unload_time = 0;
    this->max_load_time = 0;
    this->max_unload_time  = 0;
    this->acc_charge = 0;
    this->ave_cost = 0;
    this->permanent_magnet_frequency_conversion = 0;
    this->first_order_energy_efficiency = 0;

    first_order_energy_efficiency_day = 0;
    first_order_energy_efficiency_month = 0;
    first_order_energy_efficiency_year = 0;
    permanent_magnet_frequency_conversion_day = 0;
    permanent_magnet_frequency_conversion_month = 0;
    permanent_magnet_frequency_conversion_year = 0;

    this->acc_charge_normal = 0;
    this->acc_charge_peak = 0;
    this->acc_charge_valley = 0;
    vsp_cnt =0;
}

void AnalyzeResult::cpy(AnalyzeResult anares)
{
    this->acc_flow = anares.acc_flow;
    this->acc_power = anares.acc_power;
    this->ave_vsp = anares.ave_vsp;
    this->end_measure_time = anares.end_measure_time;
    this->worktime = anares.worktime;
    this->stanby_time = anares.stanby_time;
    this->start_measure_time = anares.start_measure_time;
    this->load_charge = anares.load_charge;
    this->load_charge_radio = anares.load_charge_radio;
    this->load_cnt = anares.load_cnt;
    this->load_power = anares.load_power;
    this->load_radio = anares.load_radio;
    this->load_time = anares.load_time;
    this->unload_chargd = anares.unload_chargd;
    this->unload_charge_radio = anares.unload_charge_radio;
    this->unload_power = anares.unload_power;
    this->unload_cnt = anares.unload_cnt;
    this->unload_radio = anares.unload_radio;;
    this->unload_time = anares.unload_time;
    this->max_load_time = anares.max_load_time;
    this->max_unload_time  = anares.max_unload_time;
    this->acc_charge = anares.acc_charge;
    this->ave_cost = anares.ave_cost;
    this->permanent_magnet_frequency_conversion = anares.permanent_magnet_frequency_conversion;
    this->first_order_energy_efficiency = anares.first_order_energy_efficiency;

    this->first_order_energy_efficiency_day = anares.first_order_energy_efficiency_day;
    this->first_order_energy_efficiency_month = anares.first_order_energy_efficiency_month;
    this->first_order_energy_efficiency_year = anares.first_order_energy_efficiency_year;
    this->permanent_magnet_frequency_conversion_month = anares.permanent_magnet_frequency_conversion_month;
    this->permanent_magnet_frequency_conversion_day = anares.permanent_magnet_frequency_conversion_day;
    this->permanent_magnet_frequency_conversion_year = anares.permanent_magnet_frequency_conversion_year;

    this->acc_charge_normal = anares.acc_charge_normal;
    this->acc_charge_peak = anares.acc_charge_peak;
    this->acc_charge_valley = anares.acc_charge_valley;
    this->vsp_cnt = anares.vsp_cnt;
}

