#include "souissi.h"
#include "ui_souissi.h"
#include "widget.h"
#include "ghaya/login.h"
#include "client.h"
#include<QIntValidator>
#include<QMessageBox>
#include <QRegExpValidator>
#include <QtCore>
#include <QtWidgets>
#include <QtCharts>
#include <QDebug>
#include <QtNetwork/QTcpSocket>
#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QDebug>
//#include "twilioexample.h"





  //using namespace QtCharts;

#include"smtp.h"
#include <QPixmap>
#include <QMessageBox>
#include<iostream>
#include <QMessageBox>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
//#include <QtCharts/QPieSeries>
#include <QDesktopServices>
#include <QSqlRecord>
#include<QPieSeries>
#include <QtCharts>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QPdfWriter>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include<QSsl>
#include <QSqlRecord>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateTime>
#include <QUrl>
#include <QUrlQuery>
#include <QtWidgets>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

souissi::souissi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::souissi)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));

        connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
    ui->agec->setValidator(new QIntValidator(0,99, this));
       ui->phonec->setValidator(new QIntValidator(0,99999999, this));
        ui->nomc->setValidator(new QRegExpValidator(  QRegExp("[A-Za-z]*")  ));
         ui->prenomc->setValidator(new QRegExpValidator(  QRegExp("[A-Za-z]*")  ));

      ui->tab_client->setModel(C.afficher());
      chartView = new QChartView(this);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->setParent(ui->horizontalFrameCl);
               chartView->setFixedSize(600, 350);//600

}

souissi::~souissi()
{
    delete ui;
}


void souissi::on_ajouterCl_clicked()
{
    QMessageBox msgBox;
        QString id=ui->idc->text();
        QString nom=ui->nomc->text();
        QString prenom=ui->prenomc->text();
        int age=ui->agec->text().toInt();
        int phone=ui->phonec->text().toInt();
        QString email=ui->emailc->text();

       QString sexe;
        if (ui->feminin->isChecked())
             sexe="feminin";
        else if (ui->masculin->isChecked())
             sexe="masculin";


        Client C(id,nom,prenom,age,sexe,phone,email);
        bool test=C.ajouter();
        if(test)

        {
            msgBox.setText("Ajout avec succes ");
            ui->tab_client->setModel(C.afficher());
            ui->idc->clear();
                                ui->nomc->clear();
                                ui->prenomc->clear();
                                ui->agec->clear();
                                ui->phonec->clear();
                                ui->emailc->clear();

                                ui->feminin->setChecked(false);
                                 ui->masculin->setChecked(false);

        }
         else
                    msgBox.setText("Echec d´ajout");
        msgBox.exec();



}

void souissi::on_modifierCl_clicked()
{
    QMessageBox msgBox;
        QString id=ui->idc->text();
        if (id.isEmpty()) {
                    msgBox.setText("ID n´existe pas");
               }

        QString nom=ui->nomc->text();
        if (nom.isEmpty()) {
                               QSqlQuery query;
                               query.prepare("SELECT NOM_C FROM CLIENT WHERE ID_C = :id;");
                               query.bindValue(":id", id);

                               if (query.exec() && query.next()) {
                                   nom=query.value(0).toString();
                               }}
        QString prenom=ui->prenomc->text();

                if (prenom.isEmpty()) {
                               QSqlQuery query;
                               query.prepare("SELECT PRENOM_C FROM CLIENT WHERE ID_C = :id;");
                               query.bindValue(":id", id);

                               if (query.exec() && query.next()) {
                                   prenom=query.value(0).toString();
                               }}
                int age=ui->agec->text().toInt();
                        if (age==0) {
                                       QSqlQuery query;
                                       query.prepare("SELECT AGE_C FROM CLIENT WHERE ID_C = :id;");
                                       query.bindValue(":id", id);

                                       if (query.exec() && query.next()) {
                                           age=query.value(0).toInt();
                                       }}
                        int phone=ui->phonec->text().toInt();
                        if (phone==0) {
                                       QSqlQuery query;
                                       query.prepare("SELECT NUMERO_DU_TELEPHONE_C FROM CLIENT WHERE ID_C = :id;");
                                       query.bindValue(":id", id);

                                       if (query.exec() && query.next()) {
                                           phone=query.value(0).toInt();
                                       }}
                        QString email=ui->emailc->text();
                        if (email.isEmpty()) {
                                       QSqlQuery query;
                                       query.prepare("SELECT EMAIL_C FROM CLIENT WHERE ID_C = :id;");
                                       query.bindValue(":id", id);

                                       if (query.exec() && query.next()) {
                                           email=query.value(0).toString();
                                       }}

                         QString sexe;
                          if (ui->feminin->isChecked())
                               sexe="feminin";
                          else if (ui->masculin->isChecked())
                               sexe="masculin";
                          if (sexe.isEmpty()) {
                                         QSqlQuery query;
                                         query.prepare("SELECT SEXE_C FROM CLIENT WHERE ID_C = :id;");
                                         query.bindValue(":id", id);

                                         if (query.exec() && query.next()) {
                                             sexe=query.value(0).toString();
                                         }}

        Client C(id,nom,prenom,age,sexe,phone,email);
        bool test=C.modifier();
        if (!C.exists(C.getid()))
        {
            QMessageBox::critical(this, "Erreur", "ID n'existe pas");
            return;  // Exit the function if the ID does not exist
        }

        if(test)

        {
            msgBox.setText("Modification avec succes ");
            ui->tab_client->setModel(C.afficher());
            ui->idc->clear();
                                ui->nomc->clear();
                                ui->prenomc->clear();
                                ui->agec->clear();
                                ui->phonec->clear();
                                ui->emailc->clear();

                                ui->feminin->setChecked(false);
                                 ui->masculin->setChecked(false);

        }
         else
                    msgBox.setText("Echec de modification");
        msgBox.exec();
}

void souissi::on_pdfCl_clicked()
{
    QString strStream;
           QTextStream out(&strStream);

           const int rowCount = ui->tab_client->model()->rowCount();
           const int columnCount = ui->tab_client->model()->columnCount();

           out <<  "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
               <<  QString("<title>%1</title>\n").arg("strTitle")
               <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"

               //     "<align='right'> " << datefich << "</align>"
               "<center> <H1>Liste Des Clients </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

           // headers
           out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
           for (int column = 0; column < columnCount; column++)
               if (!ui->tab_client->isColumnHidden(column))
                   out << QString("<th>%1</th>").arg(ui->tab_client->model()->headerData(column, Qt::Horizontal).toString());
           out << "</tr></thead>\n";

           // data table
           for (int row = 0; row < rowCount; row++)
           {
               out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
               for (int column = 0; column < columnCount; column++)
               {
                   if (!ui->tab_client->isColumnHidden(column))
                   {
                       QString data = ui->tab_client->model()->data(ui->tab_client->model()->index(row, column)).toString().simplified();
                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                   }
               }
               out << "</tr>\n";
           }
           out <<  "</table> </center>\n"
               "</body>\n"
               "</html>\n";
           out <<  "</table> </center>\n"
                        "<img src='C:/Users/samar/OneDrive/Desktop/untitled7/untitled7/image/lo-removebg-preview.png' style='max-width: 100%; max-height: 100%; display: block; margin: auto;' /></center>\n"
                        "</body>\n"
                        "</html>\n";


           QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
           if (QFileInfo(fileName).suffix().isEmpty())
           {
               fileName.append(".pdf");
           }

           QPrinter printer (QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

           QTextDocument doc;
           doc.setHtml(strStream);
           doc.setPageSize(printer.pageRect().size());
           doc.print(&printer);

}

void souissi::sendMail()
{
    Smtp * smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void souissi::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void souissi::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void souissi::on_supprimerCl_clicked()
{
    Client C1;
            C1.setid(ui->suppid_cl->text());

            // Check if the ID exists before attempting deletion
            if (!C1.exists(C1.getid()))
            {
                QMessageBox::critical(this, "Erreur", "ID n'existe pas");
                return;  // Exit the function if the ID does not exist
            }

            bool test = C1.supprimer(C1.getid());

            QMessageBox msgBox;
            if (test)
            {
                msgBox.setText("Suppression avec succès");
                ui->tab_client->setModel(C.afficher());
            }
            else
            {
                msgBox.setText("Échec de suppression");
            }
            msgBox.exec();

}

void souissi::on_chercherCl_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
              QSqlQuery   *query= new QSqlQuery();
              QString id=ui->chercher_idCl->text();
              query->prepare("SELECT * FROM CLIENT WHERE ID_C =:id");

              query->bindValue(":id", id );
               query->exec();
               if (query->next()) {
               model->setQuery(*query);
               ui->tab_client->setModel(model);
               }
               else {
                   QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                   QObject::tr("NO MATCH FOUND !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                   ui->chercher_idCl->clear();}
}

void souissi::on_statistiqueCl_clicked()
{
    Client c;
        QPieSeries *series = new QPieSeries();
         series->setHoleSize(0.35);
         double pf = static_cast<double>(c.statistiqueHommes("feminin")) / (c.statistiqueHommes("feminin") + c.statistiqueHommes("masculin")) * 100;
         double ph = static_cast<double>(c.statistiqueHommes("masculin")) / (c.statistiqueHommes("feminin") + c.statistiqueHommes("masculin")) * 100;

         series->append("Femmes", pf);
         series->append("Hommes", ph);

          /*slice->setExploded();
          slice->setLabelVisible();


          QChart *chart = new QChart();
          chart->addSeries(series);
          chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTitle(" Gender chart  :");
        chart ->setTheme(QChart::ChartThemeBlueCerulean);
        QChartView *chartview = new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        if (ui->horizontalFrame) {
                chartview->setParent(ui->horizontalFrame);
                chartview->setChart(chart);


                QMessageBox::information(this, "Succès", "Statistique validée avec succès.");
            } else {

               QMessageBox::critical(this, "Erreur", "Widget parent non trouvé.");
           }*/
          QChart *chart = new QChart();
                  chart->addSeries(series);
                  chart->setAnimationOptions(QChart::SeriesAnimations);
                  chart->setTitle("Gender Chart");
                  chart->setTheme(QChart::ChartThemeBlueCerulean);

                  chartView->setChart(chart);
}

void souissi::on_ContratCl_clicked()
{
   QString afficheur_code = ui->idcontratCl->text();
           QSqlQuery selectQuery;
           selectQuery.prepare("SELECT * FROM CLIENT WHERE ID_C= :idC");
           selectQuery.bindValue(":idC", afficheur_code);
           if (afficheur_code.isEmpty()) {
                   QMessageBox::critical(this, "Erreur", "Veuillez saisir un identifiant avant de générer le contrat.");
                   return;  // Sortir de la fonction en cas d'erreur
               }
           if (selectQuery.exec() && selectQuery.next() && selectQuery.isValid()) {
               QString nom=selectQuery.value("NOM_C").toString();
               QString prenom=selectQuery.value("PRENOM_C").toString();
               QString id=selectQuery.value("ID_C").toString();

               QString age=selectQuery.value("AGE_C").toString();
               QString sexe=selectQuery.value("SEXE_C").toString();
               QString num=selectQuery.value("NUMERO_DU_TELEPHONE_C").toString();

           QWidget widget;

           QPixmap screenshot = widget.grab();

           QWidget myWidget;

              QVBoxLayout* layout = new QVBoxLayout(&myWidget);

              QLabel* contentLabel = new QLabel("\n"
                                                "Ce contrat de vente de bijoux est conclu entre Aurum Master et le client : "+(nom)+" "+(prenom)+" \n"
                                                "sous l´Identifiant : "+(id)+" avec le numero du telephone : " +(num)+"\n\n\n"
                                                "\n \n"
                                                " Par la présente, le Vendeur s'engage à fournir les bijoux spécifiés dans la commande du Client,\n "
                                                "et le Client s'engage à effectuer le paiement conformément aux modalités convenues.\n\n\n "

                                                 "En cas de rétractation dans les 6 mois suivant la réception, le Client peut exercer son droit de retour\n"
                                                 " conformément aux conditions spécifiées.\n "
                                                 "Tout litige découlant de ce contrat sera résolu par arbitrage conformément aux lois de [pays/état].\n\n\n\n\n"

                                                 "Les Parties reconnaissent avoir lu, compris et accepté les termes de ce contrat, marquant ainsi leur accord en signant ci-dessous\n\n\n"
                                                 "notre signature ici                        votre signature ici\n\n\n\n\n\n\n");

                            layout->addWidget(contentLabel);
                            QLabel* imageLabel = new QLabel();
                                    QPixmap image("C:/Users/samar/OneDrive/Desktop/untitled7/untitled7/image/lo-removebg-preview.png");
                                    imageLabel->setPixmap(image);
                                    layout->addWidget(imageLabel);

              QPixmap screenshot1 = myWidget.grab();
           screenshot1.save("C:/Users/samar/OneDrive/Desktop/contrat6.png", "PNG");
           QMessageBox::information(this, "Confirmation", "Le contrat a été généré avec succès !");
    }
}

void souissi::on_triageCl_clicked()
{
    Client C;
        ui->tab_client->setModel(C.afficher_id());
}

void souissi::on_ref_Cl_clicked()
{
    Client C;
        ui->tab_client->setModel(C.afficher());
}

void souissi::on_homeCl_clicked()
{
    this->hide();
    widget *auth = new widget;
    auth->show();
}

void souissi::on_deconnectCl_clicked()
{
    this->hide();
    login *auth = new login;
    auth->show();
}
