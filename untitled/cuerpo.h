#ifndef CUERPO_H
#define CUERPO_H
#include <QGraphicsItem>
#include <QPainter>

class cuerpo: public QGraphicsPixmapItem
{

    int r;
    int posx, posy;
    int velocidad = 5;


public:
    cuerpo(int r_, int x, int y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void Move_arriba();
    void Move_abajo();
    void Move_derecha();
    void Move_izquierda();
};

#endif // CUERPO_H
