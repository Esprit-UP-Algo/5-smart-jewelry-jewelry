#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_commande->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_clicked()
{

    int numero=ui->lineEdit_N->text().toInt();
    int date_=ui->lineEdit_date->text().toInt();
    int total=ui->lineEdit_total->text().toInt();
    QString statut=ui->lineEdit_statut->text();
    Commande C ( numero, date_, total, statut );
    bool test=C.ajouter();
    if (test){
        ui->tab_commande->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajouter effectue \n"
                            "click cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("ajout non effectue.\n"
                                          "click cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_supp_clicked()
{
        int numero =ui->num_supp->text().toInt();
        bool test=c.supprimer(numero);
        if (test){
            ui->tab_commande->setModel(c.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("suppression  effectue \n"
                                "click cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("suppression non effectue.\n"
                                              "click cancel to exit."),QMessageBox::Cancel);
}
