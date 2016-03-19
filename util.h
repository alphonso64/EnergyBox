#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include "util.h"

class Util
{
public:
    Util();
    static bool writeInit(QString path, QString user_key, QString user_value);
    static bool readInit(QString path, QString user_key, QString &user_value);

};

#endif // UTIL_H
