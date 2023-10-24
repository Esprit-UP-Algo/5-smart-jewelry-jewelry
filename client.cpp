#include "client.h"

Client::Client()
{
cin="";
nom="";
prenom="";

}
void Client::setcin(QString n){cin=n;}
void Client::setnom(QString n){nom=n;}
void Client::setprenom(QString n){prenom=n;}

Qstring Client::get_cin(){return cin;}
Qstring Client::get_nom(){return nom;}
Qstring Client::get_prenom(){return prenom;}
