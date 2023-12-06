#include "conection.h"

Conection::Conection(){}

bool Conection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("skander");//inserer nom de l'utilisateur
db.setPassword("skander");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;

return  test;
}
void Conection::closeconnect(){ db.close(); }
