#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QGraphicsTextItem> // permite mostrar texto en interfas grafica
#include  <QFont> // funte de texto
//#include  <QMediaPlayer>

class puntaje : public QGraphicsTextItem
{
    int puntaje_;
    //QMediaPlayer *comer_moneda;
public:
    puntaje(QGraphicsItem *parent = 0);
    void incremento ();
    int obtener_puntaje();

};

#endif // PUNTAJE_H
