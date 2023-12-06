#include "facture.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

//setters
void Facture::setID_FACTURE(int n){ID_FACTURE= n;}
void Facture::setDATE_FACTURATION(QString n){DATE_FACTURATION= n;}
void Facture::setMONTANT(int n){MONTANT= n;}
void Facture::setMETHOD_PAIEMENT(QString n){METHOD_PAIEMENT= n;}

//getters

int Facture::get_ID_FACTURE(){return ID_FACTURE;}
QString Facture::get_DATE_FACTURATION() const {return DATE_FACTURATION;}
float Facture::get_MONTANT()  {return MONTANT;}
QString Facture::get_METHOD_PAIEMENT()const{return METHOD_PAIEMENT;}
//CONSTRUCTEUR PAR DEFAUT
Facture::Facture()
{
}
//CONSTRUCTEUR PARAMETRE
Facture::Facture(int ID_FACTURE,QString DATE_FACTURATION,QString METHOD_PAIEMENT,int MONTANT)
{
    this->ID_FACTURE=ID_FACTURE;
    this->DATE_FACTURATION=DATE_FACTURATION;
    this->METHOD_PAIEMENT=METHOD_PAIEMENT;
    this->MONTANT=MONTANT;
}
//CRUD
bool Facture::ajouter()
{
    QSqlQuery query;




        query.prepare("INSERT INTO FACTURE (ID_FACTURE, DATE_FACTURATION,METHOD_PAIEMENT,MONTANT) "
                      "VALUES (:ID_FACTURE, :DATE_FACTURATION, :METHOD_PAIEMENT, :MONTANT)");
        query.bindValue(":ID_FACTURE", ID_FACTURE);
        query.bindValue(":DATE_FACTURATION", DATE_FACTURATION);
        query.bindValue(":MONTANT", MONTANT);
        query.bindValue(":METHOD_PAIEMENT", METHOD_PAIEMENT);






       return query.exec();

}
QSqlQueryModel *Facture::afficher()
{

  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM FACTURE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FACTURATION"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("METHOD_PAIEMENT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT"));



        return model;
}
bool Facture::modifier(int)
{

QSqlQuery query;

QString id_string=QString::number(ID_FACTURE);
QString montant_string=QString::number(MONTANT);

query.prepare("UPDATE FACTURE SET ID_FACTURE=:ID_FACTURE,DATE_FACTURATION=:DATE_FACTURATION,MONTANT=:MONTANT,METHOD_PAIEMENT=:METHOD_PAIEMENT WHERE ID_FACTURE=:ID_FACTURE;");

query.bindValue(":ID_FACTURE", id_string);
query.bindValue(":DATE_FACTURATION", DATE_FACTURATION);
query.bindValue(":MONTANT", montant_string);
query.bindValue(":METHOD_PAIEMENT", METHOD_PAIEMENT);


return query.exec();

}
bool Facture::idExists(int id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FACTURE WHERE ID_FACTURE = ?");
    query.addBindValue(id);
    query.exec();
    query.next();
    int count = query.value(0).toInt();
    return count > 0;
}
bool Facture::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
         query.prepare("delete from FACTURE where ID_FACTURE=:id");
         query.bindValue(":id", res);
      return query.exec();
}
QSqlQueryModel* Facture::trie(QString critere)
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    // Utilisation de bindValue pour éviter les attaques par injection SQL
    QSqlQuery query;
    QString queryString = "SELECT * FROM FACTURE ORDER BY MONTANT " + critere;

    qDebug() << "Query: " << queryString;  // Output the generated query

    query.prepare(queryString);

    if (query.exec()) {
        modal->setQuery(query);
    } else {
        // Handle the error, e.g., show an error message
        qDebug() << "Error executing the query: " << query.lastError().text();
    }

    return modal;
}



QSqlQueryModel* Facture::searchFactureById(int idFacture)
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM FACTURE WHERE ID_FACTURE = :idFacture");
    query.bindValue(":idFacture", idFacture);

    if (query.exec()) {
        modal->setQuery(query);
    } else {
        // Handle the error, e.g., show an error message
        qDebug() << "Error executing the query: " << query.lastError().text();
    }

    return modal;
}

QChartView* Facture::stat()
{
    QSqlQuery query;
    query.prepare("SELECT METHOD_PAIEMENT, COUNT(*) AS method_count FROM FACTURE GROUP BY METHOD_PAIEMENT");
    query.exec();

    QPieSeries *series = new QPieSeries();

    while (query.next()) {
        QString methodPaiement = query.value("METHOD_PAIEMENT").toString();
        int count = query.value("method_count").toInt();
        series->append(methodPaiement, count);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique du Paiement Method");

    series->setLabelsVisible();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setAnimationOptions(QChart::AllAnimations);
    chartView->chart()->legend()->hide();
    chartView->resize(1000, 500);

    return chartView;
}

void Facture::on_pdf_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT METHOD_PAIEMENT, COUNT(*) AS method_count FROM FACTURE GROUP BY METHOD_PAIEMENT");

    if (query.exec()) {
        QPdfWriter pdfWriter("report.pdf");
        QPainter painter(&pdfWriter);
        QTextDocument doc;

        QString report = "<p style='font-size:300pt;'>statistique basé sur le methode de paiment :</p>";

        QPieSeries *series = new QPieSeries();

        // Variables to calculate the total count for percentage calculation
        int totalCount = 0;

        while (query.next()) {
            QString methodPaiement = query.value("METHOD_PAIEMENT").toString();
            int count = query.value("method_count").toInt();
            totalCount += count;

            // Add data to the pie chart series
            series->append(methodPaiement, count);
        }

        // Assuming chartView is a QChartView
        QChartView chartView;
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("statistique ");

        // Variables to store data for the PDF report
        QString pieChartReport;
        QString legendReport;

        series->setLabelsVisible();

        // Set the size of the QChartView to maximize the image size
        chartView.setRenderHint(QPainter::Antialiasing);
        chartView.setChart(chart);
        chartView.resize(5000, 5000);  // Adjust the size as needed

        // Convert chartView to an image and add it to the PDF
        QImage chartImage = chartView.grab().toImage();
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        chartImage.save(&buffer, "PNG");

        QString base64Image = QString::fromLatin1(byteArray.toBase64().data());

        // Add legend information to the PDF
        legendReport += "<p style='font-size:300pt;'><strong>methode paiment statistique:</strong></p>";

        for (int i = 0; i < series->slices().size(); ++i) {
            QPieSlice *slice = series->slices().at(i);
            QString methodPaiement = slice->label();
            int count = slice->value();

            // Calculate percentage
            qreal percentage = (static_cast<qreal>(count) / totalCount) * 100.0;

            // Add legend information to the PDF
            legendReport += QString("<p style='font-size:200pt;'><strong>%1:</strong> %2% - Color: %3</p>")
                .arg(methodPaiement)
                .arg(QString::number(percentage, 'f', 2))
                .arg(slice->color().name());
        }

        // Add legend report to the PDF
        report += legendReport;

        // Add pie chart image to the PDF at the bottom
        pieChartReport += "<p style='font-size:300pt;'><strong>Payment Method Statistics Chart:</strong></p>";
        pieChartReport += "<p></p>";

        pieChartReport += "<img src='data:image/png;base64," + base64Image + "'>";
        report += pieChartReport;

        doc.setHtml(report);
        doc.drawContents(&painter);
    }
    else {
        qDebug() << "Error generating the report: " << query.lastError();
    }
}

