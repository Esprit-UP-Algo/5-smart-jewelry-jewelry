#include "employe.h"

employe::employe()
{
    cin="";
    prenom="";
    nom="";
    abs="";
    salaire="";
    demb="";

    }

    void employe::setcin(QString n){cin=n;}
    void employe::setprenom(QString n){prenom=n;}
    void employe::setnom(QString n){nom=n;}
    void employe::setdemb(QString n){demb=n;}
    void employe::setabs(QString n){abs=n;}
    void employe::setsalaire(QString n){salaire=n;}

    QString employe::get_cin(){return cin;}
    QString employe::get_prenom(){return prenom;}
    QString employe::get_nom(){return nom;}
    QString employe::get_abs(){return abs;}
    QString employe::get_salaire(){return salaire;}
    QString employe::get_demb(){return demb;}
