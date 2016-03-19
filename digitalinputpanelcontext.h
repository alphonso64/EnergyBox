#ifndef DIGITALINPUTPANELCONTEXT_H
#define DIGITALINPUTPANELCONTEXT_H

#include <QtGui/QInputContext>
#include "digitalinputpanel.h"
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

private slots:
    void sendCharacter(QChar character);

private:
    void updatePosition();

private:
    DigitalInputPanel *inputPanel;
};

#endif // DIGITALINPUTPANELCONTEXT_H
