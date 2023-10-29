#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Produit
{
public:
    void setID(int n);
    void setNom(QString n);
    void setType(QString n);
    void setPoids(QString n);
    void setPrix(QString n);
    void setQte(QString n);

    int getID();
    QString getNom();
    QString getType();
    QString getPoids();
    QString getPrix();
    QString getQte();
    Produit();
    Produit(int,QString,QString,QString,QString,QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    int ID;
    QString Nom, Type, Poids, Prix, Qte;
};

#endif // PRODUIT_H
