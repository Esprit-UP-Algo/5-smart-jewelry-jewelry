#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include<QMessageBox>
#include<QDebug>
#include<QString>
#include<QTextTable>
#include<QPrinter>
#include <QFileDialog>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_commande->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_clicked()
{

    int numero=ui->lineEdit_N->text().toInt();
    int date_=ui->lineEdit_date->text().toInt();
    int total=ui->lineEdit_total->text().toInt();
    QString statut=ui->lineEdit_statut->text();
    Commande C ( numero, date_, total, statut );
    bool test=C.ajouter();
    if (test){
        ui->tab_commande->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajouter effectue \n"
                            "click cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("ajout non effectue.\n"
                                          "click cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_supp_clicked()
{
        int numero =ui->num_supp->text().toInt();
        bool test=c.supprimer(numero);
        if (test){
            ui->tab_commande->setModel(c.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("suppression  effectue \n"
                                "click cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("suppression non effectue.\n"
                                              "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_modif_clicked()
{

    qDebug();
    int numero=ui->lineEdit_N->text().toInt();
    int date=ui->lineEdit_date->text().toInt();
    int total=ui->lineEdit_total->text().toInt();
    QString statut=ui->lineEdit_statut->text();

    Commande c(numero,date,total,statut);

    bool test=c.modifier(numero);
    if (test){


        ui->tab_commande->setModel(c.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("modifier avec success.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr(" modifier non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_recherche_pushButton_clicked()
{
    Commande commande;
        int numero = ui->lineEdit_recherche->text().toInt();


        QSqlQueryModel *result = commande.rechercher(numero);

        ui->tableView_r->setModel(result);
}

void MainWindow::on_pushButton_clicked()
{

        Commande commande;

        QSqlQueryModel *result = commande.tri();

        ui->tableView_r->setModel(result);
}
void MainWindow::on_pdf_clicked()
{  QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) {
        return;  // L'utilisateur a annulé la boîte de dialogue
    }

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QTextCursor cursor(&doc);

    // En-tête du document
    QTextCharFormat headerFormat;
    headerFormat.setFontPointSize(14);
    headerFormat.setFontWeight(QFont::Bold);
    cursor.setCharFormat(headerFormat);
    cursor.insertText("Liste des commandes\n\n");

    // Crée un tableau avec des colonnes pour chaque champ de la table
    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignLeft);
    QTextTable *table = cursor.insertTable(1, 7, tableFormat);
    QTextCursor cellCursor;

    // Remplir les en-têtes de colonne
    cellCursor = table->cellAt(0, 0).firstCursorPosition();
    cellCursor.insertText("total de commande");

    cellCursor = table->cellAt(0, 1).firstCursorPosition();
    cellCursor.insertText("numero de commande");

    cellCursor = table->cellAt(0, 2).firstCursorPosition();
    cellCursor.insertText("Date");

    cellCursor = table->cellAt(0, 3).firstCursorPosition();
    cellCursor.insertText("statut");



    // Obtain the client data from your table model
    QSqlQueryModel *model = static_cast<QSqlQueryModel*>(ui->tab_commande->model());

    // Fill the table data
    for (int row = 0; row < model->rowCount(); ++row) {
        table->appendRows(1);

        for (int col = 0; col < 7; ++col) {
            cellCursor = table->cellAt(row + 1, col).firstCursorPosition();
            cellCursor.insertText(model->data(model->index(row, col)).toString());
        }
    }

    doc.print(&printer);

    // Display a success message
    QMessageBox::information(this, "Succès", "Liste des commandes exportée sous forme de PDF.");
}


void MainWindow::on_envoyer_clicked()
{
    Commande c;
    QString userMessage = ui->lineEdit_chatbot->text();
    std::string botResponse = c.chatbotFunction(userMessage);
       ui->label_chatbot_response->setText(QString::fromStdString(botResponse));
}

void MainWindow::on_historique_clicked()
{
    Commande commande;
        QSqlQueryModel* historiqueModel = commande.historique();
        ui->tableView_r->setModel(historiqueModel);
}

void MainWindow::on_statistiques_clicked()
{
    Commande commande;

       int totalCommandes = commande.getTotalCommandes();
       int commandesEnCours = commande.getNombreCommandesParStatut("en cours");
       int commandesValidee = commande.getNombreCommandesParStatut("validee");

       double pourcentageEnCours = 0.0;
       double pourcentageValidees = 0.0;

       if (totalCommandes > 0) {
           pourcentageEnCours = (static_cast<double>(commandesEnCours) / totalCommandes) * 100.0;
           pourcentageValidees = (static_cast<double>(commandesValidee) / totalCommandes) * 100.0;
       }

       QString statistiques = "Statistiques des commandes :\n";
       statistiques += "Nombre total de commandes : " + QString::number(totalCommandes) + "\n";
       statistiques += "Nombre de commandes en cours : " + QString::number(commandesEnCours) + " (" + QString::number(pourcentageEnCours, 'f', 2) + "%)\n";
       statistiques += "Nombre de commandes validées : " + QString::number(commandesValidee) + " (" + QString::number(pourcentageValidees, 'f', 2) + "%)";

       ui->label_stat->setText(statistiques);
}
