#include "commande.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
Commande::Commande()
{
    numero=0;
    date_=0;
    total=0;
    statut="";
}
Commande::Commande(int numero,int date_,int total,QString statut)
{
    this->numero=numero;
    this->total=total;
    this->date_=date_;
    this->statut=statut;
}
bool Commande::ajouter()
{
    QString num_string=QString::number(numero);
    QString date_string=QString::number(date_);
    QString total_string=QString::number(total);
    QSqlQuery query;
          query.prepare("insert into Commande (numero, date_, total, statut) "
                        "values (:numero,:date_,:total,:statut)");
               query.bindValue(":numero", num_string);
               query.bindValue(":date_", date_string);
               query.bindValue(":total", total_string);
               query.bindValue(":statut", statut);
         return  query.exec();

}
QSqlQueryModel * Commande::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from COMMANDE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("total"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("numero"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("statut"));
            return model;

}
bool Commande::supprimer(int numero)
{
          QSqlQuery query;
          QString res=QString::number(numero);
          query.prepare("Delete from Commande where numero=:numero ");
          query.bindValue(":numero", numero);
         return  query.exec();
}
