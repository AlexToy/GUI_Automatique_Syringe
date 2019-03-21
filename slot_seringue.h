#ifndef SLOT_SERINGUE_H
#define SLOT_SERINGUE_H

//---------------------------------------------------------//
//------------------Informations---------------------------//
//---------------------------------------------------------//
//-------Lors de la creation d'un nouveau slot_seringue,---//
//-------choisir la couleur et le canal de seringue--------//
//---------------------------------------------------------//

#include <QLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>

#include "voie1.h"
#include "voie2.h"
#include "voie3.h"
#include "seringue.h"
#include "flechehaut.h"
#include "flechebas.h"

class Slot_seringue : public QVBoxLayout
{
    Q_OBJECT
public:
    Slot_seringue();

    //Créations des objets crées
    Voie1 *voie1;
    Voie2 *voie2;
    Voie3 *voie3;
    Seringue *seringue;
    FlecheHaut *flecheHaut;
    FlecheBas *flecheBas;

    //Créations des objets Qt
    QLineEdit *lineEditPas;

private:
    QHBoxLayout *layoutVoies;
    QHBoxLayout *layoutText;
    QHBoxLayout *layoutFlechesSeringueVoies;
    QVBoxLayout *layoutFleches;
    QVBoxLayout *layoutSeringueVoies;
    QLabel *labelPas;

private slots:
    void clicVoie1();
    void clicVoie2();
    void clicVoie3();
    void clicFlecheHaut();
    void clicFlecheBas();
    void recuperationInfo();

signals:
    void signalVersEnvoie(QString trame);
    void signalVersCalculNombresPas(float surfaceSeringue, float volumeSeringue); //Signal qui recupere la surface de la seringue et l'envoye vers la class Panneau de control pour calculer le nombre de pas
    void signalVersDessinSeringue(float volumeADeplacer);
};

#endif // SLOT_SERINGUE_H
