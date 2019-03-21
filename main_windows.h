#ifndef MAIN_WINDOWS_H
#define MAIN_WINDOWS_H

#include <QMainWindow>
#include <QLayout>
#include <QToolBar>
#include <QtWidgets>
#include "slot_seringue.h"
#include "panneau_controle.h"
#include "port_serie.h"
#include "initialisation.h"
#include "nouvelle_seringue.h"

class Main_windows : public QMainWindow
{
    Q_OBJECT
public:
    Main_windows();

    //Declarations des objets crées
    Slot_seringue *slot_seringue1;
    Slot_seringue *slot_seringue2;
    Panneau_controle *panneau_controle;
    Port_serie *port_serie;
    Initialisation *initialisation;
    Nouvelle_seringue *nouvelle_seringue;

    //Déclarations des objets Qt
    QHBoxLayout *layoutHPrincipal;
    QWidget *zoneCentrale;
    QAction *actionConnexion;
    QAction *actionInitSeringue;
    QAction *actionNouvelleSeringue;
    QToolBar *toolBarFichier;

private:
    void loadStyleSheet();
};

#endif // MAIN_WINDOWS_H
