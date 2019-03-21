#include "nouvelle_seringue.h"

Nouvelle_seringue::Nouvelle_seringue()
{
    labelNomSeringue = new QLabel("Nom seringue :");
    labelVolumeSeringue = new QLabel("Volume seringue (mL) :");     //Demande du volume en mL puis convertie en mm3 avant envoie de la variable a la fonction seringue
    labelSurfaceSeringue = new QLabel("Surface seringue (mm2) :");
    labelLongueurSeringue = new QLabel("Longueur seringue (mm) :");

    nomSeringue = new QLineEdit();
    volumeSeringue = new QLineEdit();
    surfaceSeringue = new QLineEdit();
    longueurSeringue = new QLineEdit();

    boutonAnnuler = new QPushButton("Annuler");
    boutonValider = new QPushButton("Valider");

    layout = new QGridLayout;

    layout->addWidget(labelNomSeringue,1,0);
    layout->addWidget(labelVolumeSeringue,2,0);
    layout->addWidget(labelSurfaceSeringue,3,0);
    layout->addWidget(labelLongueurSeringue,4,0);
    layout->addWidget(nomSeringue,1,1);
    layout->addWidget(volumeSeringue,2,1);
    layout->addWidget(surfaceSeringue,3,1);
    layout->addWidget(longueurSeringue,4,1);
    layout->addWidget(boutonValider,5,0);
    layout->addWidget(boutonAnnuler,5,1);

    setLayout(layout);

//---Connections---//
    QObject::connect(boutonValider,SIGNAL(clicked(bool)),this,SLOT(valider()));
    QObject::connect(boutonAnnuler,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void Nouvelle_seringue::valider()
{
    if(!nomSeringue->text().isEmpty())
    {
        if(!volumeSeringue->text().isEmpty())
        {
            if(!surfaceSeringue->text().isEmpty())
            {
                if(!longueurSeringue->text().isEmpty())
                {
                    emit signalVersNouvelleSeringue(nomSeringue->text(), volumeSeringue->text().toFloat()*1000, surfaceSeringue->text().toFloat(), longueurSeringue->text().toFloat());
                    close();
                }
                else
                {
                    QMessageBox::warning(NULL,"Info ajout d'une nouvelle seringue","Attention, n'avez pas saisi la longueur de votre nouvelle seringue !");
                }
            }
            else
            {
                QMessageBox::warning(NULL,"Info ajout d'une nouvelle seringue","Attention, n'avez pas saisi la surface de votre nouvelle seringue !");
            }
        }
        else
        {
            QMessageBox::warning(NULL,"Info ajout d'une nouvelle seringue","Attention, n'avez pas saisi le volume de votre nouvelle seringue !");
        }

    }
    else
    {
        QMessageBox::warning(NULL,"Info ajout d'une nouvelle seringue","Attention, n'avez pas saisi le nom de votre nouvelle seringue !");
    }

}
