#include "employe.h"
#include<QString>
#include<QObject>
#include <iostream>
#include <QDate>
#include <QDebug>
#include <QTableView>
employe::employe()
{
    CIN=0;
    nom="";
    prenom="";
    salaire=0;
    mdp="";
    abs=0;
}
employe::employe(QString nom,QString prenom,int CIN,int abs,QDate dateE,int salaire,QString mdp)
{
    this->CIN=CIN;
    this->nom=nom;
    this->prenom=prenom;
    this->salaire=salaire;
    this->abs=abs;
    this->dateE=dateE;
    this->mdp=mdp;

}

bool employe::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(CIN);

    // Vérification de l'existence d'un employé avec le même CIN
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM employe WHERE CIN = :CIN");
    checkQuery.bindValue(":CIN", res);
    checkQuery.exec();
    checkQuery.next();

    int rowCount = checkQuery.value(0).toInt();

    if (rowCount > 0) {
        // L'employé avec ce CIN existe déjà, vous pouvez gérer l'erreur ici
        // Par exemple, afficher un message d'erreur ou journaliser l'incident
        return false;
    }

    // Si l'employé n'existe pas, insérez-le

    QString res3 = QString::number(salaire);
    QString res4 = QString::number(abs);

    query.prepare("INSERT INTO employe (CIN, nom, prenom, dateE, salaire, abs, mdp) VALUES (:CIN, :nom, :prenom, :dateE, :salaire, :abs, :mdp)");
    query.bindValue(":CIN", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateE", dateE);
    query.bindValue(":salaire", salaire);
    query.bindValue(":abs", abs);
    query.bindValue(":mdp", mdp);


    return query.exec();
}


QSqlQueryModel *employe::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery ("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("dateE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("abs"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("mdp"));
    return model;
}

bool employe::supprimer(int CIN)
{
    QSqlQuery query;
    QString res = QString::number(CIN);

    // Vérification de l'existence de l'employé avec le CIN spécifié
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM employe WHERE CIN = :CIN");
    checkQuery.bindValue(":CIN", res);
    checkQuery.exec();
    checkQuery.next();

    int rowCount = checkQuery.value(0).toInt();

    if (rowCount == 0) {
        // L'employé avec ce CIN n'existe pas, vous pouvez gérer l'erreur ici
        // Par exemple, afficher un message d'erreur ou journaliser l'incident
        return false;
    }

    // Si l'employé existe, supprimez-le
    query.prepare("DELETE FROM employe WHERE CIN = :CIN");
    query.bindValue(":CIN", res);

    return query.exec();
}

bool employe::modifier(int CIN)
{
    QSqlQuery query;
    QString res = QString::number(CIN);

    // Vérification de l'existence de l'employé avec le CIN spécifié
    QSqlQuery checkQuery;

    checkQuery.prepare("SELECT COUNT(*) FROM employe WHERE CIN = :CIN");
    checkQuery.bindValue(":CIN", res);
    checkQuery.exec();
    checkQuery.next();

    int rowCount = checkQuery.value(0).toInt();

    if (rowCount == 0) {
        // L'employé avec ce CIN n'existe pas, vous pouvez gérer l'erreur ici
        // Par exemple, afficher un message d'erreur ou journaliser l'incident
        return false;
    }

    // Si l'employé existe, mettez à jour les données

    QString res3 = QString::number(salaire);
    QString res4 = QString::number(abs);

    query.prepare("UPDATE employe SET nom = :nom, prenom = :prenom, salaire = :salaire, dateE = :dateE, abs = :abs, mdp= :mdp WHERE CIN = :CIN");
    query.bindValue(":CIN", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateE", dateE);
    query.bindValue(":salaire", res3);
    query.bindValue(":abs", res4);
    query.bindValue(":mdp", mdp);

    return query.exec();
}

QSqlQueryModel* employe::trierParSalaire()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Requête pour trier par salaire du plus élevé au moins élevé
    QString query = "SELECT * FROM employe ORDER BY salaire DESC";

    model->setQuery(query);
    return model;
}

QSqlQueryModel* employe::trierParDateEmbauche()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY dateE DESC");
    return model;
}

//++++++++++++++
void employe::rechercher(QTableView *tableView, int CIN) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery;

    // Préparation de la requête SQL avec un paramètre dynamique
    query->prepare("SELECT * FROM employe WHERE CIN = :cin");
    query->bindValue(":cin", CIN);
    query->exec();
    // Configuration du modèle avec les résultats de la requête
    model->setQuery(*query);
    model->sort(0, Qt::AscendingOrder);
    // Configuration de la vue de table avec le modèle
    tableView->setModel(model);

    // Affichage de la vue de table
    tableView->show();
}
