#ifndef FLECHEHAUT_H
#define FLECHEHAUT_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

class FlecheHaut : public QGraphicsScene
{
    Q_OBJECT
public:
    FlecheHaut();

    QGraphicsView *vue_flecheHaut;
    QPolygonF fleche;

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

signals:
    void signalVersClicFlecheHaut();
};

#endif // FLECHEHAUT_H
