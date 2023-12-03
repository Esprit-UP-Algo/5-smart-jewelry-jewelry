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
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    serialbuffer="";
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   arduino_is_available = true;
                   qDebug()<<"mrgl";
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(arduino_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
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
