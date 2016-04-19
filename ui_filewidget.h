/********************************************************************************
** Form generated from reading UI file 'filewidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEWIDGET_H
#define UI_FILEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileWidget
{
public:
    QListView *listView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *FileWidget)
    {
        if (FileWidget->objectName().isEmpty())
            FileWidget->setObjectName(QString::fromUtf8("FileWidget"));
        FileWidget->resize(906, 500);
        listView = new QListView(FileWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 60, 741, 431));
        QFont font;
        font.setPointSize(22);
        listView->setFont(font);
        pushButton = new QPushButton(FileWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(770, 80, 131, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(FileWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(770, 180, 131, 71));
        pushButton_2->setFont(font1);
        label = new QLabel(FileWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 271, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(24);
        label->setFont(font2);
        pushButton_3 = new QPushButton(FileWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(770, 340, 131, 71));
        pushButton_3->setFont(font1);
        pushButton_4 = new QPushButton(FileWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(770, 420, 131, 71));
        pushButton_4->setFont(font1);

        retranslateUi(FileWidget);

        QMetaObject::connectSlotsByName(FileWidget);
    } // setupUi

    void retranslateUi(QWidget *FileWidget)
    {
        FileWidget->setWindowTitle(QApplication::translate("FileWidget", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("FileWidget", "\346\234\254\345\234\260", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("FileWidget", "U\347\233\230", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FileWidget", "\351\200\211\346\213\251\350\246\201\345\210\206\346\236\220\347\232\204\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("FileWidget", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("FileWidget", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FileWidget: public Ui_FileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEWIDGET_H
