#include "recordworkthread.h"
// #include <unistd.h>
//bool recorderFlag;
//bool isFirstFlag;
//QString title;

//void * thr_fn1(void *arg)
//{
//	recorderFlag = false;

//	workbook wb;

//	xf_t* xf = wb.xformat();

//	worksheet* ws;

//	ws = wb.sheet("sheet1");

//	string label = "Hello, World!";

//	int cnt = 0;
//	while(!recorderFlag)
//	{
//		ws->label(cnt++,0,label,xf);
//		usleep(100000);
//	}
//	qDebug() << "save file : " << title ;
//	string ss = title.toStdString();
//	printf("save file : %s",ss.c_str());
//	wb.Dump(ss);
//}

//void DataWorkerThread::run()
//{
//	pthread_t tid1;
//	pthread_create(&tid1, NULL, thr_fn1, NULL);
//}
