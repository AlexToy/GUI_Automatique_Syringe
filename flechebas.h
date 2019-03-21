#ifndef FLECHEBAS_H
#define FLECHEBAS_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

class FlecheBas : public QGraphicsScene
{
    Q_OBJECT
public:
    FlecheBas();

    QGraphicsView *vue_flecheBas;
    QPolygonF fleche;

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

signals:
    void signalVersClicFlecheBas();
};

#endif // FLECHEBAS_H
