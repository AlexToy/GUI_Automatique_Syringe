#include "main_windows.h"

Main_windows::Main_windows()
{
//--Créations des objets crées--//
    slot_seringue1 = new Slot_seringue;
    //Initialisation du slot_seringue 1
        slot_seringue1->seringue->choixCouleurSeringue("bleu"); //Choix couleur seringure : jaune
        slot_seringue1->seringue->canalSeringue = 'X';           //Choix canal seringue : X

    slot_seringue2 = new Slot_seringue;
    //Initialisation du slot_seringue 2
        slot_seringue2->seringue->choixCouleurSeringue("jaune"); //Choix couleur seringure : jaune
        slot_seringue2->seringue->canalSeringue = 'Y';           //Choix canal seringue : X

    panneau_controle = new Panneau_controle;
    port_serie = new Port_serie;
    initialisation = new Initialisation;
    nouvelle_seringue = new Nouvelle_seringue;

//--Créations des objets Qt--//
     zoneCentrale = new QWidget;
     layoutHPrincipal = new QHBoxLayout;
     actionConnexion = new QAction(tr("&Connexion"), this);
     actionInitSeringue = new QAction(tr("&Initialisation Seringues"), this);
     actionNouvelleSeringue = new QAction(tr("&Nouvelle Seringue"), this);
     toolBarFichier = addToolBar("Connexion");
     toolBarFichier = addToolBar("Initialisation Seringues");
     toolBarFichier = addToolBar("Nouvelle Seringue");
     toolBarFichier->addAction(actionConnexion);
     toolBarFichier->addAction(actionInitSeringue);
     toolBarFichier->addAction(actionNouvelleSeringue);

//--Mise en forme de la fenetre principale--//
     layoutHPrincipal->addLayout(slot_seringue1);        //Ajout du slot_seringue1 à la fenetre principale
     layoutHPrincipal->addLayout(slot_seringue2);        //Ajout du slot_seringue2 à la fenetre principale
     layoutHPrincipal->addLayout(panneau_controle);      //Ajout du panneau_controle à la fenetre principale


     zoneCentrale->setLayout(layoutHPrincipal);                      //Definit layoutPrincipal comme un objet
     zoneCentrale->setObjectName("fenetre");                         //Ajoute le nom "fenetre" a l'objet zoneCentrale
     setCentralWidget(zoneCentrale);                                 //Definit l'objet zoneCentrale comme fenetre principale

     //------Connexion-------//
     QWidget::connect(actionConnexion, SIGNAL(triggered(bool)), port_serie, SLOT(connexion()));
     QWidget::connect(actionInitSeringue,SIGNAL(triggered(bool)),initialisation,SLOT(open()));
     QWidget::connect(actionNouvelleSeringue, SIGNAL(triggered(bool)), nouvelle_seringue, SLOT(open()));

     QWidget::connect(slot_seringue1,SIGNAL(signalVersEnvoie(QString)),port_serie,SLOT(envoie(QString)));
     QWidget::connect(slot_seringue2,SIGNAL(signalVersEnvoie(QString)),port_serie,SLOT(envoie(QString)));
     QWidget::connect(slot_seringue1,SIGNAL(signalVersCalculNombresPas(float,float)),panneau_controle,SLOT(calculNombresPasSeringueX(float,float)));
     QWidget::connect(slot_seringue2,SIGNAL(signalVersCalculNombresPas(float,float)),panneau_controle,SLOT(calculNombresPasSeringueY(float,float)));
     QWidget::connect(slot_seringue1->seringue,SIGNAL(signalVersMiseAJourInformation(float)),panneau_controle,SLOT(miseAJourInformationsSeringueX(float)));
     QWidget::connect(slot_seringue2->seringue,SIGNAL(signalVersMiseAJourInformation(float)),panneau_controle,SLOT(miseAJourInformationsSeringueY(float)));

     QWidget::connect(initialisation,SIGNAL(signalVersUpdateInitialisation(bool)),panneau_controle,SLOT(updateInitialisation(bool)));       //Signal qui transmet la valeur de la variable initialisation
     QWidget::connect(initialisation,SIGNAL(signalVersUpdateInitialisation(bool)),slot_seringue1->seringue,SLOT(updateInitialisation(bool)));         //Signal qui transmet la valeur de la variable initialisation
     QWidget::connect(initialisation,SIGNAL(signalVersUpdateInitialisation(bool)),slot_seringue2->seringue,SLOT(updateInitialisation(bool)));         //Signal qui transmet la valeur de la variable initialisation
     QWidget::connect(initialisation,SIGNAL(signalVersInitialisationDessinSeringueX(bool)),slot_seringue1->seringue,SLOT(initialisationDessinSeringue(bool)));
     QWidget::connect(initialisation,SIGNAL(signalVersInitialisationDessinSeringueY(bool)),slot_seringue2->seringue,SLOT(initialisationDessinSeringue(bool)));

     QWidget::connect(panneau_controle->boutonEnvoyer,SIGNAL(clicked(bool)),slot_seringue1,SLOT(recuperationInfo()));
     QWidget::connect(panneau_controle->boutonEnvoyer,SIGNAL(clicked(bool)),slot_seringue2,SLOT(recuperationInfo()));
     QWidget::connect(panneau_controle,SIGNAL(signalVersEnvoie(QString)),port_serie,SLOT(envoie(QString)));
     QWidget::connect(panneau_controle,SIGNAL(signalVersDessinSeringueX(float)),slot_seringue1->seringue,SLOT(dessinSeringue(float)));
     QWidget::connect(panneau_controle,SIGNAL(signalVersDessinSeringueY(float)),slot_seringue2->seringue,SLOT(dessinSeringue(float)));

     QWidget::connect(nouvelle_seringue, SIGNAL(signalVersNouvelleSeringue(QString,float,float,float)), slot_seringue1->seringue, SLOT(ajoutNouvelleSeringue(QString,float,float,float)));
     QWidget::connect(nouvelle_seringue, SIGNAL(signalVersNouvelleSeringue(QString,float,float,float)), slot_seringue2->seringue, SLOT(ajoutNouvelleSeringue(QString,float,float,float)));

     loadStyleSheet();
}

void Main_windows::loadStyleSheet()
{
    QFile file(":/qss/coffee.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());
    qApp->setStyleSheet(styleSheet);
}
