#include "voie3.h"
#include <QDebug>

Voie3::Voie3()
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

    fluide<<QPointF(7,7)<<QPointF(6,8)<<QPointF(6,18)<<QPointF(7,19)<<QPointF(15,19)<<QPointF(17,20)<<QPointF(18,22)<<QPointF(18,43)<<QPointF(19,44)<<QPointF(31,44)<<QPointF(32,43)<<QPointF(32,18)<<QPointF(31,14)<<QPointF(29,11)<<QPointF(28,10)<<QPointF(24,8)<<QPointF(20,7);
    addPolygon(fluide,QPen(Qt::black),QColor("#EFEFEF"));

    vue_voie3 = new QGraphicsView;
    vue_voie3->setScene(this);
    vue_voie3->show();
    vue_voie3->setFixedSize(60,60);
    vue_voie3->setObjectName("voie");
}

void Voie3::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug()<< "voie3";
    if(mouseEvent->button() == Qt::LeftButton)
    {
        emit signalVersClicVoie3();     //Emet un signal vers la fonction clicVoie3 dans slot_seringue
    }
}
