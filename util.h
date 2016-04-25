#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include "util.h"
#include <QStringList>
#include <string>
#include "analyzeresult.h"
#include <xlslib/xlslib.h>
#include <pthread.h>
using namespace std;
using namespace xlslib_core;
class Util
{
public:
    Util();
    static bool writeInit(QString path, QString user_key, QString user_value);
    static bool writeGroup(QString path, QStringList user_key, QStringList user_value);
    static bool readInit(QString path, QString user_key, QString &user_value);
    static QString ftos(float val);
    static QString checkUDiskPath();
    static QString checkUpdatePath(QString udiskPath);
    static QStringList getLocalFileList();
    static QStringList getUdiskFileList();
    static void genAnalyzeResultXls(AnalyzeResult res,QString savepath);
    static void deleteUnpluedUdiskPath();
    static int  InitSysLog();
    static int  RebuildSysLogFiles();
    static void SysLogE(const char *p_fmt, ...);
    static void SysLogD(const char *p_fmt, ...);
    static void writeResult(worksheet *ws, xf_t *xf, AnalyzeResult res);
    static void fileSync(const char *file);
    static int get_file_size(FILE *file);
    static void cpyFile(const char *src,const char *dst);
    static void cpyLocal2Udisk();
    static void setFileUpdateTime(const char *file,long time);
private:
};

#endif // UTIL_H
