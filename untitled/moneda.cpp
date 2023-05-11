#include "moneda.h"

moneda::moneda(int x, int y,int w_, int h_)
{
    posx = x;
    posy = y;
    w = w_;
    h = h_;
}

QRectF moneda::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void moneda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());

}
