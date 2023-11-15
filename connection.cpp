#include "connection.h"

Connection::Connection()
{

}

bool Connection::ouvrirConnexion()
{bool test=false;
 db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("souissisamar25");//inserer nom de l'utilisateur
db.setPassword("esprit2A25");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

void Connection::fermerConnexion(){db.close();}
