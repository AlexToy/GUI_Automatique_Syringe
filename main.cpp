#include <QApplication>
#include <QtWidgets>
#include "main_windows.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Main_windows fenetre;
    fenetre.show();

    return app.exec();
}
