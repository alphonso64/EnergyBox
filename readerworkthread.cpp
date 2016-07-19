#include "readerworkthread.h"
#include "util.h"
#include "stdlib.h"
#include "stdio.h"
//void ReaderWorkThread::run()
//{
//    xlsWorkBook* pWB;
//    xlsWorkSheet* pWS;
//    int i;
//    WORD t,tt;
//    pWB = xls_open(path.toStdString().c_str(), "UTF-8");

//    pWS=xls_getWorkSheet(pWB,pWB->sheets.count-1);
//    xls_parseWorkSheet(pWS);


//    char *str = (char *)pWS->rows.row[1].cells.cell[111].str;
//    float acc_power = stringToNum<float>(str);
//    str = (char *)pWS->rows.row[1].cells.cell[1].str;
//    float acc_flow = stringToNum<float>(str);



//    res.clear();
//    res.acc_flow = acc_flow;
//    res.acc_power = acc_power;

//    xls_close_WS(pWS);

//    Util::SysLogD("res %f %f\n",acc_power,acc_flow);

////    for (i=0;i<pWB->sheets.count-1;i++)
////    {
////        pWS=xls_getWorkSheet(pWB,i);
////        xls_parseWorkSheet(pWS);
////        Util::SysLogD("sheet %d %d\n",i+1,pWS->rows.lastrow);

////        for (t=0;t<=pWS->rows.lastrow;t++)
////        {
////            for (tt=0;tt<=pWS->rows.lastcol;tt++)
////            {

////            }
////        }
////        if (pWS->rows.row[t-1].cells.cell[0].str!=NULL && pWS->rows.row[t-1].cells.cell[0].str[0]!='\0')
////            Util::SysLogD("end time %s\n",pWS->rows.row[t-1].cells.cell[0].str);
////        xls_close_WS(pWS);
////    }
//    xls_close_WB(pWB);
//}

void ReaderWorkThread::run()
{
    WorkBook foo(path.toStdString());
    int sheetNum = foo.GetSheetCount();
    res.clear();

    cellContent c = foo.GetCell(sheetNum-1, (uint16_t)3, (uint16_t)2);
    if(c.str.length()!=0)
    {
       start_time = c.str;
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)4, (uint16_t)2);
    if(c.str.length()!=0)
    {
        meassure_time = c.str;
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)5, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.worktime = stringToNum<float>(c.str)*3600;
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)6, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.stanby_time = stringToNum<float>(c.str)*3600;
    }


     c = foo.GetCell(sheetNum-1, (uint16_t)8, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.acc_flow = stringToNum<float>(c.str);
    }
    c = foo.GetCell(sheetNum-1, (uint16_t)9, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.acc_power = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)10, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.acc_charge = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)11, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.ave_cost = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)12, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.ave_vsp = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)14, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.max_load_time = stringToNum<float>(c.str)*3600;
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)15, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.max_unload_time = stringToNum<float>(c.str)*3600;
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)16, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.load_time = stringToNum<float>(c.str)*3600;
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)17, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.unload_time = stringToNum<float>(c.str)*3600;
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)18, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.load_radio = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)19, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.unload_radio = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)20, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.load_cnt = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)21, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.unload_cnt = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)22, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.load_power = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)23, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.unload_power = stringToNum<float>(c.str);
    }
    c = foo.GetCell(sheetNum-1, (uint16_t)24, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.load_charge = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)25, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.unload_chargd = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)26, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.load_charge_radio = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)27, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.unload_charge_radio = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)29, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.first_order_energy_efficiency = stringToNum<float>(c.str);
    }

    c = foo.GetCell(sheetNum-1, (uint16_t)30, (uint16_t)2);
    if(c.str.length()!=0)
    {
        res.permanent_magnet_frequency_conversion = stringToNum<float>(c.str);
    }

    emit result();
}


//void ReaderWorkThread::run()
//{
//    WorkBook foo(path.toStdString());
//    int row ;
//    int col ;
//    int sheetNum = foo.GetSheetCount();
//    cellContent c = foo.GetCell(sheetNum-1, (uint16_t)2, (uint16_t)1);
//    float acc_power = stringToNum<float>(c.str);
//    c = foo.GetCell(sheetNum-1, (uint16_t)2, (uint16_t)2);
//    float acc_flow = stringToNum<float>(c.str);
//    res.clear();
//    res.acc_flow = acc_flow;
//    res.acc_power = acc_power;

//    c = foo.GetCell(0, 2, 1);
//    res.start_measure_time = stringToNum<long>(c.str);

//    int len = 1000;
//    CalTmp *temp =(CalTmp *)malloc(len*sizeof(CalTmp));
//    CalStatus status = {-1,-1.0};
//    clear(temp,len);
//    float acc_vsp = 0;
//    int acc_vsp_cnt = 0;
//    int cnt = 0;
//	long end_time;
//    for(int i=0;i<sheetNum-1;i++)
//    {
//        foo.InitIterator(i);
//        cnt = 0;
//        row = 1;
//        col = 0;
//        while(true)
//        {
//            cellContent c = foo.GetNextCell();
//            if(c.type == cellBlank)
//            {
//				end_time = temp[cnt].time;
//                cnt++;
//                if(cnt > 1)
//                {
//                   computeEnergy(temp,cnt,&status,&res);
//                }
//                break;
//            }


//            if(c.row>row)
//            {
//                row = c.row;
//                col = 0;
//                cnt++;
//            }

//            if(cnt >= len)
//            {
//                computeEnergy(temp,cnt,&status,&res);
//                cnt = 0;
//            }
//            col++ ;
//            if(c.row>1)
//            {
//                if(col == 1)
//                {
//                    temp[cnt].time = stringToNum<long>(c.str);
//                }else if(col == 5)
//                {
//                    temp[cnt].cur_a = stringToNum<float>(c.str);
//                }else if(col == 18){
//                    temp[cnt].power = stringToNum<float>(c.str);
//                }else if(col == 19){
//                    temp[cnt].vsp = stringToNum<float>(c.str);
//                    acc_vsp += temp[cnt].vsp;
//                    acc_vsp_cnt ++;
//                }
//            }
//        }
//        if(status.status == 1)
//        {
//            res.load_cnt++;
//        }else if(status.status == 0)
//        {
//            res.unload_cnt++;
//        }

//        Util::SysLogD("power::%f %f\n",res.unload_power,res.load_power);
//		//res.load_time = 0;
//		//res.unload_time = 0;
		
//    }
//    if(acc_vsp_cnt>0)
//        res.ave_vsp = acc_vsp/acc_vsp_cnt;
//    res.end_measure_time = end_time;

//    Util::SysLogD("end time ::%d %d\n",res.end_measure_time,acc_vsp_cnt);
//    res.worktime = res.load_time + res.unload_time;
//    res.stanby_time = res.end_measure_time - res.start_measure_time - res.worktime;


//    if(res.worktime != 0)
//    {
//        res.load_radio = ((float)res.load_time)/(float)res.worktime*100.0;
//        res.unload_radio = ((float)res.unload_time)/(float)res.worktime*100.0;
//    }

//    res.acc_flow = acc_flow/60;//m3/min
//    res.acc_power = acc_power/3600;//kwh
//    res.load_power /= 3600;
//    res.unload_power /= 3600;
//    Util::SysLogD("res time :: %d %d \n",res.load_time,res.unload_time);
//    Util::SysLogD("res ave_vsp :: %f %f %f\n",res.ave_vsp,res.load_radio,res.unload_radio);
//    free(temp);
//    emit result();
//}


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
			Util::SysLogD("scan sheet done::%f %d %d\n",temp[i-1].power,temp[i].time,temp[i-1].time);
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
           // printf("unload_time 1  %d %d\n",temp[len-1].time,starttime);
        }
    }
}

