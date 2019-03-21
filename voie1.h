#ifndef VOIE1_H
#define VOIE1_H

#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Voie1 : public QGraphicsScene
{
    Q_OBJECT
public:
    Voie1();

    QGraphicsView *vue_voie1;

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
    void signalVersClicVoie1();
};

#endif // VOIE1_H
