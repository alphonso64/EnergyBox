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
}


