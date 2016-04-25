/********************************************************************************
** Form generated from reading UI file 'chargeform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGEFORM_H
#define UI_CHARGEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChargeForm
{
public:
    QLineEdit *lineEdit_normal_1;
    QLineEdit *lineEdit_normal_2;
    QLineEdit *lineEdit_normal_3;
    QLineEdit *lineEdit_normal_4;
    QLineEdit *lineEdit_normal_5;
    QLineEdit *lineEdit_normal_6;
    QLineEdit *lineEdit_peak_3;
    QLineEdit *lineEdit_peak_1;
    QLineEdit *lineEdit_peak_6;
    QLineEdit *lineEdit_peak_5;
    QLineEdit *lineEdit_peak_2;
    QLineEdit *lineEdit_peak_4;
    QLineEdit *lineEdit_valley_3;
    QLineEdit *lineEdit_valley_1;
    QLineEdit *lineEdit_valley_6;
    QLineEdit *lineEdit_valley_5;
    QLineEdit *lineEdit_valley_2;
    QLineEdit *lineEdit_valley_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QLabel *label_7;

    void setupUi(QWidget *ChargeForm)
    {
        if (ChargeForm->objectName().isEmpty())
            ChargeForm->setObjectName(QString::fromUtf8("ChargeForm"));
        ChargeForm->resize(800, 381);
        lineEdit_normal_1 = new QLineEdit(ChargeForm);
        lineEdit_normal_1->setObjectName(QString::fromUtf8("lineEdit_normal_1"));
        lineEdit_normal_1->setGeometry(QRect(110, 90, 71, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        lineEdit_normal_1->setFont(font);
        lineEdit_normal_2 = new QLineEdit(ChargeForm);
        lineEdit_normal_2->setObjectName(QString::fromUtf8("lineEdit_normal_2"));
        lineEdit_normal_2->setGeometry(QRect(200, 90, 71, 41));
        lineEdit_normal_2->setFont(font);
        lineEdit_normal_3 = new QLineEdit(ChargeForm);
        lineEdit_normal_3->setObjectName(QString::fromUtf8("lineEdit_normal_3"));
        lineEdit_normal_3->setGeometry(QRect(340, 90, 71, 41));
        lineEdit_normal_3->setFont(font);
        lineEdit_normal_4 = new QLineEdit(ChargeForm);
        lineEdit_normal_4->setObjectName(QString::fromUtf8("lineEdit_normal_4"));
        lineEdit_normal_4->setGeometry(QRect(430, 90, 71, 41));
        lineEdit_normal_4->setFont(font);
        lineEdit_normal_5 = new QLineEdit(ChargeForm);
        lineEdit_normal_5->setObjectName(QString::fromUtf8("lineEdit_normal_5"));
        lineEdit_normal_5->setGeometry(QRect(580, 90, 71, 41));
        lineEdit_normal_5->setFont(font);
        lineEdit_normal_6 = new QLineEdit(ChargeForm);
        lineEdit_normal_6->setObjectName(QString::fromUtf8("lineEdit_normal_6"));
        lineEdit_normal_6->setGeometry(QRect(670, 90, 71, 41));
        lineEdit_normal_6->setFont(font);
        lineEdit_peak_3 = new QLineEdit(ChargeForm);
        lineEdit_peak_3->setObjectName(QString::fromUtf8("lineEdit_peak_3"));
        lineEdit_peak_3->setGeometry(QRect(340, 160, 71, 41));
        lineEdit_peak_3->setFont(font);
        lineEdit_peak_1 = new QLineEdit(ChargeForm);
        lineEdit_peak_1->setObjectName(QString::fromUtf8("lineEdit_peak_1"));
        lineEdit_peak_1->setGeometry(QRect(110, 160, 71, 41));
        lineEdit_peak_1->setFont(font);
        lineEdit_peak_6 = new QLineEdit(ChargeForm);
        lineEdit_peak_6->setObjectName(QString::fromUtf8("lineEdit_peak_6"));
        lineEdit_peak_6->setGeometry(QRect(670, 160, 71, 41));
        lineEdit_peak_6->setFont(font);
        lineEdit_peak_5 = new QLineEdit(ChargeForm);
        lineEdit_peak_5->setObjectName(QString::fromUtf8("lineEdit_peak_5"));
        lineEdit_peak_5->setGeometry(QRect(580, 160, 71, 41));
        lineEdit_peak_5->setFont(font);
        lineEdit_peak_2 = new QLineEdit(ChargeForm);
        lineEdit_peak_2->setObjectName(QString::fromUtf8("lineEdit_peak_2"));
        lineEdit_peak_2->setGeometry(QRect(200, 160, 71, 41));
        lineEdit_peak_2->setFont(font);
        lineEdit_peak_4 = new QLineEdit(ChargeForm);
        lineEdit_peak_4->setObjectName(QString::fromUtf8("lineEdit_peak_4"));
        lineEdit_peak_4->setGeometry(QRect(430, 160, 71, 41));
        lineEdit_peak_4->setFont(font);
        lineEdit_valley_3 = new QLineEdit(ChargeForm);
        lineEdit_valley_3->setObjectName(QString::fromUtf8("lineEdit_valley_3"));
        lineEdit_valley_3->setGeometry(QRect(340, 230, 71, 41));
        lineEdit_valley_3->setFont(font);
        lineEdit_valley_1 = new QLineEdit(ChargeForm);
        lineEdit_valley_1->setObjectName(QString::fromUtf8("lineEdit_valley_1"));
        lineEdit_valley_1->setGeometry(QRect(110, 230, 71, 41));
        lineEdit_valley_1->setFont(font);
        lineEdit_valley_6 = new QLineEdit(ChargeForm);
        lineEdit_valley_6->setObjectName(QString::fromUtf8("lineEdit_valley_6"));
        lineEdit_valley_6->setGeometry(QRect(670, 230, 71, 41));
        lineEdit_valley_6->setFont(font);
        lineEdit_valley_5 = new QLineEdit(ChargeForm);
        lineEdit_valley_5->setObjectName(QString::fromUtf8("lineEdit_valley_5"));
        lineEdit_valley_5->setGeometry(QRect(580, 230, 71, 41));
        lineEdit_valley_5->setFont(font);
        lineEdit_valley_2 = new QLineEdit(ChargeForm);
        lineEdit_valley_2->setObjectName(QString::fromUtf8("lineEdit_valley_2"));
        lineEdit_valley_2->setGeometry(QRect(200, 230, 71, 41));
        lineEdit_valley_2->setFont(font);
        lineEdit_valley_4 = new QLineEdit(ChargeForm);
        lineEdit_valley_4->setObjectName(QString::fromUtf8("lineEdit_valley_4"));
        lineEdit_valley_4->setGeometry(QRect(430, 230, 71, 41));
        lineEdit_valley_4->setFont(font);
        label = new QLabel(ChargeForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 80, 71, 51));
        label->setFont(font);
        label_2 = new QLabel(ChargeForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 150, 71, 51));
        label_2->setFont(font);
        label_3 = new QLabel(ChargeForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 220, 71, 51));
        label_3->setFont(font);
        label_4 = new QLabel(ChargeForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 10, 91, 51));
        label_4->setFont(font);
        label_5 = new QLabel(ChargeForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(370, 10, 91, 51));
        label_5->setFont(font);
        label_6 = new QLabel(ChargeForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(615, 10, 91, 51));
        label_6->setFont(font);
        pushButton_2 = new QPushButton(ChargeForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 310, 141, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        pushButton_2->setFont(font1);
        label_7 = new QLabel(ChargeForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 330, 451, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        label_7->setFont(font2);

        retranslateUi(ChargeForm);

        QMetaObject::connectSlotsByName(ChargeForm);
    } // setupUi

    void retranslateUi(QWidget *ChargeForm)
    {
        ChargeForm->setWindowTitle(QApplication::translate("ChargeForm", "Form", 0, QApplication::UnicodeUTF8));
        lineEdit_normal_1->setText(QString());
        lineEdit_normal_2->setText(QString());
        lineEdit_normal_3->setText(QString());
        lineEdit_normal_4->setText(QString());
        lineEdit_normal_5->setText(QString());
        lineEdit_normal_6->setText(QString());
        lineEdit_peak_3->setText(QString());
        lineEdit_peak_1->setText(QString());
        lineEdit_peak_6->setText(QString());
        lineEdit_peak_5->setText(QString());
        lineEdit_peak_2->setText(QString());
        lineEdit_peak_4->setText(QString());
        lineEdit_valley_3->setText(QString());
        lineEdit_valley_1->setText(QString());
        lineEdit_valley_6->setText(QString());
        lineEdit_valley_5->setText(QString());
        lineEdit_valley_2->setText(QString());
        lineEdit_valley_4->setText(QString());
        label->setText(QApplication::translate("ChargeForm", "\345\271\263\346\227\266", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChargeForm", "\345\263\260\346\227\266", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ChargeForm", "\350\260\267\346\227\266", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ChargeForm", "\357\274\210\344\270\200\357\274\211", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ChargeForm", "\357\274\210\344\272\214\357\274\211", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ChargeForm", "\357\274\210\344\270\211\357\274\211", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ChargeForm", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ChargeForm", "\346\227\266\346\256\265\350\256\276\347\275\256\344\270\27224\345\260\217\346\227\266\345\210\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChargeForm: public Ui_ChargeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGEFORM_H
