#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
public:
    Client();
    //Client(id_c,nom_c,prenom_c,age_c,phone_c,email_c);
Client(QString,QString,QString,QString,int,QString,int,QString);
QString getid();
QString getnom();
QString getprenom();
QString getemail();
int getphone();
int getage();
QString getsexe();
QString getdate();

void setid(QString);
void setnom(QString);
void setprenom(QString);
void setemail(QString);
void setphone(int);
void setsexe(QString);
void setdate(QString);
void setage(int);
bool ajouter();
QSqlQueryModel* afficher();
QSqlQueryModel* afficher_id();
bool supprimer(QString);
bool modifier( );



 private:
    QString id_c ;
    int phone_c;
    int age_c;
    QString nom_c,prenom_c,email_c,sexe_c,date_de_naissance_c;

};

#endif // CLIENT_H
