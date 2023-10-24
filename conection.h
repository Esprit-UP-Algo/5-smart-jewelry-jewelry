#ifndef CONECTION_H
#define CONECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Conection
{
public:
    Conection();
    bool createconnect();
};



#endif // CONECTION_H
