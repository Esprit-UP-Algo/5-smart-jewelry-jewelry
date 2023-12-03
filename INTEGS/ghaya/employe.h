#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>

class employe
{

public:
    employe();
    employe(QString,QString,int,int,QDate,int,QString,QString);
    //++++++++++

    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    int getcin(){return CIN;}
    int getsalaire(){return salaire;}
    QDate getdateE(){return dateE;}

    int getabs(){return abs;}
    void setcin(int nvcin){CIN=nvcin;}
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setsalaire(int s){salaire=s;}
    void setdateE(QDate d){dateE=d;}

    void setabs(int a){abs=a;}
    QString nom,prenom,mdp,RFID,status;
    int CIN,salaire,abs;
    QDate dateE;




    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    bool rfidExists(QString);
    QString rfidName (QString);

    QSqlQueryModel* trierParSalaire();
        QSqlQueryModel* trierParDateEmbauche();

         void rechercher(QTableView*, int);







};

#endif // EMPLOYE_H
