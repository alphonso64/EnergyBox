#ifndef READERWORKTHREAD_H
#define READERWORKTHREAD_H

#include <QThread>
#include <QString>
#include <stdlib.h>
#include <stdio.h>
#include "XlsReader.h"

#include <string.h>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include "analyzeresult.h"
using namespace xls;
using namespace std;



class ReaderWorkThread : public QThread
{
    Q_OBJECT
public:
    ReaderWorkThread(QObject *parent = 0)
        : QThread(parent)
    {

    }

signals:
    void result();

protected:
    template <class Type>
    Type stringToNum(const string& str)
    {
        istringstream iss(str);
        Type num;
        iss >> num;
        return num;
    }

    void run()
    {
        WorkBook foo(path.toStdString());
        int row = 1;
        int col = 0;
        int sheetNum = foo.GetSheetCount();
        printf("sheet count:%d\n",sheetNum);
        cellContent c = foo.GetCell(sheetNum-1, (uint16_t)2, (uint16_t)1);
        float acc_power = stringToNum<float>(c.str);
        c = foo.GetCell(sheetNum-1, (uint16_t)2, (uint16_t)2);
        float acc_flow = stringToNum<float>(c.str);
        printf("%f %f\n",acc_flow,acc_power);
        float acc_a = 0;
        res.acc_flow = acc_flow;
        res.acc_power = acc_power;
//        for(int i=0;i<sheetNum-1;i++)
//        {
//            foo.InitIterator(i);
//            while(true) {
//                cellContent c = foo.GetNextCell();
//                if(c.type == cellBlank) break;
//                if(c.row>row)
//                {
//                    row = c.row;
//                    col = 0;
//                }
//                col++ ;
//                if(c.row>1)
//                {
//                    if(col == 17)
//                    {
//                        printf("%s\n",c.str.c_str());
//                        float temp = stringToNum<float>(c.str);
//                        acc_a += temp;
//                    }
//                }
//            }
//        }
//        printf("cal %f\n",acc_a);
        emit result();
    }

public:
    QString path;
    AnalyzeResult res;
};

#endif // READERWORKTHREAD_H
