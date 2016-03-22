#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include "util.h"
#include <QStringList>
class Util
{
public:
    Util();
    static bool writeInit(QString path, QString user_key, QString user_value);
    static bool readInit(QString path, QString user_key, QString &user_value);
    static QString ftos(float val);
    static QString checkUDiskPath();
    static QStringList getLocalFileList();
    static QStringList getUdiskFileList();

};

#endif // UTIL_H
