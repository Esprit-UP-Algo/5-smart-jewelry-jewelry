#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include<QChart>
#include<QPieSeries>
#include<QPieSlice>
#include <QtCharts>

#include <arduino.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();



    void on_chercher_clicked();

    void on_pdf_clicked();

    void on_pushButton_clicked();



    void on_stat_clicked();

    void on_email_2_clicked();

    void on_sms_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Client C;
    QChartView *chartView;
    QByteArray data; // variable contenant les données reçues

    arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
