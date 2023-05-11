#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(700,700);
    scene->setSceneRect(0,0,700,700);
    scene->setBackgroundBrush(QPixmap(":/new/prefix1/imagenes/700x700.png"));

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle("Pac Man");

    personaje = new cuerpo(10,100,100); // se crea bolita de pacman
    scene->addItem(personaje);

    enemigo = new enemy(10,420,180); // se crea fantasma
    scene->addItem(enemigo);

/*
    //AGREGO MONEDAS
    int x = 30, y= 30 ;
    for (int i = 0; i<7 ;i ++){
        x=30;//x=30;
        for (int j =0  ; j<9; j++,x+=65){
            // crear_monedas(x,y);
        }
        y+=55;// y+=40;
      // crear_monedas(x,y);
     }
    //AGREGO PAREDES
    y= 60 ;
    for (int i = 0; i<3 ;i ++){
        x=60;//x=30;
        for (int j =0  ; j<4; j++,x+=130){
            // crear_pared(x,y);
        }
        y+=110;// y+=40;
       //crear_pared(x,y);
     }
    int p_s[16] = {0,0,590,10,0,0,10,400,0,390,590,10,580,0,10,400};
    for (int i=0;i<=16;i+=4)
    {
        //paredes.push_back(new pared(p_s[i],p_s[i+1],p_s[i+2],p_s[i+3]));
        //scene->addItem(paredes.back());
    }
*/

/*
x0,y0,w700,h34
x0,y0,w34,h233
x666,y0,w34,h233
x0,y398,w34,h700
x666,y400,w34,h300
x0,y667,w700,h34
x257,y267,w74,h34
x257,y267,w34,h99
x290,y332,w119,h34
x409,y300,w34,h66
x369,y267,w74,h34
x33,y199,w114,h34
x113,y233,w34,h65
x0,y267,w148,h34
x0,y333,w148,h34
x114,y366,w34,h65
x0,y399,w148,h34
x551,y200,w149,h34
x551,y200,w34,h100
x551,y267,w149,h34
x551,y333,w34,h100
x551,y399,w149,h34
x72,y66,w75,h34
x184,y66,w112,h34
x404,y66,w112,h34
x552,y66,w75,h34
x72,y134,w75,h34
x552,y134,w75,h34
x184,y333,w34,h100
x479,y333,w34,h100
x184,y466,w112,h34
x404,y466,w112,h34
x72,y466,w75,h34
x114,y466,w34,h100
x551,y466,w75,h34
x551,y466,w34,h100
x257,y134,w186,h34
x330,y166,w34,h64
x218,y200,w75,h34
x184,y134,w34,h166
x404,y200,w75,h34
x479,y134,w34,h166
x330,y433,w34,h67
x257,y399,w186,h34
x257,y533,w186,h34
x330,y566,w34,h67
x479,y533,w34,h66
x404,y599,w223,h34
x184,y533,w34,h66
x72,y599,w224,h34
x331,y34,w34,h66
x34,y533,w40,h34
x626,y533,w40,h34
*/

    paredes.push_back(new pared(0,0,700,34)); //0,0,700,34
    database data; //creamos objeto database
    string nombre_txt = "paredes.txt", coordenadas;
    data.set_name(nombre_txt);








    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timer->start(25);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento){
    if(evento->key()==Qt::Key_D)
     {
         //Evaluacion de colision con monedas
        personaje->Move_derecha();
        for (int i = 0;i < monedas.size();i++) {
             if(personaje->collidesWithItem(monedas.at(i))){
                 //puntaje_->incremento(); // incremento de puntaje

                 scene->removeItem(monedas.at(i));
                 monedas.removeAt(i);
              }
         }
        //Colicion con muros
        for (int i = 0;i < paredes.size();i++) {
             if(personaje->collidesWithItem(paredes.at(i))){
                personaje->Move_izquierda();
             }
        }
    }
     else if(evento->key()==Qt::Key_S)
     {
        personaje->Move_abajo();
        for (int i = 0;i < monedas.size();i++) {
             if(personaje->collidesWithItem(monedas.at(i))){
               // puntaje_->incremento(); // incremento de puntaje
                scene->removeItem(monedas.at(i));
                monedas.removeAt(i);
              }
         }

        //Colicion con muros
        for (int i = 0;i < paredes.size();i++) {
             if(personaje->collidesWithItem(paredes.at(i))){
                personaje->Move_abajo();
             }
        }
    }
     else if (evento->key()==Qt::Key_W)
     {
         personaje->Move_arriba();
         for (int i = 0;i < monedas.size();i++) {
              if(personaje->collidesWithItem(monedas.at(i))){
                 // puntaje_->incremento(); // incremento de puntaje
                  scene->removeItem(monedas.at(i)); // eliminar moneda de esena
                  monedas.removeAt(i);
               }
          }
         //Colicion con muros
         for (int i = 0;i < paredes.size();i++) {
              if(personaje->collidesWithItem(paredes.at(i))){
                 personaje->Move_arriba();
              }
         }
     }
     else if (evento->key()==Qt::Key_A)
     {

        personaje->Move_izquierda();
        for (int i = 0;i < monedas.size();i++) {
             if(personaje->collidesWithItem(monedas.at(i))){
                // puntaje_->incremento(); // incremento de puntaje
                 scene->removeItem(monedas.at(i)); // eliminar moneda de esena
                 monedas.removeAt(i);
              }
         }

        //Colicion con muros
        for (int i = 0;i < paredes.size();i++) {
             if(personaje->collidesWithItem(paredes.at(i))){
                personaje->Move_derecha();
             }
        }
    }   
}

void MainWindow::crear_pared(int x, int y, int ancho, int alto)
{

    paredes.push_back(new pared(x,y,ancho,alto));
    scene->addItem(paredes.back());
}

void MainWindow::crear_monedas(int x, int y, int ancho, int alto)
{
    monedas.push_back(new moneda(x,y,ancho,ancho));
    scene->addItem(monedas.back());
}

QList<moneda *> MainWindow::eliminarMonedas(QList<moneda *> monedas, int pos)
{
    QList<moneda *> aux;
    for (int i = 0;i < monedas.size() ; i++) {
        if(i != pos){
            aux.push_back(monedas.at(i));
        }
    }
    return aux;
}

void MainWindow::moveEnemy()
{
    if(enemigo->x() < personaje->x()){
        enemigo->right();

        for (int i = 0;i < paredes.size();i++) {
             if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->left();
             }
        }
    }

    else if(enemigo->x() > personaje->x()){
        enemigo->left();

        for (int i = 0;i < paredes.size();i++) {
             if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->right();
             }
        }
    }

    else if(enemigo->y() < personaje->y()){
        enemigo->down();
        for (int i = 0;i < paredes.size();i++) {
             if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->up();
             }
        }
    }
    else if(enemigo->y() > personaje->y()){
        enemigo->up();
        for (int i = 0;i < paredes.size();i++) {
             if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->down();
             }

        }
    }
enemigo->setPos(enemigo->posx,enemigo->posy);
}







