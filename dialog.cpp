#include "dialog.h"
#include "ui_dialog.h"

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

void Dialog::setemploye(employe e)
{
    ui->lineEdit_cind->setText(e.get_cin());
    ui->lineEdit_prenomd->setText(e.get_prenom());
    ui->lineEdit_nomd->setText(e.get_nom());
    ui->lineEdit_adressed->setText(e.get_email());
    ui->lineEdit_numd->setText(e.get_numtel());
    ui->lineEdit_salaired->setText(e.get_salaire());
    ui->lineEdit_roled->setText(e.get_role());
    ui->lineEdit_aged->setText(e.get_age());

}
