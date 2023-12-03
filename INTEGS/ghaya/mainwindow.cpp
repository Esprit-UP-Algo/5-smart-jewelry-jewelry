#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
using namespace std;
#include"employe.h"
#include"conection.h"
#include "calendrier.h"
#include "oublier.h"
#include "login.h"
#include "arduino.h"
#include <iostream>
#include <QTextCodec>
#include "widget.h"
#include "calendrier.h"
#include "events.h"



//pdf
#include <QPrinter>
#include <QPainter>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

//stat
#include <QVBoxLayout>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //*****
    //QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));
    //*************
    int ret=A.connect_arduino () ; // lancer la connexion à arduino
switch(ret) {
case (0) : qDebug ()<< "arduino is available and connected to : "<< A.getarduino_port_name () ;
break;
case (1) : qDebug() << "arduino is available but not connected to :" << A.getarduino_port_name () ;
break;
case (-1): qDebug() << "arduino is not available";
}
QObject:: connect (A.getserial (), SIGNAL(readyRead()), this, SLOT(update_label ())); // permet de lancer //le slot update_label suite à la reception du signal readyRead (reception des données).
    //*******
        ui->tableView->setModel(e.afficher());
        ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
        ui->lineEdit_cinsupp->setValidator(new QIntValidator(0,99999999,this));
        ui->lineEdit_abs->setValidator(new QIntValidator(0,999,this));
        ui->lineEdit_salaire->setValidator(new QIntValidator(0,99999,this));
        ui->lineEdit_nom->setMaxLength(8);
        ui->lineEdit_nom->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z_]{1,8}$"), this));
        ui->lineEdit_prenom->setMaxLength(8);
        ui->lineEdit_prenom->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z_]{1,8}$"), this));
        ui->lineEdit_rechcin->setValidator(new QIntValidator(0,99999999,this));


        // Créez le widget principal
            mainWidget = new QWidget(this);
            statsWidget = new QMainWindow(this);
            // Ajoutez des composants au widget principal
            // ...

            // Exemple : Ajoutez un bouton pour afficher les statistiques
            /*QPushButton *button = new QPushButton("Afficher Statistiques", mainWidget);
            connect(button, SIGNAL(clicked()), this, SLOT(afficherStatistiques()));*/
            // Positionnez et stylisez le bouton selon vos besoins

            // Créez le widget pour les statistiques (initialement masqué)
            statsWidget = new QWidget(this);
            statsWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            statsWidget->hide();

            // Ajoutez des widgets (comme votre graphique de statistiques) à statsWidget
            // ...

            // Ajoutez un bouton pour revenir à la page initiale depuis les statistiques
          //  QPushButton *backButton = new QPushButton("Revenir à la page initiale", statsWidget);
            //connect(backButton, SIGNAL(clicked()), this, SLOT(revenirPageInitiale()));
            // Positionnez et stylisez le bouton selon vos besoins
            marquerJoursFeries(ui->calendarWidget);







}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_ajouter_clicked()
{
    qDebug();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    int CIN=ui->lineEdit_cin->text().toInt();
    int abs=ui->lineEdit_abs->text().toInt();
    QDate dateE=ui->dateEdit->date();
    int salaire=ui->lineEdit_salaire->text().toInt();
    QString mdp=ui->lineEdit_mdp->text();
    QString RFID=ui->lineEdit_RFID->text();
    employe e(nom,prenom,CIN,abs,dateE,salaire,mdp,RFID);

    bool test=e.ajouter();
    if (test){


        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout avec success.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr(" ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int CIN=ui->lineEdit_cinsupp->text().toInt();
    bool test=e.supprimer(CIN);

    if (test){
        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression avec success.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr(" suppression non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_pushButton_modifier_clicked()
{

    qDebug();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    int CIN=ui->lineEdit_cin->text().toInt();
    int abs=ui->lineEdit_abs->text().toInt();
    QDate dateE=ui->dateEdit->date();
    int salaire=ui->lineEdit_salaire->text().toInt();
    QString mdp=ui->lineEdit_mdp->text();
    QString RFID=ui->lineEdit_RFID->text();

    employe e(nom,prenom,CIN,abs,dateE,salaire,mdp,RFID);

    bool test=e.modifier(CIN);
    if (test){


        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("modifier avec success.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr(" modifier non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}





void MainWindow::exportToPDF() {
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

        if (filePath.isEmpty()) {
            // L'utilisateur a annulé la sélection du fichier
            return;
        }

        // Créer un objet QPrinter
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filePath);

        // Créer un objet QPainter qui dessinera sur le QPrinter
        QPainter painter(&printer);

        // Commencer le dessin sur la page
        painter.begin(&printer);

        // Définir la taille de la page
        printer.setPageSize(QPrinter::A4);

        // Définir la police et la taille du texte
        painter.setFont(QFont("Arial", 12));

        // Dessiner le titre
        painter.drawText(100, 100, "Liste des employés");

        // Dessiner l'en-tête du tableau
        painter.drawText(100, 120, "Nom");
        painter.drawText(200, 120, "Prénom");
        painter.drawText(300, 120, "CIN");
        painter.drawText(400, 120, "Salaire");
        // Ajouter d'autres en-têtes selon vos besoins

        // Récupérer les données depuis la base de données
        QSqlQuery query;
        query.prepare("SELECT * FROM employe");
        if (query.exec()) {
            int row = 140;
            int rowCount = 0;
            while (query.next()) {
                QString nom = query.value("nom").toString();
                QString prenom = query.value("prenom").toString();
                int cin = query.value("CIN").toInt();
                int salaire = query.value("salaire").toInt();
                // Ajouter d'autres colonnes selon vos besoins

                // Dessiner les données des employés
                painter.drawText(100, row, nom);
                painter.drawText(200, row, prenom);
                painter.drawText(300, row, QString::number(cin));
                painter.drawText(400, row, QString::number(salaire));
                // Ajouter d'autres colonnes selon vos besoins

                row += 20; // Augmenter la position Y pour la prochaine ligne
                rowCount++;

                // Passer à une nouvelle page après un certain nombre de lignes (par exemple, 20 lignes)
                if (rowCount % 20 == 0) {
                    printer.newPage();
                    row = 100; // Réinitialiser la position Y pour la nouvelle page
                }
            }
        } else {
            // Gestion de l'erreur de la requête
            QMessageBox::warning(this, "Erreur", "Erreur lors de l'exécution de la requête SQL : " + query.lastError().text());
        }

        // Terminer le dessin sur la page
        painter.end();

        // Afficher un message de succès
        QMessageBox::information(this, "Export PDF", "Les données des employés ont été exportées avec succès vers un fichier PDF.");
}

void MainWindow::on_pushButton_pdf_clicked()
{
    exportToPDF();
}

//********************
void MainWindow::marquerJoursFeries(QCalendarWidget *calendrier) {
    // Liste des jours fériés (à remplir avec vos propres dates et raisons)
    QMap<QDate, QString> joursFeries;
    joursFeries.insert(QDate(2023, 1, 1), "Jour de l'an");
    joursFeries.insert(QDate(2023, 5, 1), "Fête du Travail");
    joursFeries.insert(QDate(2023, 7, 14), "Fête Nationale");

    // Appliquer le style aux jours fériés
    QTextCharFormat format;
    format.setBackground(QBrush(QColor("red")));

    for (auto it = joursFeries.begin(); it != joursFeries.end(); ++it) {
        QDate jourFerie = it.key();
        QString raison = it.value();

        calendrier->setDateTextFormat(jourFerie, format);

        // Assurez-vous que le calendrier est configuré pour être sélectionnable
        calendrier->setSelectionMode(QCalendarWidget::SingleSelection);

        // Connectez le signal clicked au slot correspondant pour afficher la raison
        connect(calendrier, &QCalendarWidget::clicked, [=](const QDate &date) {
            if (date == jourFerie) {
                ui->textEdit->setText(raison);
            }
        });
    }
}


//****************







void MainWindow::afficherStatistiques() {
    QBarSeries *series = new QBarSeries();

    // Récupérer les données d'absence depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT nom, abs FROM employe");
    if (query.exec()) {
        while (query.next()) {
            QString nom = query.value("nom").toString();
            int abs = query.value("abs").toInt();

            QBarSet *absenceSet = new QBarSet(nom);
            *absenceSet << abs;

            series->append(absenceSet);
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête SQL : " << query.lastError().text();
        // Gérez l'erreur de la requête SQL ici
        return;
    }

    // Créer le graphique et y ajouter la série
    QChart *chart = new QChart();
    chart->addSeries(series);

    // Créer l'axe X et définir le titre
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    axisX->setTitleText("employées");
    series->attachAxis(axisX);

    // Créer l'axe Y et définir le titre
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre d'absences");

    // Configurer l'axe pour afficher des étiquettes entières
    axisY->setLabelFormat("%d");
    axisY->setTickCount(10);  // Nombre de marques sur l'axe, ajustez selon vos besoins

    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Créer la vue du graphique
    if (chartView == nullptr) {
        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        ui->verticalLayout->addWidget(chartView); // Assurez-vous d'avoir un layout vertical dans votre MainWindow
    } else {
        // Si la vue du graphique existe déjà, mettez à jour la série
        chartView->chart()->removeAllSeries();
        chartView->chart()->addSeries(series);
    }

    chartView->update();
}
void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tableView->setModel(e.afficher());
}



void MainWindow::on_pushButton_stat_clicked()
{
    afficherStatistiques();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    // Instanciez un objet employe
        employe e;

        // Obtenez le critère de tri sélectionné
        QString critereTri = ui->comboBox->currentText();

        // Obtenez le modèle trié en fonction du critère sélectionné
        QSqlQueryModel *modelTri;

        if (critereTri == "Salaire") {
            modelTri = e.trierParSalaire();
        } else if (critereTri == "Date d'embauche") {
            modelTri = e.trierParDateEmbauche();
        } else {
            // Gérez toute autre option ou erreur ici
            return;
        }

        // Utilisez le modèle trié pour mettre à jour votre vue (par exemple, QTableView)
        ui->tableView->setModel(modelTri);
}

//*********************************

void MainWindow::on_pushButton_rechcin_clicked()
{
    employe e;

    // Récupération du CIN depuis le lineEdit
    int CIN = ui->lineEdit_rechcin->text().toInt();

    // Appel de la fonction de recherche avec le CIN récupéré et la vue de table
   e.rechercher(ui->tableView,CIN);
}

void MainWindow::on_pushButton_raf_clicked()
{
    ui->tableView->setModel(e.afficher());

}
//++++++++++++








/*void MainWindow::on_pushButton_eve_clicked()
{
   // calendrier *auth = new calendrier;
   // auth->show();
    marquerJoursFeries(QCalendarWidget *calendrier)

}*/
//*************


void MainWindow::on_pushButton_deconect_clicked()
{
    this->hide();
        login *auth = new login;
        auth->show();
}
//***************
/*void MainWindow::update_label() {
    QByteArray data = A.read_from_arduino();

    // Vérifiez si les données reçues commencent par "UID :"
    if (data.startsWith("UID:")) {
        QString uidString = QString(data.mid(4)).trimmed(); // Extraire l'UID des données
        QString employeeInfo = A.getemployeInfo(uidString);

        // Mettez à jour l'écran LCD ou tout autre élément d'interface utilisateur avec les informations de l'employé
        ui->lcdDisplay->clear(); // En supposant que lcdDisplay est l'ID de votre widget LCD
        ui->lcdDisplay->setText("Bonjour " + employeeInfo);
    }
}*/

void MainWindow::update_label() {
QByteArray data = A.getserial()->readAll();
    QString receivedData = QString::fromUtf8(data);

    if (!receivedData.isEmpty()) {
        // Supposons que les données série contiennent uniquement l'UID
        QString RFID = receivedData.trimmed();
        qDebug() << RFID;

        QSqlQuery query;
        query.prepare("SELECT nom, prenom FROM employe WHERE RFID=:RFID");
        query.bindValue(":RFID", RFID);

        if (query.exec() && query.next()) {
            QString nom = query.value("nom").toString();
            QString prenom = query.value("prenom").toString();
            QByteArray nomData = nom.toUtf8();
                       A.write_to_arduino(nomData);
                         // Mettre à jour l'écran LCD avec l'identifiant

        } else {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                QObject::tr("Veuillez vérifier le badge.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    }


}
//*update3
/*void MainWindow::update_label() {
    QByteArray data = A.getserial()->readAll();
    QString receivedData = QString::fromUtf8(data);

    if (!receivedData.isEmpty()) {
        QString cin = receivedData.trimmed();
        qDebug() << "CIN: " << cin;

        // Obtenir les informations de l'employé à partir de la base de données
        QString employeInfo = A.getemployeInfo(cin);

        if (employeInfo != "Non trouvé") {
            qDebug() << "Employé trouvé: " << employeInfo;

            // Mettre à jour l'écran LCD avec les informations de l'employé
            // (vous devez adapter cela en fonction de votre affichage LCD)
            // Par exemple, si vous avez une fonction d'affichage LCD comme lcd.display(employeInfo);
        } else {
            qDebug() << "Employé non trouvé";
            // Gérer le cas où l'employé n'est pas trouvé (affichage sur l'écran LCD ou autre)
        }
    }
}*/

/*void MainWindow::displayEmployeeInfoOnLCD() {
    QByteArray data = A.getserial()->readAll();
    QString receivedData = QString::fromUtf8(data);

    if (!receivedData.isEmpty() && receivedData.startsWith("UID:")) {
        QString badgeCode = receivedData.mid(4).trimmed();

        QSqlQuery query;
        query.prepare("SELECT nom, prenom FROM employe WHERE code=:badgeCode");
        query.bindValue(":badgeCode", badgeCode);
        if (query.exec() && query.next()) {
            QString nom = query.value("nom").toString();
            QString prenom = query.value("prenom").toString();

            // Envoie les informations de l'employé à Arduino via la liaison série
            QString message = "EMPLOYEE_INFO:" + nom + ":" + prenom + "\n";
            A.getserial()->write(message.toUtf8());
        } else {
            // Code de badge non trouvé dans la base de données
            qDebug() << "Code de badge non valide";
        }
    }
}*/

void MainWindow::connect_RFID()

{
    // pour tester si la connexion lors du passage de la carte rfid a ete effectué ou non avec un label 'RFID_Label'
    //ui->RFID_Label->setText("arduino detecte");

    data=A.read_from_arduino();
    QString uid = QTextCodec::codecForMib(106)->toUnicode(data);

    qDebug()<<uid;//pour tester dans la console de QT

    //ui->RFID_Label->setText(uid);/*------- pour tester avec un label----------*/

    employe e; //remplacez avec le nom de votre classe

     // cas ou elle n'existe
    if(e.rfidExists(uid))

        {

            QByteArray data1;
            data1.append('1');
            A.write_to_arduino(data1);//envoie 1 a arduino et enclenche /demarre le processus 1

            qDebug()<<"carte existante";

            //prend la valeur du nom
            QString nom = e.rfidName(uid);
            //ui->RFID_NOM->setText(nom);
            //ui->stackedWidget->setCurrentIndex(2); redirige ves la page 3 de votre application.a activer seulement si vous avez un systeme de stacked Widget


            QByteArray nomData(nom.toUtf8(), 8);
            A.write_to_arduino(nomData);

        }

    // cas ou elle n'existe pas
    else if (!e.rfidExists(uid))
        {
            //inexistante
                QByteArray data1;
                data1.append('2');
                A.write_to_arduino(data1); // envoie 2 a arduino et enclenche /demarre le processus 2

                qDebug()<<"carte inexistante";

        }

    }

void MainWindow::loginArd(){
QByteArray data = A.getserial()->readAll();
    QString receivedData = QString::fromUtf8(data);

    if (!receivedData.isEmpty()) {
        // Supposons que les données série contiennent uniquement l'UID
        QString badgeCode = receivedData.trimmed();
        qDebug() << badgeCode;

        QSqlQuery query;
        query.prepare("SELECT * FROM employe WHERE RFID=:badgeCode ");
        query.bindValue(":badgeCode", badgeCode);

        if (query.exec() && query.next()) {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Login réussi avec succès.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
            this->hide();
            widget *auth = new widget;
            auth->show();

                         // Mettre à jour l'écran LCD avec l'identifiant

        } else {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                QObject::tr("Veuillez vérifier le badge.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    }}


void MainWindow::on_pushButton_clicked()
{
   this->hide();
   widget *auth = new widget;
   auth->show();
}
