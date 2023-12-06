#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H
#include "commande.h"
#include "arduino.h"
#include "widget.h"
#include "ghaya/login.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QtCharts/QChartView>
#include "ui_mainwindow1.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow1; }
QT_END_NAMESPACE

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();
private slots:
    void on_ajout_clicked();


    void on_pushButton_supp_clicked();

    void on_modif_clicked();

    void on_recherche_pushButton_clicked();

    void on_pdf_clicked();

    void on_envoyer_clicked();

    void on_historique_clicked();

    void on_statistiques_clicked();

    void on_tri_clicked();
    void connect_commande();






    void on_pushButton_menu_clicked();

    void on_pushButton_log_clicked();

private:
    Ui::MainWindow1 *ui;
    Commande c;
     QGridLayout *gridLayout;
     arduino A;
     QByteArray data;

};
#endif // MAINWINDOW_H