#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <string>
#include <QHash>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QDate>
#include <QObject>

class Commande
{

public:
    //constructeurs
    Commande();
    Commande(int numero, QString date, int total, QString statut);
    //Getters and setters
           int Getnumero() { return numero; }
           void Setnumero(int val) { numero = val; }
           int Gettotal() { return total; }
           void Settotal(int val) { total = val; }
           QString Getdate() { return date_; }
           void Setdate(QString val) { date_ = val; }
           QString Getstatut() { return statut; }
           void Setstatut(QString val) { statut = val; }

      //fonctionnalite de base relatives a l'entite commande
       bool ajouter();
       QSqlQueryModel * afficher()const;
       bool supprimer(int);
       bool modifier(int);
       QSqlQueryModel *rechercher(int);
       QSqlQueryModel* tri();
       void exporterPDF(const QString &nomFichier) const;
       std::string chatbotFunction(const QString &userMessage);
       QSqlQueryModel* historique() const;
       void exporterHistoriqueTexte(const QString &nomFichier) const;
       QString statistiquesParStatut();
       int getNombreCommandesParStatut(const QString &statut);
       bool commandeExists();




private:
    int numero,total;
    QString date_;
    QString statut;
};

#endif // COMMANDE_H
