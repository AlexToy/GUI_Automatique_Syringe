#include <QApplication>
#include <QtWidgets>
#include "main_windows.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Main_windows fenetre;
    QSplashScreen *splash_screen = new QSplashScreen;
    QTimer *timer = new QTimer;

    timer->setInterval(5000);
    timer->start();

    splash_screen->setPixmap(QPixmap("/Users/alexandreharistoy/Documents/QtProgram/GUI_Automatique_Syringe/S\&Thingva.png"));
    splash_screen->show();

    QObject::connect(timer,SIGNAL(timeout()),splash_screen,SLOT(close()));
    QObject::connect(timer,SIGNAL(timeout()),&fenetre,SLOT(show()));

    return app.exec();
}
