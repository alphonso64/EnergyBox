/********************************************************************************
** Form generated from reading UI file 'digitalinputpanel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGITALINPUTPANEL_H
#define UI_DIGITALINPUTPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DigitalInputPanel
{
public:
    QPushButton *closeButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *panelButton_1;
    QPushButton *panelButton_2;
    QPushButton *panelButton_3;
    QPushButton *panelButton_4;
    QPushButton *panelButton_5;
    QPushButton *panelButton_6;
    QPushButton *panelButton_7;
    QPushButton *panelButton_8;
    QPushButton *panelButton_9;
    QPushButton *panelButton_0;
    QPushButton *panelButton_star;
    QPushButton *panelButton_minus;
    QPushButton *panelButton_hash;

    void setupUi(QWidget *DigitalInputPanel)
    {
        if (DigitalInputPanel->objectName().isEmpty())
            DigitalInputPanel->setObjectName(QString::fromUtf8("DigitalInputPanel"));
        DigitalInputPanel->resize(831, 91);
        closeButton = new QPushButton(DigitalInputPanel);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(100, 220, 75, 23));
        QFont font;
        font.setPointSize(8);
        closeButton->setFont(font);
        closeButton->setFocusPolicy(Qt::NoFocus);
        horizontalLayoutWidget = new QWidget(DigitalInputPanel);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 10, 831, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        panelButton_1 = new QPushButton(horizontalLayoutWidget);
        panelButton_1->setObjectName(QString::fromUtf8("panelButton_1"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(panelButton_1->sizePolicy().hasHeightForWidth());
        panelButton_1->setSizePolicy(sizePolicy);
        panelButton_1->setMinimumSize(QSize(45, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        panelButton_1->setFont(font1);
        panelButton_1->setFocusPolicy(Qt::NoFocus);
        panelButton_1->setProperty("buttonValue", QVariant(QChar(49)));

        horizontalLayout->addWidget(panelButton_1);

        panelButton_2 = new QPushButton(horizontalLayoutWidget);
        panelButton_2->setObjectName(QString::fromUtf8("panelButton_2"));
        sizePolicy.setHeightForWidth(panelButton_2->sizePolicy().hasHeightForWidth());
        panelButton_2->setSizePolicy(sizePolicy);
        panelButton_2->setMinimumSize(QSize(45, 40));
        panelButton_2->setFont(font1);
        panelButton_2->setFocusPolicy(Qt::NoFocus);
        panelButton_2->setProperty("buttonValue", QVariant(QChar(50)));

        horizontalLayout->addWidget(panelButton_2);

        panelButton_3 = new QPushButton(horizontalLayoutWidget);
        panelButton_3->setObjectName(QString::fromUtf8("panelButton_3"));
        sizePolicy.setHeightForWidth(panelButton_3->sizePolicy().hasHeightForWidth());
        panelButton_3->setSizePolicy(sizePolicy);
        panelButton_3->setMinimumSize(QSize(45, 40));
        panelButton_3->setFont(font1);
        panelButton_3->setFocusPolicy(Qt::NoFocus);
        panelButton_3->setProperty("buttonValue", QVariant(QChar(51)));

        horizontalLayout->addWidget(panelButton_3);

        panelButton_4 = new QPushButton(horizontalLayoutWidget);
        panelButton_4->setObjectName(QString::fromUtf8("panelButton_4"));
        sizePolicy.setHeightForWidth(panelButton_4->sizePolicy().hasHeightForWidth());
        panelButton_4->setSizePolicy(sizePolicy);
        panelButton_4->setMinimumSize(QSize(45, 40));
        panelButton_4->setFont(font1);
        panelButton_4->setFocusPolicy(Qt::NoFocus);
        panelButton_4->setProperty("buttonValue", QVariant(QChar(52)));

        horizontalLayout->addWidget(panelButton_4);

        panelButton_5 = new QPushButton(horizontalLayoutWidget);
        panelButton_5->setObjectName(QString::fromUtf8("panelButton_5"));
        sizePolicy.setHeightForWidth(panelButton_5->sizePolicy().hasHeightForWidth());
        panelButton_5->setSizePolicy(sizePolicy);
        panelButton_5->setMinimumSize(QSize(45, 40));
        panelButton_5->setFont(font1);
        panelButton_5->setFocusPolicy(Qt::NoFocus);
        panelButton_5->setProperty("buttonValue", QVariant(QChar(53)));

        horizontalLayout->addWidget(panelButton_5);

        panelButton_6 = new QPushButton(horizontalLayoutWidget);
        panelButton_6->setObjectName(QString::fromUtf8("panelButton_6"));
        sizePolicy.setHeightForWidth(panelButton_6->sizePolicy().hasHeightForWidth());
        panelButton_6->setSizePolicy(sizePolicy);
        panelButton_6->setMinimumSize(QSize(45, 40));
        panelButton_6->setFont(font1);
        panelButton_6->setFocusPolicy(Qt::NoFocus);
        panelButton_6->setProperty("buttonValue", QVariant(QChar(54)));

        horizontalLayout->addWidget(panelButton_6);

        panelButton_7 = new QPushButton(horizontalLayoutWidget);
        panelButton_7->setObjectName(QString::fromUtf8("panelButton_7"));
        sizePolicy.setHeightForWidth(panelButton_7->sizePolicy().hasHeightForWidth());
        panelButton_7->setSizePolicy(sizePolicy);
        panelButton_7->setMinimumSize(QSize(45, 40));
        panelButton_7->setFont(font1);
        panelButton_7->setFocusPolicy(Qt::NoFocus);
        panelButton_7->setProperty("buttonValue", QVariant(QChar(55)));

        horizontalLayout->addWidget(panelButton_7);

        panelButton_8 = new QPushButton(horizontalLayoutWidget);
        panelButton_8->setObjectName(QString::fromUtf8("panelButton_8"));
        sizePolicy.setHeightForWidth(panelButton_8->sizePolicy().hasHeightForWidth());
        panelButton_8->setSizePolicy(sizePolicy);
        panelButton_8->setMinimumSize(QSize(45, 40));
        panelButton_8->setFont(font1);
        panelButton_8->setFocusPolicy(Qt::NoFocus);
        panelButton_8->setProperty("buttonValue", QVariant(QChar(56)));

        horizontalLayout->addWidget(panelButton_8);

        panelButton_9 = new QPushButton(horizontalLayoutWidget);
        panelButton_9->setObjectName(QString::fromUtf8("panelButton_9"));
        sizePolicy.setHeightForWidth(panelButton_9->sizePolicy().hasHeightForWidth());
        panelButton_9->setSizePolicy(sizePolicy);
        panelButton_9->setMinimumSize(QSize(45, 40));
        panelButton_9->setFont(font1);
        panelButton_9->setFocusPolicy(Qt::NoFocus);
        panelButton_9->setProperty("buttonValue", QVariant(QChar(57)));

        horizontalLayout->addWidget(panelButton_9);

        panelButton_0 = new QPushButton(horizontalLayoutWidget);
        panelButton_0->setObjectName(QString::fromUtf8("panelButton_0"));
        sizePolicy.setHeightForWidth(panelButton_0->sizePolicy().hasHeightForWidth());
        panelButton_0->setSizePolicy(sizePolicy);
        panelButton_0->setMinimumSize(QSize(45, 40));
        panelButton_0->setFont(font1);
        panelButton_0->setFocusPolicy(Qt::NoFocus);
        panelButton_0->setProperty("buttonValue", QVariant(QChar(48)));

        horizontalLayout->addWidget(panelButton_0);

        panelButton_star = new QPushButton(horizontalLayoutWidget);
        panelButton_star->setObjectName(QString::fromUtf8("panelButton_star"));
        sizePolicy.setHeightForWidth(panelButton_star->sizePolicy().hasHeightForWidth());
        panelButton_star->setSizePolicy(sizePolicy);
        panelButton_star->setMinimumSize(QSize(45, 40));
        panelButton_star->setFocusPolicy(Qt::NoFocus);
        panelButton_star->setProperty("buttonValue", QVariant(QChar(46)));

        horizontalLayout->addWidget(panelButton_star);

        panelButton_minus = new QPushButton(horizontalLayoutWidget);
        panelButton_minus->setObjectName(QString::fromUtf8("panelButton_minus"));
        sizePolicy.setHeightForWidth(panelButton_minus->sizePolicy().hasHeightForWidth());
        panelButton_minus->setSizePolicy(sizePolicy);
        panelButton_minus->setMinimumSize(QSize(45, 40));
        panelButton_minus->setFont(font1);
        panelButton_minus->setFocusPolicy(Qt::NoFocus);
        panelButton_minus->setProperty("buttonValue", QVariant(QChar(45)));

        horizontalLayout->addWidget(panelButton_minus);

        panelButton_hash = new QPushButton(horizontalLayoutWidget);
        panelButton_hash->setObjectName(QString::fromUtf8("panelButton_hash"));
        sizePolicy.setHeightForWidth(panelButton_hash->sizePolicy().hasHeightForWidth());
        panelButton_hash->setSizePolicy(sizePolicy);
        panelButton_hash->setMinimumSize(QSize(45, 40));
        panelButton_hash->setFont(font1);
        panelButton_hash->setFocusPolicy(Qt::NoFocus);
        panelButton_hash->setProperty("buttonValue", QVariant(QChar(35)));

        horizontalLayout->addWidget(panelButton_hash);


        retranslateUi(DigitalInputPanel);

        QMetaObject::connectSlotsByName(DigitalInputPanel);
    } // setupUi

    void retranslateUi(QWidget *DigitalInputPanel)
    {
        DigitalInputPanel->setWindowTitle(QApplication::translate("DigitalInputPanel", "Form", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("DigitalInputPanel", "Close", 0, QApplication::UnicodeUTF8));
        panelButton_1->setText(QApplication::translate("DigitalInputPanel", "1", 0, QApplication::UnicodeUTF8));
        panelButton_2->setText(QApplication::translate("DigitalInputPanel", "2", 0, QApplication::UnicodeUTF8));
        panelButton_3->setText(QApplication::translate("DigitalInputPanel", "3", 0, QApplication::UnicodeUTF8));
        panelButton_4->setText(QApplication::translate("DigitalInputPanel", "4", 0, QApplication::UnicodeUTF8));
        panelButton_5->setText(QApplication::translate("DigitalInputPanel", "5", 0, QApplication::UnicodeUTF8));
        panelButton_6->setText(QApplication::translate("DigitalInputPanel", "6", 0, QApplication::UnicodeUTF8));
        panelButton_7->setText(QApplication::translate("DigitalInputPanel", "7", 0, QApplication::UnicodeUTF8));
        panelButton_8->setText(QApplication::translate("DigitalInputPanel", "8", 0, QApplication::UnicodeUTF8));
        panelButton_9->setText(QApplication::translate("DigitalInputPanel", "9", 0, QApplication::UnicodeUTF8));
        panelButton_0->setText(QApplication::translate("DigitalInputPanel", "0", 0, QApplication::UnicodeUTF8));
        panelButton_star->setText(QApplication::translate("DigitalInputPanel", ".", 0, QApplication::UnicodeUTF8));
        panelButton_minus->setText(QApplication::translate("DigitalInputPanel", "-", 0, QApplication::UnicodeUTF8));
        panelButton_hash->setText(QApplication::translate("DigitalInputPanel", "\351\200\200\346\240\274", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DigitalInputPanel: public Ui_DigitalInputPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGITALINPUTPANEL_H
