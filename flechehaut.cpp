#include "flechehaut.h"
#include <QDebug>

FlecheHaut::FlecheHaut()
{
    setSceneRect(0,0,this->width(),this->height());

    fleche <<QPointF(25,4)<<QPointF(11,29)<<QPointF(20,29)<<QPointF(20,46)<<QPointF(30,46)<<QPointF(30,29)<<QPointF(39,29);
    addPolygon(fleche, QPen(Qt::black),QColor("#EFEFEF"));

    vue_flecheHaut = new QGraphicsView;
    vue_flecheHaut->setScene(this);
    vue_flecheHaut->show();
    vue_flecheHaut->setFixedSize(50,55);
    vue_flecheHaut->setObjectName("fleche");
}

void FlecheHaut::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug()<< "Fleche haut";
    if(mouseEvent->button() == Qt::LeftButton)
    {
        emit signalVersClicFlecheHaut();     //Emet un signal vers la fonction clicFlecheHaut dans slot_seringue
    }
}

//--Colore la fleche en blanc lorsque l'on clic sur le bouton fleche--//
void FlecheHaut::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton)
    {
        addPolygon(fleche,QPen(Qt::black),QColor("#303030"));
        vue_flecheHaut->setStyleSheet("background-color: #EFEFEF");
    }
}
