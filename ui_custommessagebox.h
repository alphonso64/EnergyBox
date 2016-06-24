/********************************************************************************
** Form generated from reading UI file 'custommessagebox.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMMESSAGEBOX_H
#define UI_CUSTOMMESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomMessageBox
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QWidget *CustomMessageBox)
    {
        if (CustomMessageBox->objectName().isEmpty())
            CustomMessageBox->setObjectName(QString::fromUtf8("CustomMessageBox"));
        CustomMessageBox->resize(472, 235);
        label = new QLabel(CustomMessageBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 441, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(26);
        label->setFont(font);
        pushButton = new QPushButton(CustomMessageBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(319, 170, 141, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        pushButton->setFont(font1);
        label_2 = new QLabel(CustomMessageBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 471, 81));
        label_2->setFont(font);

        retranslateUi(CustomMessageBox);

        QMetaObject::connectSlotsByName(CustomMessageBox);
    } // setupUi

    void retranslateUi(QWidget *CustomMessageBox)
    {
        CustomMessageBox->setWindowTitle(QApplication::translate("CustomMessageBox", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton->setText(QApplication::translate("CustomMessageBox", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CustomMessageBox: public Ui_CustomMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMMESSAGEBOX_H
