#ifndef CHARGEFORM_H
#define CHARGEFORM_H

#include <QWidget>
#include "const_define.h"

namespace Ui {
class ChargeForm;
}

class ChargeForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit ChargeForm(QWidget *parent = 0);
    ~ChargeForm();

signals:
    void periodset(int flag);
    
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::ChargeForm *ui;
public:
    int normal_peroid[PEROID_LENGTH];
    int normal_len;
    int peak_peroid[PEROID_LENGTH];
    int peak_len;
    int valley_peroid[PEROID_LENGTH];
    int valley_len;

    void getParam();
    void setParam(int *normal,int *peak,int *valley);
};

#endif // CHARGEFORM_H
