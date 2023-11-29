#include "commande.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QPdfWriter>
#include <QPainter>
#include <algorithm>
#include <QMap>
#include <QHash>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QDate>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>

Commande::Commande()
{
    numero=0;
    date_="";
    total=0;
    statut="";
}
Commande::Commande(int numero,QString date_,int total,QString statut)
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
        QString total_string = QString::number(total);

        QSqlQuery query;
        query.prepare("INSERT INTO Commande (numero, date_, total, statut) "
                      "VALUES (:numero, :date_, :total, :statut)");
        query.bindValue(":numero", num_string);
        query.bindValue(":date_", date_);
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
    QString res3= QString::number(total);
    query.prepare("update commande set numero=:numero,date_=:date_,total=:total,statut=:statut WHERE numero=:numero");
    query.bindValue(":numero",res);
    query.bindValue(":date_",date_);
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
    query.prepare("SELECT * FROM commande ORDER BY TO_DATE(date_, 'DD/MM/YYYY') DESC");
    if (query.exec()) {
        model->setQuery(query);
    }
    return model;
}
void Commande::exporterHistoriqueTexte(const QString &nomFichier) const
{
    QFile file(nomFichier);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << "Liste des Commandes\n\n";

        QSqlQueryModel *model = historique();

        for (int row = 0; row < model->rowCount(); ++row)
        {
            stream << "date: " << model->data(model->index(row, 2)).toString() << "\t";
            stream << "numero: " << model->data(model->index(row, 1)).toString() << "\t";
            stream << "total: " << model->data(model->index(row, 0)).toString() << "\t";
            stream << "statut: " << model->data(model->index(row, 3)).toString() << "\n";
        }

        file.close();
    }
    else {
        qDebug() << "Erreur lors de l'ouverture du fichier : " << file.errorString();
    }
}

QString Commande::statistiquesParStatut()
{
    int commandesEnCours = getNombreCommandesParStatut("en cours");
    int commandesValidees = getNombreCommandesParStatut("validee");
    int totalCommandes = commandesEnCours + commandesValidees;

    QtCharts::QPieSeries *pieSeries = new QtCharts::QPieSeries();

    QtCharts::QPieSlice *enCoursSlice = new QtCharts::QPieSlice();
    QtCharts::QPieSlice *valideeSlice = new QtCharts::QPieSlice();

    enCoursSlice->setBrush(QColor(Qt::red));
    valideeSlice->setBrush(QColor(Qt::blue));

    if (totalCommandes > 0) {
        enCoursSlice->setValue(static_cast<double>(commandesEnCours));
        valideeSlice->setValue(static_cast<double>(commandesValidees));
    }

    pieSeries->append(enCoursSlice);
    pieSeries->append(valideeSlice);

    enCoursSlice->setLabel(QObject::tr("En cours") + ": " + QString::number(enCoursSlice->percentage() * 100, 'f', 1) + "%");
    valideeSlice->setLabel(QObject::tr("Validée") + ": " + QString::number(valideeSlice->percentage() * 100, 'f', 1) + "%");

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(pieSeries);
    chart->setTitle("Statistiques des commandes");

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    chartView->show();

    QString statistiques = "Statistiques des commandes :\n";
    statistiques += QObject::tr("En cours") + " : " + QString::number(enCoursSlice->percentage() * 100, 'f', 1) + "%\n";
    statistiques += QObject::tr("Validée") + " : " + QString::number(valideeSlice->percentage() * 100, 'f', 1) + "%";

    return statistiques;
}
/*
QGraphicsScene& Commande::statistiquesParStatut()
{
    int commandesEnCours = getNombreCommandesParStatut("en cours");
    int commandesValidees = getNombreCommandesParStatut("validee");
    int totalCommandes = commandesEnCours + commandesValidees;

    QtCharts::QPieSeries *pieSeries = new QtCharts::QPieSeries();

    QtCharts::QPieSlice *enCoursSlice = new QtCharts::QPieSlice();
    QtCharts::QPieSlice *valideeSlice = new QtCharts::QPieSlice();

    enCoursSlice->setBrush(QColor(Qt::red));
    valideeSlice->setBrush(QColor(Qt::blue));

    if (totalCommandes > 0) {
        enCoursSlice->setValue(static_cast<double>(commandesEnCours));
        valideeSlice->setValue(static_cast<double>(commandesValidees));
    }

    pieSeries->append(enCoursSlice);
    pieSeries->append(valideeSlice);

    enCoursSlice->setLabel(QObject::tr("En cours") + ": " + QString::number(enCoursSlice->percentage() * 100, 'f', 1) + "%");
    valideeSlice->setLabel(QObject::tr("Validée") + ": " + QString::number(valideeSlice->percentage() * 100, 'f', 1) + "%");

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(pieSeries);
    chart->setTitle("Statistiques des commandes");

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QGraphicsProxyWidget *proxyWidget = new QGraphicsProxyWidget();
    proxyWidget->setWidget(chartView);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(proxyWidget);

    return *scene;
}
*/
int Commande::getNombreCommandesParStatut(const QString &statut)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Commande WHERE statut = :statut");
    query.bindValue(":statut", statut);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }

    return -1; // Une valeur négative indique une erreur
}
bool Commande::commandeExists()
{
    QSqlQuery query("SELECT COUNT(*) FROM commande WHERE etat = 'annuler'");

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();

        // If there are commands with state 'annuler', return true
        if (count > 0) {
            return true;
        }
    }

    return false;
}
