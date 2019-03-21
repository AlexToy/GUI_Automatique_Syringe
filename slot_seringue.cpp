#include "slot_seringue.h"
#include <QGraphicsRectItem>

Slot_seringue::Slot_seringue()
{
    //créations des objets crées
    voie1 = new Voie1;
    voie2 = new Voie2;
    voie3 = new Voie3;
    seringue = new Seringue;
    flecheHaut = new FlecheHaut;
    flecheBas = new FlecheBas;

    //Créations des objets Qt
    layoutVoies = new QHBoxLayout;
    layoutText = new QHBoxLayout;
    layoutFlechesSeringueVoies = new QHBoxLayout;
    layoutFleches = new QVBoxLayout;
    layoutSeringueVoies = new QVBoxLayout;
    lineEditPas = new QLineEdit;
    labelPas = new QLabel;

    //Configuration des widgets
    labelPas->setText("Pas (mL) :");
    labelPas->setObjectName("labelPas");
    lineEditPas->setText("1");
    lineEditPas->setObjectName("linePas");
    lineEditPas->setFixedWidth(20);

    //Mise en page des éléments du slot_seringue

    //---Création layout contenant les trois voies--//
    layoutVoies->addWidget(voie1->vue_voie1);
    layoutVoies->addWidget(voie2->vue_voie2);
    layoutVoies->addWidget(voie3->vue_voie3);

    //---Création layout du texte pas---//
    layoutText->addWidget(labelPas);
    layoutText->addWidget(lineEditPas);

    //---Création layout contenant les deux fleches--//
    layoutFleches->addWidget(flecheHaut->vue_flecheHaut,1,Qt::AlignBottom);
    layoutFleches->addLayout(layoutText);
    layoutFleches->addWidget(flecheBas->vue_flecheBas,1,Qt::AlignTop);

    //---Création layout contenant le layout fleche et la seringue--//
    layoutSeringueVoies->addLayout(layoutVoies);
    layoutSeringueVoies->addWidget(seringue->vue_seringue,0,Qt::AlignHCenter);

     //---Création layout contenant le layout fleche, seringue et typeSeringue--//
    layoutFlechesSeringueVoies->addLayout(layoutFleches);
    layoutFlechesSeringueVoies->addLayout(layoutSeringueVoies);

    addLayout(layoutFlechesSeringueVoies);
    addWidget(seringue->typeSeringue);

    QWidget::connect(voie1,SIGNAL(signalVersClicVoie1()),this,SLOT(clicVoie1()));   //Signal envoyé par voie1
    QWidget::connect(voie2,SIGNAL(signalVersClicVoie2()),this,SLOT(clicVoie2()));   //Signal envoyé par voie2
    QWidget::connect(voie3,SIGNAL(signalVersClicVoie3()),this,SLOT(clicVoie3()));   //Signal envoyé par voie3
    QWidget::connect(flecheHaut,SIGNAL(signalVersClicFlecheHaut()),this,SLOT(clicFlecheHaut())); //Signal envoyé par Fleche haut
    QWidget::connect(flecheBas,SIGNAL(signalVersClicFlecheBas()),this,SLOT(clicFlecheBas())); //Signal envoyé par Fleche bas

    QWidget::connect(this,SIGNAL(signalVersDessinSeringue(float)),seringue,SLOT(dessinSeringue(float)));
}

void Slot_seringue::clicVoie1()
{
    qDebug()<<"clicVoie1";
    QString trameVoie;
//---grise la voie1 selectionnées et remet en blanc les deux autres---//
    voie1->vue_voie1->setStyleSheet("background-color: #EFEFEF");
    voie1->addPolygon(voie1->fluide,QPen(Qt::black),QColor("#303030"));
    voie1->addPolygon(voie1->ligne_superieur,QPen("#303030"));
    voie1->addPolygon(voie1->ligne_horizontal_inferieur_gauche,QPen("#303030"));
    voie1->addPolygon(voie1->ligne_oblique_inferieur_gauche,QPen("#303030"));
    voie1->addPolygon(voie1->ligne_vertical_inferieur_gauche,QPen("#303030"));
    voie1->addPolygon(voie1->ligne_horizontal_inferieur_droit,QPen("#303030"));
    voie1->addPolygon(voie1->ligne_oblique_inferieur_droit,QPen("#303030"));
    voie1->addPolygon(voie1->ligne_vertical_inferieur_droit,QPen("#303030"));

    voie2->vue_voie2->setStyleSheet("background-color: #303030");
    voie2->addPolygon(voie2->fluide,QPen(Qt::black),QColor("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_superieur,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_horizontal_inferieur_gauche,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_oblique_inferieur_gauche,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_vertical_inferieur_gauche,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_horizontal_inferieur_droit,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_oblique_inferieur_droit,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_vertical_inferieur_droit,QPen("#EFEFEF"));

    voie3->vue_voie3->setStyleSheet("background-color: #303030");
    voie3->addPolygon(voie3->fluide,QPen(Qt::black),QColor("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_superieur,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_horizontal_inferieur_gauche,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_oblique_inferieur_gauche,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_vertical_inferieur_gauche,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_horizontal_inferieur_droit,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_oblique_inferieur_droit,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_vertical_inferieur_droit,QPen("#EFEFEF"));

//---Ecriture et transmission de la trame voie à la fonction envoie (class Port_serie) en passant par Main_windows---//
    if(seringue->canalSeringue == 'X')
    {
        trameVoie = "M121";
    }
    else if(seringue->canalSeringue == 'Y')
    {
        trameVoie = "N121";
    }

    emit signalVersEnvoie(trameVoie);
}

void Slot_seringue::clicVoie2()
{
    qDebug()<<"clicVoie2";
    QString trameVoie;
//---grise la voie2 selectionnées et remet en blanc les deux autres---//
    voie1->vue_voie1->setStyleSheet("background-color: #303030");
    voie1->addPolygon(voie1->fluide,QPen(Qt::black),QColor("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_superieur,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_horizontal_inferieur_gauche,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_oblique_inferieur_gauche,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_vertical_inferieur_gauche,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_horizontal_inferieur_droit,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_oblique_inferieur_droit,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_vertical_inferieur_droit,QPen("#EFEFEF"));

    voie2->vue_voie2->setStyleSheet("background-color: #EFEFEF");
    voie2->addPolygon(voie2->fluide,QPen(Qt::black),QColor("#303030"));
    voie2->addPolygon(voie2->ligne_superieur,QPen("#303030"));
    voie2->addPolygon(voie2->ligne_horizontal_inferieur_gauche,QPen("#303030"));
    voie2->addPolygon(voie2->ligne_oblique_inferieur_gauche,QPen("#303030"));
    voie2->addPolygon(voie2->ligne_vertical_inferieur_gauche,QPen("#303030"));
    voie2->addPolygon(voie2->ligne_horizontal_inferieur_droit,QPen("#303030"));
    voie2->addPolygon(voie2->ligne_oblique_inferieur_droit,QPen("#303030"));
    voie2->addPolygon(voie2->ligne_vertical_inferieur_droit,QPen("#303030"));

    voie3->vue_voie3->setStyleSheet("background-color: #303030");
    voie3->addPolygon(voie3->fluide,QPen(Qt::black),QColor("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_superieur,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_horizontal_inferieur_gauche,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_oblique_inferieur_gauche,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_vertical_inferieur_gauche,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_horizontal_inferieur_droit,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_oblique_inferieur_droit,QPen("#EFEFEF"));
    voie3->addPolygon(voie3->ligne_vertical_inferieur_droit,QPen("#EFEFEF"));

//---Ecriture et transmission de la trame voie à la fonction envoie (class Port_serie) en passant par Main_windows---//
    if(seringue->canalSeringue == 'X')
    {
        trameVoie = "M122";
    }
    else if(seringue->canalSeringue == 'Y')
    {
        trameVoie = "N122";
    }

    emit signalVersEnvoie(trameVoie);
}

void Slot_seringue::clicVoie3()
{
    qDebug()<<"clicVoie3";
    QString trameVoie;
//---grise la voie3 selectionnées et remet en blanc les deux autres---//
    voie1->vue_voie1->setStyleSheet("background-color: #303030");
    voie1->addPolygon(voie1->fluide,QPen(Qt::black),QColor("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_superieur,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_horizontal_inferieur_gauche,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_oblique_inferieur_gauche,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_vertical_inferieur_gauche,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_horizontal_inferieur_droit,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_oblique_inferieur_droit,QPen("#EFEFEF"));
    voie1->addPolygon(voie1->ligne_vertical_inferieur_droit,QPen("#EFEFEF"));

    voie2->vue_voie2->setStyleSheet("background-color: #303030");
    voie2->addPolygon(voie2->fluide,QPen(Qt::black),QColor("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_superieur,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_horizontal_inferieur_gauche,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_oblique_inferieur_gauche,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_vertical_inferieur_gauche,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_horizontal_inferieur_droit,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_oblique_inferieur_droit,QPen("#EFEFEF"));
    voie2->addPolygon(voie2->ligne_vertical_inferieur_droit,QPen("#EFEFEF"));

    voie3->vue_voie3->setStyleSheet("background-color: #EFEFEF");
    voie3->addPolygon(voie3->fluide,QPen(Qt::black),QColor("#303030"));
    voie3->addPolygon(voie3->ligne_superieur,QPen("#303030"));
    voie3->addPolygon(voie3->ligne_horizontal_inferieur_gauche,QPen("#303030"));
    voie3->addPolygon(voie3->ligne_oblique_inferieur_gauche,QPen("#303030"));
    voie3->addPolygon(voie3->ligne_vertical_inferieur_gauche,QPen("#303030"));
    voie3->addPolygon(voie3->ligne_horizontal_inferieur_droit,QPen("#303030"));
    voie3->addPolygon(voie3->ligne_oblique_inferieur_droit,QPen("#303030"));
    voie3->addPolygon(voie3->ligne_vertical_inferieur_droit,QPen("#303030"));

//---Ecriture et transmission de la trame voie à la fonction envoie (class Port_serie) en passant par Main_windows---//
    if(seringue->canalSeringue == 'X')
    {
        trameVoie = "M123";
    }
    else if(seringue->canalSeringue == 'Y')
    {
        trameVoie = "N123";
    }

    emit signalVersEnvoie(trameVoie);
}

void Slot_seringue::clicFlecheHaut()
{
//---Ecriture est transmission de la trame du mode pas à pas (Fleche bas prend le signe "+" pour faire pousser la seringue---//
    QString trameSeringue;
    if(seringue->canalSeringue == 'X')
    {   
        flecheHaut->addPolygon(flecheHaut->fleche,QPen(Qt::black),QColor("#EFEFEF"));   //Redessine le bouton par defaut une fois le moussePress laché
        flecheHaut->vue_flecheHaut->setStyleSheet("background-color: #303030");         //Redessine le bouton par defaut une fois le moussePress laché

        trameSeringue = trameSeringue + "G00" + " X" + lineEditPas->text() + " F20";  //Attention, ici la vitesse est fixée dans le code en brute

        if(seringue->initialisation == true)      //On dessine si l'initialisation a ete faite
        {
            emit signalVersDessinSeringue(lineEditPas->text().toFloat());
        }
    }
    else if(seringue->canalSeringue == 'Y')
    {
        flecheHaut->addPolygon(flecheHaut->fleche,QPen(Qt::black),QColor("#EFEFEF"));   //Redessine le bouton par defaut une fois le moussePress laché
        flecheHaut->vue_flecheHaut->setStyleSheet("background-color: #303030");         //Redessine le bouton par defaut une fois le moussePress laché

        trameSeringue = trameSeringue + "G00" + " Y" + lineEditPas->text() + " F20";  //Attention, ici la vitesse est fixée dans le code en brute

        if(seringue->initialisation == true)//On dessine si l'initialisation a ete faite
        {
            emit signalVersDessinSeringue(lineEditPas->text().toFloat());
        }
    }
//---La trame est envoyée a la fonction envoie (class Port_serie) en passant par Main_windows---//
    emit signalVersEnvoie(trameSeringue);
}

void Slot_seringue::clicFlecheBas()
{
//---Ecriture est transmission de la trame du mode pas à pas (Fleche bas prend le signe "-" pour faire aspirer la seringue---//
    QString trameSeringue;
    if(seringue->canalSeringue == 'X')
    {
        flecheBas->addPolygon(flecheBas->fleche,QPen(Qt::black),QColor("#EFEFEF"));     //Redessine le bouton par defaut une fois le moussePress laché
        flecheBas->vue_flecheBas->setStyleSheet("background-color: #303030");           //Redessine le bouton par defaut une fois le moussePress laché

        trameSeringue = trameSeringue + "G00" + " X-" + lineEditPas->text() + " F20";  //Attention, ici la vitesse est fixée dans le code en brute

        if(seringue->initialisation == true)//On dessine si l'initialisation a ete faite
        {
            emit signalVersDessinSeringue(-lineEditPas->text().toFloat());
        }
    }
    else if(seringue->canalSeringue == 'Y')
    {
        flecheBas->addPolygon(flecheBas->fleche,QPen(Qt::black),QColor("#EFEFEF"));     //Redessine le bouton par defaut une fois le moussePress laché
        flecheBas->vue_flecheBas->setStyleSheet("background-color: #303030");           //Redessine le bouton par defaut une fois le moussePress laché

        trameSeringue = trameSeringue + "G00" + " Y-" + lineEditPas->text() + " F20";  //Attention, ici la vitesse est fixée dans le code en brute

        if(seringue->initialisation == true)//On dessine si l'initialisation a ete faite
        {
            emit signalVersDessinSeringue(-lineEditPas->text().toFloat());
        }
    }
//---La trame est envoyée a la fonction envoie (class Port_serie) en passant par Main_windows---//
    emit signalVersEnvoie(trameSeringue);
}

void Slot_seringue::recuperationInfo()
{
    qDebug()<< "Fonction RecuperationInfo";
    emit signalVersCalculNombresPas(seringue->surfaceSeringue, seringue->volumeSeringue); //Envoie la surface de la seringue a la fonction dans panneau de contorle qui calcul le nombre de pas
}
