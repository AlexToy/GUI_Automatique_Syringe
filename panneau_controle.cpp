#include "panneau_controle.h"

Panneau_controle::Panneau_controle()
{
    validator = new QDoubleValidator(0, 1000, 3, this);
    validator->setLocale(QLocale::C);   //Ajoute le . dans les nombres à virgule

    //---Creation des objets---//
    infoVolumeX = new QLineEdit("--");
    infoVolumeX->setReadOnly(1);
    infoVolumeY = new QLineEdit("--");
    infoVolumeY->setReadOnly(1);
    infoVitesseX = new QLineEdit("--");
    infoVitesseX->setReadOnly(1);
    infoVitesseY = new QLineEdit("--");
    infoVitesseY->setReadOnly(1);

    actionInjecterX = new QLineEdit("0");
    actionInjecterX->setValidator(validator);
    actionInjecterY = new QLineEdit("0");
    actionInjecterY->setValidator(validator);
    actionAspirerX = new QLineEdit("0");
    actionAspirerX->setValidator(validator);
    actionAspirerY = new QLineEdit("0");
    actionAspirerY->setValidator(validator);
    actionVitesseX = new QLineEdit("0");
    actionVitesseX->setValidator(validator);
    actionVitesseY = new QLineEdit("0");
    actionVitesseY->setValidator(validator);

    labelInfoVolumeX = new QLabel("Volume (mL)");
    labelInfoVolumeY = new QLabel("Volume (mL)");
    labelInfoVitesseX = new QLabel("Vitesse (mm/s)");
    labelInfoVitesseY = new QLabel("Vitesse (mm/s)");

    labelActionInjecterX = new QLabel("Injecter (mL)");
    labelActionInjecterY = new QLabel("Injecter (mL)");
    labelActionAspirerX = new QLabel("Aspirer (mL)");
    labelActionAspirerY = new QLabel("Aspirer (mL)");
    labelActionVitesseX = new QLabel("Vitesse (mm/s)");
    labelActionVitesseY = new QLabel("Vitesse (mm/s)");

    layoutInfoX = new QVBoxLayout;
    layoutInfoY = new QVBoxLayout;
    layoutActionX = new QVBoxLayout;
    layoutActionY = new QVBoxLayout;

    layoutInfo = new QHBoxLayout;
    layoutAction = new QHBoxLayout;
    layoutBoutonEtLayoutAction = new QVBoxLayout;

    boxInfo = new QGroupBox("Informations");
    boxInfo->setFixedHeight(220);       //limite la taille du GroupBox Info en hauteur
    boxInfo->setObjectName("box");
    boxAction = new QGroupBox("Actions");
    boxAction->setObjectName("box");

    boutonEnvoyer = new QPushButton("ENVOYER");


//-----------Mise en page des elements du panneau de controle----------//

    //----Panneau Information----//
    layoutInfoX->addWidget(labelInfoVolumeX);
    layoutInfoX->addWidget(infoVolumeX);
    layoutInfoX->addWidget(labelInfoVitesseX);
    layoutInfoX->addWidget(infoVitesseX);

    layoutInfoY->addWidget(labelInfoVolumeY);
    layoutInfoY->addWidget(infoVolumeY);
    layoutInfoY->addWidget(labelInfoVitesseY);
    layoutInfoY->addWidget(infoVitesseY);

    layoutInfo->addLayout(layoutInfoX);
    layoutInfo->addLayout(layoutInfoY);

    boxInfo->setLayout(layoutInfo);

    //----Panneau Action----//
    layoutActionX->addWidget(labelActionInjecterX);
    layoutActionX->addWidget(actionInjecterX);
    layoutActionX->addWidget(labelActionAspirerX);
    layoutActionX->addWidget(actionAspirerX);
    layoutActionX->addWidget(labelActionVitesseX);
    layoutActionX->addWidget(actionVitesseX);

    layoutActionY->addWidget(labelActionInjecterY);
    layoutActionY->addWidget(actionInjecterY);
    layoutActionY->addWidget(labelActionAspirerY);
    layoutActionY->addWidget(actionAspirerY);
    layoutActionY->addWidget(labelActionVitesseY);
    layoutActionY->addWidget(actionVitesseY);

    layoutAction->addLayout(layoutActionX);
    layoutAction->addLayout(layoutActionY);

    layoutBoutonEtLayoutAction->addLayout(layoutAction);
    layoutBoutonEtLayoutAction->addWidget(boutonEnvoyer);

    boxAction->setLayout(layoutBoutonEtLayoutAction);

    addWidget(boxInfo);
    addWidget(boxAction);

    QWidget::connect(this,SIGNAL(signalVersGenerationTrame()),this,SLOT(generationTrame()));

}

void Panneau_controle::calculNombresPasSeringueX(float surfaceSeringueX, float volumeSeringue)
{
    qDebug()<< "Fonction calculX";
    distanceInjecterX = actionInjecterX->text().toFloat() * 1000 / surfaceSeringueX;  //on multiplie pas 1000 pour passer en mm3
    distanceAspirerX = actionAspirerX->text().toFloat() * 1000 / surfaceSeringueX;  //on multiplie pas 1000 pour passer en mm3

    volumeSeringueX = volumeSeringue;

    calculEffectueX = true;
}

void Panneau_controle::calculNombresPasSeringueY(float surfaceSeringueY, float volumeSeringue)
{
    qDebug()<< "Fonction calculY";

    distanceInjecterY = actionInjecterY->text().toFloat() * 1000 / surfaceSeringueY;
    distanceAspirerY = actionAspirerY->text().toFloat() * 1000 / surfaceSeringueY;

    volumeSeringueY = volumeSeringue;

    calculEffectueY = true;

    if(calculEffectueX == true && calculEffectueY == true)
    {
        emit signalVersGenerationTrame();
    }
}

void Panneau_controle::generationTrame()
{
    QString trame = "G00";

//------------------Recuperation de la trame pour la seringue X--------------------//
    if(actionInjecterX->text().toFloat() != 0 || actionAspirerX->text().toFloat() != 0)     //Si les deux champs ne sont pas à 0 on continue
    {
            if(actionVitesseX->text().toFloat() != 0)       //Si la vitesse n'est pas a 0 on continue
            {
                if((actionInjecterX->text().toFloat() * 1000) <= volumeSeringueX && (actionAspirerX->text().toFloat() * 1000) <= volumeSeringueX)     //Si le volume a injecter ou aspirer est inferieur au volume de la seringue on continue
                {
                    if(actionInjecterX->text().toFloat() != 0 && actionAspirerX->text().toFloat() == 0)
                    {                      
                        trame = trame + " X" + QString::number(distanceInjecterX) + " F" + actionVitesseX->text();
                        if(initialisation == true)      //Si l'initialisation a ete faite on dessine sur la seringue
                        {
                            qDebug()<<"signalVersDessin";
                            emit signalVersDessinSeringueX(actionInjecterX->text().toFloat());
                        }
                    }

                    else if(actionInjecterX->text().toFloat() == 0 && actionAspirerX->text().toFloat() != 0)
                    {
                        trame = trame + " X-" + QString::number(distanceAspirerX) + " F" + actionVitesseX->text(); //Ajout du '-' pour Aspirer
                        if(initialisation == true)
                        {
                            emit signalVersDessinSeringueX(-actionAspirerX->text().toFloat());
                        }
                    }
                    else
                    {
                        QMessageBox::warning(NULL,"Info Seringue X","Attention, vous avez rempli les deux champs Injecter et Aspirer");
                        return;
                    }
                }
                else
                {
                    QMessageBox::warning(NULL,"Info Seringue X","Attention, votre volume de seringue X ne correspond pas");
                    return;
                }
            }
            else
            {
                QMessageBox::warning(NULL,"Info Seringue X","Attention, vous n'avez entré aucune vitesse pour la seringue X");
                return;
            }
    }

//------------------Recuperation de la trame pour la seringue Y--------------------//
    if(actionInjecterY->text().toFloat() != 0 || actionAspirerY->text().toFloat() != 0)
    {
            if(actionVitesseY->text().toFloat() != 0)
            {
                if((actionInjecterY->text().toFloat() * 1000) <= volumeSeringueY && (actionAspirerY->text().toFloat() * 1000) <= volumeSeringueY)
                {
                    if(actionInjecterY->text().toFloat() != 0 && actionAspirerY->text().toFloat() == 0)
                    {
                        trame = trame + " Y" + QString::number(distanceInjecterY) + " F" + actionVitesseY->text();
                        if(initialisation == true)
                        {
                            emit signalVersDessinSeringueY(actionInjecterY->text().toFloat());
                        }
                    }

                    else if(actionInjecterY->text().toFloat() == 0 && actionAspirerY->text().toFloat() != 0)
                    {
                        trame = trame + " Y-" + QString::number(distanceAspirerY) + " F" + actionVitesseY->text(); //Ajout du '-' pour Aspirer
                        if(initialisation == true)
                        {
                            emit signalVersDessinSeringueY(-actionAspirerY->text().toFloat());
                        }
                    }
                    else
                    {
                        QMessageBox::warning(NULL,"Info Seringue Y","Attention, vous avez rempli les deux champs Injecter et Aspirer");
                        return;
                    }
                }
                else
                {
                    QMessageBox::warning(NULL,"Info Seringue Y","Attention, votre volume de seringue Y ne correspond pas");
                    return;
                }
            }
            else
            {
            QMessageBox::warning(NULL,"Info Seringue Y","Attention, vous n'avez entré aucune vitesse pour la seringue Y");
            return;
            }
    }

//---Ecriture et transmission de la trame seringue à la fonction envoie (class Port_serie) en passant par Main_windows---//
    emit signalVersEnvoie(trame);
}

void Panneau_controle::miseAJourInformationsSeringueX(float volume)
{
    infoVolumeX->setText(QString::number(volume/1000));
}

void Panneau_controle::miseAJourInformationsSeringueY(float volume)
{
    infoVolumeY->setText(QString::number(volume/1000));
}

void Panneau_controle::updateInitialisation(bool boolInitialisation)
{
    qDebug()<<"Panneau_controle::updateInitialisation";
    initialisation = boolInitialisation;
    qDebug()<<initialisation;
}
