#include "recordworkthread.h"
#include "util.h"

#define SHEET_MAX_LINE 5000
#define SHEET_MAX_INDEX 4

void RecordWorkThread::run()
{
    recorderFlag = false;

    workbook wb;
    xf_t* xf = wb.xformat();
    worksheet* ws;
    ws = wb.sheet("sheet1");
    setTitle(ws,xf);
    acc_power = 0;
    acc_flow = 0;
    int cnt = 0;
    int cntt = 0;
    int sheetNUM = 1;
    overflow = false;
    while(!recorderFlag)
    {
        if(overflow)
        {
            usleep(200000);
        }
        EnergyParam param = dataWoker->getEnergyParam();
        if(lastTime != param.time)
        {

            cnt++;
            cntt++;
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
            if(cnt>1)
            {
                acc_power += param.power*(param.time - lastTime);
                acc_flow += param.flow_content*(param.time - lastTime);
                //printf("time %d %d\n",param.time);
            }
            lastTime = param.time;

            for(int i= 0;i<100;i++)
            {
                cnt++;
                cntt++;
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
            }
        }

        if(cntt >2000)
        {
           Util::SysLogD("recorder index : %d\n",cnt);
           cntt = 0;
        }
        if(cnt>SHEET_MAX_LINE)
        {
            if(sheetNUM < SHEET_MAX_INDEX)
            {
                char temp[10];
                sprintf(temp,"sheet%d",sheetNUM+1);
                ws = wb.sheet(temp);
            }else {
                emit recordoverflow(1);
                overflow = true;
            }
            sheetNUM++;
            cnt = 0;
        }

        //;
    }
    char temp[10];
    sprintf(temp,"sheet%d",sheetNUM+1);
    ws = wb.sheet(temp);
    ws->label(0,0,"acc_power(kwh)",xf);
    ws->label(1,0,itos(acc_power),xf);
    ws->label(0,1,"acc_flow(m3)",xf);
    ws->label(1,1,itos(acc_flow),xf);

    string path_post = title.toStdString();
    string path = path_pre + path_post; 
    wb.Dump(path);
    Util::SysLogD("save file : %s\n",path.c_str());
    emit recordoverflow(2);
}
