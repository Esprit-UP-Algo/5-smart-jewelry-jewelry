#include "dialog.h"
#include "ui_Interface.h"
#include "produit.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
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

void Dialog::on_pushButton_clicked()
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

}
