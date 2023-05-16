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

    personaje = new cuerpo(15,60,60); // se crea bolita de pacman
    scene->addItem(personaje);

    enemigo = new enemy(10,120,180); // se crea fantasma
    scene->addItem(enemigo);

    paredes_();
    monedas_();

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timer->start(25);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento){
    if(evento->key()==Qt::Key_D){
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
     else if(evento->key()==Qt::Key_S){
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
                personaje->Move_arriba();
             }
        }
    }
     else if (evento->key()==Qt::Key_W){
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
                 personaje->Move_abajo();
              }
         }
     }
     else if (evento->key()==Qt::Key_A){
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
    monedas.push_back(new moneda(x,y,ancho,alto));
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

    else if(enemigo->y() < personaje->y()){
        enemigo->down();
        for (int i = 0;i < paredes.size();i++) {
             if(enemigo->collidesWithItem(paredes.at(i))){
                enemigo->down();
             }
        }
    }

enemigo->setPos(enemigo->posx,enemigo->posy);
}

void MainWindow::paredes_()
{
    crear_pared(0,0,700,34);
    crear_pared(0,0,34,233);
    crear_pared(666,0,34,233);
    crear_pared(0,398,34,700);
    crear_pared(666,400,34,300);
    crear_pared(0,667,700,34);
    crear_pared(257,267,74,34);
    crear_pared(257,267,34,99);
    crear_pared(257,267,34,99);
    crear_pared(409,300,34,66);
    crear_pared(369,267,74,34);
    crear_pared(33,199,114,34);
    crear_pared(113,233,34,65);
    crear_pared(0,267,148,34);
    crear_pared(0,333,148,34);
    crear_pared(114,366,34,65);
    crear_pared(0,399,148,34);
    crear_pared(551,200,149,34);
    crear_pared(551,200,34,100);
    crear_pared(551,267,149,34);
    crear_pared(551,333,34,100);
    crear_pared(551,399,149,34);
    crear_pared(72,66,75,34);
    crear_pared(184,66,112,34);
    crear_pared(404,66,112,34);
    crear_pared(552,66,75,34);
    crear_pared(72,134,75,34);
    crear_pared(552,134,75,34);
    crear_pared(184,333,34,100);
    crear_pared(479,333,34,100);
    crear_pared(184,466,112,34);
    crear_pared(404,466,112,34);
    crear_pared(72,466,75,34);
    crear_pared(114,466,34,100);
    crear_pared(551,466,75,34);
    crear_pared(551,466,34,100);
    crear_pared(257,134,186,34);
    crear_pared(330,166,34,64);
    crear_pared(218,200,75,34);
    crear_pared(184,134,34,166);
    crear_pared(404,200,75,34);
    crear_pared(479,134,34,166);
    crear_pared(330,433,34,67);
    crear_pared(257,399,186,34);
    crear_pared(257,533,186,34);
    crear_pared(330,566,34,67);
    crear_pared(479,533,34,66);
    crear_pared(404,599,223,34);
    crear_pared(184,533,34,66);
    crear_pared(72,599,224,34);
    crear_pared(331,34,34,66);
    crear_pared(34,533,40,34);
    crear_pared(626,533,40,34);
    crear_pared(552,333,200,34);
    crear_pared(286,333,148,34);

}

void MainWindow::monedas_()
{
    crear_monedas(50,46,10,10);
    crear_monedas(159,46,10,10);
    crear_monedas(210,46,10,10);
    crear_monedas(260,46,10,10);
    crear_monedas(305,46,10,10);
    crear_monedas(380,46,10,10);
    crear_monedas(430,46,10,10);
    crear_monedas(470,46,10,10);
    crear_monedas(528,46,10,10);
    crear_monedas(580,46,10,10);
    crear_monedas(638,46,10,10);
    crear_monedas(50,78,10,10);
    crear_monedas(159,78,10,10);
    crear_monedas(305,78,10,10);
    crear_monedas(380,78,10,10);
    crear_monedas(528,78,10,10);
    crear_monedas(638,78,10,10);
    crear_monedas(50,110,10,10);
    crear_monedas(103,110,10,10);
    crear_monedas(159,110,10,10);
    crear_monedas(210,110,10,10);
    crear_monedas(260,110,10,10);
    crear_monedas(305,110,10,10);
    crear_monedas(380,110,10,10);
    crear_monedas(430,110,10,10);
    crear_monedas(483,110,10,10);
    crear_monedas(531,110,10,10);
    crear_monedas(580,110,10,10);
    crear_monedas(644,110,10,10);
    crear_monedas(50,145,10,10);
    crear_monedas(159,145,10,10);
    crear_monedas(531,145,10,10);
    crear_monedas(644,145,10,10);
    crear_monedas(50,176,10,10);
    crear_monedas(103,176,10,10);
    crear_monedas(159,176,10,10);
    crear_monedas(260,176,10,10);
    crear_monedas(305,176,10,10);
    crear_monedas(380,176,10,10);
    crear_monedas(430,176,10,10);
    crear_monedas(531,176,10,10);
    crear_monedas(580,176,10,10);
    crear_monedas(644,176,10,10);
    //crear_monedas(50,212,10,10);
    crear_monedas(305,212,10,10);
    crear_monedas(380,212,10,10);
    crear_monedas(531,212,10,10);
    //crear_monedas(50,244,10,10);
    crear_monedas(260,244,10,10);
    crear_monedas(305,244,10,10);
    crear_monedas(380,244,10,10);
    crear_monedas(430,244,10,10);
    crear_monedas(531,244,10,10);
    //crear_monedas(580,244,10,10);
    //crear_monedas(644,244,10,10);
    //crear_monedas(50,275,10,10);
    //crear_monedas(644,275,10,10);
    crear_monedas(50,308,10,10);
    crear_monedas(103,308,10,10);
    crear_monedas(159,308,10,10);
    crear_monedas(531,308,10,10);
    crear_monedas(580,308,10,10);
    crear_monedas(644,308,10,10);
    //crear_monedas(50,342,10,10);
    crear_monedas(531,342,10,10);
    //crear_monedas(50,375,10,10);
    crear_monedas(260,375,10,10);
    crear_monedas(305,375,10,10);
    crear_monedas(380,375,10,10);
    crear_monedas(430,375,10,10);
    crear_monedas(531,375,10,10);
   // crear_monedas(50,408,10,10);
    crear_monedas(531,408,10,10);
    crear_monedas(50,444,10,10);
    crear_monedas(103,444,10,10);
    crear_monedas(159,444,10,10);
    crear_monedas(210,444,10,10);
    crear_monedas(260,444,10,10);
    crear_monedas(305,444,10,10);
    crear_monedas(380,444,10,10);
    crear_monedas(430,444,10,10);
    crear_monedas(483,444,10,10);
    crear_monedas(531,444,10,10);
    crear_monedas(580,444,10,10);
    crear_monedas(644,444,10,10);
    crear_monedas(50,474,10,10);
    crear_monedas(159,474,10,10);
    crear_monedas(305,474,10,10);
    crear_monedas(380,474,10,10);
    crear_monedas(531,474,10,10);
    crear_monedas(644,474,10,10);
    crear_monedas(50,510,10,10);
    crear_monedas(159,510,10,10);
    crear_monedas(210,510,10,10);
    crear_monedas(260,510,10,10);
    crear_monedas(305,510,10,10);
    crear_monedas(380,510,10,10);
    crear_monedas(430,510,10,10);
    crear_monedas(483,510,10,10);
    crear_monedas(531,510,10,10);
    crear_monedas(644,510,10,10);
    //crear_monedas(50,540,10,10);
    crear_monedas(159,540,10,10);
    crear_monedas(531,540,10,10);
    //crear_monedas(580,540,10,10);
    crear_monedas(50,574,10,10);
    crear_monedas(103,574,10,10);
    crear_monedas(159,574,10,10);
    crear_monedas(260,574,10,10);
    crear_monedas(305,574,10,10);
    crear_monedas(380,574,10,10);
    crear_monedas(430,574,10,10);
    //crear_monedas(483,574,10,10);
    crear_monedas(531,574,10,10);
    crear_monedas(580,574,10,10);
    crear_monedas(644,574,10,10);
    crear_monedas(50,608,10,10);
    crear_monedas(305,608,10,10);
    crear_monedas(380,608,10,10);
    crear_monedas(644,608,10,10);
    crear_monedas(50,642,10,10);
    crear_monedas(103,642,10,10);
    crear_monedas(159,642,10,10);
    crear_monedas(210,642,10,10);
    crear_monedas(260,642,10,10);
    crear_monedas(305,642,10,10);
    crear_monedas(380,642,10,10);
    crear_monedas(430,642,10,10);
    crear_monedas(483,642,10,10);
    crear_monedas(531,642,10,10);
    crear_monedas(580,642,10,10);
    crear_monedas(644,642,10,10);
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
    //crear_monedas();
}





