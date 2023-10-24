#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    employe e ;
    e.setnom(ui->lineEdit_nom->text());
    e.setprenom(ui->lineEdit_prenom->text());
    e.setabs(ui->lineEdit_abs->text());
    e.setsalaire(ui->lineEdit_salaire->text());
    e.setcin(ui->lineEdit_cin->text());
    e.setdemb(ui->lineEdit_demb->text());


    Dialog d;
    d.setemploye(e);
    d.exec();


}

void MainWindow::on_pushButton_2_clicked()
{
        QApplication::quit(); //sert à faire quitter l'utilisateur de la fenetre
}

