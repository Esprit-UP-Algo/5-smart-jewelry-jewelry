#include "conection.h"

Conection::Conection()
{

}

bool Conection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("souissisamar25");//inserer nom de l'utilisateur
db.setPassword("esprit2A25");

if (db.open())
test=true;





    return  test;
}

void Conection::closeConnection() {db.close();}
