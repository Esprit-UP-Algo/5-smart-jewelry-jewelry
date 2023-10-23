#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>

class employe
{
public:

     void setprenom(QString n);
     void setnom(QString n);
     void setemail(QString n);
     void setnumtel(QString n);
     void setsalaire(QString n);
     void setcin(QString n);
     void setrole(QString n);
     void setage(QString n);
     QString get_prenom();
     QString get_nom();
     QString get_email();
     QString get_numtel();
     QString get_salaire();
     QString get_cin();
     QString get_role();
     QString get_age();
    employe();
private:
    QString nom, prenom, email, numtel, salaire , cin, role, age;
};

#endif // EMPLOYE_H
