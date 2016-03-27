#include "readerworkthread.h"

void ReaderWorkThread::run()
{
    WorkBook foo(path.toStdString());
    int row = 1;
    int col = 0;
    int sheetNum = foo.GetSheetCount();
    cellContent c = foo.GetCell(sheetNum-1, (uint16_t)2, (uint16_t)1);
    float acc_power = stringToNum<float>(c.str);
    c = foo.GetCell(sheetNum-1, (uint16_t)2, (uint16_t)2);
    float acc_flow = stringToNum<float>(c.str);
    res.clear();
    res.acc_flow = acc_flow;
    res.acc_power = acc_power;


    c = foo.GetCell(0, 2, 1);
    res.start_measure_time = stringToNum<long>(c.str);



    int len = 1000;
    CalTmp *temp =(CalTmp *)malloc(len*sizeof(CalTmp));
    CalStatus status = {-1,-1.0};
    clear(temp,len);
    int cnt = 0;
    float acc_vsp = 0;
    int acc_vsp_cnt = 0;
    for(int i=0;i<sheetNum-1;i++)
    {
        foo.InitIterator(i);
        while(true)
        {
            cellContent c = foo.GetNextCell();
            if(c.type == cellBlank)
            {
                cnt++;
                if(cnt !=0)
                {
                   computeEnergy(temp,cnt,&status,&res);
                }
                break;
            }
            if(c.row>row)
            {
                row = c.row;
                col = 0;
                cnt++;
            }

            if(cnt >= len)
            {
                computeEnergy(temp,cnt,&status,&res);
                clear(temp,len);
                cnt = 0;
            }
            col++ ;
            if(c.row>1)
            {
                if(col == 1)
                {
                    temp[cnt].time = stringToNum<long>(c.str);
                    //printf("time : %d\n",temp[cnt].time);
                }else if(col == 5)
                {
                    temp[cnt].cur_a = stringToNum<float>(c.str);
                }else if(col == 18){
                    temp[cnt].power = stringToNum<float>(c.str);
                }else if(col == 19){
                    temp[cnt].vsp = stringToNum<float>(c.str);
                    printf("vsp : %f\n",temp[cnt].vsp);
                    acc_vsp += temp[cnt].vsp;
                    acc_vsp_cnt ++;
                }
//                else if(col == 3)
//                {
//                    temp[cnt].vol_b = stringToNum<float>(c.str);
//                }else if(col == 4)
//                {
//                    temp[cnt].vol_c = stringToNum<float>(c.str);
//                }else if(col == 5)
//                {
//                    temp[cnt].cur_a = stringToNum<float>(c.str);
//                }else if(col == 6)
//                {
//                    temp[cnt].cur_b = stringToNum<float>(c.str);
//                }else if(col == 7)
//                {
//                    temp[cnt].cur_c = stringToNum<float>(c.str);
//                }
            }
        }
        if(acc_vsp_cnt>0)
            res.ave_vsp = acc_vsp/acc_vsp_cnt;
        res.end_measure_time = temp[cnt-1].time;

        if(status.status == 1)
        {
            res.load_cnt++;
        }else if(status.status == 0)
        {
            res.unload_cnt++;
        }
        res.worktime = res.load_time + res.unload_time;
        res.stanby_time = res.end_measure_time - res.start_measure_time - res.worktime;


        if(res.worktime != 0)
        {
            res.load_radio = ((float)res.load_time)/(float)res.worktime*100.0;
            res.unload_radio = ((float)res.unload_time)/(float)res.worktime*100.0;
        }

        res.acc_flow = acc_flow/60;//m3/min
        res.acc_power = acc_power/3600;//kwh
        res.load_power /= 3600;
        res.unload_power /= 3600;
        printf("res time :: %d %d \n",res.load_time,res.unload_time);
        printf("res ave_vsp :: %f %f %f\n",res.ave_vsp,res.load_radio,res.unload_radio);
        //printf("res :: %d %d %d %d\n",calres.loadTime,calres.loadCnt,calres.unloadTime,calres.unloadCnt);
        free(temp);
    }
    emit result();
}


void ReaderWorkThread::clear(CalTmp *temp,int len)
{
    for(int i=0;i<len;i++)
    {
        temp[i].time = 0;
        temp[i].cur_a = 0;
//        temp[i].cur_b = 0;
//        temp[i].cur_c = 0;
//        temp[i].vol_a = 0;
//        temp[i].vol_b = 0;
//        temp[i].vol_c = 0;
        temp[i].status = 0;
        temp[i].power = 0;
        temp[i].vsp = 0;
    }
}

void ReaderWorkThread::computeEnergy(CalTmp *temp,int len,CalStatus *status,AnalyzeResult *res)
{

    status->status = -1;
    if(status->last_cur_a>-0.5)
    {
        if(temp[0].cur_a>status->last_cur_a)
        {
            temp[0].status = 1;
        }else if(temp[0].cur_a<status->last_cur_a){
            temp[0].status = 0;

        }else if(temp[0].cur_a==status->last_cur_a){
            temp[0].status = 2;
        }
    }else
    {
        temp[0].status = 2;
    }
    status->last_cur_a = temp[len-1].cur_a;
    for(int i=1;i<len;i++)
    {
        if(temp[i].cur_a>temp[i-1].cur_a)
        {
            temp[i].status = 1;
            res->load_power += temp[i-1].power*(temp[i].time - temp[i-1].time);
        }else if(temp[i].cur_a<temp[i-1].cur_a){
            temp[i].status = 0;
            res->unload_power += temp[i-1].power*(temp[i].time - temp[i-1].time);
        }else if(temp[i].cur_a==temp[i-1].cur_a){
            temp[i].status = 2;
        }
    }

//   for(int i=0;i<200;i++)
//   {
//       printf("index %5d %d\n",i,temp[i].status);
//   }

   
    long starttime  = temp[0].time;
    for(int i=1;i<len;i++)
    {
        if(temp[i].status !=temp[i-1].status)
        {
            if(temp[i-1].status == 2 )//|| temp[i].status == 2)
            {
                starttime = temp[i].time;
            }else
            {
                if(temp[i-1].status== 1)
                {
                    res->load_time += temp[i].time-starttime;
                    res->load_cnt++;
                   // printf("status 1 %d %d %d\n",i,temp[i].time,starttime);
                }else if(temp[i-1].status== 0)
                {
                    res->unload_time += temp[i].time-starttime;
                    res->unload_cnt++;
                   // printf("unload_time 1 %d %d %d\n",i,temp[i].time,starttime);
                }
                starttime = temp[i].time;
            }

        }
    }

    if(starttime != temp[len -1].time)
    {
        if(temp[len-1].status== 1)
        {
            res->load_time += temp[len-1].time-starttime;
            status->status = 1;
        }else if(temp[len-1].status== 0)
        {
            res->unload_time += temp[len-1].time-starttime;
            status->status = 0;
            printf("unload_time 1  %d %d\n",temp[len-1].time,starttime);
        }
    }
}

