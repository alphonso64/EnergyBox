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

    workbook wb;
    xf_t* xf = wb.xformat();
    worksheet* ws;
    ws = wb.sheet("sheet1");
    setTitle(ws,xf);
    int cnt = 1;
    int cntt = 0;
    int sheetNUM = 1;
    overflow = false;
    bool first = true;

    while(!recorderFlag)
    {
        if(overflow)
        {
            usleep(200000);
        }
        EnergyParam param = dataWoker->getEnergyParam();
        if(first)
        {
            anares.start_measure_time = param.time;
            first = false;
            initStatus(&cstatus,&param);
            writeParam(ws,xf,param,cnt);

//            for(int i=0;i<100;i++)
//            {
//                cnt++;
//                cntt++;
//                param.time++;
//                updateResult(&cstatus,&param);
//                writeParam(ws,xf,param,cnt);
//            }

        }
        if(cstatus.lastTime < param.time)
        {

            cnt++;
            cntt++;
            updateResult(&cstatus,&param);
            writeParam(ws,xf,param,cnt);

//            for(int i=0;i<100;i++)
//            {
//                cnt++;
//                cntt++;
//                param.time++;
//                updateResult(&cstatus,&param);
//                writeParam(ws,xf,param,cnt);
//            }
        }

//        if(cntt >2000)
//        {
//           Util::SysLogD("recorder index : %d\n",cnt);
//           cntt = 0;
//        }

        acc_flow = anares.acc_flow;
        acc_power = anares.acc_power;
        load_radio = ((float)anares.load_time/(float)(anares.load_time + anares.unload_time))*100.0;
        if(cnt>SHEET_MAX_LINE)
        {
            if(sheetNUM < SHEET_MAX_INDEX)
            {
                char temp[10];
                sprintf(temp,"sheet%d",sheetNUM+1);
                ws = wb.sheet(temp);
                sheetNUM++;
            }else {
                emit recordoverflow(1);
                overflow = true;
            }
            cnt = 0;
        }
    }

    if(cstatus.state = STAGE_LOAD )
    {
        anares.load_cnt++;
        anares.load_time += cstatus.duration;
        //Util::SysLogD("last load duration£º%d\n",cstatus.duration);
        if(anares.max_load_time < cstatus.duration)
        {
            anares.max_load_time = cstatus.duration;
        }
    }else if(cstatus.state = STAGE_UNLOAD )
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
        anares.ave_vsp = anares.ave_vsp/cstatus.acc_vsp_cnt;
    anares.end_measure_time = cstatus.lastTime;

    anares.worktime = anares.load_time + anares.unload_time;
    anares.stanby_time = anares.end_measure_time - anares.start_measure_time - anares.worktime;

    Util::SysLogD("start and end time  : %d %d\n",anares.start_measure_time,anares.end_measure_time);
    Util::SysLogD("load and unload time  : %d %d\n",anares.load_time,anares.unload_time);
    Util::SysLogD("acc_flow : %f\n",anares.acc_flow);
    Util::SysLogD("cur : %d %d\n",max_cur_standby,max_cur_unload);

    if(anares.worktime != 0)
    {
        anares.load_radio = ((float)anares.load_time)/(float)anares.worktime*100.0;
        anares.unload_radio = ((float)anares.unload_time)/(float)anares.worktime*100.0;
    }

    anares.acc_flow = anares.acc_flow/60;//m3/min
    anares.acc_power = anares.acc_power/3600;//kwh
    anares.load_power /= 3600;
    anares.unload_power /= 3600;

    anares.acc_charge = anares.acc_power*power_charge;
    anares.load_charge = anares.load_power*power_charge;
    anares.unload_chargd = anares.unload_power*power_charge;
    anares.load_charge_radio = anares.load_charge/ anares.acc_charge *100.0;
    anares.unload_charge_radio = anares.unload_chargd/ anares.acc_charge *100.0;
    anares.ave_cost = anares.acc_charge / anares.acc_flow;

    char temp[10];
    sprintf(temp,"sheet%d",sheetNUM+1);
    ws = wb.sheet(temp);
    Util::writeResult(ws,xf,anares);

    string path_post = title.toStdString();
    string path = path_pre + path_post; 
    wb.Dump(path);
    Util::SysLogD("save file : %s\n",path.c_str());
    emit recordoverflow(2);
}

void RecordWorkThread::writeParam(worksheet* ws,xf_t* xf,EnergyParam param,int cnt)
{
    ws->label(cnt,0,itos(param.time),xf);
    ws->label(cnt,1,itos(param.voltage_a),xf);
    ws->label(cnt,2,itos(param.voltage_b),xf);
    ws->label(cnt,3,itos(param.voltage_c),xf);
    ws->label(cnt,4,itos(param.current_a),xf);
    ws->label(cnt,5,itos(param.current_b),xf);
    ws->label(cnt,6,itos(param.current_c),xf);

    ws->label(cnt,7,itos(param.power_factor),xf);
    ws->label(cnt,8,itos(param.frequency),xf);
    ws->label(cnt,9,itos(param.active_power),xf);
    ws->label(cnt,10,itos(param.reactive_power),xf);
    ws->label(cnt,11,itos(param.apparent_power),xf);

    ws->label(cnt,12,itos(param.env_temp),xf);
    ws->label(cnt,13,itos(param.env_humidity),xf);
    ws->label(cnt,14,itos(param.air_temp),xf);
    ws->label(cnt,15,itos(param.air_pressure),xf);
    ws->label(cnt,16,itos(param.flow_content),xf);
    ws->label(cnt,17,itos(param.power),xf);
    ws->label(cnt,18,itos(param.vsp),xf);
    ws->label(cnt,19,itos(param.load_type),xf);
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

    if(cur_stage != stas->state)
    {
        if(stas->state == STAGE_LOAD)
        {
            anares.load_cnt++;
            anares.load_time += stas->duration;
//            Util::SysLogD("load duration£º%d\n",stas->duration);
            if(anares.max_load_time < stas->duration)
            {
                anares.max_load_time = stas->duration;
            }
        }else if(stas->state == STAGE_UNLOAD)
        {
            anares.unload_cnt++;
            anares.unload_time += stas->duration;
//            Util::SysLogD("unload duration£º%d\n",stas->duration);
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
            anares.load_power += time_step*stas->lastPower;
        }else if(cur_stage == STAGE_UNLOAD)
        {
            stas->duration = time_step;
            anares.unload_power += time_step*stas->lastPower;
        }

    }else
    {
        if(stas->state == STAGE_LOAD)
        {

            stas->duration += time_step;
            anares.load_power += time_step*stas->lastPower;
        }else if(stas->state == STAGE_UNLOAD)
        {
            stas->duration += time_step;
            anares.unload_power += time_step*stas->lastPower;
        }
    }
    anares.acc_flow += time_step*stas->lastFlow;
    anares.acc_power += time_step*stas->lastPower;

    stas->lastTime = param.time;
    stas->lastPower = param.power;
    stas->lastFlow = param.flow_content;
    if(eparam->vsp>0)
    {
        stas->acc_vsp_cnt++;
        anares.ave_vsp += eparam->vsp;
    }
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
    if(eparam->vsp>0)
    {
        stas->acc_vsp_cnt = 1;
        anares.ave_vsp += eparam->vsp;
    }
}


