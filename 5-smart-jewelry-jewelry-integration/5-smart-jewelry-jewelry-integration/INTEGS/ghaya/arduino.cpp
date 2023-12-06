#include "arduino.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
arduino::arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}
int arduino::connect_arduino()
{
    serialbuffer="";
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_producy_id) {
                arduino_is_available = true;
                qDebug() << "Arduino détecté sur le port : " << serial_port_info.portName();
                arduino_port_name = serial_port_info.portName();
            }
        }
    }

    if (arduino_is_available) {
        // Ajoutez un message de débogage ici
        qDebug() << "Arduino est disponible. Tentative de connexion à : " << arduino_port_name;

        // Configuration de la communication série
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            // Ajoutez un message de débogage ici
            qDebug() << "Connexion à Arduino réussie.";
            return 0;
        } else {
            // Ajoutez un message de débogage ici
            qDebug() << "Échec de la connexion à Arduino.";
            return 1;
        }
    } else {
        // Ajoutez un message de débogage ici
        qDebug() << "Arduino non détecté.";
        return -1;
    }
}

int arduino::close_arduino()

{ if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;

}
QSerialPort *arduino::getserial()
{
   return serial;
}

QByteArray arduino::read_from_arduino()
{

   if(serial->isReadable())
        data=serial->readAll();
        return data;

}

void arduino::write_to_arduino(QByteArray d)
{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
bool arduino::modifier(int RFID)
{

    QString res = QString::number(RFID);


    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT status FROM employe WHERE RFID = :RFID");
    checkQuery.bindValue(":RFID", res);
    checkQuery.exec();

    if (!checkQuery.next()) {

        qDebug() << "Employee with RFID " << RFID << " not found.";
        return false;
    }

    QString currentStatus = checkQuery.value(0).toString();


    QSqlQuery query;
    query.prepare("UPDATE employe SET status = :status WHERE RFID = :RFID");
    query.bindValue(":RFID", res);

    if (currentStatus == "present") {
        query.bindValue(":status", "absent");
    } else {
        query.bindValue(":status", "present");
    }

    return query.exec();
}
QString arduino::modifierquantite(int ID, QString QUANTITE) {
    // Assuming you have a database connection named 'database'

    // Check if the product with the given ID exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM produit WHERE ID = :ID");
    checkQuery.bindValue(":ID", ID);

    if (!checkQuery.exec()) {
        // Handle the database error
        return "Database error";
    }

    if (checkQuery.next()) {
        // Product with the given ID exists, proceed to update the quantity
        int currentQuantity = checkQuery.value("NOMBRE").toInt();
        int newQuantity = currentQuantity + QUANTITE.toInt();

        // Update the quantity in the database
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE produit SET NOMBRE = :newQuantity WHERE ID = :ID");
        updateQuery.bindValue(":ID", ID);
        updateQuery.bindValue(":newQuantity", newQuantity);

        if (!updateQuery.exec()) {
            // Handle the database error during the update
            return "Update error";
        }

        // Fetch the name of the product for the return string
        QString productID = checkQuery.value("ID").toString();

        // Return the result in the specified format
        return QString("%1,%2").arg(productID).arg(newQuantity);
    } else {
        // Product with the given ID does not exist
        return "0";
    }
}

