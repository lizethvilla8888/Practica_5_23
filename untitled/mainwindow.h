#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsView>
#include <QList>
#include <QString>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QTimer>

#include "cuerpo.h"
#include "enemy.h"
#include "pared.h"
#include "moneda.h"
#include "puntaje.h"
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }


QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    cuerpo *personaje;
    enemy *enemigo;

    QList<moneda *> monedas;
    QList <pared*> paredes;

    QGraphicsScene *scene;
    QTimer *timer;

    void keyPressEvent(QKeyEvent * evento);
    QList<moneda *> eliminarMonedas(QList<moneda *> monedas,int pos);
    void crear_pared(int, int, int ancho, int);
    void crear_monedas (int, int, int ancho, int alto);

public slots:
    void moveEnemy();


};
#endif // MAINWINDOW_H

