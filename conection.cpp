#include "conection.h"

Conection::Conection()
{

}

bool Conection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2A");
db.setUserName("ghaya");//inserer nom de l'utilisateur
db.setPassword("ghaya");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

void Conection::closeConnection() {db.close();}
