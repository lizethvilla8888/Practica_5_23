#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>

class enemy: public QObject, public QGraphicsItem
{
    Q_OBJECT

    int r;
    int velocidad = 5;

public:
    enemy(int r_, int x, int y);
    int posx, posy;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void up();
    void down();
    void left();
    void right();

};

#endif // ENEMY_H
