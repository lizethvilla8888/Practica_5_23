#include "cuerpo.h"

cuerpo::cuerpo(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
    //setPixmap(QPixmap(":/new/prefix1/imagenes/PACMAN.png"));
}

QRectF cuerpo::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt:: yellow);
    painter->drawEllipse(boundingRect());
}

void cuerpo::Move_arriba()
{
    posy -= 1*velocidad;
    setPos(posx, posy);
}

void cuerpo::Move_abajo()
{
    posy += 1*velocidad;
    setPos(posx, posy);
}

void cuerpo::Move_izquierda()
{
    posx -= 1*velocidad;
    setPos(posx, posy);
}

void cuerpo::Move_derecha()
{
    posx += 1*velocidad;
    setPos(posx, posy);
}
