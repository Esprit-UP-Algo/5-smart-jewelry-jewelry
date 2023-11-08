#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include<QIntValidator>
#include<QMessageBox>
#include <QRegExpValidator>
#include <QtCore>
#include <QtWidgets>
#include <QtCharts>


  using namespace QtCharts;


#include <QPixmap>
#include <QMessageBox>
#include<iostream>
#include <QMessageBox>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QtCharts/QPieSeries>

#include <QSqlRecord>
#include<QPieSeries>

#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QPdfWriter>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include <QSqlRecord>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QtWidgets>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->agec->setValidator(new QIntValidator(0,999, this));
   ui->phonec->setValidator(new QIntValidator(0,99999999, this));

  ui->tab_client->setModel(C.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    QMessageBox msgBox;
    QString id=ui->idc->text();
    QString nom=ui->nomc->text();
    QString prenom=ui->prenomc->text();
    int age=ui->agec->text().toInt();
    int phone=ui->phonec->text().toInt();
    QString email=ui->emailc->text();
    QString date=ui->datec->text();
    QString sexe=ui->sexec->text();

    Client C(id,nom,prenom,date,age,sexe,phone,email);
    bool test=C.ajouter();
    if(test)

    {
        msgBox.setText("Ajout avec succes ");
        ui->tab_client->setModel(C.afficher());
    }
     else
                msgBox.setText("Echec d´ajout");
    msgBox.exec();



}

void MainWindow::on_supprimer_clicked()
{
    Client C1;
    C1.setid(ui->suppid_c->text());
    bool test=C1.supprimer(C1.getid());

    QMessageBox msgBox;
    if(test)

    {msgBox.setText("Supprission avec succes ");
        ui->tab_client->setModel(C.afficher());
    }
     else
                msgBox.setText("Echec de suppression");
    msgBox.exec();

}

void MainWindow::on_modifier_clicked()
{
    QMessageBox msgBox;
    QString id=ui->idc->text();
    QString nom=ui->nomc->text();
    QString prenom=ui->prenomc->text();
    int age=ui->agec->text().toInt();
    int phone=ui->phonec->text().toInt();
    QString email=ui->emailc->text();
     QString date=ui->datec->text();
      QString sexe=ui->sexec->text();

    Client C(id,nom,prenom,date,age,sexe,phone,email);
    bool test=C.modifier();
    if(test)

    {
        msgBox.setText("Modification avec succes ");
        ui->tab_client->setModel(C.afficher());
    }
     else
                msgBox.setText("Echec de modification");
    msgBox.exec();





}



void MainWindow::on_chercher_clicked()
{


}

void MainWindow::on_pdf_clicked()
{


}

void MainWindow::on_pushButton_clicked()
{

}



void MainWindow::on_stat_clicked()
{
    QPieSeries *series = new QPieSeries();
     series->setHoleSize(0.35);
     series->append("Femmes", 20);
      QPieSlice *slice = series->append("Hommes", 80);

      slice->setExploded();
      slice->setLabelVisible();


      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("  specialité de presataire  :");
    chart ->setTheme(QChart::ChartThemeBlueCerulean);
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    if (ui->horizontalFrame) {
            chartview->setParent(ui->horizontalFrame);


            QMessageBox::information(this, "Succès", "Statistique validée avec succès.");
        } else {

           QMessageBox::critical(this, "Erreur", "Widget parent non trouvé.");
       }
}
