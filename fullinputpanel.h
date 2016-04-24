#ifndef FULLINPUTPANEL_H
#define FULLINPUTPANEL_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include "ui_fullinputpanel.h"

class FullInputPanel : public QWidget
{
    Q_OBJECT

public:
    FullInputPanel();

signals:
    void fullcharacterGenerated(QChar character);

protected:
    bool event(QEvent *e);

private slots:
    void saveFocusWidget(QWidget *oldFocus, QWidget *newFocus);
    void buttonClicked(QWidget *w);

private:
    Ui::FullInputPanel form;
    QWidget *lastFocusedWidget;
    QSignalMapper signalMapper;

};

#endif // FULLINPUTPANEL_H
