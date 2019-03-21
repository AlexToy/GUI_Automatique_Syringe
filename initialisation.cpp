#include "initialisation.h"

Initialisation::Initialisation()
{
//---Creation des objets---//
    labelSeringueA = new QLabel("Initialisation seringue A");
    labelSeringueB = new QLabel("Initialisation seringue B");

    comboBoxSeringueA = new QComboBox;
    comboBoxSeringueA->addItem("Pleine");
    comboBoxSeringueA->addItem("Vide");

    comboBoxSeringueB = new QComboBox;
    comboBoxSeringueB->addItem("Pleine");
    comboBoxSeringueB->addItem("Vide");

    boutonValider = new QPushButton("Valider");
    boutonAnnuler = new QPushButton("Annuler");

//---Mise en forme de la QDialog---//
    layoutSeringueA = new QVBoxLayout;
    layoutSeringueA->addWidget(labelSeringueA);
    layoutSeringueA->addWidget(comboBoxSeringueA);

    layoutSeringueB = new QVBoxLayout;
    layoutSeringueB->addWidget(labelSeringueB);
    layoutSeringueB->addWidget(comboBoxSeringueB);

    layoutSeringueAetSeringueB = new QHBoxLayout;
    layoutSeringueAetSeringueB->addLayout(layoutSeringueA);
    layoutSeringueAetSeringueB->addLayout(layoutSeringueB);

    layoutBoutons = new QHBoxLayout;
    layoutBoutons->addWidget(boutonValider);
    layoutBoutons->addWidget(boutonAnnuler);

    layout = new QVBoxLayout;
    layout->addLayout(layoutSeringueAetSeringueB);
    layout->addLayout(layoutBoutons);

    setLayout(layout);


//---Connections---//
    QObject::connect(boutonValider,SIGNAL(clicked(bool)),this,SLOT(valider()));
    QObject::connect(boutonAnnuler,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void Initialisation::valider()
{
    qDebug()<<"Initialisation::valider";
    initialisation = true;
    emit signalVersUpdateInitialisation(initialisation);

    if(comboBoxSeringueA->currentText() == "Pleine")
    {
       emit signalVersInitialisationDessinSeringueX(true);
    }

    if(comboBoxSeringueA->currentText() == "Vide")
    {
       emit signalVersInitialisationDessinSeringueX(false);
    }

    if(comboBoxSeringueB->currentText() == "Pleine")
    {
       emit signalVersInitialisationDessinSeringueY(true);
    }

    if(comboBoxSeringueB->currentText() == "Vide")
    {
       emit signalVersInitialisationDessinSeringueY(false);
    }
    close();
}
