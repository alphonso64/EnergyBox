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
int cnt = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("color:#ffffff;");
    ui->label_2->setPixmap(QPixmap("./logo_small.png"));
   // QString *style = new QString("QPushButton{background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:pressed{background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(178, 223, 219, 255), stop:0.5 rgba(224, 242, 241, 255)); border-radius:5px;border: 1px solid #5F92B2;}");
   QString *style = new QString("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(38, 166, 154, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #24a69a;} QPushButton:pressed{background-color: rgba(38, 166, 154, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #24a69a;}");
   QString *style_a = new QString("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(255, 152, 0, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #ff9800;} QPushButton:pressed{background-color: rgba(255, 152, 0, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #ff9800;}");
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
   ui->widget->hide();
   ui->widget_2->show();
   ui->widget_5->hide();
   ui->widget_6->hide();
   ui->widget_7->hide();

   ui->pushButton_2->setEnabled(false);

   pageIndex = 2;

   timer = new QTimer( this );
   timer->start(500);
   connect ( timer , SIGNAL (timeout ()), this , SLOT (show_time()));

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

   if(sysparam.loadParam())
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
   }

   startFlag = -1;

   recorder = new RecordWorkThread(this);
   dataWoker = new DataWorkerThread(this);
   recorder->dataWoker = dataWoker;
   dataWoker->start();

   flowDial = new CommonDial( ui->widget_2 );
   flowDial->setScaleStepSize( 60.0 );
   flowDial->setScale( 0.0, 300.0 );
   flowDial->scaleDraw()->setPenWidth( 2 );
   flowDial->move(180,0);

   powerDial = new CommonDial( ui->widget_2 );
   powerDial->setScaleStepSize( 20.0 );
   powerDial->setScale( 0.0, 120.0 );
   powerDial->scaleDraw()->setPenWidth( 2 );
   powerDial->move(620,0);

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
  }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_pressed()
{
    if(pageIndex!=1){
        ui->widget->show();
        ui->widget_2->hide();
        ui->widget_5->hide();
        ui->widget_6->hide();
        ui->widget_7->hide();
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
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
        path_pre = QString("/media/pi/"+path_pre+"/");
    }
    else
    {
        path_pre = "./";
    }
    recorder->path_pre = path_pre.toStdString();
    if(startFlag != 0){
        startFlag = 0;
        ui->pushButton_3->setEnabled(false);

        startTime =QDateTime::currentDateTime();
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
        QDateTime  end_time =QDateTime::currentDateTime();
        record_end_time = end_time.toString("yy/MM/dd hh:mm:ss");
        recorder->title = QString(record_start_time+"_______"+record_end_time+".xls");
        recorder->title.replace(":","-");
        recorder->title.replace("/","-");
        recorder->recorderFlag = true;
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
    QDateTime  time =QDateTime::currentDateTime();
    QString string_a = time.toString("yyyy/MM/dd hh:mm:ss");
    ui->lcdNumber_clock->display(string_a);
    cnt++;
    EnergyParam param = dataWoker->getEnergyParam();
    if(startFlag == 0){
        setInfo(param);
    }
    setInfo_detail(param);

    flowDial->setValue( param.flow_content );


    if(startFlag == 0 )
    {
        uint c = 0, d =0,e =0 ;
        c = (uint)time.toTime_t();
        d = (uint)startTime.toTime_t();
        e = c - d;
        QDateTime time_;
        time_.setTime_t(e);
        ui->label_end_time_content->setText(time_.toString("hh:mm:ss"));
    }


}

void MainWindow::setInfo(EnergyParam param){
    ui->label_power_content->setText(Util::ftos(recorder->acc_power));
    ui->label_flow_content->setText(Util::ftos(recorder->acc_flow));
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
