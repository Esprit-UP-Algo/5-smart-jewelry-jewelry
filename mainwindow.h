#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "commande.h"
#include "arduino.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QtCharts/QChartView>
#include "ui_mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
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




private:
    Ui::MainWindow *ui;
    Commande c;
     QGridLayout *gridLayout;
     arduino A;

};
#endif // MAINWINDOW_H
