#ifndef FACTURE_H
#define FACTURE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSlice>

class Facture
{
    QString METHOD_PAIEMENT,DATE_FACTURATION;
    int ID_FACTURE;
    int MONTANT;
public:

    Facture();
    Facture(int, QString, QString,int);
    void setID_FACTURE(int n);
    void setMETHOD_PAIEMENT(QString n);
    void setDATE_FACTURATION(QString n);
    void setMONTANT(int n);

    //Getters
    int get_ID_FACTURE();
    QString get_METHOD_PAIEMENT() const;
    QString get_DATE_FACTURATION() const ;
    float get_MONTANT();
    bool ajouter();
    bool modifier(int);
    bool supprimer(int);
     bool idExists(int id) ;
    QSqlQueryModel * afficher();
    QSqlQueryModel *trie(QString critere);
    QSqlQueryModel*  searchFactureById(int idFacture);
    QChartView * stat();
void  on_pdf_clicked();
};

#endif // FACTURE_H
