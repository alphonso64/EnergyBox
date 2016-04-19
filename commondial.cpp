#include "commondial.h"

#include <qpainter.h>
#include <qwt_dial_needle.h>
#include <qwt_round_scale_draw.h>

CommonDial::CommonDial( QWidget *parent ):
    QwtDial( parent ),
    d_label( "" )
{


    QwtRoundScaleDraw *scaleDraw = new QwtRoundScaleDraw();
    scaleDraw->setSpacing( 3 );
    scaleDraw->enableComponent( QwtAbstractScaleDraw::Backbone, false );
    scaleDraw->setTickLength( QwtScaleDiv::MinorTick, 0 );
    scaleDraw->setTickLength( QwtScaleDiv::MediumTick, 4 );
    scaleDraw->setTickLength( QwtScaleDiv::MajorTick, 8 );
    setScaleDraw( scaleDraw );

    setWrapping( false );
    setReadOnly( true );

    setOrigin( 135.0);
    setScaleArc( 0.0, 270.0 );

    QwtDialSimpleNeedle *needle = new QwtDialSimpleNeedle(
        QwtDialSimpleNeedle::Arrow, true, Qt::red,
        QColor( Qt::gray ).light( 130 ) );
    setNeedle( needle );

}

void CommonDial::setLabel( const QString &label )
{
    d_label = label;
    update();
}

QString CommonDial::label() const
{
    return d_label;
}

void CommonDial::drawScaleContents( QPainter *painter,
    const QPointF &center, double radius ) const
{
    QRectF rect( 0.0, 0.0, 2.0 * radius, 2.0 * radius - 10.0 );
    rect.moveCenter( center );

    const QColor color(0x87,0x87,0x87,255); //= palette().color( QPalette::Text );
    painter->setPen( color );

    QFont font( "Times", 12);
    painter->setFont(font);
    const int flags = Qt::AlignBottom | Qt::AlignHCenter;
    painter->drawText( rect, flags, d_label );

//    QRectF rect( 0.0, 0.0, 2.0 * radius, 2.0 * radius - 10.0 );
//    rect.moveCenter( center );

//    const QColor color(0x45,0x45,0x45,255); //= palette().color( QPalette::Text );
//    painter->setPen( color );

//    QFont font( "Times", 20);
//    painter->setFont(font);
//    painter->translate(100,180);
//    const int flags = Qt::AlignBottom | Qt::AlignHCenter;

//    QTextDocument td;
//    td.setHtml("K<sub>max</sub>=K<sub>2</sub> &middot; 3");
//    td.drawContents(painter);
}


