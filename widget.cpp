#include "widget.h"
#include "ui_widget.h"
#include "ghaya/mainwindow.h"
#include "selim/dialog.h"
#include "ghaya/arduino.h"
#include "Samar/souissi.h"
widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    //arduino A;
    //*************
//    int ret=A.connect_arduino () ; // lancer la connexion à arduino
/*switch(ret) {
case (0) : qDebug ()<< "arduino is available and connected to : "<< A.getarduino_port_name () ;
break;
case (1) : qDebug() << "arduino is available but not connected to :" << A.getarduino_port_name () ;
break;
case (-1): qDebug() << "arduino is not available";
}
QObject:: connect (A.getserial (), SIGNAL(readyRead()), this, SLOT(update_label ())); // permet de lancer //le slot update_label suite à la reception du signal readyRead (reception des données).
    //*******
QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));

*/}

widget::~widget()
{
    delete ui;
}


void widget::on_pushButton_emp_clicked()
{
    this->hide();
    MainWindow *auth = new MainWindow;
    auth->show();

}

void widget::on_pushButton_prod_clicked()
{
    this->hide();
    Dialog *auth = new Dialog;
    auth->show();
}

void widget::on_gestionclient_clicked()
{
    this->hide();
    souissi *auth = new souissi;
    auth->show();
}
