   #include "port_serie.h"

Port_serie::Port_serie()
{

}

void Port_serie::envoie(QString trame)
{
    qDebug()<< trame;
    if(this != NULL )
    {
        qDebug()<< "Start transmission";
        QByteArray byteSend; //byte a envoyer
        QByteArray byteReceive; //byte a envoyer
        //QString textReceive; //byte a envoyer
        qint64 bw = 0; //bytes really writen

        byteSend.clear(); // on efface le contenu de byte
        byteSend.append(trame); // on ajoute "value" a byte
        byteSend.append("\n"); // On ajoute le retour a la lgine

        if(this->isWritable())      // on vérifie qu'on peut ecrire dans le 'fichier'
        {
            bw = this->write(byteSend); // on écrit les byte | //(bw récupere le nombre de byte écris)
            qDebug() << bw << "byte(s) written | Value sent:" << trame ;

            if(this->waitForBytesWritten(10000))    //Attend max 10s qu'un bite soit émis
            {
                if(this->waitForReadyRead(60000))   //Attend max 1min qu'un bite soit recu
                {
                    byteReceive = this->readAll();
                    qDebug() << byteReceive;
                }
                else
                {
                    qDebug() << "Probleme de lecture";
                }
            }
            else
            {
                qDebug() << "Problème d'écriture";
            }
       }

    }
    qDebug()<< "fin";
}

void Port_serie::connexion()
{
    microControlleur_is_available = false;
    microControlleur_port_name = "";

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
            if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
            {
                if(serialPortInfo.vendorIdentifier() == microControlleur_uno_vendor_id)
                {
                    if(serialPortInfo.productIdentifier() == microControlleur_uno_product_id)
                    {
                        microControlleur_port_name = serialPortInfo.portName();
                        microControlleur_is_available = true;
                    }
                }
            }
        }

    if(microControlleur_is_available)
    {
        qDebug() << "Initialisation";
           // open and configure the serialport
           this->setPortName(microControlleur_port_name);
           this->open(QSerialPort::ReadWrite);
           this->setBaudRate(QSerialPort::Baud115200);
           this->setDataBits(QSerialPort::Data8);
           this->setParity(QSerialPort::NoParity);
           this->setStopBits(QSerialPort::OneStop);
           this->setFlowControl(QSerialPort::NoFlowControl);
           QMessageBox::information(NULL, "Info Port", "connection effectuée avec succèse");
           qDebug() << "port ouvert ? " << this->isOpen();
     }
    else
    {
           // give error message if not available
           int reponse = QMessageBox::question(NULL, "Port error", "Problème de connection, utilisez vous un nouveau produit ?");

           if(reponse == QMessageBox::Yes)
           {
               recuperationMicroControlleurID();
           }
     }
}

void Port_serie::recuperationMicroControlleurID()
{
    qDebug() << "Number port: " << QSerialPortInfo::availablePorts().length();
        foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
            qDebug() << "Has Vendor ID: " << serialPortInfo.hasVendorIdentifier();
            if(serialPortInfo.hasVendorIdentifier()){
                qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
                microControlleur_uno_vendor_id = serialPortInfo.vendorIdentifier(); //Nouveau Vendor ID
            }
            qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
            if(serialPortInfo.hasProductIdentifier()){
                qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
                microControlleur_uno_product_id = serialPortInfo.productIdentifier();
            }

        }

    connexion();    //Relance la fonction connection avec les nouvelles ID
}
