#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::Dialog()
{
    delete ui;
}

void Dialog::setclient(Client c)
{
    ui->lineEdit_cind->setText(c.get_cin());
    ui->lineEdit_nomd->setText(c.get_nom());
    ui->lineEdit_prenomd->setText(c.get_prenom());
}
