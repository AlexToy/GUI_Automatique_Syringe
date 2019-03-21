#include "seringue.h"

Seringue::Seringue()
{
//---Créations et initilisations des objets Qt---//
    typeSeringue = new QComboBox;
    typeSeringue->addItem("Seringue 1mL");
    typeSeringue->addItem("Seringue 3mL");
    typeSeringue->addItem("Seringue 5mL");
    typeSeringue->addItem("Seringue 10mL");
    typeSeringue->addItem("Seringue 20mL");
    typeSeringue->addItem("Seringue 30mL");
    typeSeringue->addItem("Seringue 50mL");

    //Initialisation parametres scene
    setSceneRect(0,40,130,390);

    //Création des couleurs
    creationDegradeCouleur();

    //Création du dessin de la seringue
    addRect(QRectF(63.5,18,3,33), QPen(Qt::black),degradeGris);                                                                                             // aiguille
    addRect(QRectF(50,51,30,11), QPen(Qt::black),degradeGrisPetit);                                                                                         // rectangle en dessous de l'aiguille
    addPolygon(QPolygonF(QVector<QPointF>() << QPointF(42,62) << QPointF(24,81) << QPointF(107,81) << QPointF(88,62)), QPen(Qt::black),degradeGrisAngle);   // trapeze en dessous de l'aiguille
    addRect(QRectF(24,81,83,364), QPen(Qt::black));                                                                                                         // Rectangle sans remplissage (si couleur choisie, on ne le voit pas)
    pousseLiquide = addRect(QRectF(24,331,83,15), QPen(Qt::black),degradeGrisPousseLiquide);                                                                // Rectangle qui pousse le liquide
    tigePousseLiquide = addRect(QRectF(58,346,15,99), QPen(Qt::black),degradeGrisTigePousseLiquide);                                                        // Tige qui pousse le rectangle qui pousse le liquide
    addRect(QRectF(6,445,118,10), QPen(Qt::black),degradeGrisTigePousseLiquideBas);                                                                         // Rectangle en bout de seringue

    //Initialisation parametres vue
    vue_seringue = new QGraphicsView();
    vue_seringue->setScene(this);
    vue_seringue->setObjectName("seringue");
    vue_seringue->setFixedSize(140,470);
    vue_seringue->show();

    QObject::connect(typeSeringue,SIGNAL(currentTextChanged(QString)),this,SLOT(selectionSeringue()));

}

void Seringue::ajoutNouvelleSeringue(QString nom,float volume,float surface,float longueur)
{
    nombreNouvelleSeringue = nombreNouvelleSeringue + 1;

    if(nombreNouvelleSeringue > 3)
    {
        QMessageBox::warning(NULL,"info ajout nouvelle seringue","Vous avez atteint le nombre maximal de nouvelle seringue...");
        return;
    }

    qDebug()<< "Ajout de la seringue " + nom;

    typeSeringue->addItem(nom);

    if(nombreNouvelleSeringue == 1)
    {
        volumeSeringueNewS1 = volume;
        surfaceSeringueNewS1 = surface;
        longeurSeringueNewS1 = longueur;
    }
    if(nombreNouvelleSeringue == 2)
    {
        volumeSeringueNewS2 = volume;
        surfaceSeringueNewS2 = surface;
        longeurSeringueNewS2 = longueur;
    }
    if(nombreNouvelleSeringue == 3)
    {
        volumeSeringueNewS3 = volume;
        surfaceSeringueNewS3 = surface;
        longeurSeringueNewS3 = longueur;
    }
}

void Seringue::selectionSeringue()
{
    if(typeSeringue->currentText() == "Seringue 1mL")
    {
        volumeSeringue = 1000;
        surfaceSeringue = 17.945091;
        longeurSeringue = 55.725546;
    }
    if(typeSeringue->currentText() == "Seringue 3mL")
    {
        volumeSeringue = 3000;
        surfaceSeringue = 58.901406;
        longeurSeringue = 50.932570;
    }
    if(typeSeringue->currentText() == "Seringue 5mL")
    {
        volumeSeringue = 5000;
        surfaceSeringue = 114.231136;
        longeurSeringue = 43.770903;
    }
    if(typeSeringue->currentText() == "Seringue 10mL")
    {
        volumeSeringue = 10000;
        surfaceSeringue = 165.129964;
        longeurSeringue = 60.558361;
    }
    if(typeSeringue->currentText() == "Seringue 20mL")
    {
        volumeSeringue = 20000;
        surfaceSeringue = 287.421877;
        longeurSeringue = 69.584126;
    }
    if(typeSeringue->currentText() == "Seringue 30mL")
    {
        volumeSeringue = 30000;
        surfaceSeringue = 369.836141;
        longeurSeringue = 81.117005;
    }
    if(typeSeringue->currentText() == "Seringue 50mL")
    {
        volumeSeringue = 50000;
        surfaceSeringue = 559.902497;
        longeurSeringue = 89.301263;
    }
    if(typeSeringue->currentIndex() == 7)
    {
        volumeSeringue = volumeSeringueNewS1;
        surfaceSeringue = surfaceSeringueNewS1;
        longeurSeringue = longeurSeringueNewS1;
    }
    if(typeSeringue->currentIndex() == 8)
    {
        volumeSeringue = volumeSeringueNewS2;
        surfaceSeringue = surfaceSeringueNewS2;
        longeurSeringue = longeurSeringueNewS2;
    }
    if(typeSeringue->currentIndex() == 9)
    {
        volumeSeringue = volumeSeringueNewS3;
        surfaceSeringue = surfaceSeringueNewS3;
        longeurSeringue = longeurSeringueNewS3;
    }

    volumeRestant = volumeSeringue;
    pasRectangleLiquide = tailleRectangleLiquide / (volumeSeringue);

    if(initialisation == true)
    {
        emit signalVersMiseAJourInformation(volumeRestant);
    }
}

void Seringue::choixCouleurSeringue(QString couleur)
{
    if(couleur == "jaune")
    {
        liquide = this->addRect(QRectF(24,81,83,tailleRestanteRectangleLiquide), QPen(Qt::black),degradeJaune); //Liquide
    }
    if(couleur == "bleu")
    {
        liquide = this->addRect(QRectF(24,81,83,tailleRestanteRectangleLiquide), QPen(Qt::black),degradeBleu); //Liquide
    }
}

void Seringue::creationDegradeCouleur()
{
    degradeJaune.setStart(QPointF(24,81));
    degradeJaune.setFinalStop(QPointF(108,81));
    degradeJaune.setColorAt(0,QColor(255,222,0,255));
    degradeJaune.setColorAt(0.35,QColor(178,145,8,255));
    degradeJaune.setColorAt(0.45,QColor(178,145,8,255));
    degradeJaune.setColorAt(1,QColor(255,222,0,255));

    degradeBleu.setStart(QPointF(24,81));
    degradeBleu.setFinalStop(QPointF(108,81));
    degradeBleu.setColorAt(0,QColor(41,171,226,255));
    degradeBleu.setColorAt(0.35,QColor(0,113,188,255));
    degradeBleu.setColorAt(0.45,QColor(0,113,188,255));
    degradeBleu.setColorAt(1,QColor(41,171,226,255));

    degradeGrisAngle.setStart(QPointF(31,62));
    degradeGrisAngle.setFinalStop(QPointF(108,81));
    degradeGrisAngle.setColorAt(0,QColor(242,242,242,255));
    degradeGrisAngle.setColorAt(0.35,QColor(147,147,147,255));
    degradeGrisAngle.setColorAt(0.45,QColor(147,147,147,255));
    degradeGrisAngle.setColorAt(1,QColor(242,242,242,255));

    degradeGris.setStart(QPointF(24,62));
    degradeGris.setFinalStop(QPointF(108,81));
    degradeGris.setColorAt(0,QColor(242,242,242,255));
    degradeGris.setColorAt(0.35,QColor(147,147,147,255));
    degradeGris.setColorAt(0.45,QColor(147,147,147,255));
    degradeGris.setColorAt(1,QColor(242,242,242,255));

    degradeGrisPetit.setStart(QPointF(50,51));
    degradeGrisPetit.setFinalStop(QPointF(80,51));
    degradeGrisPetit.setColorAt(0,QColor(242,242,242,255));
    degradeGrisPetit.setColorAt(0.35,QColor(147,147,147,255));
    degradeGrisPetit.setColorAt(0.45,QColor(147,147,147,255));
    degradeGrisPetit.setColorAt(1,QColor(242,242,242,255));

    degradeGrisPousseLiquide.setStart(QPointF(24,331));
    degradeGrisPousseLiquide.setFinalStop(QPointF(108,331));
    degradeGrisPousseLiquide.setColorAt(0,QColor(242,242,242,255));
    degradeGrisPousseLiquide.setColorAt(0.35,QColor(147,147,147,255));
    degradeGrisPousseLiquide.setColorAt(0.45,QColor(147,147,147,255));
    degradeGrisPousseLiquide.setColorAt(1,QColor(242,242,242,255));

    degradeGrisTigePousseLiquide.setStart(QPointF(58,346));
    degradeGrisTigePousseLiquide.setFinalStop(QPointF(73,346));
    degradeGrisTigePousseLiquide.setColorAt(0,QColor(242,242,242,255));
    degradeGrisTigePousseLiquide.setColorAt(0.40,QColor(147,147,147,255));
    degradeGrisTigePousseLiquide.setColorAt(0.45,QColor(147,147,147,255));
    degradeGrisTigePousseLiquide.setColorAt(1,QColor(242,242,242,255));

    degradeGrisTigePousseLiquideBas.setStart(QPointF(6,445));
    degradeGrisTigePousseLiquideBas.setFinalStop(QPointF(123,445));
    degradeGrisTigePousseLiquideBas.setColorAt(0,QColor(242,242,242,255));
    degradeGrisTigePousseLiquideBas.setColorAt(0.40,QColor(147,147,147,255));
    degradeGrisTigePousseLiquideBas.setColorAt(0.45,QColor(147,147,147,255));
    degradeGrisTigePousseLiquideBas.setColorAt(1,QColor(242,242,242,255));
}

void Seringue::dessinSeringue(float volumeADeplacer)
{
    qDebug()<<"Seringue::dessinSeringue";
    volumeADeplacer = volumeADeplacer * 1000;       //On multiplie par 1000 pour avoir le volume en mm3
    mouvementRectangleLiquide = pasRectangleLiquide * volumeADeplacer;        //calcul la quantité total à injecter. On multiplie par 1000 pour avoir le volume en mm3

    if(volumeADeplacer > 0)     //Si on a un volume à injecter, il est positif. Lorsqu'on injecte le volume dans la seringue diminue donc on fait une soustraction
    {
        qDebug()<<"volumeRestant";
        qDebug()<<volumeRestant;
        qDebug()<<"volumeADeplacer";
        qDebug()<<volumeADeplacer;
        if(volumeRestant >= volumeADeplacer)     //Si il reste assez de produit dans la seringue, on injecte
        {
            for(int x=0; x<mouvementRectangleLiquide; x=x+1)
            {
                    tailleRestanteRectangleLiquide = tailleRestanteRectangleLiquide - 1;
                    liquide->setRect(24,81,83,tailleRestanteRectangleLiquide);
            }
            volumeRestant = volumeRestant - volumeADeplacer;    //On met a jour le volume présent dans la seringue,
            emit signalVersMiseAJourInformation(volumeRestant);
        }
        else
        {
            QMessageBox::warning(NULL,"Info Seringue","Attention, vous n'avez pas assez de liquide pour injecter cette quantité");
            return;
        }
    }

    else if(volumeADeplacer < 0)    //Si on a un volume à aspirer, il est negatif. Lorsqu'on aspire le volume dans la seringue augmente donc on fait une addition
    {
        if( (-volumeADeplacer + volumeRestant) <= volumeSeringue)     //Si il reste assez de place dans la seringue, on injecte
        {
            for(int x=0; x<-mouvementRectangleLiquide; x=x+1)
            {
                    tailleRestanteRectangleLiquide = tailleRestanteRectangleLiquide + 1;
                    liquide->setRect(24,81,83,tailleRestanteRectangleLiquide);
            }
            volumeRestant = volumeRestant - volumeADeplacer;    //On met a jour le volume présent dans la seringue, On met un - car 'volumeADeplacer' dans ce cas est négatif et - + - = +
            emit signalVersMiseAJourInformation(volumeRestant);
        }
        else
        {
            QMessageBox::warning(NULL,"Info Seringue","Attention, place dans la seringue manquante");
            return;
        }
    }
}

void Seringue::initialisationDessinSeringue(bool pleine)
{
    qDebug()<<"Seringue::initialisation";
    if(pleine == true)
    {
        liquide->setRect(24,81,83,250);
        volumeRestant = volumeSeringue;         //Mise à jour du volume restant dans la seringue
        tailleRestanteRectangleLiquide = 250;   //Mise a jour du volume restant dans le dessin de la seringue
    }

    else if(pleine == false)
    {
        liquide->setRect(24,81,83,0);
        volumeRestant = 0;                      //Mise à jour du volume restant dans la seringue
        tailleRestanteRectangleLiquide = 0;     //Mise a jour du volume restant dans le dessin de la seringue
    }

    emit signalVersMiseAJourInformation(volumeRestant);
    qDebug()<<volumeRestant;
}

void Seringue::updateInitialisation(bool boolInitialisation)
{
    qDebug()<<"Slot_seringue::updateInitialisation";
    initialisation = boolInitialisation;
}
