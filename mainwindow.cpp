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
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_r->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_clicked()
{

    int numero=ui->lineEdit_N->text().toInt();
    QString date_ = ui->lineEdit_date->text();
    int total=ui->lineEdit_total->text().toInt();
    QString statut=ui->lineEdit_statut->text();
    Commande C(numero,date_,total,statut);
    bool test=C.ajouter();
    if (test){
        ui->tableView_r->setModel(c.afficher());
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
            ui->tableView_r->setModel(c.afficher());
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
    QString date = ui->lineEdit_date->text();
    int total=ui->lineEdit_total->text().toInt();
    QString statut=ui->lineEdit_statut->text();

    Commande c(numero,date,total,statut);

    bool test=c.modifier(numero);
    if (test){


        ui->tableView_r->setModel(c.afficher());
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

void MainWindow::on_tri_clicked()
{

        Commande commande;

        QSqlQueryModel *result = commande.tri();

        ui->tableView_r->setModel(result);
}
void MainWindow::on_pdf_clicked()
{  QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) {
        return;
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
    QSqlQueryModel *model = static_cast<QSqlQueryModel*>(ui->tableView_r->model());

    // Fill the table data
    for (int row = 0; row < model->rowCount(); ++row) {
        table->appendRows(1);

        for (int col = 0; col < 7; ++col) {
            cellCursor = table->cellAt(row + 1, col).firstCursorPosition();
            cellCursor.insertText(model->data(model->index(row, col)).toString());
        }
    }

    doc.print(&printer);

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
        QString fileName = QFileDialog::getSaveFileName(this, "Exporter l'historique en texte", "", "Fichiers texte (*.txt)");
        if (!fileName.isEmpty()) {
            commande.exporterHistoriqueTexte(fileName);
            QMessageBox::information(this, "Succès", "Historique exporté sous forme de fichier texte.");
        }
}

void MainWindow::on_statistiques_clicked()
{
    Commande commande;
    QString statistiques = commande.statistiquesParStatut();

       ui->label_stat->setText(statistiques);
}
/*
void MainWindow::on_statistiques_clicked()
{
    QGraphicsScene& scene = c.statistiquesParStatut();
        ui->graphicsView_sta->setScene(&scene);
}
*/
void MainWindow::connect_commande()
{
    Commande c;

    // Check for command with status 'annuler'
    if (c.commandeExists()) {
        QByteArray data1;
        data1.append('1');
        A.write_to_arduino(data1);

        qDebug() << "Commande avec statut 'annuler' trouvée";
    } else {
        // Handle other cases if needed
    }
}
