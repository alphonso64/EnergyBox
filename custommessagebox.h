#ifndef CUSTOMMESSAGEBOX_H
#define CUSTOMMESSAGEBOX_H

#include <QWidget>

namespace Ui {
class CustomMessageBox;
}

class CustomMessageBox : public QWidget
{
    Q_OBJECT
    
public:
    explicit CustomMessageBox(QWidget *parent = 0);
    ~CustomMessageBox();
    void setMessage(QString msg);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::CustomMessageBox *ui;
};

#endif // CUSTOMMESSAGEBOX_H
