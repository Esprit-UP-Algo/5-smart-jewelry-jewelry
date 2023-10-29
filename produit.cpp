#include "produit.h"
#include <QStandardItemModel>
Produit::Produit()
{
 ID=NULL;
 Nom="";
 Type="";
 Poids="";
 Prix="";
 Qte="";

}
Produit::Produit(int ID,QString Nom,QString Type,QString Poids,QString Prix,QString Qte){
   this->ID=ID;
   this->Nom=Nom;
   this->Type=Type;
   this->Poids=Poids;
   this->Prix=Prix;
   this->Qte=Qte;
}

void Produit::setID(int n){ID=n;}
void Produit::setNom(QString n){Nom=n;}
void Produit::setType(QString n){Type=n;}
void Produit::setPoids(QString n){Poids=n;}
void Produit::setPrix(QString n){Prix=n;}
void Produit::setQte(QString n){Qte=n;}

int Produit::getID(){return ID;}
QString Produit::getNom(){return Nom;}
QString Produit::getType(){return Type;}
QString Produit::getPoids(){return Poids;}
QString Produit::getPrix(){return Prix;}
QString Produit::getQte(){return Qte;}

bool Produit::ajouter(){
    Produit p;
 QSqlQuery query;
 query.prepare("insert into Produit (ID, Nom, Type, Poids, Prix, Qte)" "values(:ID, :Nom, :Type ,:Poids, :Prix, :Qte)");

 query.bindValue(":ID",ID);
 query.bindValue(":Nom",Nom);
 query.bindValue(":Type",Type);
 query.bindValue(":Poids",Poids);
 query.bindValue(":Prix",Prix);
 query.bindValue(":Qte",Qte);

 return query.exec();

}

bool Produit::supprimer(int IDx){
    QSqlQuery query;
    query.prepare("Delete from Produit where ID=:ID");
    query.bindValue(":ID",IDx);
    return query.exec();
}

QSqlQueryModel * Produit::afficher(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Produit");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Poids"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Qte"));

    return model;
}
