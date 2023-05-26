#include "puntaje.h"



puntaje::puntaje(QGraphicsItem *parent)
{
    puntaje_ = 0;
    setPlainText(QString ("Puntaje: ") + QString::number( puntaje_));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica", 14 ));
}

void puntaje::incremento()
{
    puntaje_++;
    QLabel label("¡Hola, mundo!");
    label.show();

//    setPlainText(QString ("Puntaje: ") + QString::number( puntaje_));
//    if (puntaje_ == 51){
//        setPlainText(QString ("    GANASTE    "));
//        setDefaultTextColor(Qt::black);
//        setFont(QFont("Helvetica", 25 ));

//    }
}

int puntaje::obtener_puntaje()
{
    return puntaje_;
}

