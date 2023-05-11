#include "puntaje.h"
//#include  <QMediaPlayer>

/*
puntaje::puntaje(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    puntaje_ = 0;
    setPlainText(QString ("Puntaje: ") + QString::number( puntaje_));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica", 14 ));
}

void puntaje::incremento()
{
    puntaje_++;

    // sonido del pacman comiendo monedas
    //comer_moneda = new QMediaPlayer();
    //comer_moneda->setMedia(QUrl("qrc:/new/prefix1/Nueva carpeta/Pacman_Come_Cereza.mp3"));

    if (comer_moneda->state() == QMediaPlayer::PlayingState){
        comer_moneda->setPosition(0);
        comer_moneda->play();
    }
    else if (comer_moneda->state()==QMediaPlayer::StoppedState){
        comer_moneda->play();
    }

    //setPlainText(QString ("Puntaje: ") + QString::number( puntaje_));
    if (puntaje_ == 51){
        setPlainText(QString ("    GANASTE    "));
        setDefaultTextColor(Qt::black);
        setFont(QFont("Helvetica", 25 ));

    }
}

int puntaje::obtener_puntaje()
{
    return puntaje_;
}
*/
