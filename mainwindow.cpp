#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include "twilioexample.h"





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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
   // connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
   // connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
   ui->agec->setValidator(new QIntValidator(0,999, this));
   ui->phonec->setValidator(new QIntValidator(0,99999999, this));
    ui->nomc->setValidator(new QRegExpValidator(  QRegExp("[A-Za-z]*")  ));
     ui->prenomc->setValidator(new QRegExpValidator(  QRegExp("[A-Za-z]*")  ));

  ui->tab_client->setModel(C.afficher());
  chartView = new QChartView(this);
          chartView->setRenderHint(QPainter::Antialiasing);
          chartView->setParent(ui->horizontalFrame);
          chartView->setFixedSize(600, 400);//600


          int ret=A.connect_arduino(); // lancer la connexion à arduino
          switch(ret){
          case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
              break;
          case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
             break;
          case(-1):qDebug() << "arduino is not available";
          }
           QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
           //le slot update_label suite à la reception du signal readyRead (reception des données).

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    QMessageBox msgBox;
    QString id=ui->idc->text();
    QString nom=ui->nomc->text();
    QString prenom=ui->prenomc->text();
    int age=ui->agec->text().toInt();
    int phone=ui->phonec->text().toInt();
    QString email=ui->emailc->text();
    QString date=ui->datec->text();
   QString sexe;
    if (ui->feminin->isChecked())
         sexe="feminin";
    else if (ui->masculin->isChecked())
         sexe="masculin";


    Client C(id,nom,prenom,date,age,sexe,phone,email);
    bool test=C.ajouter();
    if(test)

    {
        msgBox.setText("Ajout avec succes ");
        ui->tab_client->setModel(C.afficher());
    }
     else
                msgBox.setText("Echec d´ajout");
    msgBox.exec();



}

void MainWindow::on_supprimer_clicked()
{
    Client C1;
        C1.setid(ui->suppid_c->text());

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

void MainWindow::on_modifier_clicked()
{
    QMessageBox msgBox;
    QString id=ui->idc->text();
    QString nom=ui->nomc->text();
    QString prenom=ui->prenomc->text();
    int age=ui->agec->text().toInt();
    int phone=ui->phonec->text().toInt();
    QString email=ui->emailc->text();
     QString date=ui->datec->text();
     QString sexe;
      if (ui->feminin->isChecked())
           sexe="feminin";
      else if (ui->masculin->isChecked())
           sexe="masculin";

    Client C(id,nom,prenom,date,age,sexe,phone,email);
    bool test=C.modifier();

    if(test)

    {
        msgBox.setText("Modification avec succes ");
        ui->tab_client->setModel(C.afficher());
    }
     else
                msgBox.setText("Echec de modification");
    msgBox.exec();





}



void MainWindow::on_chercher_clicked()
{

    QSqlQueryModel *model= new QSqlQueryModel();
          QSqlQuery   *query= new QSqlQuery();
          QString id=ui->chercher_id->text();
          query->prepare("SELECT * FROM CLIENT WHERE ID_C  LIKE :id");
          query->bindValue(":id", id + "%");
           query->exec();
           if (query->next()) {
           model->setQuery(*query);
           ui->tab_client->setModel(model);
           }
           else {
               QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                               QObject::tr("NO MATCH FOUND !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
               ui->chercher_id->clear();}
}


void MainWindow::on_pdf_clicked()
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

void MainWindow::on_pushButton_clicked()
{
    Client C;
    ui->tab_client->setModel(C.afficher_id());
}



void MainWindow::on_stat_clicked()
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



void MainWindow::sendMail()
{
    Smtp * smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    //if( !files.isEmpty() )
       // smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    //else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void MainWindow::on_sms_clicked()
{



            QDesktopServices::openUrl(QUrl("https://mystudents.tunisiesms.tn/send"));


}


void MainWindow::on_pushButton_2_clicked()
{
    int afficheur_code = ui->idcontrat->text().toInt();
       QSqlQuery selectQuery;
       selectQuery.prepare("SELECT * FROM CLIENT WHERE ID_C= :idC");
       selectQuery.bindValue(":idC", afficheur_code);
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

          QLabel* contentLabel = new QLabel("\n\n\n\n l´id du client: " + (id)+"\n\n\n  "

                                            "avec le numero du telephone :" +(num)+"\n\n\n"
                                            "sous le nom :"+(nom)+"\n\n\n"
                                            "et prenom :"+(prenom)+"\n\n\n"
                                            "de sexe :"+(sexe)+"\n\n\n"

                                            "\n\n\n\n\n"
                                            "notre signature ici                        votre signature ici\n\n\n\n\n\n\n");

          layout->addWidget(contentLabel);

          QPixmap screenshot1 = myWidget.grab();
       screenshot1.save("C:/Users/samar/OneDrive/Desktop/window_design5.png", "PNG");
}}
