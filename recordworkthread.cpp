#include "recordworkthread.h"
#include "util.h"
#include <QDateTime>

#define SHEET_MAX_LINE 30000
#define SHEET_MAX_INDEX 4

void RecordWorkThread::run()
{
    recorderFlag = false;
    anares.clear();
    CurrentStaus cstatus;

    workbook *wb = new workbook();
    xf_t* xf = wb->xformat();
    worksheet* ws;
    ws = wb->sheet("sheet1");
    setTitle(ws,xf);
    int cnt = 1;
    int sheetNUM = 1;
    overflow = false;
    bool first = true;

    Util::SysLogD("charge type : %d %f %f %f\n ",charge_type,power_charge_normal,power_charge_peak,power_charge_valley);
    Util::SysLogD("normal : %d %d %d %d %d %d\n ",normal_period[0],normal_period[1],normal_period[2],normal_period[3],normal_period[4],normal_period[5]);
    Util::SysLogD("peak : %d %d %d %d %d %d\n ",peak_period[0],peak_period[1],peak_period[2],peak_period[3],peak_period[4],peak_period[5]);
    Util::SysLogD("valley : %d %d %d %d %d %d\n ",valley_period[0],valley_period[1],valley_period[2],valley_period[3],valley_period[4],valley_period[5]);
    while(!recorderFlag)
    {
        if(overflow)
        {
            usleep(300000);
        }
        usleep(300000);
        EnergyParam param = dataWoker->getEnergyParam();
        if(first)
        {
            anares.start_measure_time = param.time;
            first = false;
            initStatus(&cstatus,&param);
            writeParam(ws,xf,param,cnt);

        }
        if(cstatus.lastTime < param.time)
        {

            cnt++;
            updateResult(&cstatus,&param);
            writeParam(ws,xf,param,cnt);
        }

        acc_flow = anares.acc_flow;
        acc_power = anares.acc_power;
        load_radio = ((float)anares.load_time/(float)(anares.load_time + anares.unload_time))*100.0;
        if(cnt>SHEET_MAX_LINE)
        {
            if(sheetNUM < SHEET_MAX_INDEX)
            {
                char temp[10];
                sprintf(temp,"sheet%d",sheetNUM+1);
                ws = wb->sheet(temp);
                setTitle(ws,xf);
                sheetNUM++;
            }else {
                emit recordoverflow(1);
                overflow = true;
            }
            cnt = 0;
        }

    }

    if(cstatus.state == STAGE_LOAD )
    {
        anares.load_cnt++;
        anares.load_time += cstatus.duration;
        //Util::SysLogD("last load duration£º%d\n",cstatus.duration);
        if(anares.max_load_time < cstatus.duration)
        {
            anares.max_load_time = cstatus.duration;
        }
    }else if(cstatus.state == STAGE_UNLOAD )
    {
        anares.unload_cnt++;
        anares.unload_time += cstatus.duration;
        //Util::SysLogD("unload duration£º%d\n",cstatus.duration);
        if(anares.max_unload_time < cstatus.duration)
        {
            anares.max_unload_time = cstatus.duration;
        }
    }


    if(cstatus.acc_vsp_cnt>0)
        anares.ave_vsp = anares.ave_vsp/(float)cstatus.acc_vsp_cnt;
    anares.end_measure_time = cstatus.lastTime;

    anares.worktime = anares.load_time + anares.unload_time;
    anares.stanby_time = anares.end_measure_time - anares.start_measure_time - anares.worktime;

    Util::SysLogD("start and end time  : %d %d\n",anares.start_measure_time,anares.end_measure_time);
    Util::SysLogD("load and unload time  : %d %d\n",anares.load_time,anares.unload_time);
    Util::SysLogD("acc_flow : %f\n",anares.acc_flow);
    Util::SysLogD("cur : %d %d\n",max_cur_standby,max_cur_unload);
    Util::SysLogD("max time : %d %d\n",anares.max_load_time,anares.max_unload_time);
    Util::SysLogD("max time : %d %d\n",anares.max_load_time,anares.max_unload_time);
    Util::SysLogD("vas : %f %d\n",anares.ave_vsp,cstatus.acc_vsp_cnt);

    if(anares.worktime != 0)
    {
        anares.load_radio = ((float)anares.load_time)/(float)anares.worktime*100.0;
        anares.unload_radio = ((float)anares.unload_time)/(float)anares.worktime*100.0;
    }

    anares.acc_flow = anares.acc_flow/60;//m3/min
    anares.acc_power = anares.acc_power/3600;//kwh
    anares.load_power /= 3600;
    anares.unload_power /= 3600;

    if(charge_type == 1)
    {
        anares.acc_charge_normal =  anares.acc_charge_normal*power_charge_normal/3600;
        anares.acc_charge_peak =  anares.acc_charge_peak*power_charge_peak/3600;
        anares.acc_charge_valley =  anares.acc_charge_valley*power_charge_valley/3600;
        anares.acc_charge = anares.acc_charge_normal+anares.acc_charge_peak+anares.acc_charge_valley;
        anares.load_charge /= 3600;
        anares.unload_chargd /= 3600;

    }else if(charge_type == 0)
    {
        anares.acc_charge = anares.acc_power*power_charge;
        anares.load_charge = anares.load_power*power_charge;
        anares.unload_chargd = anares.unload_power*power_charge;
    }

    anares.permanent_magnet_frequency_conversion = anares.unload_power+anares.load_power*0.1;
    anares.first_order_energy_efficiency = 7.2*anares.acc_flow/60 - anares.acc_power;

    anares.load_charge_radio = anares.load_charge/ anares.acc_charge *100.0;
    anares.unload_charge_radio = anares.unload_chargd/ anares.acc_charge *100.0;
    anares.ave_cost = anares.acc_charge / anares.acc_flow;

    char temp[10];
    sprintf(temp,"sheet%d",sheetNUM+1);
    ws = wb->sheet(temp);
    Util::writeResult(ws,xf,anares);

    string path_post = title.toStdString();
    string path = path_pre + path_post; 
    wb->Dump(path);
    delete wb;
    Util::fileSync(path.c_str());
    Util::SysLogD("save file : %s\n",path.c_str());
    emit recordoverflow(2);
}

void RecordWorkThread::writeParam(worksheet* ws,xf_t* xf,EnergyParam param,int cnt)
{
    QDateTime  time ;
    time.setTime_t(param.time);
    QString time_str = time.toString("yyyy-MM-dd hh:mm:ss");

    ws->label(cnt,INDEX_TIME,time_str.toStdString(),xf);

    ws->label(cnt,INDEX_VOLTAGE_A,itos(param.voltage_a),xf);
    ws->label(cnt,INDEX_VOLTAGE_B,itos(param.voltage_b),xf);
    ws->label(cnt,INDEX_VOLTAGE_C,itos(param.voltage_c),xf);

    ws->label(cnt,INDEX_VOLTAGE_AB,itos(param.voltage_ab),xf);
    ws->label(cnt,INDEX_VOLTAGE_BC,itos(param.voltage_bc),xf);
    ws->label(cnt,INDEX_VOLTAGE_CA,itos(param.voltage_ca),xf);

    ws->label(cnt,INDEX_CURRENT_A,itos(param.current_a),xf);
    ws->label(cnt,INDEX_CURRENT_B,itos(param.current_b),xf);
    ws->label(cnt,INDEX_CURRENT_C,itos(param.current_c),xf);

    ws->label(cnt,INDEX_FREQUENCY,itos(param.frequency),xf);
    ws->label(cnt,INDEX_ACTIVEP,itos(param.active_power),xf);
    ws->label(cnt,INDEX_REACTIVEP,itos(param.reactive_power),xf);
    ws->label(cnt,INDEX_APPARENTP,itos(param.apparent_power),xf);
    ws->label(cnt,INDEX_FACTOR,itos(param.power_factor),xf);
	
    ws->label(cnt,INDEX_ENV_TEMP,itos(param.env_temp),xf);
    ws->label(cnt,INDEX_ENV_HUMIDITY,itos(param.env_humidity),xf);
    ws->label(cnt,INDEX_AIR_TEMP,itos(param.air_temp),xf);
    ws->label(cnt,INDEX_AIR_PRESSURE,itos(param.air_pressure),xf);
    ws->label(cnt,INDEX_FLOW,itos(param.flow_content),xf);
    ws->label(cnt,INDEX_VSP,itos(param.vsp),xf);
    ws->label(cnt,INDEX_STATE,itos(param.load_type),xf);
}

void RecordWorkThread::updateResult(CurrentStaus *stas,EnergyParam *eparam)
{
    int cur_stage;
    EnergyParam param = *eparam;
    if(param.current_a <= max_cur_standby)
    {
        cur_stage = STAGE_STANDBY;
    }else if(param.current_a <= max_cur_unload)
    {
        cur_stage = STAGE_UNLOAD;
    }else{
        cur_stage = STAGE_LOAD;
    }
    eparam->load_type = cur_stage;
    long time_step = param.time - stas->lastTime;

    anares.acc_flow += time_step*stas->lastFlow;
    float power_temp = time_step*stas->lastPower;
    anares.acc_power += power_temp;

    int load_type = -1;
    if(cur_stage != stas->state)
    {
        if(stas->state == STAGE_LOAD)
        {
            anares.load_cnt++;
            anares.load_time += stas->duration;
            if(anares.max_load_time < stas->duration)
            {
                anares.max_load_time = stas->duration;
            }
        }else if(stas->state == STAGE_UNLOAD)
        {
            anares.unload_cnt++;
            anares.unload_time += stas->duration;
            if(anares.max_unload_time < stas->duration)
            {
                anares.max_unload_time = stas->duration;
            }
        }

        //update stas;
        stas->state = cur_stage;
        stas->duration = 0;
        if(cur_stage == STAGE_LOAD)
        {
            stas->duration = time_step;
            anares.load_power += power_temp;
            load_type = 2;
        }else if(cur_stage == STAGE_UNLOAD)
        {
            stas->duration = time_step;
            anares.unload_power +=  power_temp;
            load_type =1;
        }

    }else
    {
        if(stas->state == STAGE_LOAD)
        {
            stas->duration += time_step;
            anares.load_power +=  power_temp;
             load_type = 2;
        }else if(stas->state == STAGE_UNLOAD)
        {
            stas->duration += time_step;
            anares.unload_power +=  power_temp;
             load_type = 1;
        }
    }
    float charge_temp;

    if(charge_type == 1)
    {
       QDateTime qdte;
       qdte.setTime_t(param.time);
       int hour = qdte.time().hour();
       Util::SysLogD("update hour %d\n",hour);
       for(int i=0;i<6;i+=2)
       {
            if(normal_period[i]!=-1)
            {
                if(normal_period[i]<normal_period[i+1])
                {
                    if(hour<normal_period[i+1] && hour>=normal_period[i])
                    {
                        anares.acc_charge_normal += power_temp;
                        charge_temp = power_temp*power_charge_normal;
                        Util::SysLogD("Normal period %f\n",power_charge_normal);
                        break;
                    }
                }else if(normal_period[i]>normal_period[i+1])
                {
                    if(hour<normal_period[i+1] || hour>=normal_period[i])
                    {
                        anares.acc_charge_normal += power_temp;
                        charge_temp = power_temp*power_charge_normal;
                        Util::SysLogD("Normal period %f\n",power_charge_normal);
                        break;
                    }
                }
            }
            if(peak_period[i]!=-1)
            {
                if(peak_period[i]<peak_period[i+1])
                {
                    if(hour<peak_period[i+1] && hour>=peak_period[i])
                    {
                        anares.acc_charge_peak += power_temp;
                        charge_temp = power_temp*power_charge_peak;
                        Util::SysLogD("peak period %f\n",power_charge_peak);
                        break;
                    }
                }else if(peak_period[i]>peak_period[i+1])
                {
                    if(hour<peak_period[i+1] || hour>=peak_period[i])
                    {
                        anares.acc_charge_peak += power_temp;
                        charge_temp = power_temp*power_charge_peak;
                        Util::SysLogD("peak period %f\n",power_charge_peak);
                        break;
                    }
                }
            }
            if(valley_period[i]!=-1)
            {
                if(valley_period[i]<valley_period[i+1])
                {
                    if(hour<valley_period[i+1] && hour>=valley_period[i])
                    {
                        anares.acc_charge_valley += power_temp;
                        charge_temp = power_temp*power_charge_valley;
                        Util::SysLogD("valley period %f\n",power_charge_valley);
                        break;
                    }
                }else if(valley_period[i]>valley_period[i+1])
                {
                    if(hour<valley_period[i+1] || hour>=valley_period[i])
                    {
                        anares.acc_charge_valley += power_temp;
                        charge_temp = power_temp*power_charge_valley;
                        Util::SysLogD("valley period %f\n",power_charge_valley);
                        break;
                    }
                }
            }
       }
    }

    if(load_type == 2)
    {
        anares.load_charge += charge_temp;
    }else if(load_type == 1)
    {
        anares.unload_chargd += charge_temp;
    }

    stas->lastTime = param.time;
    stas->lastPower = param.power;
    stas->lastFlow = param.flow_content;
    if(eparam->vsp>0.00001 && cur_stage == STAGE_LOAD)
    {
        stas->acc_vsp_cnt++;
        anares.ave_vsp += eparam->vsp;
    }
    return;
}

void RecordWorkThread::initStatus(CurrentStaus *stas,EnergyParam *eparam)
{
    if(eparam->current_a <= max_cur_standby)
    {
        stas->state = STAGE_STANDBY;
    }else if(eparam->current_a <= max_cur_unload)
    {
        stas->state = STAGE_UNLOAD;
    }else{
        stas->state = STAGE_LOAD;
    }
    eparam->load_type = stas->state;
    stas->duration = 0;
    stas->lastTime = eparam->time;
    stas->lastPower = eparam->power;
    stas->lastFlow = eparam->flow_content;
    if(eparam->vsp>0.00001 &&  stas->state == STAGE_LOAD )
    {
        stas->acc_vsp_cnt = 1;
        anares.ave_vsp += eparam->vsp;
    }
    return;
}


