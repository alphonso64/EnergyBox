#include "util.h"
#include <QSettings>
#include <stdio.h>
#include <QRegExp>
#include <QDebug>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string>
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
    dir = opendir("/media/pi"); ///open the dir
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
    QString abs_path = QString("/media/pi/"+path+"/");

    dir = opendir(abs_path.toStdString().c_str()); ///open the dir
    QString pattern(".+\\.xls");
    QRegExp rx(pattern);

    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        if(rx.exactMatch(ptr->d_name))
        {
            list.push_back(ptr->d_name);
            //printf("name %s\n",ptr->d_name);
        }
    }
    closedir(dir);
    return list;
}

QStringList Util::getLocalFileList()
{
    QStringList list;
    DIR    *dir;
    struct    dirent    *ptr;
    dir = opendir("./"); ///open the dir
    QString pattern(".+\\.xls");
    QRegExp rx(pattern);

    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        if(rx.exactMatch(ptr->d_name))
        {
            list.push_back(ptr->d_name);
            //printf("name %s\n",ptr->d_name);
        }
    }
    closedir(dir);
    return list;
}


