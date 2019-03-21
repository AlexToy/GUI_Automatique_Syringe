#include "voie1.h"
#include <QDebug>

Voie1::Voie1()
{
    setSceneRect(0,0,50,50);

    ligne_superieur << QPoint(5,4) << QPoint(45, 4);
    addPolygon(ligne_superieur, QPen("#EFEFEF")); //ligne superieur

    ligne_horizontal_inferieur_gauche << QPoint(5, 22) << QPoint(14, 22);
    addPolygon(ligne_horizontal_inferieur_gauche, QPen("#EFEFEF"));    //ligne horizontal inferieur gauche

    ligne_oblique_inferieur_gauche << QPoint(14, 22) << QPoint(15, 23);
    addPolygon(ligne_oblique_inferieur_gauche, QPen("#EFEFEF"));       //ligne oblique inferieur gauche

    ligne_vertical_inferieur_gauche << QPoint(15, 23) << QPoint(15, 45);
    addPolygon(ligne_vertical_inferieur_gauche, QPen("#EFEFEF"));      //ligne vertical inferieur gauche

    ligne_horizontal_inferieur_droit<< QPoint(35, 45) << QPoint(35, 23);
    addPolygon(ligne_horizontal_inferieur_droit, QPen("#EFEFEF"));     //ligne horizontal inferieur droit

    ligne_oblique_inferieur_droit << QPoint(35, 23) << QPoint(36, 22);
    addPolygon(ligne_oblique_inferieur_droit, QPen("#EFEFEF"));        //ligne oblique inferieur droit

    ligne_vertical_inferieur_droit << QPoint(36, 22) << QPoint(45, 22);
    addPolygon(ligne_vertical_inferieur_droit, QPen("#EFEFEF"));       //ligne vertical inferieur droit


    fluide <<QPointF(43,7)<<QPointF(30,7)<<QPointF(26,8)<<QPointF(22,10)<<QPointF(21,11)<<QPointF(19,14)<<QPointF(18,18)<<QPointF(18,43)<<QPointF(19,44)<<QPointF(31,44)<<QPointF(32,43)<<QPointF(32,22)<<QPointF(33,20)<<QPointF(35,19)<<QPointF(43,19)<<QPointF(44,18)<<QPointF(44,8);
    addPolygon(fluide,QPen(Qt::black),QColor("#EFEFEF"));


    vue_voie1 = new QGraphicsView;
    vue_voie1->setScene(this);
    vue_voie1->show();
    vue_voie1->setFixedSize(60,60);
    vue_voie1->setObjectName("voie");

}

void Voie1::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug()<< "voie1";
    if(mouseEvent->button() == Qt::LeftButton)
    {
        emit signalVersClicVoie1();     //Emet un signal vers la fonction clicVoie1 dans slot_seringue
    }
}
