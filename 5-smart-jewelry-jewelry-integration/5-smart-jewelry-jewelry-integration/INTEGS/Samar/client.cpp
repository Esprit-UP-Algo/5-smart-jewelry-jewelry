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

    sexe_c="";



}


Client::Client(QString id,QString nom,QString prenom,int age,QString sexe,int phone,QString email)
{

id_c=id;
phone_c=phone;
age_c=age;
nom_c=nom;
prenom_c=prenom;
email_c=email;

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



bool Client::ajouter()
{
QSqlQuery query;

    QString phone_string=QString::number(phone_c);
    QString age_string=QString::number(age_c);

    query.prepare("INSERT INTO CLIENT (NOM_C,PRENOM_C,ID_C,AGE_C,SEXE_C,NUMERO_DU_TELEPHONE_C,EMAIL_C) "
                  "VALUES (:nom, :prenom, :id,  :age, :sexe, :phone, :email)");


            query.bindValue(":nom", nom_c);


            query.bindValue(":prenom", prenom_c);


        query.bindValue(":id", id_c);













        query.bindValue(":age",age_string );

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
        else {
            QMessageBox::critical(nullptr, QObject::tr("ajout"),
                            QObject::tr("adresse mail incorrecte !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
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


         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero_du_telephone"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Email"));
   return model;

}

QSqlQueryModel *Client::afficher_id()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM CLIENT ORDER BY AGE_C ");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Identifiant"));

         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero_du_telephone"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Email"));
         return model;
 }

bool Client::supprimer(QString id)
{

    QSqlQuery query;

    query.prepare(" Delete from CLIENT where ID_C=:id");
    query.bindValue(":id", id);

    return query.exec(); ;

}

bool Client::modifier(  )
{
    QSqlQuery query;


        QString phone_string=QString::number(phone_c);
        QString age_string=QString::number(age_c);

        query.prepare("UPDATE CLIENT SET NOM_C=:nom,PRENOM_C=:prenom,SEXE_C=:sexe ,AGE_C=:age,NUMERO_DU_TELEPHONE_C=:phone,EMAIL_C=:email WHERE ID_C=:id;");
        query.bindValue(":nom", nom_c);
        query.bindValue(":prenom", prenom_c);
        query.bindValue(":id", id_c);
        query.bindValue(":sexe",sexe_c);

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

double Client::statistiqueHommes(QString sexe)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM CLIENT WHERE SEXE_C = :sexe");
    query.bindValue(":sexe",sexe);
    query.exec();

    int count = 0;

    while (query.next())
    {
        count = query.value(0).toInt();
    }

            QString message = QString("Number of male clients: %1").arg(count);
            //QMessageBox::information(nullptr, "Male Clients Statistic", message);


    return count;

}

