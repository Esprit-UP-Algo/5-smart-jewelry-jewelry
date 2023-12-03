#ifndef SOUISSI_H
#define SOUISSI_H

#include <QMainWindow>
#include <QMainWindow>
#include "client.h"
#include<QChart>
#include<QPieSeries>
#include<QPieSlice>
#include <QtCharts>
#include<QSsl>
QT_BEGIN_NAMESPACE
namespace Ui { class souissi; }
QT_END_NAMESPACE

class souissi : public QMainWindow
{
    Q_OBJECT

public:
    souissi(QWidget *parent = nullptr);
    ~souissi();

private slots:
    void on_ajouterCl_clicked();

    void on_modifierCl_clicked();

    void on_pdfCl_clicked();


    void sendMail();
            void mailSent(QString);
            void browse();
    void on_supprimerCl_clicked();

    void on_chercherCl_clicked();

    void on_statistiqueCl_clicked();

    void on_ContratCl_clicked();

    void on_triageCl_clicked();

    void on_ref_Cl_clicked();

    void on_homeCl_clicked();

    void on_deconnectCl_clicked();

private:
    Ui::souissi *ui;
    Client C;
        QChartView *chartView;
        QStringList files;
};
#endif // SOUISSI_H
