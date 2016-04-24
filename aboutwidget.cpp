#include "aboutwidget.h"
#include "ui_aboutwidget.h"
#include "const_define.h"

AboutWidget::AboutWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint |Qt::FramelessWindowHint);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setText(SOFT_VERSION);

    QRegExp double_rx("([0-9]{0,1}[\.][0-9]{1,3})");
    ui->lineEdit->setValidator(new QRegExpValidator(double_rx,ui->lineEdit));
}


AboutWidget::~AboutWidget()
{
    delete ui;
}

void AboutWidget::customShow()
{
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(true);
    this->show();
}

QString AboutWidget::getParam()
{
    return ui->lineEdit->text();
}

void AboutWidget::setParam(QString str)
{
     ui->lineEdit->setText(str);
}

void AboutWidget::on_pushButton_3_clicked()
{
    this->hide();
}

void AboutWidget::on_pushButton_clicked()
{
    ui->label->setVisible(false);
    ui->label_2->setVisible(true);
    ui->lineEdit->setVisible(false);
    ui->pushButton_3->setVisible(true);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
}

void AboutWidget::on_pushButton_2_clicked()
{
    ui->label->setVisible(true);
    ui->label_2->setVisible(false);
    ui->lineEdit->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
}
