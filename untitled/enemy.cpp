#include "enemy.h"

enemy::enemy(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
}

QRectF enemy::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void enemy::up()
{
    posy -= 3;
    setPos(posx, posy);
}

void enemy::down()
{
    posy += 3;
    setPos(posx, posy);
}

void enemy::left()
{
    posx -= 3;
    setPos(posx, posy);
}

void enemy::right()
{
    posx += 3;
    setPos(posx, posy);
}
