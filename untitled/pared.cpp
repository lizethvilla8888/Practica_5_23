#include "pared.h"

pared::pared(int x, int y,int w_, int h_)
{
    posx = x;
    posy = y;
    w = w_;
    h = h_;
}

QRectF pared::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
