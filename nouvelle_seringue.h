#ifndef NOUVELLE_SERINGUE_H
#define NOUVELLE_SERINGUE_H

#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>

class Nouvelle_seringue : public QDialog
{
    Q_OBJECT
public:
    Nouvelle_seringue();

private:
    QLabel *labelNomSeringue;
    QLabel *labelVolumeSeringue;
    QLabel *labelSurfaceSeringue;
    QLabel *labelLongueurSeringue;
    QLineEdit *nomSeringue;
    QLineEdit *volumeSeringue;
    QLineEdit *surfaceSeringue;
    QLineEdit *longueurSeringue;
    QGridLayout *layout;
    QPushButton *boutonValider;
    QPushButton *boutonAnnuler;

public slots:
    void valider();

signals:
    void signalVersNouvelleSeringue(QString nomSeringue, float volumeSeringue, float surfaceSeringue, float longueurSeringue);
};

#endif // NOUVELLE_SERINGUE_H
