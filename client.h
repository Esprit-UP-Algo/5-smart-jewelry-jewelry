#ifndef CLIENT_H
#define CLIENT_H
#include<QString>

class Client
{
public:
    void setcin(QString n);
    void setnom(QString n);
    void setprenom(QString n);
    QString get_cin();
    QString get_nom();
    QString get_prenom();
    Client();
private:
    QString cin, nom, prenom;
};

#endif // CLIENT_H
