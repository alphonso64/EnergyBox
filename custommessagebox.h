#ifndef CUSTOMMESSAGEBOX_H
#define CUSTOMMESSAGEBOX_H

#include <QWidget>

#define RMFILE_CHECKED 1
#define UPDATE_CHECKED 2
#define NORMAL_CHECKED 3
#define EXPORT_CHECKED 0

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
    void showWithoutButton();
    void showWithALLButton();
    void showWithButton();
    int flag;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void cusMsgBoxReturn(int);

private:
    Ui::CustomMessageBox *ui;
};

#endif // CUSTOMMESSAGEBOX_H
