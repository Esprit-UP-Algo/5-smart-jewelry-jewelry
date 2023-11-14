#include "mainwindow.h"
#include <QMessageBox>
#include "conection.h"
#include <QApplication>
#include <iostream>
#include "employe.h"
#include "login.h"
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    employe e;
    qDebug();

    login l;
    Conection c;
    bool test=c.createconnect();
    MainWindow w;
    l.show();
    if(test)
    {

        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();



}
