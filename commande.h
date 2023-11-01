#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

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
       QSqlQueryModel * afficher();
       bool supprimer(int);
private:
    int numero,total,date_;
    QString statut;
};

#endif // COMMANDE_H
