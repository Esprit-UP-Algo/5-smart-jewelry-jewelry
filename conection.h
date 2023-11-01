#ifndef CONECTION_H
#define CONECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Conection
{
    QSqlDatabase db;
public:
    Conection();
    bool createconnect();
    void closeConnection();
};



#endif // CONECTION_H
