#include "mainwindow.h"
#include "ui_mainwindow.h"

int cnt = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("color:#ffffff;");
    ui->label_2->setPixmap(QPixmap("C:/Qt/qtcreator-2.5.0/test_a/logo_small.png"));
   // QString *style = new QString("QPushButton{background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:pressed{background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(178, 223, 219, 255), stop:0.5 rgba(224, 242, 241, 255)); border-radius:5px;border: 1px solid #5F92B2;}");
   QString *style = new QString("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(38, 166, 154, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #24a69a;} QPushButton:pressed{background-color: rgba(38, 166, 154, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #24a69a;}");
   QString *style_a = new QString("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(255, 152, 0, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #ff9800;} QPushButton:pressed{background-color: rgba(255, 152, 0, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #ff9800;}");

   ui->pushButton->setStyleSheet(*style);
   ui->pushButton_2->setStyleSheet(*style);
   ui->pushButton_3->setStyleSheet(*style_a);
   ui->pushButton_4->setStyleSheet(*style_a);
   ui->pushButton_5->setStyleSheet(*style);
   ui->pushButton_6->setStyleSheet(*style);
   ui->pushButton_7->setStyleSheet(*style);
   ui->pushButton_8->setStyleSheet(*style);
   ui->pushButton_9->setStyleSheet(*style);
   ui->pushButton->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_2->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_3->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_4->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_5->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_6->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_7->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_8->setFocusPolicy ( Qt::NoFocus );
   ui->pushButton_9->setFocusPolicy ( Qt::NoFocus );


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

   startFlag = -1;
    //ui->pushButton->setStyleSheet("QPushButton{background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton#pushButton:pressed{background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255)); border-radius:5px;border: 1px solid #5F92B2;}");
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
    }

}

void MainWindow::on_pushButton_2_pressed()
{
    if(pageIndex!=2){
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

void MainWindow::on_pushButton_3_pressed()
{
/*    if(pageIndex!=3){
        ui->widget->hide();
        ui->widget_2->hide();
        ui->widget_3->show();
        ui->widget_4->hide();
        ui->widget_5->hide();
        ui->widget_6->hide();
        ui->widget_7->hide();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        pageIndex =3;
    }*/
    if(startFlag != 0){
        startFlag = 0;
        ui->pushButton_3->setEnabled(false);

        QTime  time =QTime::currentTime();
        QString string_a = time.toString("hh:mm:ss");
        ui->label_start_time_content->setText(string_a);
        ui->label_end_time_content->clear();
    }

}

void MainWindow::on_pushButton_4_pressed()
{
/*    if(pageIndex!=4){
        ui->widget->hide();
        ui->widget_2->hide();
        ui->widget_3->hide();
        ui->widget_4->show();
        ui->widget_5->hide();
        ui->widget_6->hide();
        ui->widget_7->hide();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(true);
        pageIndex =4;
    }*/
    if(startFlag == 0){
        startFlag = -1;
        ui->pushButton_3->setEnabled(true);

        QTime  time =QTime::currentTime();
        QString string_a = time.toString("hh:mm:ss");
        ui->label_end_time_content->setText(string_a);

    }
}

void MainWindow::on_pushButton_5_pressed()
{
    if(pageIndex!=5){
        ui->widget->hide();
        ui->widget_2->hide();
        ui->widget_5->show();
        ui->widget_6->hide();
        ui->widget_7->hide();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_5->setEnabled(false);
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
    QTime  time =QTime::currentTime();
    QString string_a = time.toString("hh:mm:ss");
    ui->lcdNumber_clock->display(string_a);
    cnt++;
    if(startFlag == 0){
        setInfo();
    }
    setInfo_detail();

}

void MainWindow::setInfo(){
    int temp = cnt;
    ui->label_IPower_content->setText(itos(temp++));
    ui->label_IFlow_content->setText(itos(temp++));
    ui->label_power_content->setText(itos(temp++));
    ui->label_flow_content->setText(itos(temp++));
    ui->label_loding_rate_content->setText(itos(temp++));
    ui->label_power_radio_content->setText(itos(temp++));
    ui->label_power_save_a_content->setText(itos(temp++));
    ui->label_power_save_b_content->setText(itos(temp++));
    ui->label_power_saverate_a_content->setText(itos(temp++));
    ui->label_power_saverate_b_content->setText(itos(temp++));
}

void MainWindow::setInfo_detail(){
    int temp = cnt;
    ui->label_env_humidity_content->setText(itos(temp++));
    ui->label_env_temp_content->setText(itos(temp++));
    ui->label_air_pressure_content->setText(itos(temp++));
    ui->label_air_temp_content->setText(itos(temp++));
    ui->label_flow_content_1->setText(itos(temp++));

    ui->label_voltage_a_content->setText(itos(temp++));
    ui->label_voltage_b_content->setText(itos(temp++));
    ui->label_voltage_c_content->setText(itos(temp++));

    ui->label_current_a_content->setText(itos(temp++));
    ui->label_current_b_content->setText(itos(temp++));
    ui->label_current_c_content->setText(itos(temp++));

    ui->label_active_power_content->setText(itos(temp++));
    ui->label_reactive_power_content->setText(itos(temp++));
    ui->label_power_factor_content->setText(itos(temp++));
    ui->label_frequency_content->setText(itos(temp++));
    ui->label_apparent_power_content->setText(itos(temp++));
}

QString MainWindow::itos(int val){
    stringstream ss;
    ss<<val;
    QString string_a(ss.str().c_str());
    return string_a;
}
