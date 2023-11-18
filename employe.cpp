#include "employe.h"
#include<QString>
#include<QObject>
#include <iostream>
#include <QDate>
#include <QDebug>
#include <QTableView>
#include <QMessageBox>
#include <QSqlError>
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
    QSqlQuery query; // Pas besoin d'allouer dynamiquement ici

    // Préparez la requête SQL avec la clause WHERE
    query.prepare("SELECT * FROM employe WHERE CIN = :cin");
    query.bindValue(":cin", CIN);

    // Exécutez la requête préparée
    if (query.exec()) {
        // Configuration du modèle avec les résultats de la requête
        model->setQuery(query);

        if (model->rowCount() > 0) {
            // Si des résultats sont trouvés, triez le modèle par ordre croissant sur la première colonne (0)
            model->sort(0, Qt::AscendingOrder);

            // Configuration de la vue de table avec le modèle
            tableView->setModel(model);

            // Affichage de la vue de table
            tableView->show();

            // Affichage d'un message de succès
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Recherche réussie.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        } else {
            // Aucun résultat trouvé
            qDebug() << "Aucun employé trouvé avec le CIN : " << CIN;

            // Affichage d'un message indiquant que la recherche n'a donné aucun résultat
            QMessageBox::information(nullptr, QObject::tr("Aucun résultat"),
                                     QObject::tr("Aucun employé trouvé avec le CIN spécifié."), QMessageBox::Ok);
        }
    } else {
        // Gestion de l'erreur de la requête SQL
        qDebug() << "Erreur lors de la recherche par CIN : " << query.lastError().text();

        // Affichage d'un message d'erreur en cas d'échec de la requête SQL
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Erreur lors de la recherche par CIN.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

//+++++++++++
void employe::afficherMessagerie()
{
    // Implémentez la logique d'affichage de la messagerie ici
    // Vous pouvez utiliser une boîte de dialogue, une fenêtre, etc.
    // Par exemple, afficher les messages dans une QMessageBox
    QMessageBox::information(nullptr, "Messagerie", messages);
}
void employe::envoyerMessage(employe *destinataire, const QString &message)
{
    // Implémentez la logique d'envoi de message ici
    // Par exemple, ajouter le message à la liste des messages du destinataire
    destinataire->messages += QString("De %1 : %2\n").arg(prenom).arg(message);
}