#include "filewidget.h"
#include "ui_filewidget.h"
#include <QStringListModel>
#include "util.h"
#include <stdio.h>
#include <QModelIndexList>
#include <QDebug>
#include "const_define.h"
FileWidget::FileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint |Qt::X11BypassWindowManagerHint);
    QStringListModel *model = new QStringListModel(this);
    ui->listView->setModel(model);
    QString *style = new QString("QPushButton{background-color: rgba(236, 236, 236, 255);  border: 1px solid rgb(124, 124, 124); border-radius:5px;} QPushButton:disabled{background-color: rgba(38, 166, 154, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #24a69a;} QPushButton:pressed{background-color: rgba(38, 166, 154, 255);color: rgba(0, 0, 0, 255); border-radius:5px;border: 1px solid #24a69a;}");

    ui->pushButton->setStyleSheet(*style);
    ui->pushButton_2->setStyleSheet(*style);

    ui->pushButton->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_2->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_3->setFocusPolicy ( Qt::NoFocus );
    ui->pushButton_4->setFocusPolicy ( Qt::NoFocus );
}

FileWidget::~FileWidget()
{
    delete ui;
}

void FileWidget::on_pushButton_3_pressed()
{

}

void FileWidget::on_pushButton_pressed()
{
    setLocalView();
}

void FileWidget::on_pushButton_2_pressed()
{
    setUDiskView();
}

void FileWidget::setLocalView()
{
    QStringListModel *model =(QStringListModel *)  ui->listView->model();
    model ->removeRows( 0, model->rowCount() );
    model->setStringList( Util::getLocalFileList());
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    isLocal= true;
}

void FileWidget::setUDiskView()
{
    QStringListModel *model =(QStringListModel *)  ui->listView->model();
    model ->removeRows( 0, model->rowCount() );
    model->setStringList( Util::getUdiskFileList());
    ui->pushButton_2->setEnabled(false);
    ui->pushButton->setEnabled(true);
    isLocal= false;
}

void FileWidget::on_pushButton_4_pressed()
{

}

void FileWidget::on_pushButton_3_clicked()
{
    QModelIndexList list =ui->listView->selectionModel()->selectedIndexes();
    if(list.size()>0)
    {
        qDebug() << list.at(0).data(Qt::DisplayRole ).toString();
        if(isLocal)
        {
            QString path(LOCAL_PATH_PREFIX+list.at(0).data(Qt::DisplayRole ).toString());
            filename = QString(list.at(0).data(Qt::DisplayRole ).toString());
            emit fileopen(path);
        }
        else
        {

            QString path(UDISK_PATH_PREFIX+Util::checkUDiskPath()+"/"+list.at(0).data(Qt::DisplayRole ).toString());
            filename = QString(list.at(0).data(Qt::DisplayRole ).toString());
            emit fileopen(path);
        }
        this->hide();
    }
}


void FileWidget::on_pushButton_4_clicked()
{
    this->hide();
}
