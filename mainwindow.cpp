#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalinputpanelcontext.h"
#include "energyparam.h"
//extern bool recorderFlag;
//extern bool isFirstFlag;
//extern QString title;
#include <qwt_dial_needle.h>
#include <qwt_round_scale_draw.h>
#include "util.h"
#include <QFileDialog>
#include "const_define.h"
#include <sys/stat.h>
#include <sys/types.h>
int cnt = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Util::InitSysLog();
    ui->setupUi(this);
    ui->label->setStyleSheet("color:#ffffff;");
    ui->label_2->setPixmap(QPixmap(PRODUCE_LOGO_PATH));
    ui->label_3->setPixmap(QPixmap(UDISK_LOGO_PATH));
    ui->label_3->setVisible(false);
    QString *style = new QString("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(38, 166, 154, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #24a69a;} QPushButton:pressed{background-color: rgba(38, 166, 154, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #24a69a;}");
    QString *style_a = new QString("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(255, 152, 0, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #ff9800;} QPushButton:pressed{background-color: rgba(255, 152, 0, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #ff9800;}");
    QString *style_b = new QString("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(128, 128, 128, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 0px solid #101010;} QPushButton:pressed{background-color: rgba(255, 152, 0, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #ff9800;}");

   this->setWindowFlags(Qt::CustomizeWindowHint) ;
   ui->pushButton->setStyleSheet(*style);
   ui->pushButton_2->setStyleSheet(*style);
   ui->pushButton_3->setStyleSheet(*style_a);
   ui->pushButton_4->setStyleSheet(*style_a);
   ui->pushButton_5->setStyleSheet(*style);
   ui->pushButton_6->setStyleSheet(*style_a);
   ui->pushButton_7->setStyleSheet(*style);
   ui->pushButton_8->setStyleSheet(*style_a);
   ui->pushButton_9->setStyleSheet(*style_a);
   ui->pushButton_12->setStyleSheet(*style_a);
   ui->pushButton_11->setStyleSheet(*style_a);
   ui->pushButton_13->setStyleSheet(*style_a);
   ui->pushButton_14->setStyleSheet(*style_a);
   ui->pushButton_15->setStyleSheet(*style_a);
   ui->pushButton_16->setStyleSheet(*style_a);
   ui->pushButton_17->setStyleSheet(*style_a);
   ui->pushButton_18->setStyleSheet(*style_a);
   ui->pushButton_19->setStyleSheet(*style_b);
   ui->pushButton_20->setStyleSheet(*style_a);
   ui->pushButton_21->setStyleSheet(*style_a);

   ui->pushButton->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_2->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_3->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_4->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_5->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_6->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_7->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_8->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_9->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_12->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_11->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_13->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_14->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_15->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_16->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_17->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_18->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_19->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_20->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_19->setEnabled(false);
   ui->pushButton_21->setFocusPolicy ( Qt::NoFocus );

   ui->widget->hide();
   ui->widget_2->show();
   ui->widget_5->hide();
   ui->widget_6->hide();
   ui->widget_7->hide();

   ui->pushButton_2->setEnabled(false);

   pageIndex = 2;

   ui->lcdNumber_clock->setVisible(false);
   timeStampFlag = false;

   //system("sudo rm -f /media/pi/*");

   Util::deleteUnpluedUdiskPath();

   timer = new QTimer( this );
   timer->start(500);
   connect ( timer , SIGNAL (timeout ()), this , SLOT (show_time()));

   timer_check = new QTimer( this );
   timer_check->start(1500);
   connect ( timer , SIGNAL (timeout ()), this , SLOT (check_status()));

   QRegExp double_rx10000("10000|([0-9]{0,4}[\.][0-9]{1,3})");
   ui->lineEdit_radio->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_radio));
   ui->lineEdit_current_idle_max->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_current_idle_max));
   ui->lineEdit_current_down_max->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_current_down_max));
   ui->lineEdit_charge->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_charge));
   ui->lineEdit_loading_pressure->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_loading_pressure));
   ui->lineEdit_unloading_pressure->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_unloading_pressure));
   ui->lineEdit_gas->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_gas));
   ui->lineEdit_power->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_power));

   QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
   QStringList strings;
   strings << "本地" << "U盘" ;
   ui->comboBox_store_type->clear();
   ui->comboBox_store_type->addItems(strings);

   QStringList strings_;
   strings_ << "三相三线" << "三相四线" ;
   ui->comboBox_store_type_2->clear();
   ui->comboBox_store_type_2->addItems(strings_); 

   sysparam.loadParam();

   startFlag = -1;

   recorder = new RecordWorkThread(this);
   dataWoker = new DataWorkerThread(this);
   recorder->dataWoker = dataWoker;
   reader = new ReaderWorkThread(this);
   dataWoker->start();

   QFont font( "Times", 14);
   flowDial = new CommonDial( ui->widget_2 );
   flowDial->setScaleStepSize( 20.0 );
   flowDial->setScale( 0.0, 160.0 );
   flowDial->setFont(font);
   flowDial->setLabel("流量");
   flowDial->scaleDraw()->setPenWidth( 2 );
   flowDial->move(620,0);

   powerDial = new CommonDial( ui->widget_2 );
   powerDial->setScaleStepSize( 20.0 );
   powerDial->setScale( 0.0, 160.0 );
   powerDial->setFont(font);
   powerDial->setLabel("功率");
   powerDial->scaleDraw()->setPenWidth( 2 );
   powerDial->move(180,0);

   ui->label_flow_unit->setText("m<sup>3</sup>/min");
   ui->label_flow_2->setText("m<sup>3</sup>/min");
   ui->label_acc_flow_unit->setText("m<sup>3</sup>");
   ui->label_acc_flow_1->setText("m<sup>3</sup>");

   ui->label_gas_produce_rated->setText("m<sup>3</sup>/min");
   ui->label_gas_produce_rated_1->setText("m<sup>3</sup>/min");
   ui->label_VSP->setText("Kw/(m<sup>3</sup>/min)");
   ui->label_VSP_1->setText("Kw/(m<sup>3</sup>/min)");
   ui->label_cost->setText("元/m<sup>3");

   cusMsg = new CustomMessageBox();
   cusMsg->hide();
   cusMsg->move(270,180);

   file = new FileWidget();
   file->hide();
   file->move(62,50);

   connect(file, SIGNAL(fileopen(QString)), SLOT(on_analysis(QString)));
   connect(reader, SIGNAL(result()), SLOT(on_result()));
   connect(recorder, SIGNAL(recordoverflow(int)), SLOT(on_overflow(int)));



  }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_result()
{
    //ui->label_acc_flow_2->setText(Util::ftos(reader->res.acc_flow));
    //ui->label_acc_power_2->setText(Util::ftos(reader->res.acc_power));
    ui->label_analyze_file_name->setText(file->filename);
    ui->label_analyze_rated_power->setText(Util::ftos(sysparam.power));
    ui->label_analyze_rated_flow->setText(Util::ftos(sysparam.gas));
    QDateTime date;
    date.setTime_t(reader->res.start_measure_time);
    ui->label_analyze_start_time->setText(date.toString("yy/MM/dd hh:mm:ss"));

    float time = (float)(reader->res.end_measure_time-reader->res.start_measure_time)/3600.0;
    ui->label_analyze_all_time->setText(Util::ftos(time));

    time = (float)(reader->res.worktime)/3600.0;
    ui->label_analyze_work_time->setText(Util::ftos(time));

    time = (float)(reader->res.stanby_time)/3600.0;
    ui->label_analyze_standby_time->setText(Util::ftos(time));

    ui->label_analyze_acc_power->setText(Util::ftos(reader->res.acc_power));
    ui->label_analyze_acc_flow->setText(Util::ftos(reader->res.acc_flow));
    ui->label_analyze_ave_vsp->setText(Util::ftos(reader->res.ave_vsp));
    ui->label_analyze_acc_charge->setText("电费");
    ui->label_analyze_flow_cost->setText("成本");

    time = (float)(reader->res.load_time)/3600.0;
    ui->label_analyze_loadtime->setText(Util::ftos(time));

    time = (float)(reader->res.unload_time)/3600.0;
    ui->label_analyze_unloadtime->setText(Util::ftos(time));

    ui->label_analyze_loadcnt->setText(QString::number(reader->res.load_cnt));
    ui->label_analyze_unloadcnt->setText(QString::number(reader->res.unload_cnt));
    ui->label_analyze_load_radio->setText(Util::ftos(reader->res.load_radio));
    ui->label_analyze_unload_radio->setText(Util::ftos(reader->res.unload_radio));
    ui->label_analyze_load_power->setText(Util::ftos(reader->res.load_power));
    ui->label_analyze_unload_power->setText(Util::ftos(reader->res.unload_power));

    ui->pushButton_19->setEnabled(true);

//    ui->label_analyze_load_power->setText(Util::ftos(reader->res.load_power));
//    ui->label_analyze_unload_power->setText(Util::ftos(reader->res.unload_power));
}


void MainWindow::on_analysis(QString path)
{
    printf("on_analysis %s\n",path.toStdString().c_str());
    reader->path = path;
    reader->start();
}

void MainWindow::clearAnalyzeView()
{
//    ui->label_acc_flow_2->setText("");
//    ui->label_acc_power_2->setText("");
}



void MainWindow::on_pushButton_pressed()
{
    if(pageIndex!=1){

        if(sysparam.initFlag)
        {
             ui->lineEdit_charge->setText(QString("%1").arg(sysparam.charge));
             ui->lineEdit_current_down_max->setText(QString("%1").arg(sysparam.current_down_max));
             ui->lineEdit_current_idle_max->setText(QString("%1").arg(sysparam.current_idle_max));
             ui->lineEdit_gas->setText(QString("%1").arg(sysparam.gas));
             ui->lineEdit_loading_pressure->setText(QString("%1").arg(sysparam.loading_pressure));
             ui->lineEdit_unloading_pressure->setText(QString("%1").arg(sysparam.unloading_pressure));
             ui->lineEdit_power->setText(QString("%1").arg(sysparam.power));
             ui->lineEdit_radio->setText(QString("%1").arg(sysparam.radio));
             ui->comboBox_store_type->setCurrentIndex(sysparam.save_type);
             ui->comboBox_store_type_2->setCurrentIndex(sysparam.wiring_type);
        }

        ui->widget->show();
		ui->widget_3->hide();
        ui->widget_2->hide();
        ui->widget_5->hide();
        ui->widget_6->hide();
        ui->widget_7->hide();
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_16->setEnabled(false);
        ui->pushButton_17->setEnabled(true);
        pageIndex =1;
        DigitalInputPanelContext *dc = (DigitalInputPanelContext*)qApp->inputContext();
        dc->hideWidget(false);
    }

}

void MainWindow::on_pushButton_2_pressed()
{
    if(pageIndex!=2){
        if(pageIndex == 1)
        {
            DigitalInputPanelContext *dc = (DigitalInputPanelContext*)qApp->inputContext();
            dc->hideWidget(true);
        }
        ui->widget->hide();
        ui->widget_2->show();
        ui->widget_5->hide();
        ui->widget_6->hide();
        ui->widget_7->hide();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_5->setEnabled(true);

        ui->label_IPower_content->raise();

        pageIndex =2;
    }
}
//开始记录
void MainWindow::on_pushButton_3_pressed()
{

    if(!sysparam.loadParam())
    {
        cusMsg->setMessage(QString("请先设置参数!"));
        cusMsg->show();
        return;
    }
    QString path_pre;
    if(sysparam.save_type == 1)
    {

        path_pre = Util::checkUDiskPath();
        if(path_pre == NULL)
        {
            cusMsg->setMessage(QString("U盘未插入"));
            cusMsg->show();
            return;
        }
        path_pre = QString(UDISK_PATH_PREFIX+path_pre+"/");
    }
    else
    {
        path_pre = LOCAL_PATH_PREFIX;
    }
    recorder->path_pre = path_pre.toStdString();
    if(startFlag != 0){
        startFlag = 0;
        ui->pushButton_3->setEnabled(false);

        startTime.setTime_t(dataWoker->time);
        record_start_time = startTime.toString("yy/MM/dd hh:mm:ss");
        ui->label_start_time_content->setText(record_start_time);
        ui->label_end_time_content->clear();
        recorder->start();
    }
}

//结束记录
void MainWindow::on_pushButton_4_pressed()
{
    if(startFlag == 0)
    {
        startFlag = -1;
        ui->pushButton_3->setEnabled(true);
        QDateTime  end_time;
        end_time.setTime_t(dataWoker->time);
        record_end_time = end_time.toString("yy/MM/dd hh:mm:ss");
        recorder->title = QString(record_start_time+"----"+record_end_time+".xls");
        recorder->title.replace(":","_");
        recorder->title.replace("/","-");
        recorder->recorderFlag = true;
        cusMsg->setMessage(QString("结束测量，正在保存数据"));
        cusMsg->show();
    }
}
//溢出 结束记录
void MainWindow::on_overflow(int cmd)
{
    if(cmd == 1)
    {
        if(startFlag == 0)
        {
            startFlag = -1;
            ui->pushButton_3->setEnabled(true);
            QDateTime  end_time;
            end_time.setTime_t(dataWoker->time);
            record_end_time = end_time.toString("yy/MM/dd hh:mm:ss");
            recorder->title = QString(record_start_time+"----"+record_end_time+".xls");
            recorder->title.replace(":","_");
            recorder->title.replace("/","-");
            recorder->recorderFlag = true;
            cusMsg->setMessage(QString("结束测量，正在保存数据"));
            cusMsg->show();
        }
    }else if(cmd == 2)
    {
        cusMsg->setMessage(QString("数据保存成"));
        cusMsg->show();
    }

}

void MainWindow::on_pushButton_5_pressed()
{
    if(pageIndex == 1)
    {
        DigitalInputPanelContext *dc = (DigitalInputPanelContext*)qApp->inputContext();
        dc->hideWidget(true);
    }
    if(pageIndex!=5)
    {
        //clearAnalyzeView();
        ui->widget->hide();
        ui->widget_2->hide();
        ui->widget_5->show();
        ui->widget_6->hide();
        ui->widget_7->hide();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_11->setEnabled(false);
        ui->pushButton_13->setEnabled(true);
        ui->widget_4->show();
        ui->widget_8->hide();
        pageIndex =5;
    }

}

void MainWindow::on_pushButton_6_pressed()
{
    ui->widget_2->hide();
    ui->widget_6->show();
}

void MainWindow::on_pushButton_7_pressed()
{
    ui->widget_2->hide();
    ui->widget_7->show();
}

void MainWindow::on_pushButton_8_pressed()
{
    ui->widget_6->hide();
    ui->widget_2->show();
}

void MainWindow::on_pushButton_9_pressed()
{
    ui->widget_7->hide();
    ui->widget_2->show();
}

void MainWindow::show_time(){
    if(!timeStampFlag)
    {
        if(dataWoker->time <=0)
        {
            return;
        }
        timeStampFlag = true;
        ui->lcdNumber_clock->setVisible(true);
    }
    QDateTime  time ;
    time.setTime_t(dataWoker->time);
    QString string_a = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->lcdNumber_clock->display(string_a);
    EnergyParam param = dataWoker->getEnergyParam();
    setInfo_detail(param);
    flowDial->setValue( param.flow_content );
    powerDial->setValue( param.power );

    if(startFlag == 0 )
    {
        uint c = 0, d =0,e =0 ;
        c = (uint)time.toTime_t();
        d = (uint)startTime.toTime_t();
        e = c - d;
        QDateTime time_;
        time_.setTime_t(e);
        ui->label_end_time_content->setText(time_.toString("hh:mm:ss"));
        setInfo(param);
    }
}

void MainWindow::check_status(){
    if(Util::checkUDiskPath() == NULL)
    {
        ui->label_3->setVisible(false);
    }else
    {
        ui->label_3->setVisible(true);
        //printf("u insert\n");
    }


}

void MainWindow::setInfo(EnergyParam param){
    ui->label_power_content->setText(Util::ftos(recorder->acc_power/3600));
    ui->label_flow_content->setText(Util::ftos(recorder->acc_flow/60));
//    ui->label_loding_rate_content->setText(itos(temp++));
}

void MainWindow::setInfo_detail(EnergyParam param){
    //int temp = cnt;

    ui->label_IPower_content->setText(Util::ftos(param.power));
    ui->label_IFlow_content->setText(Util::ftos(param.flow_content));
    ui->label_power_radio_content->setText(Util::ftos(param.vsp));

    ui->label_env_humidity_content->setText(Util::ftos(param.env_humidity));
    ui->label_env_temp_content->setText(Util::ftos(param.env_temp));
    ui->label_air_pressure_content->setText(Util::ftos(param.air_pressure));
    ui->label_air_temp_content->setText(Util::ftos(param.air_temp));
    ui->label_flow_content_1->setText(Util::ftos(param.flow_content));

    ui->label_voltage_a_content->setText(Util::ftos(param.voltage_a));
    ui->label_voltage_b_content->setText(Util::ftos(param.voltage_b));
    ui->label_voltage_c_content->setText(Util::ftos(param.voltage_c));

    ui->label_current_a_content->setText(Util::ftos(param.current_a));
    ui->label_current_b_content->setText(Util::ftos(param.current_b));
    ui->label_current_c_content->setText(Util::ftos(param.current_c));

    ui->label_active_power_content->setText(Util::ftos(param.active_power));
    ui->label_reactive_power_content->setText(Util::ftos(param.reactive_power));
    ui->label_power_factor_content->setText(Util::ftos(param.power_factor));
    ui->label_frequency_content->setText(Util::ftos(param.frequency));
    ui->label_apparent_power_content->setText(Util::ftos(param.apparent_power));
}

QString MainWindow::itos(int val){
    stringstream ss;
    ss<<val;
    QString string_a(ss.str().c_str());
    return string_a;
}

void MainWindow::on_pushButton_12_clicked()
{

    SysParam param;
    QString content = ui->lineEdit_charge->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.charge = content.toFloat();

    content = ui->lineEdit_radio->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.radio = content.toFloat();

    content = ui->lineEdit_power->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.power = content.toFloat();

    content = ui->lineEdit_current_idle_max->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.current_idle_max = content.toFloat();


    param.save_type = ui->comboBox_store_type->currentIndex();
    param.wiring_type = ui->comboBox_store_type_2->currentIndex();

    content = ui->lineEdit_gas->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.gas = content.toFloat();

    content = ui->lineEdit_current_down_max->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.current_down_max = content.toFloat();

    content = ui->lineEdit_unloading_pressure->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.unloading_pressure = content.toFloat();

    content = ui->lineEdit_loading_pressure->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.loading_pressure = content.toFloat();

    sysparam.setParam(param);
    sysparam.saveParam();
    cusMsg->setMessage(QString("保存成功"));
    cusMsg->show();

    dataWoker->sendMsg(1,param.radio,1,param.wiring_type,0,0);
    return;

    EXIT_FAIL:
        cusMsg->setMessage(QString("内容不能为空！"));
        cusMsg->show();


}

void MainWindow::on_pushButton_10_clicked()
{
    qApp->exit(0);
}

void MainWindow::on_pushButton_11_pressed()
{
    ui->pushButton_13->setEnabled(true);
    ui->pushButton_11->setEnabled(false);
    ui->widget_4->show();
    ui->widget_8->hide();
}

void MainWindow::on_pushButton_13_pressed()
{
    ui->pushButton_11->setEnabled(true);
    ui->pushButton_13->setEnabled(false);
    ui->widget_8->show();
    ui->widget_4->hide();
}




void MainWindow::on_pushButton_14_pressed()
{
    file->show();
    file->setLocalView();
}

void MainWindow::on_pushButton_15_pressed()
{

}

void MainWindow::on_pushButton_16_pressed()
{
    ui->widget_3->hide();
    ui->pushButton_16->setEnabled(false);
    ui->pushButton_17->setEnabled(true);
}

void MainWindow::on_pushButton_17_pressed()
{
    ui->widget_3->show();
    ui->pushButton_16->setEnabled(true);
    ui->pushButton_17->setEnabled(false);
}

void MainWindow::on_pushButton_18_pressed()
{

}

void MainWindow::on_pushButton_18_clicked()
{
    QString path_pre = Util::checkUDiskPath();
    if(path_pre == NULL)
    {
        cusMsg->setMessage(QString("U盘未插入"));
        cusMsg->show();
        return;
    }
    path_pre = QString(UDISK_PATH_PREFIX+path_pre+"/");
    path_pre = QString("sudo cp -rf *.xls "+path_pre);

    printf("path %s\n",path_pre.toStdString().c_str());
    system(path_pre.toStdString().c_str());
    cusMsg->setMessage(QString("导出成功！"));
    cusMsg->show();
    return;
}

void MainWindow::on_pushButton_15_clicked()
{
    system("sudo rm -rf *.xls");
    cusMsg->setMessage(QString("删除成功！"));
    cusMsg->show();

}

void MainWindow::on_pushButton_19_clicked()
{
    QString path_pre = Util::checkUDiskPath();
    if(path_pre == NULL)
    {
        cusMsg->setMessage(QString("U盘未插入"));
        cusMsg->show();
        return;
    }
    QString path =  QString(UDISK_PATH_PREFIX+path_pre+"/res");
    mkdir(path.toStdString().c_str(),0777);
    path_pre = QString(path+"/res_"+file->filename);
    Util::genAnalyzeResultXls(reader->res,path_pre);
    cusMsg->setMessage(QString("导出结果成功"));
    cusMsg->show();
}

void MainWindow::on_pushButton_20_clicked()
{
    QString path_pre = Util::checkUDiskPath();
    if(path_pre == NULL)
    {
        cusMsg->setMessage(QString("U盘未插入"));
        cusMsg->show();
        return;
    }
    QString path(UDISK_PATH_PREFIX + path_pre);

    QString file_name = Util::checkUpdatePath(path);
    if(file_name == NULL)
    {
        cusMsg->setMessage(QString("未检测到更新文件"));
        cusMsg->show();
        return;
    }
    file_name = QString(path+"/"+file_name);
    //printf("update path %s\n",file_name.toStdString().c_str());
    QString cmd("sudo cp "+file_name+" /home/program/temp/");
    system(cmd.toStdString().c_str());
    cusMsg->setMessage(QString("更新成功，请重启机器"));
    cusMsg->show();
    return;
}

void MainWindow::on_pushButton_21_clicked()
{
    QString path_pre = Util::checkUDiskPath();
    if(path_pre == NULL)
    {
        cusMsg->setMessage(QString("U盘未插入"));
        cusMsg->show();
        return;
    }
    QString path(UDISK_PATH_PREFIX + path_pre);
    QDateTime  time ;
    time.setTime_t(dataWoker->time);
    QString time_str = time.toString("yyyy-MM-dd_hh_mm_ss");
    path = QString(path + "/"+time_str+".png");
    path = QString("scrot "+path);
    printf("save png %s\n",path.toStdString().c_str());
    system(path.toStdString().c_str());

}
