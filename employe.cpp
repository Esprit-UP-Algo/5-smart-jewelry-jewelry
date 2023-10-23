#include "employe.h"

employe::employe()
{
    cin="";
    prenom="";
    nom="";
    email="";
    numtel="";
    salaire="";
    role="";
    age="";
    }

    void employe::setcin(QString n){cin=n;}
    void employe::setprenom(QString n){prenom=n;}
    void employe::setnom(QString n){nom=n;}
    void employe::setage(QString n){age=n;}
    void employe::setrole(QString n){role=n;}
    void employe::setnumtel(QString n){numtel=n;}
    void employe::setemail(QString n){email=n;}
    void employe::setsalaire(QString n){salaire=n;}

    QString employe::get_cin(){return cin;}
    QString employe::get_prenom(){return prenom;}
    QString employe::get_nom(){return nom;}
    QString employe::get_email(){return email;}
    QString employe::get_numtel(){return numtel;}
    QString employe::get_salaire(){return salaire;}
    QString employe::get_role(){return role;}
    QString employe::get_age(){return age;}
