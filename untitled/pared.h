#ifndef PARED_H
#define PARED_H
#include <QGraphicsItem>
#include <QPainter>

class pared: public QGraphicsItem
{
    int w,h;
    int posx, posy;

public:
    pared( int x, int y,int w_, int h_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PARED_H
