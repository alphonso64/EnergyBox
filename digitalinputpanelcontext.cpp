#include "digitalinputpanelcontext.h"
#include <QtCore>
#include "util.h"

//! [0]

DigitalInputPanelContext::DigitalInputPanelContext()
{
    inputPanel = new DigitalInputPanel;
    fullPanel = new FullInputPanel;
    connect(inputPanel, SIGNAL(characterGenerated(QChar)), SLOT(sendCharacter(QChar)));
    connect(fullPanel, SIGNAL(fullcharacterGenerated(QChar)), SLOT(sendCharacter(QChar)));
    inputPanel->hide();
    fullPanel->hide();
    fullPanel->move(110,280);
    inputPanel->move(90,500);
}

//! [0]

DigitalInputPanelContext::~DigitalInputPanelContext()
{
    delete inputPanel;
}

//! [1]

bool DigitalInputPanelContext::filterEvent(const QEvent* event)
{
    //qDebug("event %d",event->type());
//    if (event->type() == QEvent::MouseButtonRelease ) {
//        //updatePosition();
//        inputPanel->show();
//        inputPanel->move(25,480);
//		qDebug("event %d",event->type());
//        return true;
//    } else if (event->type() == QEvent::CloseSoftwareInputPanel) {
//        inputPanel->hide();
//        return true;
//    }
    return false;
}

//! [1]

QString DigitalInputPanelContext::identifierName()
{
    return "MyInputPanelContext";
}

void DigitalInputPanelContext::reset()
{
}

bool DigitalInputPanelContext::isComposing() const
{
    return false;
}

QString DigitalInputPanelContext::language()
{
    return "en_US";
}

//! [2]

void DigitalInputPanelContext::sendCharacter(QChar character)
{
    QPointer<QWidget> w = focusWidget();

    Util::SysLogD("press %d\n",character);

    if(character == 35)
    {
        if (!w)
            return;

        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier);
        QApplication::sendEvent(w, &keyPress);

    }else
    {
        if (!w)
            return;

        QKeyEvent keyPress(QEvent::KeyPress, character.unicode(), Qt::NoModifier, QString(character));
        QApplication::sendEvent(w, &keyPress);



        if (!w)
            return;

        QKeyEvent keyRelease(QEvent::KeyPress, character.unicode(), Qt::NoModifier, QString());
        QApplication::sendEvent(w, &keyRelease);
    }


}

void DigitalInputPanelContext::panelChange(int flag)
{
    if(flag == 1)
    {
        inputPanel->show();
        fullPanel->hide();
    }else if(flag == 2)
    {
        fullPanel->show();
        inputPanel->hide();
    }else if(flag == 3)
    {
        fullPanel->hide();
        inputPanel->hide();
    }
}

void DigitalInputPanelContext::updatePosition()
{
    QWidget *widget = focusWidget();
    if (!widget)
        return;

    QRect widgetRect = widget->rect();

    QPoint panelPos = QPoint(widgetRect.left(), widgetRect.bottom() + 2);
    panelPos = widget->mapToGlobal(panelPos);
    inputPanel->move(panelPos);
}

void DigitalInputPanelContext::hideWidget(bool flag)
{
    if(flag){
        fullPanel->hide();
        inputPanel->hide();
    }else{
        inputPanel->show();
        fullPanel->hide();
    }
}

//! [3]
