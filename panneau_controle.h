#ifndef PANNEAU_CONTROLE_H
#define PANNEAU_CONTROLE_H

#include <QLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>
#include <QDoubleValidator>

class Panneau_controle : public QVBoxLayout
{
    Q_OBJECT
public:
    Panneau_controle();

    QLineEdit *infoVolumeX;
    QLineEdit *infoVolumeY;
    QLineEdit *infoVitesseX;
    QLineEdit *infoVitesseY;

    QLineEdit *actionInjecterX;
    QLineEdit *actionInjecterY;
    QLineEdit *actionAspirerX;
    QLineEdit *actionAspirerY;
    QLineEdit *actionVitesseX;
    QLineEdit *actionVitesseY;

    QPushButton *boutonEnvoyer;

private:
    QLabel *labelInfoVolumeX;
    QLabel *labelInfoVolumeY;
    QLabel *labelInfoVitesseX;
    QLabel *labelInfoVitesseY;

    QLabel *labelActionInjecterX;
    QLabel *labelActionInjecterY;
    QLabel *labelActionAspirerX;
    QLabel *labelActionAspirerY;
    QLabel *labelActionVitesseX;
    QLabel *labelActionVitesseY;

    QVBoxLayout *layoutInfoX;
    QVBoxLayout *layoutInfoY;
    QVBoxLayout *layoutActionX;
    QVBoxLayout *layoutActionY;

    QHBoxLayout *layoutInfo;
    QHBoxLayout *layoutAction;
    QVBoxLayout *layoutBoutonEtLayoutAction;

    QGroupBox *boxInfo;
    QGroupBox *boxAction;

    QDoubleValidator *validator;

    float distanceInjecterX = 0;
    float distanceAspirerX = 0;
    float distanceInjecterY = 0;
    float distanceAspirerY = 0;

    float volumeSeringueX = 0;
    float volumeSeringueY = 0;

    bool calculEffectueX = false;
    bool calculEffectueY = false;

    bool initialisation = false;

public slots:
    void generationTrame();
    void calculNombresPasSeringueX(float surfaceSeringueX, float volumeSeringue);
    void calculNombresPasSeringueY(float surfaceSeringueY, float volumeSeringue);
    void updateInitialisation(bool boolInitialisation);
    void miseAJourInformationsSeringueX(float volume);
    void miseAJourInformationsSeringueY(float volume);

signals:
    void signalVersEnvoie(QString trame);
    void signalVersGenerationTrame();
    void signalVersDessinSeringueX(float volumeADeplacer);
    void signalVersDessinSeringueY(float volumeADeplacer);

};

#endif // PANNEAU_CONTROLE_H
