#ifndef COMMONDIAL_H
#define COMMONDIAL_H
#include <qstring.h>
#include <qwt_dial.h>
class CommonDial: public QwtDial
{
public:
    CommonDial( QWidget *parent = NULL );

    void setLabel( const QString & );
    QString label() const;

protected:
    virtual void drawScaleContents( QPainter *painter,
        const QPointF &center, double radius ) const;

private:
    QString d_label;
};

#endif // COMMONDIAL_H



