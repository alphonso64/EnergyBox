#include "custommessagebox.h"
#include "ui_custommessagebox.h"

CustomMessageBox::CustomMessageBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomMessageBox)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint |Qt::X11BypassWindowManagerHint);
    ui->label->setAlignment(Qt::AlignCenter);
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
}

void CustomMessageBox::showWithoutButton()
{
    this->show();
    ui->pushButton->setVisible(false);
}


void CustomMessageBox::showWithButton()
{
    this->show();
    ui->pushButton->setVisible(true);
}

