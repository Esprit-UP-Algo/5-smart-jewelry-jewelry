#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QRegularExpression>
#include <QMessageBox>

#include<QDate>
Client::Client()
{
    id_c="";
    phone_c=0;
   age_c=0;
    nom_c="";
    prenom_c="";
    email_c="";
    date_de_naissance_c="";
    sexe_c="";



}


Client::Client(QString id,QString nom,QString prenom,QString date,int age,QString sexe,int phone,QString email)
{

id_c=id;
phone_c=phone;
age_c=age;
nom_c=nom;
prenom_c=prenom;
email_c=email;
date_de_naissance_c=date;
sexe_c=sexe;


}
QString Client::getid()
{
    return id_c;
}
QString Client::getnom()
{
    return nom_c;
}
QString Client::getprenom()
{
    return prenom_c;
}
QString Client::getemail()
{
    return email_c;
}
int Client::getphone()
{
    return phone_c;
}
int Client::getage()
{
    return age_c;
}
QString Client::getsexe()
{
    return sexe_c;
}
QString Client::getdate()
{
    return date_de_naissance_c;
}

void  Client::setid(QString id)
{
    id_c=id;
}
void  Client::setnom(QString nom)
{
    nom_c=nom;
}
void  Client::setprenom(QString prenom)
{
    prenom_c=prenom;
}
void  Client::setemail(QString email)
{
    email_c=email;
}
void  Client::setphone(int phone)
{
    phone_c=phone;
}
void  Client::setage(int age)
{
    age_c=age;
}
void  Client::setsexe(QString sexe)
{
    sexe_c=sexe;
}
void  Client::setdate(QString date)
{
    date_de_naissance_c=date;
}


bool Client::ajouter()
{
QSqlQuery query;

    QString phone_string=QString::number(phone_c);
    QString age_string=QString::number(age_c);

    query.prepare("INSERT INTO CLIENT (NOM_C,PRENOM_C,ID_C,DATE_DE_NAISSANCE_C,AGE_C,SEXE_C,NUMERO_DU_TELEPHONE_C,EMAIL_C) "
                  "VALUES (:nom, :prenom, :id, :date, :age, :sexe, :phone, :email)");


            query.bindValue(":nom", nom_c);


            query.bindValue(":prenom", prenom_c);


        query.bindValue(":id", id_c);

        QRegularExpression datePattern("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\\d{4}$");

        if (datePattern.match(date_de_naissance_c).hasMatch()) {
            query.bindValue(":date", date_de_naissance_c);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("ajout"),
                            QObject::tr("date incorrecte !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }



        QDate date = QDate::fromString(date_de_naissance_c, "dd/MM/yyyy");
        int annee_naissance = date.year();
        int annee_actuelle = QDate::currentDate().year();
        int age = annee_actuelle - annee_naissance;

        if (age == age_c) {





        query.bindValue(":age",age_string );
}
        else {
            QMessageBox::critical(nullptr, QObject::tr("ajout"),
                            QObject::tr("age incorrecte !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
        QRegularExpression sexePattern("^(feminin|masculin)$");
         //QRegularExpression::CaseInsensitiveOption

        if (sexePattern.match(sexe_c).hasMatch()) {
            query.bindValue(":sexe", sexe_c);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("ajout"),
                            QObject::tr("sexe incorrecte !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }

        query.bindValue(":phone",phone_string );

        QRegularExpression emailPattern("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");


        if (emailPattern.match(email_c).hasMatch()) {

            query.bindValue(":email", email_c);
        }



 return query.exec();
}


QSqlQueryModel* Client::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();


       model->setQuery("SELECT * FROM CLIENT");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Identifiant"));

         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_naissance"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Age"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numero_du_telephone"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("Email"));
   return model;

}

QSqlQueryModel *Client::afficher_id()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM CLIENT ORDER BY AGE_C ");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_naissance"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Age"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numero_du_telephone"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("Email"));
         return model;
 }

bool Client::supprimer(QString id)
{

    QSqlQuery query;

    query.prepare(" Delete from CLIENT where ID_C=:id");
    query.bindValue(":id", id);

    return query.exec(); ;

}

bool Client::modifier()
{
    QSqlQuery query;

        QString phone_string=QString::number(phone_c);
        QString age_string=QString::number(age_c);

        query.prepare("UPDATE CLIENT SET NOM_C=:nom,PRENOM_C=:prenom,SEXE_C=:sexe ,DATE_DE_NAISSANCE_C=:date,NUMERO_DU_TELEPHONE_C=:phone,EMAIL_C=:email WHERE ID_C=:id;");
        query.bindValue(":nom", nom_c);
        query.bindValue(":prenom", prenom_c);
        query.bindValue(":id", id_c);
        query.bindValue(":sexe",sexe_c);
        query.bindValue(":date",date_de_naissance_c );
        query.bindValue(":age",age_string );

        query.bindValue(":phone",phone_string );
        query.bindValue(":email",email_c );





     return query.exec();
}

bool Client::exists(const QString id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT WHERE ID_C = :id");
    query.bindValue(":id", id);
    query.exec();

    return query.next();
}



