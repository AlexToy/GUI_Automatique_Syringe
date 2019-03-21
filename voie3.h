#ifndef VOIE3_H
#define VOIE3_H

#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Voie3 : public QGraphicsScene
{
    Q_OBJECT
public:
    Voie3();

    QGraphicsView *vue_voie3;

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
    void signalVersClicVoie3();
};

#endif // VOIE3_H
