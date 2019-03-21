#ifndef SERINGUE_H
#define SERINGUE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QComboBox>
#include <QDebug>
#include <QMessageBox>

class Seringue : public QGraphicsScene
{
    Q_OBJECT
public:
    Seringue();

    //---Déclarations des variables---//

        //variables des caractéristiques physiques de la seringue avec les valeurs par defauts
        float volumeSeringue = 1000;            //volume en mm3
        float surfaceSeringue = 17.945091;      //surface en mm2
        float longeurSeringue = 55.725546;      //longueur en mm
        float pasPousseSeringue = 0.0078125;    //pas en mm (caractéristique physique de pousse seringue)
        float vitesseDeplacement = 10;

        //Variables de calcul du mouvement du liquide
        float volumeRestant = volumeSeringue/1000;      //volume restant en mL
        float tailleRectangleLiquide = 250;
        float pasRectangleLiquide = 250;                //pas de la seringue 1mL
        qreal mouvementRectangleLiquide;
        qreal tailleRestanteRectangleLiquide = 250;

    //---DÃ©clarations des objets Qt---//

        //Objets dessin de la seringue
        QGraphicsRectItem *liquide;
        QGraphicsRectItem *pousseLiquide;
        QGraphicsRectItem *tigePousseLiquide;

        //Objet vue
        QGraphicsView *vue_seringue;

        //Objets couleurs
        QLinearGradient degradeBleu;
        QLinearGradient degradeJaune;
        QLinearGradient degradeGrisAngle;
        QLinearGradient degradeGris;
        QLinearGradient degradeGrisPetit;
        QLinearGradient degradeGrisPousseLiquide;
        QLinearGradient degradeGrisTigePousseLiquide;
        QLinearGradient degradeGrisTigePousseLiquideBas;

        //Objets de caractérisation
        QComboBox *typeSeringue;
        char canalSeringue;

        bool initialisation = false;

private:
        int nombreNouvelleSeringue = 0;
        //Stockage des caractéristiques des seringues ajoutées par l'utilisateur
        float volumeSeringueNewS1;
        float surfaceSeringueNewS1;
        float longeurSeringueNewS1;

        float volumeSeringueNewS2;
        float surfaceSeringueNewS2;
        float longeurSeringueNewS2;

        float volumeSeringueNewS3;
        float surfaceSeringueNewS3;
        float longeurSeringueNewS3;

public slots:
    void selectionSeringue();                       //Fonction permettant de changer de seringue
    void choixCouleurSeringue(QString couleur);     //Fonction permettant de choisir la couleur de la seringue
    void dessinSeringue(float volumeADeplacer);
    void initialisationDessinSeringue(bool pleine);
    void updateInitialisation(bool boolInitialisation);
    void ajoutNouvelleSeringue(QString nom, float volume, float surface, float longueur);                   //Fonction qui permet à l'utilisateur d'ajouter une nouvelle seringue | bouton présent dans la toolbar

private slots:
    void creationDegradeCouleur();

signals:
    void signalVersMiseAJourInformation(float volume);          //Signal
};

#endif // SERINGUE_H
