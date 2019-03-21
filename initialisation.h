#ifndef INITIALISATION_H
#define INITIALISATION_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QLayout>
#include <QPushButton>
#include <QDebug>

class Initialisation : public QDialog
{
    Q_OBJECT
public:
    Initialisation();

private:
    QLabel *labelSeringueA;
    QLabel *labelSeringueB;
    QComboBox *comboBoxSeringueA;
    QComboBox *comboBoxSeringueB;
    QVBoxLayout *layoutSeringueA;
    QVBoxLayout *layoutSeringueB;
    QVBoxLayout *layout;
    QHBoxLayout *layoutSeringueAetSeringueB;
    QHBoxLayout *layoutBoutons;
    QPushButton *boutonValider;
    QPushButton *boutonAnnuler;

    bool initialisation = false;


private slots:
    void valider();

signals:
    void signalVersUpdateInitialisation(bool initialisation);
    void signalVersInitialisationDessinSeringueX(bool pleine);
    void signalVersInitialisationDessinSeringueY(bool pleine);

};

#endif // INITIALISATION_H
