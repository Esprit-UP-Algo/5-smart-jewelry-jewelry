#include "commande.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QPdfWriter>
#include <QPainter>
#include <algorithm>
Commande::Commande()
{
    numero=0;
    date_=0;
    total=0;
    statut="";
}
Commande::Commande(int numero,int date_,int total,QString statut)
{
    this->numero=numero;
    this->total=total;
    this->date_=date_;
    this->statut=statut;
}
bool Commande::ajouter()
{
    // Vérifier si le numéro de commande existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Commande WHERE numero = :numero");
    checkQuery.bindValue(":numero", numero);
    checkQuery.exec();

    if (checkQuery.next()) {
        // Le numéro de commande existe déjà, l'ajout ne peut pas être effectué
        return false;
    } else {
        // Le numéro de commande n'existe pas, procéder à l'ajout
        QString num_string = QString::number(numero);
        QString date_string = QString::number(date_);
        QString total_string = QString::number(total);

        QSqlQuery query;
        query.prepare("INSERT INTO Commande (numero, date_, total, statut) "
                      "VALUES (:numero, :date_, :total, :statut)");
        query.bindValue(":numero", num_string);
        query.bindValue(":date_", date_string);
        query.bindValue(":total", total_string);
        query.bindValue(":statut", statut);

        return query.exec();
    }
}

QSqlQueryModel * Commande::afficher()const
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from COMMANDE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("total"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("numero"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("statut"));
            return model;

}
/*
bool Commande::supprimer(int numero)
{
          QSqlQuery query;
          QString res=QString::number(numero);
          query.prepare("Delete from Commande where numero=:numero ");
          query.bindValue(":numero", numero);
         return  query.exec();
}
*/
bool Commande::supprimer(int numero)
{
    // Vérifier si le numéro de commande existe avant de le supprimer
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Commande WHERE numero = :numero");
    checkQuery.bindValue(":numero", numero);
    checkQuery.exec();

    if (!checkQuery.next()) {
        // Le numéro de commande n'existe pas, la suppression ne peut pas être effectuée
        return false;
    }

    // Procéder à la suppression
    QSqlQuery query;
    query.prepare("DELETE FROM Commande WHERE numero=:numero");
    query.bindValue(":numero", numero);

    return query.exec();
}

bool Commande::modifier(int numero)
{
    QSqlQuery query;
    QString res= QString::number(numero);
    QString res1= QString::number(date_);
    QString res3= QString::number(total);
    query.prepare("update commande set numero=:numero,date_=:date_,total=:total,statut=:statut WHERE numero=:numero");
    query.bindValue(":numero",res);
    query.bindValue(":date_",res1);
    query.bindValue(":total",res3);
    query.bindValue(":statut",statut);
    return query.exec();
}
QSqlQueryModel * Commande::rechercher(int numero)
{
    QSqlQuery query;
    QString numero_str = QString::number(numero);


    QString queryStr = "SELECT * FROM Commande WHERE 1=1";

    if (numero > 0) {
        queryStr += " AND numero = :numero";
    }

    query.prepare(queryStr);

    if (numero > 0) {
        query.bindValue(":numero", numero_str);
    }


    query.exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);

    return model;
}
QSqlQueryModel * Commande::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * from COMMANDE order by TOTAL");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("total"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("numero"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("statut"));
    return model;
}
void Commande::exporterPDF(const QString &nomFichier) const
{
    QFile file(nomFichier);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QPdfWriter pdfWriter(&file);
        pdfWriter.setPageSize(QPageSize(QPageSize::A4));
        QPainter painter(&pdfWriter);

        painter.drawText(100, 100, "Liste des Commandes");

        painter.drawText(100, 150, "Numéro");
        painter.drawText(200, 150, "Total");
        painter.drawText(300, 150, "Date");
        painter.drawText(400, 150, "Statut");

        QSqlQueryModel *model = afficher();

        for (int row = 0; row < model->rowCount(); ++row)
        {
            for (int col = 0; col < model->columnCount(); ++col)
            {
                QString data = model->data(model->index(row, col)).toString();
                painter.drawText(100 + col * 100, 200 + row * 50, data);
            }
        }

        file.close();
    }
    else {
        qDebug() << "Erreur lors de l'ouverture du fichier : " << file.errorString();
    }
}
std::string Commande::chatbotFunction(const QString &userMessage) {
std::string lowerMessage = userMessage.toStdString();
std::transform(lowerMessage.begin(), lowerMessage.end(), lowerMessage.begin(), ::tolower);

    if (lowerMessage.find("bonjour") != std::string::npos) {
        return "Salut! Comment puis-je vous aider aujourd'hui?";
    } else if (lowerMessage.find("comment ça va?") != std::string::npos) {
        return "Je suis un programme, donc je n'ai pas de sentiments, mais merci de demander!";
    } else if (lowerMessage.find("quel est ton nom?") != std::string::npos) {
        return "Je suis un chatbot créé par OpenAI.";
    } else if (lowerMessage.find("au revoir") != std::string::npos) {
        return "Au revoir! N'hésitez pas à revenir si vous avez d'autres questions.";
    } else {
        return "Désolé, je ne comprends pas. Pouvez-vous reformuler votre question?";
    }
    return  "Reponse du chatbot";
}
QSqlQueryModel* Commande::historique() const
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM commande ORDER BY date_ DESC");
    if (query.exec()) {
        model->setQuery(query);
    }
    return model;
}
int Commande::getNombreCommandesParStatut(const QString& statut)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM commande WHERE statut = :statut");
    query.bindValue(":statut", statut);
    query.exec();

    if (query.next()) {
        return query.value(0).toInt();
    }

    return 0;
}
int Commande::getTotalCommandes()
{
    QSqlQuery query("SELECT COUNT(*) FROM commande");
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}
