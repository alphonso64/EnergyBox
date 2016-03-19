#ifndef DIGITALINPUTPANEL_H
#define DIGITALINPUTPANEL_H

#include <QtGui>
#include <QtCore>

#include "ui_digitalinputpanel.h"

//! [0]

class DigitalInputPanel : public QWidget
{
    Q_OBJECT

public:
    DigitalInputPanel();

signals:
    void characterGenerated(QChar character);

protected:
    bool event(QEvent *e);

private slots:
    void saveFocusWidget(QWidget *oldFocus, QWidget *newFocus);
    void buttonClicked(QWidget *w);

private:
    Ui::DigitalInputPanel form;
    QWidget *lastFocusedWidget;
    QSignalMapper signalMapper;
};

#endif // DIGITALINPUTPANEL_H
