#include "custommessagebox.h"
#include "ui_custommessagebox.h"

CustomMessageBox::CustomMessageBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomMessageBox)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint |Qt::X11BypassWindowManagerHint);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->pushButton_2->setVisible(false);
    flag = NORMAL_CHECKED;
}

CustomMessageBox::~CustomMessageBox()
{
    delete ui;
}

void CustomMessageBox::setMessage(QString msg)
{
    ui->label->setText(msg);
}



void CustomMessageBox::on_pushButton_clicked()
{
    this->hide();
    if(flag != NORMAL_CHECKED)
    {
        emit cusMsgBoxReturn(flag);
        flag = NORMAL_CHECKED;
        ui->pushButton_2->setVisible(false);
    }
}

void CustomMessageBox::showWithoutButton()
{
    this->show();
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
}


void CustomMessageBox::showWithButton()
{
    this->show();
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(false);
}

void CustomMessageBox::showWithALLButton()
{
    this->show();
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(true);
}

void CustomMessageBox::on_pushButton_2_clicked()
{
    this->hide();
    flag = NORMAL_CHECKED;
    ui->pushButton_2->setVisible(false);
}
