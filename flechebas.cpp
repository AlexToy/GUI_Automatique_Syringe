#include "flechebas.h"
#include <QDebug>

FlecheBas::FlecheBas()
{
    setSceneRect(0,0,this->width(),this->height());

    fleche <<QPointF(10,1)<<QPointF(10,18)<<QPointF(0.5,18)<<QPointF(15,43)<<QPointF(29.5,18)<<QPointF(20,18)<<QPointF(20,1);
    addPolygon(fleche, QPen(Qt::black),QColor("#EFEFEF"));

    vue_flecheBas = new QGraphicsView;
    vue_flecheBas->setScene(this);
    vue_flecheBas->show();
    vue_flecheBas->setFixedSize(50,55);
    vue_flecheBas->setObjectName("fleche");
}

void FlecheBas::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug()<< "Fleche Bas";
    if(mouseEvent->button() == Qt::LeftButton)
    {
        emit signalVersClicFlecheBas();     //Emet un signal vers la fonction clicFlecheBas dans slot_seringue
    }
}

//--Colore la fleche en blanc lorsque l'on clic sur le bouton fleche--//
void FlecheBas::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton)
    {
        addPolygon(fleche,QPen(Qt::black),QColor("#303030"));
        vue_flecheBas->setStyleSheet("background-color: #EFEFEF");
    }
}

