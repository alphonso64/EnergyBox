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
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(QPixmap(PRODUCE_LOGO_PATH));
    ui->label_3->setPixmap(QPixmap(UDISK_LOGO_PATH));
    ui->label_3->setVisible(false);
    QString style("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(38, 166, 154, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #24a69a;} QPushButton:pressed{background-color: rgba(38, 166, 154, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #24a69a;}");
    QString style_a("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(255, 152, 0, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #ff9800;} QPushButton:pressed{background-color: rgba(255, 152, 0, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #ff9800;}");
    QString style_b ("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(128, 128, 128, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 0px solid #101010;} QPushButton:pressed{background-color: rgba(255, 152, 0, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #ff9800;}");

    this->setWindowFlags(Qt::CustomizeWindowHint) ;
    ui->pushButton->setStyleSheet(style);
    ui->pushButton_2->setStyleSheet(style);
    ui->pushButton_3->setStyleSheet(style_a);
    ui->pushButton_4->setStyleSheet(style_a);
    ui->pushButton_26->setStyleSheet(style_b);
    ui->pushButton_5->setStyleSheet(style);
    ui->pushButton_6->setStyleSheet(style_a);
    ui->pushButton_7->setStyleSheet(style_a);
    ui->pushButton_8->setStyleSheet(style_a);
    ui->pushButton_9->setStyleSheet(style_a);
    ui->pushButton_12->setStyleSheet(style_a);
    ui->pushButton_11->setStyleSheet(style_a);
    ui->pushButton_13->setStyleSheet(style_a);
    ui->pushButton_14->setStyleSheet(style_a);
    ui->pushButton_15->setStyleSheet(style_a);
    ui->pushButton_16->setStyleSheet(style_a);
    ui->pushButton_17->setStyleSheet(style_a);
    ui->pushButton_24->setStyleSheet(style_a);
    ui->pushButton_18->setStyleSheet(style_a);
    ui->pushButton_19->setStyleSheet(style_a);
    ui->pushButton_20->setStyleSheet(style_a);
    ui->pushButton_21->setStyleSheet(style_a);
    ui->pushButton_22->setStyleSheet(style_a);
    ui->pushButton_23->setStyleSheet(style_a);
    ui->pushButton_25->setStyleSheet(style_a);
    ui->pushButton_27->setStyleSheet(style_a);
    ui->pushButton_28->setStyleSheet(style_a);
    ui->pushButton_29->setStyleSheet(style_a);

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
    ui->pushButton_24->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_18->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_19->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_20->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_21->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_22->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_23->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_25->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_26->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_27->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_28->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_29->setFocusPolicy ( Qt::NoFocus );
    ui->widget->hide();
    ui->widget_2->show();
    ui->widget_5->hide();
    ui->widget_6->hide();
    ui->widget_7->hide();
    ui->widget_13->hide();

    ui->pushButton_2->setEnabled(false);
//    ui->pushButton_10->setVisible(false);
    ui->lcdNumber_clock->setVisible(false);
    ui->pushButton_26->setEnabled(false);

    pageIndex = 2;
    timeStampFlag = false;
    Util::deleteUnpluedUdiskPath();
    sysparam.loadParam();
    startFlag = -1;
    saveState = false;

    timer = new QTimer( this );
    timer->start(500);
    connect ( timer , SIGNAL (timeout ()), this , SLOT (show_time()));
    timer_check = new QTimer( this );
    timer_check->start(1500);
    connect ( timer , SIGNAL (timeout ()), this , SLOT (check_status()));

    QRegExp double_rx10000("10000|([-]{0,1}[0-9]{0,4}[\.][0-9]{1,3})");

    ui->lineEdit_radio->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_radio));
    ui->lineEdit_current_idle_max->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_current_idle_max));
    ui->lineEdit_current_down_max->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_current_down_max));
    ui->lineEdit_charge->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_charge));
    ui->lineEdit_loading_pressure->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_loading_pressure));
    ui->lineEdit_unloading_pressure->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_unloading_pressure));
    ui->lineEdit_gas->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_gas));
    ui->lineEdit_power->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_power));
    ui->lineEdit_env_hum->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_env_hum));
    ui->lineEdit_env_temp->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_env_temp));
   // ui->lineEdit_flow_modify->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_flow_modify));
    ui->lineEdit_charge_normal->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_charge_normal));
    ui->lineEdit_charge_peak->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_charge_peak));
    ui->lineEdit_charge_valley->setValidator(new QRegExpValidator(double_rx10000,ui->lineEdit_charge_valley));

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
    //   ui->label->setText(QString("空压系统节能分析仪 GSA500-P"));
    ui->label->setText(QString("空压系统能效测试仪"));
    QStringList strings;
    strings << "本地" << "U盘" ;
    ui->comboBox_store_type->clear();
    ui->comboBox_store_type->addItems(strings);
    QStringList strings_;
    strings_ << "三相三线" << "三相四线" ;
    ui->comboBox_store_type_2->clear();
    ui->comboBox_store_type_2->addItems(strings_);
    QStringList strings__;
    strings__ << "不分时计费" << "分时计费" ;
    ui->comboBox_charge_type->clear();
    ui->comboBox_charge_type->addItems(strings__);
    QStringList strings_a;
    strings_a << "自动获取" << "手动输入" ;
    ui->comboBox_env_temp->clear();
    ui->comboBox_env_temp->addItems(strings_a);

    ui->comboBox_env_hum->clear();
    ui->comboBox_env_hum->addItems(strings_a);

    recorder = new RecordWorkThread(this);
    dataWoker = new DataWorkerThread(this);
    copyer = new FileCopyer(this);
    recorder->dataWoker = dataWoker;
    reader = new ReaderWorkThread(this);
    dataWoker->start();

    dataWoker->env_hum_type = sysparam.env_hum_type;
    dataWoker->env_temp_type = sysparam.env_temp_type;
    dataWoker->env_hum = sysparam.env_hum;
    dataWoker->env_temp = sysparam.env_temp;
    dataWoker->flow_modify = sysparam.flow_modify/100;

    QFont font( "Times", 14);
    flowDial = new CommonDial( ui->widget_2 );
    flowDial->setPalette( colorTheme( QColor( Qt::lightGray ).dark( 80 ) ) );
    flowDial->setScaleStepSize( 10.0 );
    flowDial->setScale( 0.0, 100.0 );
    flowDial->setFont(font);
    flowDial->setLabel("流量");
    flowDial->scaleDraw()->setPenWidth( 2 );
    flowDial->move(620,0);
    flowDial->setFocusPolicy ( Qt::NoFocus );
    //flowDial->setLineWidth( 2 );
    //flowDial->setFrameShadow( QwtDial::Sunken );

    powerDial = new CommonDial( ui->widget_2 );
    powerDial->setPalette( colorTheme( QColor( Qt::lightGray ).dark( 80 ) ) );
    powerDial->setScaleStepSize( 20.0 );
    powerDial->setScale( 0.0, 160.0 );
    powerDial->setFont(font);
    powerDial->setLabel("功率");
    powerDial->scaleDraw()->setPenWidth( 2 );
    powerDial->move(180,0);
    powerDial->setFocusPolicy ( Qt::NoFocus );
    //powerDial->setLineWidth( 2 );
    //powerDial->setFrameShadow( QwtDial::Sunken );

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

    chargeform = new ChargeForm();
    chargeform->hide();
    chargeform->move(100 ,95);

    aboutwidget = new AboutWidget();
    aboutwidget->hide();
    aboutwidget->move(220 ,130);

    file = new FileWidget();
    file->hide();
    file->move(62,50);

    connect(file, SIGNAL(fileopen(QString)), SLOT(on_analysis(QString)));
    connect(reader, SIGNAL(result()), SLOT(on_result()));
    connect(recorder, SIGNAL(recordoverflow(int)), SLOT(on_overflow(int)));
    connect(dataWoker, SIGNAL(setEcho(int)), SLOT(on_setEcho(int)));
    connect(chargeform, SIGNAL(periodset(int)), SLOT(on_setPeriod(int)));
    connect(copyer, SIGNAL(copyDone(int)), SLOT(on_copyDone(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setPeriod(int flag)
{
    if(flag == -1)
    {
        cusMsg->setMessage("时间段错误");
        cusMsg->show();
    }
}

void MainWindow::on_copyDone(int flag)
{
    if(flag == MODE_COPY)
    {
        cusMsg->setMessage("导出数据成功");
        cusMsg->showWithButton();
    }
    else if(flag == MODE_SCREENSHOT)
    {
        cusMsg->setMessage(QString("截图成功"));
        cusMsg->showWithButton();
    }
    else if(flag == MODE_UPDATE)
    {
        cusMsg->setMessage(QString("更新成功，请重启机器"));
        cusMsg->showWithButton();
    }
}

void MainWindow::on_result()
{
    //ui->label_acc_flow_2->setText(Util::ftos(reader->res.acc_flow));
    //ui->label_acc_power_2->setText(Util::ftos(reader->res.acc_power));
    ui->label_analyze_file_name->setText(file->filename);
    ui->label_analyze_rated_power->setText(Util::ftos(sysparam.power));
    ui->label_analyze_rated_flow->setText(Util::ftos(sysparam.gas));
//    QDateTime date;
//    date.setTime_t(reader->res.start_measure_time);
    if(reader->start_time.length()>0)
        ui->label_analyze_start_time->setText(reader->start_time.c_str());

//    float time = (float)(reader->res.end_measure_time-reader->res.start_measure_time)/3600.0;
    if(reader->meassure_time.length()>0)
        ui->label_analyze_all_time->setText(reader->meassure_time.c_str());

    float time = (float)(reader->res.worktime)/3600.0;
    ui->label_analyze_work_time->setText(Util::ftos(time));

    time = (float)(reader->res.stanby_time)/3600.0;
    ui->label_analyze_standby_time->setText(Util::ftos(time));

    ui->label_analyze_acc_power->setText(Util::ftos(reader->res.acc_power));
    ui->label_analyze_acc_flow->setText(Util::ftos(reader->res.acc_flow));
    ui->label_analyze_ave_vsp->setText(Util::ftos(reader->res.ave_vsp));
    ui->label_analyze_acc_charge->setText(Util::ftos(reader->res.acc_charge));
    ui->label_analyze_flow_cost->setText(Util::ftos(reader->res.ave_cost));

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
    ui->label_analyze_load_charge->setText(Util::ftos(reader->res.load_charge));
    ui->label_analyze_unload_charge->setText(Util::ftos(reader->res.unload_chargd));
    ui->label_analyze_load_power_radio->setText(Util::ftos(reader->res.load_charge_radio));
    ui->label_analyze_unload_power_radio->setText(Util::ftos(reader->res.unload_charge_radio));
    ui->label_analyze_save_a->setText(Util::ftos(reader->res.first_order_energy_efficiency));
    ui->label_analyze_save_b->setText(Util::ftos(reader->res.permanent_magnet_frequency_conversion));

    time = (float)(reader->res.max_load_time)/3600.0;
    ui->label_analyze_max_loadtime->setText(Util::ftos(time));
    time = (float)(reader->res.max_unload_time)/3600.0;
    ui->label_analyze_max_unloadtime->setText(Util::ftos(time));
}


void MainWindow::on_analysis(QString path)
{
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
    if(!saveState )
    {
        if(pageIndex == 5)
        {
            file->hide();
        }
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
                 ui->comboBox_charge_type->setCurrentIndex(sysparam.charge_type);
                 ui->comboBox_env_hum->setCurrentIndex(sysparam.env_hum_type);
                 ui->comboBox_env_temp->setCurrentIndex(sysparam.env_temp_type);
                 ui->lineEdit_env_hum->setText(QString("%1").arg(sysparam.env_hum));
                 ui->lineEdit_env_temp->setText(QString("%1").arg(sysparam.env_temp));
                 ui->lineEdit_charge_peak->setText(QString("%1").arg(sysparam.charge_peak));
                 ui->lineEdit_charge_valley->setText(QString("%1").arg(sysparam.charge_valley));
                 ui->lineEdit_charge_normal->setText(QString("%1").arg(sysparam.charge_normal));
                 ui->lineEdit_fileprefix->setText(sysparam.prefix);
                 chargeform->setParam(sysparam.normal_period,sysparam.peak_period,sysparam.valley_period);
                 //ui->lineEdit_flow_modify->setText(QString("%1").arg(sysparam.flow_modify));
                 aboutwidget->setParam(QString("%1").arg(sysparam.flow_modify));
                 //Util::SysLogD("Init View %d %f",sysparam.wiring_type,sysparam.radio);
            }

            ui->widget->show();
            ui->widget_3->hide();
            ui->widget_9->show();
            ui->widget_10->hide();
            ui->widget_12->hide();
            ui->widget_2->hide();
            ui->widget_5->hide();
            ui->widget_6->hide();
            ui->widget_7->hide();
            ui->pushButton->setEnabled(false);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_5->setEnabled(true);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_17->setEnabled(true);
            ui->pushButton_24->setEnabled(true);
            ui->pushButton_24->setEnabled(true);
            pageIndex =1;
            DigitalInputPanelContext *dc = (DigitalInputPanelContext*)qApp->inputContext();
            dc->hideWidget(false);
        }
    }
}

void MainWindow::on_pushButton_2_pressed()
{

    if(pageIndex!=2){
        if(pageIndex == 1)
        {
            DigitalInputPanelContext *dc = (DigitalInputPanelContext*)qApp->inputContext();
            dc->hideWidget(true);
            chargeform->hide();
        }else if(pageIndex == 5)
        {
            file->hide();
        }
        ui->widget->hide();
        ui->widget_2->show();
        ui->widget_5->hide();
        ui->widget_6->hide();
        ui->widget_7->hide();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_5->setEnabled(true);
        pageIndex =2;
    }
}
//开始记录
void MainWindow::on_pushButton_3_pressed()
{
    if(!saveState )
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
            recorder->max_cur_standby = sysparam.current_down_max;
            recorder->max_cur_unload = sysparam.current_idle_max;
            recorder->power_charge = sysparam.charge;
            recorder->charge_type = sysparam.charge_type;
            recorder->power_charge_normal = sysparam.charge_normal;
            recorder->power_charge_peak = sysparam.charge_peak;
            recorder->power_charge_valley = sysparam.charge_valley;
            for(int i=0;i<PEROID_LENGTH;i++)
            {
                recorder->normal_period[i] = sysparam.normal_period[i];
                recorder->peak_period[i] = sysparam.peak_period[i];
                recorder->valley_period[i] = sysparam.valley_period[i];
            }

            recorder->start();
            ui->pushButton_26->setEnabled(true);
        }
    }
}

//结束记录
void MainWindow::on_pushButton_4_pressed()
{
    if(!saveState )
    {
        if(startFlag == 0)
        {
            startFlag = -1;
            ui->pushButton_3->setEnabled(true);
//            QDateTime  end_time;
//            end_time.setTime_t(dataWoker->time);
//            record_end_time = end_time.toString("yy/MM/dd hh:mm:ss");
//            recorder->title = QString(record_start_time+"----"+record_end_time+".xls");
            if(sysparam.prefix.length()!=0)
            {
                recorder->title = QString(sysparam.prefix+"__"+record_start_time+".xls");
            }else
            {
                recorder->title = QString(record_start_time+".xls");
            }
            recorder->title.replace(":","_");
            recorder->title.replace("/","-");
            recorder->recorderFlag = true;
            cusMsg->setMessage(QString("结束测量，正在保存数据"));
            cusMsg->showWithoutButton();
            saveState = true;
            ui->pushButton_26->setEnabled(false);
        }
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
            cusMsg->showWithoutButton();
            saveState = true;
        }
    }else if(cmd == 2)
    {
        cusMsg->setMessage(QString("数据保存成功"));
        cusMsg->showWithButton();
        saveState = false;
        ui->pushButton_26->setEnabled(false);
    }

}

void MainWindow::on_pushButton_5_pressed()
{
    if(!saveState )
    {
        if(pageIndex == 1)
        {
            DigitalInputPanelContext *dc = (DigitalInputPanelContext*)qApp->inputContext();
            dc->hideWidget(true);
            chargeform->hide();
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
            ui->pushButton_19->setEnabled(true);
            ui->widget_4->show();
            ui->widget_8->hide();
            ui->widget_11->hide();
            pageIndex =5;
        }
    }
}

void MainWindow::on_pushButton_6_pressed()
{
    if(!saveState )
    {
        ui->widget_2->hide();
        ui->widget_6->show();
    }
}

void MainWindow::on_pushButton_26_pressed()
{
    if(!saveState )
    {
        ui->widget_2->hide();
        ui->widget_13->show();
        ui->widget_14->show();
        ui->widget_15->hide();
        ui->pushButton_28->setEnabled(false);
        ui->pushButton_29->setEnabled(true);
    }
}

void MainWindow::on_pushButton_7_pressed()
{
    if(!saveState )
    {
        ui->widget_2->hide();
        ui->widget_7->show();

    }
}

void MainWindow::on_pushButton_8_pressed()
{

    ui->widget_6->hide();
    ui->widget_2->show();
}

void MainWindow::on_pushButton_27_pressed()
{
    ui->widget_13->hide();
    ui->widget_2->show();
}

void MainWindow::on_pushButton_28_pressed()
{
    ui->widget_14->show();
    ui->widget_15->hide();
    ui->pushButton_28->setEnabled(false);
    ui->pushButton_29->setEnabled(true);
}

void MainWindow::on_pushButton_29_pressed()
{
    ui->widget_15->show();
    ui->widget_14->hide();
    ui->pushButton_29->setEnabled(false);
    ui->pushButton_28->setEnabled(true);
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
        time_t tt = (time_t)dataWoker->time;
        stime(&tt);
    }
    QDateTime  time ;//= QDateTime::currentDateTime() ;
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
        long hour = e/3600;
        QString aa(itos(hour)+time_.toString(":mm:ss"));
        ui->label_end_time_content->setText(aa);
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
    }

    if(startFlag == 0)
    {
        AnalyzeResult anares = recorder->getAnares();

        if(anares.vsp_cnt>0)
            anares.ave_vsp = anares.ave_vsp/(float)anares.vsp_cnt;

        anares.worktime = anares.load_time + anares.unload_time;
        anares.stanby_time = anares.end_measure_time - anares.start_measure_time - anares.worktime;

        if(anares.worktime != 0)
        {
            anares.load_radio = ((float)anares.load_time)/(float)anares.worktime*100.0;
            anares.unload_radio = ((float)anares.unload_time)/(float)anares.worktime*100.0;
        }

        anares.acc_flow = anares.acc_flow/60;//m3/min
        anares.acc_power = anares.acc_power/3600;//kwh
        anares.load_power /= 3600;
        anares.unload_power /= 3600;

        if(recorder->charge_type == 1)
        {
            anares.acc_charge_normal =  anares.acc_charge_normal*recorder->power_charge_normal/3600;
            anares.acc_charge_peak =  anares.acc_charge_peak*recorder->power_charge_peak/3600;
            anares.acc_charge_valley =  anares.acc_charge_valley*recorder->power_charge_valley/3600;
            anares.acc_charge = anares.acc_charge_normal+anares.acc_charge_peak+anares.acc_charge_valley;
            anares.load_charge /= 3600;
            anares.unload_chargd /= 3600;

        }else if(recorder->charge_type == 0)
        {
            anares.acc_charge = anares.acc_power*recorder->power_charge;
            anares.load_charge = anares.load_power*recorder->power_charge;
            anares.unload_chargd = anares.unload_power*recorder->power_charge;
        }

        anares.permanent_magnet_frequency_conversion = anares.unload_power+anares.load_power*0.1;
        anares.first_order_energy_efficiency = -7.2*anares.acc_flow/60 + anares.acc_power;
        if(anares.first_order_energy_efficiency <0.00001)
        {
            anares.first_order_energy_efficiency = 0;
        }
        anares.load_charge_radio = anares.load_charge/ anares.acc_charge *100.0;
        anares.unload_charge_radio = anares.unload_chargd/ anares.acc_charge *100.0;
        anares.ave_cost = anares.acc_charge / anares.acc_flow;

        float time = (float)(anares.worktime)/3600.0;
        ui->label_analyze_work_time_2->setText(Util::ftos(time));

        time = (float)(anares.stanby_time)/3600.0;
        ui->label_analyze_standby_time_2->setText(Util::ftos(time));

        anares.acc_power = cnt++;
        ui->label_analyze_acc_power_2->setText(Util::ftos(anares.acc_power));
        ui->label_analyze_acc_flow_2->setText(Util::ftos(anares.acc_flow));
        ui->label_analyze_ave_vsp_2->setText(Util::ftos(anares.ave_vsp));
        ui->label_analyze_acc_charge_2->setText(Util::ftos(anares.acc_charge));
        ui->label_analyze_flow_cost_2->setText(Util::ftos(anares.ave_cost));

        time = (float)(anares.load_time)/3600.0;
        ui->label_analyze_loadtime_2->setText(Util::ftos(time));
        time = (float)(anares.unload_time)/3600.0;
        ui->label_analyze_unloadtime_2->setText(Util::ftos(time));

        ui->label_analyze_loadcnt_2->setText(QString::number(anares.load_cnt));
        ui->label_analyze_unloadcnt_2->setText(QString::number(anares.unload_cnt));
        ui->label_analyze_load_radio_2->setText(Util::ftos(anares.load_radio));
        ui->label_analyze_unload_radio_2->setText(Util::ftos(anares.unload_radio));
        ui->label_analyze_load_power_2->setText(Util::ftos(anares.load_power));
        ui->label_analyze_unload_power_2->setText(Util::ftos(anares.unload_power));
        ui->label_analyze_load_charge_2->setText(Util::ftos(anares.load_charge));
        ui->label_analyze_unload_charge_2->setText(Util::ftos(anares.unload_chargd));
        ui->label_analyze_load_power_radio_2->setText(Util::ftos(anares.load_charge_radio));
        ui->label_analyze_unload_power_radio_2->setText(Util::ftos(anares.unload_charge_radio));
        ui->label_analyze_save_a_2->setText(Util::ftos(anares.first_order_energy_efficiency));
        ui->label_analyze_save_b_2->setText(Util::ftos(anares.permanent_magnet_frequency_conversion));

        time = (float)(anares.max_load_time)/3600.0;
        ui->label_analyze_max_loadtime_2->setText(Util::ftos(time));
        time = (float)(anares.max_unload_time)/3600.0;
        ui->label_analyze_max_unloadtime_2->setText(Util::ftos(time));

    }

}

void MainWindow::setInfo(EnergyParam param){
    ui->label_power_content->setText(Util::ftos(recorder->acc_power/3600));
    ui->label_flow_content->setText(Util::ftos(recorder->acc_flow/60));
    ui->label_loding_rate_content->setText(Util::ftos(recorder->load_radio));
}

void MainWindow::setInfo_detail(EnergyParam param){
    ui->label_IPower_content->setText(Util::ftos(param.power));
    ui->label_IFlow_content->setText(Util::ftos(param.flow_content));
    ui->label_power_radio_content->setText(Util::ftos(param.vsp));

    ui->label_env_hum_content->setText(Util::ftos(param.env_humidity));
    ui->label_env_temp_content->setText(Util::ftos(param.env_temp));
    ui->label_air_pressure_content->setText(Util::ftos(param.air_pressure));
    ui->label_air_temp_content->setText(Util::ftos(param.air_temp));
    ui->label_flow_content_1->setText(Util::ftos(param.flow_content));

    ui->label_voltage_a_content->setText(Util::ftos(param.voltage_a));
    ui->label_voltage_b_content->setText(Util::ftos(param.voltage_b));
    ui->label_voltage_c_content->setText(Util::ftos(param.voltage_c));
    ui->label_voltage_ab_content->setText(Util::ftos(param.voltage_ab));
    ui->label_voltage_bc_content->setText(Util::ftos(param.voltage_bc));
    ui->label_voltage_ca_content->setText(Util::ftos(param.voltage_ca));

    if(sysparam.wiring_type == 0)
    {
        ui->label_linetype_content->setText("三相三线制");
    }else
    {
        ui->label_linetype_content->setText("三相四线制");
    }

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

    content = ui->lineEdit_charge_peak->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.charge_peak = content.toFloat();

    content = ui->lineEdit_charge_valley->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.charge_valley = content.toFloat();

    content = ui->lineEdit_charge_normal->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.charge_normal = content.toFloat();

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
    param.charge_type = ui->comboBox_charge_type->currentIndex();
    param.env_hum_type = ui->comboBox_env_hum->currentIndex();
    param.env_temp_type = ui->comboBox_env_temp->currentIndex();

    content = ui->lineEdit_env_temp->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.env_temp = content.toFloat();

    content = ui->lineEdit_env_hum->text();
    if(content.size() == 0){
        goto EXIT_FAIL;
    }
    param.env_hum = content.toFloat();


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

//    content = ui->lineEdit_flow_modify->text();
//    if(content.size() == 0){
//        goto EXIT_FAIL;
//    }
    content = aboutwidget->getParam();
    if(content.size() == 0){
        param.flow_modify = 0;
    }
    param.flow_modify = content.toFloat();

    param.prefix = ui->lineEdit_fileprefix->text();

    chargeform->getParam();

    for(int i=0;i<PEROID_LENGTH;i++)
    {
        if(i<chargeform->normal_len)
        {
            param.normal_period[i] = chargeform->normal_peroid[i];
        }else{
             param.normal_period[i] = -1;
        }

        if(i<chargeform->peak_len)
        {
            param.peak_period[i] = chargeform->peak_peroid[i];
        }else{
             param.peak_period[i] = -1;
        }

        if(i<chargeform->valley_len)
        {
            param.valley_period[i] = chargeform->valley_peroid[i];
        }else{
             param.valley_period[i] = -1;
        }
    }

    sysparam.setParam(param);
    sysparam.saveLocalParam();
    dataWoker->env_hum_type = sysparam.env_hum_type;
    dataWoker->env_temp_type = sysparam.env_temp_type;
    dataWoker->env_hum = sysparam.env_hum;
    dataWoker->env_temp = sysparam.env_temp;
    dataWoker->flow_modify = sysparam.flow_modify;
    Util::SysLogD("dataWoker->flow_modify %f\n",dataWoker->flow_modify);

    cusMsg->setMessage(QString("正在保存参数"));
    cusMsg->show();

    dataWoker->sendMsg(1,param.radio,1,param.wiring_type,0,0);
    return;

    EXIT_FAIL:
        cusMsg->setMessage(QString("内容不能为空"));
        cusMsg->show();
}

void MainWindow::on_setEcho(int res)
{
    if(res != 0)
    {
        cusMsg->setMessage(QString("保存失败"));
        cusMsg->show();
    }else
    {
        sysparam.saveRemoveParam();
        cusMsg->setMessage(QString("保存成功"));
        cusMsg->show();
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    qApp->exit(0);
}

void MainWindow::on_pushButton_11_pressed()
{
    ui->pushButton_13->setEnabled(true);
    ui->pushButton_19->setEnabled(true);
    ui->pushButton_11->setEnabled(false);
    ui->widget_4->show();
    ui->widget_8->hide();
    ui->widget_11->hide();
}

void MainWindow::on_pushButton_13_pressed()
{
    ui->pushButton_11->setEnabled(true);
    ui->pushButton_19->setEnabled(true);
    ui->pushButton_13->setEnabled(false);
    ui->widget_8->show();
    ui->widget_4->hide();
    ui->widget_11->hide();
}

void MainWindow::on_pushButton_19_pressed()
{
    ui->pushButton_11->setEnabled(true);
    ui->pushButton_19->setEnabled(false);
    ui->pushButton_13->setEnabled(true);
    ui->widget_8->hide();
    ui->widget_4->hide();
    ui->widget_11->show();
}

void MainWindow::on_pushButton_19_clicked()
{

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
    ui->widget_9->show();
    ui->widget_3->hide();
    ui->widget_10->hide();
    ui->widget_12->hide();
    ui->pushButton_16->setEnabled(false);
    ui->pushButton_17->setEnabled(true);
    ui->pushButton_24->setEnabled(true);
    ui->pushButton_25->setEnabled(true);
    DigitalInputPanelContext *dc = (DigitalInputPanelContext*)qApp->inputContext();
    dc->panelChange(1);
}

void MainWindow::on_pushButton_17_pressed()
{
    ui->widget_9->hide();
    ui->widget_3->hide();
    ui->widget_10->show();
    ui->widget_12->hide();
    ui->pushButton_16->setEnabled(true);
    ui->pushButton_17->setEnabled(false);
    ui->pushButton_24->setEnabled(true);
    ui->pushButton_25->setEnabled(true);
    DigitalInputPanelContext *dc = (DigitalInputPanelContext*)qApp->inputContext();
    dc->panelChange(1);
}

void MainWindow::on_pushButton_24_pressed()
{
    ui->widget_9->hide();
    ui->widget_3->hide();
    ui->widget_10->hide();
    ui->widget_12->show();
    ui->pushButton_16->setEnabled(true);
    ui->pushButton_17->setEnabled(true);
    ui->pushButton_24->setEnabled(false);
    ui->pushButton_25->setEnabled(true);
    DigitalInputPanelContext *dc = (DigitalInputPanelContext*)qApp->inputContext();
    dc->panelChange(2);
}

void MainWindow::on_pushButton_25_pressed()
{
    ui->widget_9->hide();
    ui->widget_3->show();
    ui->widget_10->hide();
    ui->widget_12->hide();
    ui->pushButton_16->setEnabled(true);
    ui->pushButton_17->setEnabled(true);
    ui->pushButton_24->setEnabled(true);
    ui->pushButton_25->setEnabled(false);
    DigitalInputPanelContext *dc = (DigitalInputPanelContext*)qApp->inputContext();
    dc->panelChange(3);
}

void MainWindow::on_pushButton_24_clicked()
{

}

void MainWindow::on_pushButton_25_clicked()
{

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

    cusMsg->setMessage("正在复制数据");
    cusMsg->showWithoutButton();
    copyer->mode = MODE_COPY;
    copyer->start();
    return;
}

void MainWindow::on_pushButton_15_clicked()
{
    system("sudo rm -rf /home/program/*.xls");
    cusMsg->setMessage(QString("删除成功！"));
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

    cusMsg->setMessage(QString("正在更新程序"));
    cusMsg->showWithoutButton();

    file_name = QString(path+"/"+file_name);
    copyer->filename = file_name;
    copyer->mode = MODE_UPDATE;
    copyer->start();
    return;
}

void MainWindow::on_pushButton_21_clicked()
{
    if(!saveState )
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
        copyer->cmd = path;
        copyer->mode = MODE_SCREENSHOT;
        copyer->start();
    }
}

void MainWindow::on_pushButton_22_clicked()
{
//    cusMsg->setMessage(QString(SOFT_VERSION));
//    cusMsg->show();
    aboutwidget->customShow();
}



void MainWindow::on_pushButton_23_clicked()
{
    chargeform->show();
}


QPalette MainWindow::colorTheme( const QColor &base ) const
{
    QPalette palette;
    palette.setColor( QPalette::Base, base );
    palette.setColor( QPalette::Window, base.dark( 150 ) );
    palette.setColor( QPalette::Mid, base.dark( 110 ) );
    palette.setColor( QPalette::Light, base.light( 170 ) );
    palette.setColor( QPalette::Dark, base.dark( 170 ) );
    palette.setColor( QPalette::Text, base.dark( 200 ).light( 800 ) );
    palette.setColor( QPalette::WindowText, base.dark( 200 ) );

    return palette;
}






