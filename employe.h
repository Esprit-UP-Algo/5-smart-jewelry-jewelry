#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>

class employe
{
public:

     void setprenom(QString n);
     void setnom(QString n);
     void setabs(QString n);
     void setnumtel(QString n);
     void setsalaire(QString n);
     void setcin(QString n);
     void setdemb(QString n);
     QString get_prenom();
     QString get_nom();
     QString get_abs();
     QString get_salaire();
     QString get_cin();
     QString get_demb();

    employe();
private:
    QString nom, prenom, abs, salaire , cin, demb;
};

#endif // EMPLOYE_H
