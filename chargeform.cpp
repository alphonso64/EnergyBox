#include "chargeform.h"
#include "ui_chargeform.h"
#include <QString>
ChargeForm::ChargeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChargeForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint |Qt::FramelessWindowHint);

    QRegExp double_rx("([01]?[0-9]|2[0-3])");
    ui->lineEdit_normal_1->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_normal_1));
    ui->lineEdit_normal_2->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_normal_2));
    ui->lineEdit_normal_3->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_normal_3));
    ui->lineEdit_normal_4->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_normal_4));
    ui->lineEdit_normal_5->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_normal_5));
    ui->lineEdit_normal_6->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_normal_6));

    ui->lineEdit_peak_1->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_peak_1));
    ui->lineEdit_peak_2->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_peak_2));
    ui->lineEdit_peak_3->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_peak_3));
    ui->lineEdit_peak_4->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_peak_4));
    ui->lineEdit_peak_5->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_peak_5));
    ui->lineEdit_peak_6->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_peak_6));

    ui->lineEdit_valley_1->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_valley_1));
    ui->lineEdit_valley_2->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_valley_2));
    ui->lineEdit_valley_3->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_valley_3));
    ui->lineEdit_valley_4->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_valley_4));
    ui->lineEdit_valley_5->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_valley_5));
    ui->lineEdit_valley_6->setValidator(new QRegExpValidator(double_rx,ui->lineEdit_valley_6));
}

ChargeForm::~ChargeForm()
{
    delete ui;
}

void ChargeForm::setParam(int *normal,int *peak,int *valley)
{
    if(normal[0] != -1)
    {
        ui->lineEdit_normal_1->setText(QString::number(normal[0]));
    }else{
        ui->lineEdit_normal_1->setText(QString(""));
    }
    if(normal[1] != -1)
    {
        ui->lineEdit_normal_2->setText(QString::number(normal[1]));
    }else{
        ui->lineEdit_normal_2->setText(QString(""));
    }
    if(normal[2] != -1)
    {
        ui->lineEdit_normal_3->setText(QString::number(normal[2]));
    }else{
        ui->lineEdit_normal_3->setText(QString(""));
    }
    if(normal[3] != -1)
    {
        ui->lineEdit_normal_4->setText(QString::number(normal[3]));
    }else{
        ui->lineEdit_normal_4->setText(QString(""));
    }
    if(normal[4] != -1)
    {
        ui->lineEdit_normal_5->setText(QString::number(normal[4]));
    }else{
        ui->lineEdit_normal_5->setText(QString(""));
    }
    if(normal[5] != -1)
    {
        ui->lineEdit_normal_6->setText(QString::number(normal[5]));
    }else{
        ui->lineEdit_normal_6->setText(QString(""));
    }

    if(peak[0] != -1)
    {
        ui->lineEdit_peak_1->setText(QString::number(peak[0]));
    }else{
        ui->lineEdit_peak_1->setText(QString(""));
    }
    if(peak[1] != -1)
    {
        ui->lineEdit_peak_2->setText(QString::number(peak[1]));
    }else{
        ui->lineEdit_peak_2->setText(QString(""));
    }
    if(peak[2] != -1)
    {
        ui->lineEdit_peak_3->setText(QString::number(peak[2]));
    }else{
        ui->lineEdit_peak_3->setText(QString(""));
    }
    if(peak[3] != -1)
    {
        ui->lineEdit_peak_4->setText(QString::number(peak[3]));
    }else{
        ui->lineEdit_peak_4->setText(QString(""));
    }
    if(peak[4] != -1)
    {
        ui->lineEdit_peak_5->setText(QString::number(peak[4]));
    }else{
        ui->lineEdit_peak_5->setText(QString(""));
    }
    if(peak[5] != -1)
    {
        ui->lineEdit_peak_6->setText(QString::number(peak[5]));
    }else{
        ui->lineEdit_peak_6->setText(QString(""));
    }

    if(valley[0] != -1)
    {
        ui->lineEdit_valley_1->setText(QString::number(valley[0]));
    }else{
        ui->lineEdit_valley_1->setText(QString(""));
    }
    if(valley[1] != -1)
    {
        ui->lineEdit_valley_2->setText(QString::number(valley[1]));
    }else{
        ui->lineEdit_valley_2->setText(QString(""));
    }
    if(valley[2] != -1)
    {
        ui->lineEdit_valley_3->setText(QString::number(valley[2]));
    }else{
        ui->lineEdit_valley_3->setText(QString(""));
    }
    if(valley[3] != -1)
    {
        ui->lineEdit_valley_4->setText(QString::number(valley[3]));
    }else{
        ui->lineEdit_valley_4->setText(QString(""));
    }
    if(valley[4] != -1)
    {
        ui->lineEdit_valley_5->setText(QString::number(valley[4]));
    }else{
        ui->lineEdit_valley_5->setText(QString(""));
    }
    if(valley[5] != -1)
    {
        ui->lineEdit_valley_6->setText(QString::number(valley[5]));
    }else{
        ui->lineEdit_valley_6->setText(QString(""));
    }
}

void ChargeForm::getParam()
{
    QString content_a = ui->lineEdit_normal_1->text();
    QString content_b = ui->lineEdit_normal_2->text();
    int period_start,period_end;
    normal_len = 0;
    if(content_a.size() != 0 && content_b.size() != 0){
        period_start = content_a.toInt();
        period_end = content_b.toInt();
        normal_peroid[normal_len++] = period_start;
        normal_peroid[normal_len++] = period_end;
    }else{
        ui->lineEdit_normal_1->clear();
        ui->lineEdit_normal_2->clear();
    }
    content_a = ui->lineEdit_normal_3->text();
    content_b = ui->lineEdit_normal_4->text();
    if(content_a.size() != 0 && content_b.size() != 0){
        period_start = content_a.toInt();
        period_end = content_b.toInt();
        normal_peroid[normal_len++] = period_start;
        normal_peroid[normal_len++] = period_end;
    }else{
        ui->lineEdit_normal_3->clear();
        ui->lineEdit_normal_4->clear();
    }
    content_a = ui->lineEdit_normal_5->text();
    content_b = ui->lineEdit_normal_6->text();
    if(content_a.size() != 0 && content_b.size() != 0){
        period_start = content_a.toInt();
        period_end = content_b.toInt();
        normal_peroid[normal_len++] = period_start;
        normal_peroid[normal_len++] = period_end;
    }else{
            ui->lineEdit_normal_5->clear();
            ui->lineEdit_normal_6->clear();
    }

    peak_len = 0;
    content_a = ui->lineEdit_peak_1->text();
    content_b = ui->lineEdit_peak_2->text();
    if(content_a.size() != 0 && content_b.size() != 0){
        period_start = content_a.toInt();
        period_end = content_b.toInt();
        peak_peroid[peak_len++] = period_start;
        peak_peroid[peak_len++] = period_end;
    }else{
        ui->lineEdit_peak_1->clear();
        ui->lineEdit_peak_2->clear();
    }
    content_a = ui->lineEdit_peak_3->text();
    content_b = ui->lineEdit_peak_4->text();
    if(content_a.size() != 0 && content_b.size() != 0){
        period_start = content_a.toInt();
        period_end = content_b.toInt();
        peak_peroid[peak_len++] = period_start;
        peak_peroid[peak_len++] = period_end;
    }else{
        ui->lineEdit_peak_3->clear();
        ui->lineEdit_peak_4->clear();
    }

    content_a = ui->lineEdit_peak_5->text();
    content_b = ui->lineEdit_peak_6->text();
    if(content_a.size() != 0 && content_b.size() != 0){
        period_start = content_a.toInt();
        period_end = content_b.toInt();
        peak_peroid[peak_len++] = period_start;
        peak_peroid[peak_len++] = period_end;
    }else{
        ui->lineEdit_peak_5->clear();
        ui->lineEdit_peak_6->clear();
    }

    valley_len = 0;
    content_a = ui->lineEdit_valley_1->text();
    content_b = ui->lineEdit_valley_2->text();
    if(content_a.size() != 0 && content_b.size() != 0){
        period_start = content_a.toInt();
        period_end = content_b.toInt();
        valley_peroid[valley_len++] = period_start;
        valley_peroid[valley_len++] = period_end;
    }else{
        ui->lineEdit_valley_1->clear();
        ui->lineEdit_valley_2->clear();
    }

    content_a = ui->lineEdit_valley_3->text();
    content_b = ui->lineEdit_valley_4->text();
    if(content_a.size() != 0 && content_b.size() != 0){
        period_start = content_a.toInt();
        period_end = content_b.toInt();
        valley_peroid[valley_len++] = period_start;
        valley_peroid[valley_len++] = period_end;
    }else{
        ui->lineEdit_valley_3->clear();
        ui->lineEdit_valley_4->clear();
    }


    content_a = ui->lineEdit_valley_5->text();
    content_b = ui->lineEdit_valley_6->text();
    if(content_a.size() != 0 && content_b.size() != 0){
        period_start = content_a.toInt();
        period_end = content_b.toInt();
        valley_peroid[valley_len++] = period_start;
        valley_peroid[valley_len++] = period_end;
    }else{
        ui->lineEdit_valley_5->clear();
        ui->lineEdit_valley_6->clear();
    }

}

void ChargeForm::on_pushButton_2_clicked()
{
    this->hide();
    return;
}
