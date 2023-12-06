#include "widget.h"
#include "ghaya/login.h"
#include "ghaya/calendrier.h"
#include "ghaya/conection.h"
#include <QApplication>
#include <QMessageBox>
#include "widget.h"
#include "ghaya/arduino.h"
#include <QApplication>
#include"ghaya/login.h"
#include"ghaya/conection.h"
#include"ghaya/mainwindow.h"
#include "skander/mainwindow1.h"

#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    employe e;
    qDebug();


    Conection c;
    bool test=c.createconnect();
    login l;
    arduino A;
    MainWindow w;
    l.show();
    if(test)
    {
        /*QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();
}
