#ifndef FILECOPYER_H
#define FILECOPYER_H
#include <QThread>
#include <QString>
#include "util.h"

class FileCopyer : public QThread
{
    Q_OBJECT
public:
    FileCopyer(QObject *parent = 0)
        : QThread(parent)
    {

    }
protected:
    void run();

signals:
    void copyDone();

};
#endif // FILECOPYER_H
