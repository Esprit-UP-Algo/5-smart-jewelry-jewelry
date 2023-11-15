#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <string>

class Commande
{
public:
    //constructeurs
    Commande();
    Commande(int,int,int,QString);
    //Getters and setters
           int Getnumero() { return numero; }
           void Setnumero(int val) { numero = val; }
           int Gettotal() { return total; }
           void Settotal(int val) { total = val; }
           int Getdate() { return date_; }
           void Setdate(int val) { date_ = val; }
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
       int getNombreCommandesParStatut(const QString& statut);
       int getTotalCommandes();


private:
    int numero,total,date_;
    QString statut;
};

#endif // COMMANDE_H
