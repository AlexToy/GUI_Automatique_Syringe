#ifndef PORT_SERIE_H
#define PORT_SERIE_H

#include <QWidget>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

class Port_serie : public QSerialPort
{
    Q_OBJECT
public:
    Port_serie();

public slots:
    void connexion();
    void envoie(QString trame);
    void recuperationMicroControlleurID();  //recupere le vendor_id et le product_id necessaire à la liaison avec le micro

protected:
    quint16 microControlleur_uno_vendor_id;
    quint16 microControlleur_uno_product_id;
    QString microControlleur_port_name;
    bool microControlleur_is_available;
};

#endif // PORT_SERIE_H
