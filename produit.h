#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>

class Produit
{
public:
    void setID(QString n);
    void setNom(QString n);
    void setType(QString n);
    void setPoids(QString n);
    void setPrix(QString n);
    void setQte(QString n);

    QString getID();
    QString getNom();
    QString getType();
    QString getPoids();
    QString getPrix();
    QString getQte();
    Produit();
private:
    QString ID,Nom, Type, Poids, Prix, Qte;
};

#endif // PRODUIT_H
