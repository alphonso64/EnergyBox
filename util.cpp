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
#include<map>
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
    QString pattern("GSP1RMCULFR.*");
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


