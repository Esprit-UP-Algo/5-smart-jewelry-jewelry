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
    ui->lineEdit_absd->setText(e.get_abs());
    ui->lineEdit_salaired->setText(e.get_salaire());
    ui->lineEdit_dembd->setText(e.get_demb());


}
