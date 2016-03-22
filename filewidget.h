#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QWidget>

namespace Ui {
class FileWidget;
}

class FileWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit FileWidget(QWidget *parent = 0);
    ~FileWidget();
    void setLocalView();
    void setUDiskView();
    
private slots:
    void on_pushButton_3_pressed();

    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_4_pressed();

private:
    Ui::FileWidget *ui;
    QString filePath;
};

#endif // FILEWIDGET_H
