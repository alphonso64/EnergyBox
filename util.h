#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include "util.h"
#include <QStringList>
#include <string>
#include "analyzeresult.h"
#include <xlslib/xlslib.h>
using namespace std;
using namespace xlslib_core;
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
    static void genAnalyzeResultXls(AnalyzeResult res,QString savepath);

};

#endif // UTIL_H
