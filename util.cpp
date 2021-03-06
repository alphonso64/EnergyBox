﻿#include "util.h"
#include <QSettings>
#include <stdio.h>
#include <QRegExp>
#include <QDebug>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "const_define.h"
#include <sys/stat.h>
#include <map>
#include <QDateTime>
#include <fcntl.h>


pthread_mutex_t gSysLogMutex = PTHREAD_MUTEX_INITIALIZER;
int gServerLog_num = 0;
FILE *gSysLogHandle;
int gCurLogRows = 0;
#define MAX_RTP_TCP_NUMBER 10000
#define TCP_RTP_LOG_FILE "/home/log"

typedef multimap<time_t, string> result_set_t;
Util::Util()
{

}

bool Util::writeGroup(QString path, QStringList user_key, QStringList user_value)
{
    if(path.isEmpty() || user_key.isEmpty())
    {
        return false;
    }
    else
    {
        //创建配置文件操作对象
        QSettings *config = new QSettings(path, QSettings::IniFormat);

        //将信息写入配置文件
        config->beginGroup("config");
        QStringList::iterator it_key = user_key.begin();
        QStringList::iterator it_value = user_value.begin();
        for(;it_key!=user_key.end()&& it_value !=user_value.end() ;++it_key,++it_value){
            config->setValue(*it_key, *it_value);
        }
        config->endGroup();
        return true;
    }
}

bool Util::writeInit(QString path, QString user_key, QString user_value)
{
    if(path.isEmpty() || user_key.isEmpty())
    {
        return false;
    }
    else
    {
        //创建配置文件操作对象
        QSettings *config = new QSettings(path, QSettings::IniFormat);

        //将信息写入配置文件
        config->beginGroup("config");
        config->setValue(user_key, user_value);
        config->endGroup();

        return true;
    }
}

bool Util::readInit(QString path, QString user_key, QString &user_value)
{
    user_value = QString("");
    if(path.isEmpty() || user_key.isEmpty())
    {
        return false;
    }
    else
    {
        //创建配置文件操作对象
        QSettings *config = new QSettings(path, QSettings::IniFormat);

        //读取用户配置信息
        user_value = config->value(QString("config/") + user_key).toString();

        return true;
    }
}

QString Util::ftos(float val)
{
    char temp[20];
    sprintf(temp,"%.3f",val);
    QString ss(temp);
    return ss;
}

QString Util::checkUDiskPath()
{
    DIR    *dir;
    struct    dirent    *ptr;
    dir = opendir(UDISK_PATH_PREFIX); ///open the dir
    QString pattern_a("\\.");
    QString pattern_b("\\.\\.");
    QRegExp rx_a(pattern_a);
    QRegExp rx_b(pattern_b);

    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        if(ptr->d_type == 4)
        {
            {
                if(!rx_a.exactMatch(ptr->d_name))
                {
                    if(!rx_b.exactMatch(ptr->d_name))
                    {
                        closedir(dir);
                        return QString(ptr->d_name);
                    }
                }
            }
        }
    }
    closedir(dir);
    return NULL;
}

void Util::deleteUnpluedUdiskPath()
{
    DIR    *dir;
    struct    dirent    *ptr;
    dir = opendir(UDISK_PATH_PREFIX);
    QString path_pre = QString(UDISK_PATH_PREFIX);
    QString pattern_a("\\.");
    QString pattern_b("\\.\\.");
    QRegExp rx_a(pattern_a);
    QRegExp rx_b(pattern_b);
    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        if(ptr->d_type == 4)
        {

            if(!rx_a.exactMatch(ptr->d_name))
            {
                if(!rx_b.exactMatch(ptr->d_name))
                {
                    QString path = QString(path_pre+ptr->d_name);
                    struct stat buf;
                    int res  = stat(path.toStdString().c_str(), &buf);
                    if(res == 0)
                    {
                        if(buf.st_uid != 1000)
                        {
                            QString cmd("sudo rm -rf "+path_pre+"\""+ptr->d_name+"\"");
                            system(cmd.toStdString().c_str());
                        }
                    }


                }
            }
        }
    }

    closedir(dir);
}

QString Util::checkUpdatePath(QString udiskPath)
{
    DIR    *dir;
    struct    dirent    *ptr;
    dir = opendir(udiskPath.toStdString().c_str()); ///open the dir
    QString pattern("BoxUpdateFile");
    QRegExp rx(pattern);

    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        //if(ptr->d_type == 4)
        {
            if(rx.exactMatch(ptr->d_name))
            {
//                printf("file type %d\n",ptr->d_type);
                closedir(dir);
                return QString(ptr->d_name);
            }
        }
    }
    closedir(dir);
    return NULL;
}

QStringList Util::getUdiskFileList()
{
    QStringList list;
    DIR    *dir;
    struct    dirent    *ptr;
    QString path = checkUDiskPath();
    if(path == NULL)
    {
        return list;
    }
    QString abs_path = QString(UDISK_PATH_PREFIX+path+"/");

    dir = opendir(abs_path.toStdString().c_str()); ///open the dir
    QString pattern(".+\\.xls");
    QRegExp rx(pattern);
    result_set_t res_set;
    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        if(rx.exactMatch(ptr->d_name))
        {
            string name(ptr->d_name);
            string path (abs_path.toStdString()+name);
            struct stat buf;
            stat(path.c_str(), &buf);
            if(buf.st_size>0)
            {
                res_set.insert(result_set_t::value_type(buf.st_mtime,name));
            }
        }
    }
    multimap<time_t, string>::reverse_iterator   i, iend;
    iend = res_set.rend();
    for (i=res_set.rbegin(); i!=iend; ++i)
    {
        list.push_back(((string)((*i).second)).c_str());
    }
    closedir(dir);
    return list;
}

static void setFileUpdateTime(const char *file,long time)
{
//    struct stat buf;
//    stat(path.c_str(), &buf);
//    SysLogD("now time %d\n",buf.st_mtime);
//    buf.st_mtime = time;


}

void Util::fileSync(const char *file)
{
    int fd =  open( file, O_RDWR);
    if(fd != -1)
    {
        syncfs(fd);
        close(fd);
    }
}

int Util::get_file_size(FILE *file)
{
    int size = 0;
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return size;
}

void Util::cpyFile(const char *src, const char *dst)
{
    FILE *fp = fopen(src, "rb+");
    if(NULL == fp)
    {
        return ;
    }
    int val = get_file_size(fp) ;
    if(val == 0)
    {
            return ;
    }
    char *buff = (char *)malloc(val);
    fread (buff,1,val,fp) ;
    fclose(fp);

    fp = fopen(dst, "wb+");
    fwrite(buff,1,val,fp) ;
    fclose(fp);
    free(buff);
    chmod(dst,S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH|S_IXOTH);
}

QStringList Util::getLocalFileList()
{
    QStringList list;
    DIR    *dir;
    struct    dirent    *ptr;
    dir = opendir(LOCAL_PATH_PREFIX); ///open the dir
    QString pattern(".+\\.xls");
    QRegExp rx(pattern);
    result_set_t res_set;
    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        if(rx.exactMatch(ptr->d_name))
        {
            string name(ptr->d_name);
            string path (LOCAL_PATH_PREFIX+name);
            struct stat buf;
            stat(path.c_str(), &buf);
            if(buf.st_size>0)
            {
                res_set.insert(result_set_t::value_type(buf.st_mtime,name));
            }

        }
    }
    multimap<time_t, string>::reverse_iterator   i, iend;
    iend = res_set.rend();
    for (i=res_set.rbegin(); i!=iend; ++i)
    {
        list.push_back(((string)((*i).second)).c_str());
    }
    closedir(dir);
    return list;
}

void Util::cpyLocal2Udisk()
{
    QStringList list;
    DIR    *dir;
    struct    dirent    *ptr;
    dir = opendir(LOCAL_PATH_PREFIX); ///open the dir
    QString pattern(".+\\.xls");
    QRegExp rx(pattern);

    QString path_udisk = checkUDiskPath();
    if(path_udisk == NULL)
    {
        return ;
    }
    QString abs_path = QString(UDISK_PATH_PREFIX+path_udisk+"/");

    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        if(rx.exactMatch(ptr->d_name))
        {
            string name(ptr->d_name);
            string path (LOCAL_PATH_PREFIX+name);
            string path_dst (abs_path.toStdString()+name);
            struct stat buf;
            stat(path.c_str(), &buf);
            if(buf.st_size>0)
            {
                cpyFile(path.c_str(),path_dst.c_str());
                fileSync(path_dst.c_str());
            }

        }
    }
}

void Util::genAnalyzeResultXls(AnalyzeResult res, QString savepath)
{
//    workbook wb;
//    xf_t* xf = wb.xformat();
//    worksheet* ws;
//    ws = wb.sheet("sheet1");

//    QDateTime date;
//    date.setTime_t(res.start_measure_time);
//    ws->label(1,1,"开始时间",xf);
//    ws->label(1,2,date.toString("yy/MM/dd hh:mm:ss").toStdString(),xf);
//    float time = (float)(res.end_measure_time-res.start_measure_time)/3600.0;
//    ws->label(1,5,"测量时间(h)",xf);
//    ws->label(1,6,Util::ftos(time).toStdString(),xf);
	
//	time = (float)(res.worktime)/3600.0;
//	ws->label(2,1,"工作时间(h)",xf);
//    ws->label(2,2,Util::ftos(time).toStdString(),xf);
//	time = (float)(res.stanby_time)/3600.0;
//	ws->label(2,5,"待机时间(h)",xf);
//    ws->label(2,6,Util::ftos(time).toStdString(),xf);

//	ws->label(3,1,"总产气量(m3)",xf);
//    ws->label(3,2,Util::ftos(res.acc_flow).toStdString(),xf);
//	ws->label(3,5,"总耗电量(kwh)",xf);
//    ws->label(3,6,Util::ftos(res.acc_power).toStdString(),xf);
	
//	ws->label(4,1,"电费总额(元)",xf);
//    ws->label(4,2,"电费待定",xf);
//	ws->label(4,5,"气体成本(元/m3)",xf);
//    ws->label(4,6,"成本待定",xf);
	
//	ws->label(5,1,"平均比功率(kw/(m3/min))",xf);
//    ws->label(5,2,Util::ftos(res.ave_vsp).toStdString(),xf);
	
//	time = (float)(res.load_time)/3600.0;
//	ws->label(7,1,"满载时间(h)",xf);
//    ws->label(7,2,Util::ftos(time).toStdString(),xf);
//	time = (float)(res.unload_time)/3600.0;
//	ws->label(6,5,"空载时间(h)",xf);
//    ws->label(6,6,Util::ftos(time).toStdString(),xf);

//	ws->label(7,1,"满载率(%)",xf);
//    ws->label(7,2,Util::ftos(res.load_radio).toStdString(),xf);
//	ws->label(7,5,"空载率(%)",xf);
//    ws->label(7,6,Util::ftos(res.unload_radio).toStdString(),xf);
	
//	ws->label(8,1,"加载次数",xf);
//    ws->label(8,2,QString::number(res.load_cnt).toStdString(),xf);
//	ws->label(8,5,"卸载次数",xf);
//    ws->label(8,6,QString::number(res.unload_cnt).toStdString(),xf);
	
	
//	ws->label(9,1,"满载耗电(kwh)",xf);
//    ws->label(9,2,Util::ftos(res.load_power).toStdString(),xf);
//	ws->label(9,5,"空载耗电(kwh)",xf);
//    ws->label(9,6,Util::ftos(res.unload_power).toStdString(),xf);
	
//	ws->label(10,1,"满载电费(元)",xf);
//    ws->label(10,2,"22",xf);
//	ws->label(10,5,"空载电费(元)",xf);
//    ws->label(10,6,"33",xf);
	
//	ws->label(11,1,"满载耗电占比(%)",xf);
//    ws->label(11,2,"111",xf);
//	ws->label(11,5,"空载耗电占比(%)",xf);
//    ws->label(11,6,"22",xf);
	
//    wb.Dump(savepath.toStdString());
}

void Util::writeResult(worksheet *ws, xf_t *xf, AnalyzeResult res)
{
    QDateTime date;
    date.setTime_t(res.start_measure_time);
    ws->label(1,1,"开始时间",xf);
    ws->label(1,2,date.toString("yy/MM/dd hh:mm:ss").toStdString(),xf);
    float time = (float)(res.end_measure_time-res.start_measure_time)/3600.0;
    ws->label(1,5,"测量时间(h)",xf);
    ws->label(1,6,Util::ftos(time).toStdString(),xf);

    time = (float)(res.worktime)/3600.0;
    ws->label(2,1,"工作时间(h)",xf);
    ws->label(2,2,Util::ftos(time).toStdString(),xf);
    time = (float)(res.stanby_time)/3600.0;
    ws->label(2,5,"待机时间(h)",xf);
    ws->label(2,6,Util::ftos(time).toStdString(),xf);

    ws->label(3,1,"总产气量(m3)",xf);
    ws->label(3,2,Util::ftos(res.acc_flow).toStdString(),xf);
    ws->label(3,5,"总耗电量(kwh)",xf);
    ws->label(3,6,Util::ftos(res.acc_power).toStdString(),xf);

    ws->label(4,1,"电费总额(元)",xf);
    ws->label(4,2,Util::ftos(res.acc_charge).toStdString(),xf);
    ws->label(4,5,"气体成本(元/m3)",xf);
    ws->label(4,6,Util::ftos(res.ave_cost).toStdString(),xf);

    ws->label(5,1,"平均比功率(kw/(m3/min))",xf);
    ws->label(5,2,Util::ftos(res.ave_vsp).toStdString(),xf);

    time = (float)(res.max_load_time)/3600.0;
    ws->label(6,1,"最长加载时间(h)",xf);
    ws->label(6,2,Util::ftos(time).toStdString(),xf);
    time = (float)(res.max_unload_time)/3600.0;
    ws->label(6,5,"最长卸载时间(h)",xf);
    ws->label(6,6,Util::ftos(time).toStdString(),xf);

    time = (float)(res.load_time)/3600.0;
    ws->label(7,1,"满载时间(h)",xf);
    ws->label(7,2,Util::ftos(time).toStdString(),xf);
    time = (float)(res.unload_time)/3600.0;
    ws->label(7,5,"空载时间(h)",xf);
    ws->label(7,6,Util::ftos(time).toStdString(),xf);

    ws->label(8,1,"满载率(%)",xf);
    ws->label(8,2,Util::ftos(res.load_radio).toStdString(),xf);
    ws->label(8,5,"空载率(%)",xf);
    ws->label(8,6,Util::ftos(res.unload_radio).toStdString(),xf);

    ws->label(9,1,"加载次数",xf);
    ws->label(9,2,QString::number(res.load_cnt).toStdString(),xf);
    ws->label(9,5,"卸载次数",xf);
    ws->label(9,6,QString::number(res.unload_cnt).toStdString(),xf);


    ws->label(10,1,"满载耗电(kwh)",xf);
    ws->label(10,2,Util::ftos(res.load_power).toStdString(),xf);
    ws->label(10,5,"空载耗电(kwh)",xf);
    ws->label(10,6,Util::ftos(res.unload_power).toStdString(),xf);

    ws->label(11,1,"满载电费(元)",xf);
    ws->label(11,2,Util::ftos(res.load_charge).toStdString(),xf);
    ws->label(11,5,"空载电费(元)",xf);
    ws->label(11,6,Util::ftos(res.unload_chargd).toStdString(),xf);

    ws->label(12,1,"满载耗电占比(%)",xf);
    ws->label(12,2,Util::ftos(res.load_charge_radio).toStdString(),xf);
    ws->label(12,5,"空载耗电占比(%)",xf);
    ws->label(12,6,Util::ftos(res.unload_charge_radio).toStdString(),xf);

    ws->label(13,1,"采用一级能效机组节省电量(kwh)",xf);
    ws->label(13,2,Util::ftos(res.first_order_energy_efficiency).toStdString(),xf);
    ws->label(13,5,"采用永磁变频机组节省电量(kwh）",xf);
    ws->label(13,6,Util::ftos(res.permanent_magnet_frequency_conversion).toStdString(),xf);
}

void Util::setCellFormat(cell_t *cell)
{
    cell->borderstyle(BORDER_BOTTOM, BORDER_THIN);
    cell->borderstyle(BORDER_TOP, BORDER_THIN);
    cell->borderstyle(BORDER_LEFT, BORDER_THIN);
    cell->borderstyle(BORDER_RIGHT, BORDER_THIN);
    cell->valign(VALIGN_CENTER);
}

void Util::writeResultWithFormat(worksheet *ws, xf_t *xf, AnalyzeResult res)
{
    cell_t *cell;
    range *ra;
    int index = 0;
    int start,end;
    int colA = 0;
    int colB = 1;
    int colC = 2;
    unsigned int labelHeiht = 256*1.4;
    QDateTime date;
    float time;
    ws->defaultColwidth(8);
    ws->rowheight(0, 256 * 2.5);
    ws->colwidth(0, 256 * 24);
    ws->colwidth(1, 256 * 28);
    ws->colwidth(2, 256 * 28);
    ws->merge(0,0,0,2);
    cell = ws->label(index++, 0, "节能分析结果", xf);
    cell->halign(HALIGN_CENTER);
    cell->valign(VALIGN_CENTER);
    cell->fontcolor(CLR_WHITE);
    cell->fontheight(300);
    ra = ws->rangegroup(0,0,0,2);
    ra->cellcolor(CLR_BLUE_GRAY);
/*------------时间统计-----------*/
    ws->merge(index,colA,index,colC);
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"时间统计",xf);
    cell->valign(VALIGN_CENTER);
    ra = ws->rangegroup(index,colA,index,colC);
    ra->cellcolor(CLR_PALE_BLUE);
    index++;

    start = index;
    date.setTime_t(res.start_measure_time);
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"开始时间",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,date.toString("yy/MM/dd hh:mm:ss").toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"",xf);
    setCellFormat(cell);

    time = (float)(res.end_measure_time-res.start_measure_time)/3600.0;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"测量时间",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(time).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"小时",xf);
    setCellFormat(cell);

    time = (float)(res.worktime)/3600.0;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"工作时间",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(time).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"小时",xf);
    setCellFormat(cell);

    end = index;
    time = (float)(res.stanby_time)/3600.0;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"待机时间",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(time).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"小时",xf);
    setCellFormat(cell);

    ra = ws->rangegroup(start,colA,end,colA);
    ra->cellcolor(CLR_GRAY25);

/*------------累计数据统计-----------*/
    ws->merge(index,colA,index,colC);
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"累计数据及比功率",xf);
    cell->valign(VALIGN_CENTER);
    ra = ws->rangegroup(index,colA,index,colC);
    ra->cellcolor(CLR_PALE_BLUE);
    index++;

    start  = index;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"总产气量",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.acc_flow).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"m3",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"总耗电量",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.acc_power).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"kwh",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"电费总额",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.acc_charge).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"元",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"气体成本",xf);
    setCellFormat(cell);
    cell =  ws->label(index,colB,Util::ftos(res.ave_cost).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"元/m3",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"单位成本",xf);
    setCellFormat(cell);
    cell =  ws->label(index,colB,Util::ftos(res.ave_power_cost).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"元/m3",xf);
    setCellFormat(cell);

    end =index;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"平均比功率",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.ave_vsp).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"kw/(m3/min)",xf);
    setCellFormat(cell);

    ra = ws->rangegroup(start,colA,end,colA);
    ra->cellcolor(CLR_GRAY25);

/*------------加卸载数据统计-----------*/
    ws->merge(index,colA,index,colC);
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"加卸载分析",xf);
    cell->valign(VALIGN_CENTER);
    ra = ws->rangegroup(index,colA,index,colC);
    ra->cellcolor(CLR_PALE_BLUE);
    index++;

    start  = index;
    time = (float)(res.max_load_time)/3600.0;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"最长加载时间",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(time).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"小时",xf);
    setCellFormat(cell);

    time = (float)(res.max_unload_time)/3600.0;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"最长卸载时间",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(time).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"小时",xf);
    setCellFormat(cell);

    time = (float)(res.load_time)/3600.0;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"满载时间",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(time).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"小时",xf);
    setCellFormat(cell);

    time = (float)(res.unload_time)/3600.0;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"空载时间",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(time).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"小时",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"满载率",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.load_radio).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"%",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"空载率",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.unload_radio).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"%",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"加载次数",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,QString::number(res.load_cnt).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"卸载次数",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,QString::number(res.unload_cnt).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"满载耗电",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.load_power).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"kwh",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"空载耗电",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.unload_power).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"kwh",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"满载电费",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.load_charge).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"元",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"空载电费",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.unload_chargd).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"元",xf);
    setCellFormat(cell);

    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"满载耗电占比",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.load_charge_radio).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"%",xf);
    setCellFormat(cell);

    end  = index;;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"空载耗电占比",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.unload_charge_radio).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index++,colC,"%",xf);
    setCellFormat(cell);

    ra = ws->rangegroup(start,colA,end,colA);
    ra->cellcolor(CLR_GRAY25);

/*------------预计节能分析-----------*/
    ws->merge(index,colA,index,colC);
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"预计节能分析",xf);
    cell->valign(VALIGN_CENTER);
    ra = ws->rangegroup(index,colA,index,colC);
    ra->cellcolor(CLR_PALE_BLUE);
    index++;

//    start  = index;
//    ws->rowheight(index, labelHeiht);
//    cell = ws->label(index,colA,"采用一级能效机组节省电量",xf);
//    setCellFormat(cell);
//    cell = ws->label(index,colB,Util::ftos(res.first_order_energy_efficiency).toStdString(),xf);
//    setCellFormat(cell);
//    cell = ws->label(index++,colC,"kwh",xf);
//    setCellFormat(cell);

//    end = index;
//    ws->rowheight(index, labelHeiht);
//    cell = ws->label(index,colA,"采用永磁变频机组节省电量",xf);
//    setCellFormat(cell);
//    cell = ws->label(index,colB,Util::ftos(res.permanent_magnet_frequency_conversion).toStdString(),xf);
//    setCellFormat(cell);
//    cell = ws->label(index++,colC,"kwh",xf);
//    setCellFormat(cell);

//    ra = ws->rangegroup(start,colA,end,colA);
//    ra->cellcolor(CLR_GRAY25);
    start  = index;\
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,"采用一级能效机组节省电量(kwh)",xf);
    setCellFormat(cell);
    cell = ws->label(index,colC,"采用一级能效机组节省电量(kwh)",xf);
    setCellFormat(cell);
    ra = ws->rangegroup(start,colA,start,colC);
    ra->cellcolor(CLR_GRAY25);

    index++;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"本次测量时间",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.first_order_energy_efficiency).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index,colC,Util::ftos(res.permanent_magnet_frequency_conversion).toStdString(),xf);
    setCellFormat(cell);

    index++;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"一天（每天12小时工作时间）",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.first_order_energy_efficiency_day).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index,colC,Util::ftos(res.permanent_magnet_frequency_conversion_day).toStdString(),xf);
    setCellFormat(cell);

    index++;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"一月（30*12=360小时）",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.first_order_energy_efficiency_month).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index,colC,Util::ftos(res.permanent_magnet_frequency_conversion_month).toStdString(),xf);
    setCellFormat(cell);

    index++;
    end = index;
    ws->rowheight(index, labelHeiht);
    cell = ws->label(index,colA,"一年（365*12=4380小时）",xf);
    setCellFormat(cell);
    cell = ws->label(index,colB,Util::ftos(res.first_order_energy_efficiency_year).toStdString(),xf);
    setCellFormat(cell);
    cell = ws->label(index,colC,Util::ftos(res.permanent_magnet_frequency_conversion_year).toStdString(),xf);
    setCellFormat(cell);

    ra = ws->rangegroup(start,colA,end,colA);
    ra->cellcolor(CLR_GRAY25);
}

int Util::InitSysLog()
{
#ifdef LOG_TEST
    char log[256];
    snprintf(log, sizeof(log), "%s_%d.log",TCP_RTP_LOG_FILE,gServerLog_num);
    printf("****INIT LOG SYS****\n");
    printf("--------------------------------------------------------------\n");
    printf("OPEN LOGFILE %s\n",log);
    gSysLogHandle = fopen((char*)log, "at");
    if (gSysLogHandle){
       // printf("###%s(),creat log file %s sucessfull!\n",__FUNCTION__, log);

    printf("--------------------------------------------------------------\n\n");
        return 0;
    }else{
        //printf("###$s(), Fail openning event log file (errno=%s)\n", __FUNCTION__, strerror(errno));
        return  - 1;
    }
#else
    return 0;
#endif
}

int Util::RebuildSysLogFiles()
{
#ifdef LOG_TEST
    gServerLog_num ++;
    if (gSysLogHandle)
    {
        char log[256];
        fclose(gSysLogHandle);
        snprintf(log, sizeof(log), "%s_%d.log",TCP_RTP_LOG_FILE,gServerLog_num);
        gSysLogHandle = fopen((char*)log, "at");
    }
    return 0;
#else
    return 0;
#endif

}



void Util::SysLogE(const char *p_fmt, ...)
{
#ifdef LOG_TEST
    char date[256];
    time_t now;
    struct tm ptm;
    va_list ap;


    if (!gSysLogHandle){
        return;
    }

    pthread_mutex_lock(&gSysLogMutex);

    time(&now);                   // Gets the system time

    if (localtime_r(&now, &ptm))
    {
        strftime(date, sizeof (date), "%F %T", &ptm);
        fprintf(gSysLogHandle, "[ %s ] ", date);

        fprintf(gSysLogHandle, "Error: ");

        va_start(ap, p_fmt);
        vfprintf(gSysLogHandle, p_fmt, ap);
        va_end(ap);

//        fprintf(gSysLogHandle, "\r\n");

        fflush(gSysLogHandle);

        gCurLogRows++;

        if(gCurLogRows > MAX_RTP_TCP_NUMBER)
        {
            RebuildSysLogFiles();
            gCurLogRows = 0;
        }
    }

    pthread_mutex_unlock(&gSysLogMutex);
#endif
}


void Util::SysLogD(const char *p_fmt, ...)
{
#ifdef LOG_TEST
    char date[256];
    time_t now;
    struct tm ptm;
    va_list ap;


    if (!gSysLogHandle){
        return;
    }

    pthread_mutex_lock(&gSysLogMutex);

    time(&now);                   // Gets the system time

    if (localtime_r(&now, &ptm))
    {
        strftime(date, sizeof (date), "%F %T", &ptm);
        fprintf(gSysLogHandle, "[ %s ] ", date);
        fprintf(gSysLogHandle, "Debug: ");
        va_start(ap, p_fmt);
        vfprintf(gSysLogHandle, p_fmt, ap);
        va_end(ap);

        fflush(gSysLogHandle);

        gCurLogRows++;

        if(gCurLogRows > MAX_RTP_TCP_NUMBER)
        {
            RebuildSysLogFiles();
            gCurLogRows = 0;
        }
    }

    pthread_mutex_unlock(&gSysLogMutex);
#endif
}

bool Util::isDevicelegal()
{
    char *serial_a = (char *)malloc(16);
    char *serial_b = (char *)malloc(16);
    if(get_cpu_serial(serial_a)!=0)
    {
         goto EXIT_FAIL;
    }
    if(get_local_serial(serial_b)!=0)
    {
         goto EXIT_FAIL;
    }
    if(strcmp(serial_a,serial_b) == 0)
    {
         free(serial_a);
         free(serial_b);
         return true;
    }
 EXIT_FAIL:
    free(serial_a);
    free(serial_b);
    return false;
}

int Util::get_cpu_serial(char *serail)
{
    char* match;
    FILE *cpuinfo = fopen("/proc/cpuinfo", "rb");
    char *arg = 0;
    size_t size = 0;
    char serial_str[16];
    while(getdelim(&arg, &size, 0, cpuinfo) != -1)
    {
         match = strstr (arg, "Serial");
         if (match == NULL)
             return -1;
         sscanf (match, "Serial		: %s", serial_str);
         strcpy(serail,serial_str);
         return 0;
    }
    free(arg);
    fclose(cpuinfo);
    return -1;
}

int Util::get_local_serial(char *serail)
{
    char* match;
    FILE *cpuinfo = fopen("/home/pi/cpuserial", "rb");
    char *arg = 0;
    size_t size = 0;
    char serial_str[16];
    while(getdelim(&arg, &size, 0, cpuinfo) != -1)
    {
         match = strstr (arg, "Serial");
         if (match == NULL)
             return -1;
         sscanf (match, "Serial		: %s", serial_str);
         strcpy(serail,serial_str);
         return 0;
    }
    free(arg);
    fclose(cpuinfo);
    return -1;
}

int Util::getFreeDiskSpaceByMB()
{
    struct statfs sfs;
    statfs("/", &sfs);
    int size =  sfs.f_bfree/1024*sfs.f_bsize/1024;
    return size;
}



