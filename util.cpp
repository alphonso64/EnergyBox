#include "util.h"
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
typedef multimap<time_t, string> result_set_t;
Util::Util()
{
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
    //QString pattern("GSP1RMCULFR.*");
	QString pattern("BC73-B58D");
    QString pattern_a("\\.");
    QString pattern_b("\\.\\.");
    QRegExp rx(pattern);
    QRegExp rx_a(pattern_a);
    QRegExp rx_b(pattern_b);

    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        if(ptr->d_type == 4)
        {
            if(!rx.exactMatch(ptr->d_name))
            {
                if(!rx_a.exactMatch(ptr->d_name))
                {
                    if(!rx_b.exactMatch(ptr->d_name))
                    {
                        printf("d_type:%d d_name: %s\n", ptr->d_type,ptr->d_name);
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
            string path ("./"+name);
            struct stat buf;
            stat(path.c_str(), &buf);
            res_set.insert(result_set_t::value_type(buf.st_mtime,name));
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
            string path ("./"+name);
            struct stat buf;
            stat(path.c_str(), &buf);
            res_set.insert(result_set_t::value_type(buf.st_mtime,name));
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

void Util::genAnalyzeResultXls(AnalyzeResult res, QString savepath)
{
    workbook wb;
    xf_t* xf = wb.xformat();
    worksheet* ws;
    ws = wb.sheet("sheet1");

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
    ws->label(4,2,"电费待定",xf);	
	ws->label(4,5,"气体成本(元/m3)",xf);
    ws->label(4,6,"成本待定",xf);
	
	ws->label(5,1,"平均比功率(kw/(m3/min))",xf);
    ws->label(5,2,Util::ftos(res.ave_vsp).toStdString(),xf);
	
	time = (float)(res.load_time)/3600.0;
	ws->label(6,1,"满载时间(h)",xf);
    ws->label(6,2,Util::ftos(time).toStdString(),xf);	
	time = (float)(res.unload_time)/3600.0;
	ws->label(6,5,"空载时间(h)",xf);
    ws->label(6,6,Util::ftos(time).toStdString(),xf);

	ws->label(7,1,"满载率(%)",xf);
    ws->label(7,2,Util::ftos(res.load_radio).toStdString(),xf);	
	ws->label(7,5,"空载率(%)",xf);
    ws->label(7,6,Util::ftos(res.unload_radio).toStdString(),xf);
	
	ws->label(8,1,"加载次数",xf);
    ws->label(8,2,QString::number(res.load_cnt).toStdString(),xf);	
	ws->label(8,5,"卸载次数",xf);
    ws->label(8,6,QString::number(res.unload_cnt).toStdString(),xf);
	
	
	ws->label(9,1,"满载耗电(kwh)",xf);
    ws->label(9,2,Util::ftos(res.load_power).toStdString(),xf);	
	ws->label(9,5,"空载耗电(kwh)",xf);
    ws->label(9,6,Util::ftos(res.unload_power).toStdString(),xf);
	
	ws->label(10,1,"满载电费(元)",xf);
    ws->label(10,2,"22",xf);	
	ws->label(10,5,"空载电费(元)",xf);
    ws->label(10,6,"33",xf);
	
	ws->label(11,1,"满载耗电占比(%)",xf);
    ws->label(11,2,"111",xf);	
	ws->label(11,5,"空载耗电占比(%)",xf);
    ws->label(11,6,"22",xf);
	
    wb.Dump(savepath.toStdString());
}


