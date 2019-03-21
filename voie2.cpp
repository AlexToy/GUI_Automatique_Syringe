#include "voie2.h"
#include <QDebug>

Voie2::Voie2()
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

    fluide<<QPointF(7,7)<<QPointF(6,8)<<QPointF(6,18)<<QPointF(7,19)<<QPointF(43,19)<<QPointF(44,18)<<QPointF(44,8)<<QPointF(43,7);
    addPolygon(fluide,QPen(Qt::black),QColor("#EFEFEF"));

    vue_voie2 = new QGraphicsView;
    vue_voie2->setScene(this);
    vue_voie2->show();
    vue_voie2->setFixedSize(60,60);
    vue_voie2->setObjectName("voie");
}

void Voie2::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug()<< "voie2";
    if(mouseEvent->button() == Qt::LeftButton)
    {
        emit signalVersClicVoie2();     //Emet un signal vers la fonction clicVoie2 dans slot_seringue
    }
}
