#include "produit.h"

Produit::Produit()
{
 ID="";
 Nom="";
 Type="";
 Poids="";
 Prix="";
 Qte="";

}

void Produit::setID(QString n){ID=n;}
void Produit::setNom(QString n){Nom=n;}
void Produit::setType(QString n){Type=n;}
void Produit::setPoids(QString n){Poids=n;}
void Produit::setPrix(QString n){Prix=n;}
void Produit::setQte(QString n){Qte=n;}

QString Produit::getID(){return ID;}
QString Produit::getNom(){return Nom;}
QString Produit::getType(){return Type;}
QString Produit::getPoids(){return Poids;}
QString Produit::getPrix(){return Prix;}
QString Produit::getQte(){return Qte;}
