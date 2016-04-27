#ifndef FILECOPYER_H
#define FILECOPYER_H
#include <QThread>
#include <QString>
#include "util.h"
#define MODE_COPY 1
#define MODE_UPDATE 2
#define MODE_SCREENSHOT 3
#define MODE_SYNC 4

class FileCopyer : public QThread
{
    Q_OBJECT
public:
    FileCopyer(QObject *parent = 0)
        : QThread(parent)
    {

    }
    int mode;
    QString filename;
    QString cmd;
protected:
    void run();

signals:
    void copyDone(int);

};
#endif // FILECOPYER_H
