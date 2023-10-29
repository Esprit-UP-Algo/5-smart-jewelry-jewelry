#include "dialog.h"
#include "ui_Interface.h"
#include "produit.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //ui->tableView->setModel(Ptemp.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setProduit(Produit p){
    ui->lineEdit_Nom->setText(p.getNom());
    ui->lineEdit_Type->setText(p.getType());
    ui->lineEdit_Poids->setText(p.getPoids());
    ui->lineEdit_Prix->setText(p.getPrix());
    ui->lineEdit_Qte->setText(p.getQte());
}

/*void Dialog::on_pushButton_clicked()
{
    Produit p;
    p.setID(ui->lineEdit_ID->text());
    p.setNom(ui->lineEdit_Nom->text());
    p.setType(ui->lineEdit_Type->text());
    p.setPoids(ui->lineEdit_Poids->text());
    p.setPrix(ui->lineEdit_Prix->text());
    p.setQte(ui->lineEdit_Qte->text());

Dialog d;
d.setProduit(p);
d.exec();

}*/

void Dialog::on_pushButton_Add_clicked(){
    int ID=ui->lineEdit_ID->text().toInt();
    QString Nom=ui->lineEdit_Nom->text();
    QString Type=ui->lineEdit_Type->text();
    QString Poids=ui->lineEdit_Poids->text();
    QString Prix=ui->lineEdit_Prix->text();
    QString Qte=ui->lineEdit_Qte->text();

   Produit P(ID,Nom,Type,Poids,Prix,Qte);
   bool test=P.ajouter();
   if (test){
       QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué \n"),QMessageBox::Cancel);
   }
   else QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Ajout non effectué\n"),QMessageBox::Cancel);
}

void Dialog::on_pushButton_Delete_clicked(){
    int ID=ui->lineEdit_IDd->text().toInt();
    bool test=Ptemp.supprimer(ID);
    if (test){
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Supression effectuée \n"),QMessageBox::Cancel);
    }
    else QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Suppression non effectuée\n"),QMessageBox::Cancel);

}





