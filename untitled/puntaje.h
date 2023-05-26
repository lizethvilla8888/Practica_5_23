#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QApplication>
#include <QLabel>

class puntaje :public QGraphicsTextItem
{
    int puntaje_;
public:
    puntaje(QGraphicsItem *parent = 0);
    void incremento ();
    int obtener_puntaje();

};

#endif // PUNTAJE_H
