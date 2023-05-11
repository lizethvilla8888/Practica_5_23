#ifndef MONEDA_H
#define MONEDA_H

#include <QGraphicsItem>
#include <QPainter>
#include <vector>

#include  "database.h"

class moneda: public QGraphicsItem
{
    int w,h;
    int posx, posy;

public:
    moneda( int x, int y,int w_, int h_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // MONEDA_H
