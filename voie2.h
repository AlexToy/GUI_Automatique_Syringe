#ifndef VOIE2_H
#define VOIE2_H

#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Voie2 : public QGraphicsScene
{
    Q_OBJECT
public:
    Voie2();

    QGraphicsView *vue_voie2;

    QPolygonF fluide;
    QPolygonF ligne_superieur;
    QPolygonF ligne_horizontal_inferieur_gauche;
    QPolygonF ligne_oblique_inferieur_gauche;
    QPolygonF ligne_vertical_inferieur_gauche;
    QPolygonF ligne_horizontal_inferieur_droit;
    QPolygonF ligne_oblique_inferieur_droit;
    QPolygonF ligne_vertical_inferieur_droit;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

signals:
    void signalVersClicVoie2();
};

#endif // VOIE2_H
