#ifndef DATAWORKERTHREAD_H
#define DATAWORKERTHREAD_H

#include <QThread>
#include <QString>
#include <stdlib.h>
#include <stdio.h>
#include <QDebug>
#include <xlslib/xlslib.h>
#include <pthread.h>
using namespace xlslib_core;
using namespace std;
/*
class DataWorkerThread : public QThread
{
    Q_OBJECT
public:
    DataWorkerThread(QObject *parent = 0)
        : QThread(parent)
    {

    }
protected:
    void run()
    {
        workbook wb;

        xf_t* xf = wb.xformat();

        worksheet* ws;

        ws = wb.sheet("sheet1");

        string label = "Hello, World!";

        for(int i=0;i<200;i++)
        {
            for(int j=0;j<26;j++)
                ws->label(i,j,label,xf);
        }
        ws = wb.sheet("sheet2");
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<26;j++)
                ws->label(i,j,label,xf);
        }

        //wb.Dump("workbook.xls");

        recorderFlag = false;
        isFirstFlag = false;
		int cnt=0;
        while(true)
        {
			isFirstFlag = true;
            if(recorderFlag)
            {
                if(!isFirstFlag)
                {
                    qDebug() << "start: " ;
                }
                isFirstFlag = true;
            }else
            {
                if(isFirstFlag)
                {
                    qDebug() << "save file : " << title ;
                    wb.Dump("workbook.xls");
                }
                isFirstFlag = false;
            }
        }
    }

public:
    bool recorderFlag;
    bool isFirstFlag;
    QString title;
};*/

class DataWorkerThread
{
public:
    DataWorkerThread()
    {

    }
	
	void run();
	
public:

};


#endif // DATAWORKERTHREAD_H
