#ifndef DIGITALINPUTPANELCONTEXT_H
#define DIGITALINPUTPANELCONTEXT_H

#include <QtGui/QInputContext>
#include "digitalinputpanel.h"
#include "fullinputpanel.h"

class DigitalInputPanelContext: public QInputContext
{
    Q_OBJECT

public:
    DigitalInputPanelContext();
    ~DigitalInputPanelContext();

    bool filterEvent(const QEvent* event);

    QString identifierName();
    QString language();

    bool isComposing() const;

    void reset();

    void hideWidget(bool flag);

    void panelChange(int);

private slots:
    void sendCharacter(QChar character);

private:
    void updatePosition();

private:
    DigitalInputPanel *inputPanel;
    FullInputPanel *fullPanel;
};

#endif // DIGITALINPUTPANELCONTEXT_H
