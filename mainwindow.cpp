#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Ftmp.afficher());



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_button_clicked()
{

    int id= ui->lineEdit_id->text().toInt();
    QString date = ui->lineEdit_date->text();
    QString method = ui->lineEdit_method->text();
    int montant= ui->lineEdit_montant->text().toInt();

    QString idstr=QString::number(id);
    QString montantstr=QString::number(montant);

    Facture F(id,date ,method,montant);
    if(!idstr.isEmpty() && !date.isEmpty() && !method.isEmpty() )
    {
    F.ajouter();
    ui->tableView->setModel(F.afficher());

}}


void MainWindow::on_modifier_button_clicked()
{
        int idInt = ui->lineEdit_id_2->text().toInt();
        QString date = ui->lineEdit_date_2->text();
        float montantF = ui->lineEdit_montant_2->text().toFloat();
        QString method = ui->lineEdit_method_2->text();

        QSqlQuery query;
        query.prepare("SELECT * FROM FACTURE WHERE ID_FACTURE = ?");
        query.addBindValue(idInt);

        if (query.exec() && query.next()) {
            Facture F(idInt,date,method,montantF);

          bool test =F.modifier(idInt);

            if (test) {
                QMessageBox::information(nullptr, QObject::tr("Modification réussie"),
                                         QObject::tr("Modification effectuée avec succès.\n"
                                                     "Cliquez sur Annuler pour quitter."),
                                         QMessageBox::Cancel);
                ui->tableView->setModel(F.afficher());




            } else {
                QMessageBox::critical(nullptr, QObject::tr("Erreur de modification"),
                                         QObject::tr("La modification a échoué.\n"
                                                     "Cliquez sur Annuler pour quitter."),
                                         QMessageBox::Cancel);
            }
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                     QObject::tr("Le CIN du médecin n'existe pas."),
                                     QMessageBox::Cancel);
        }

}

void MainWindow::on_pushButton_supprimer_clicked()
{





        int id=ui->lineEdit_supprimer->text().toInt();
        if (!Ftmp.idExists(id)) {
            QMessageBox::critical(nullptr,QObject::tr("Erreur"),
                QObject::tr("L'id de la facture n'existe pas.\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
            return;
        }
        else {
            bool test = Ftmp.supprimer(id);
            if(test) {
                QString nom;
                QString prenom;
                int row = 0;
                int rowCount = ui->tableView->model()->rowCount();
                for (; row < rowCount; row++){
                    nom = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString().simplified();
                    prenom = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toString().simplified();
                }
                ui->tableView->setModel(Ftmp.afficher());

                QMessageBox::information(nullptr,QObject::tr("OK"),
                                         QObject::tr("Suppression effectuée\n"
                                                     "Click Cancel to exit."),QMessageBox::Cancel);
            }
            else {
                QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                          QObject::tr("Suppression non effectuée.\n"
                                                      "Click Cancel to exit."),QMessageBox::Cancel);
            }
        }
    }



    void MainWindow::on_pushButton_clicked()
    {
        QString critere;

        if (ui->asc->isChecked()) {
            critere = "ASC";
        } else if (ui->desc->isChecked()) {
            critere = "DESC";
        }

         ui->tableView->setModel(Ftmp.trie(critere));

        // Utilisez resultModel comme nécessaire, par exemple, pour afficher les données dans une vue.
    }



void MainWindow::on_all_clicked()
{
    ui->tableView->setModel(Ftmp.afficher());

}



void MainWindow::on_pushButton_2_clicked()
{
    QChartView *chartView = Ftmp.stat();
    chartView->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    Ftmp.on_pdf_clicked();
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
     using namespace qrcodegen;

        QString val = ui->tableView->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from FACTURE where ID_FACTURE='" + val + "'");

        if (qry.exec()) {
            while (qry.next()) {
                // Assuming these are the attributes of the Facture class
                int ID_FACTURE = qry.value(0).toInt();
                QString DATE_FACTURATION = qry.value(1).toString();
                QString METHOD_PAIEMENT = qry.value(2).toString();
                double MONTANT = qry.value(3).toDouble();



                // Using QrCodegen to create a QR code from Facture attributes
                QString text = "ID: " + QString::number(ID_FACTURE) + "\n"
                                "Date: " + DATE_FACTURATION + "\n"
                                "Payment Method: " + METHOD_PAIEMENT + "\n"
                                "Amount: " + QString::number(MONTANT) + "\n";

                QrCode qr = QrCode::encodeText(text.toUtf8().data(), QrCode::Ecc::MEDIUM);

                qint32 sz = qr.getSize();
                QImage im(sz, sz, QImage::Format_RGB32);
                QRgb black = qRgb(191, 112, 105);
                QRgb white = qRgb(255, 255, 255);

                for (int y = 0; y < sz; y++) {
                    for (int x = 0; x < sz; x++) {
                        im.setPixel(x, y, qr.getModule(x, y) ? black : white);
                    }
                }
                ui->qrcode->setPixmap(QPixmap::fromImage(im.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation), Qt::MonoOnly));

                int i = 0;
                for (i = 0; i < 100; i = i + 0.001) {
                    i++;
                    ui->progressBar->setValue(i);
                }
            }
        } else {
            qDebug() << "Error";
        }
}

void MainWindow::on_idsearch_cursorPositionChanged(int arg1, int arg2)
{

    int idToSearch = ui->idsearch->text().toInt(); // Assuming you have a line edit for entering the ID_FACTURE

    QSqlQueryModel *resultModel = Ftmp.searchFactureById(idToSearch);

    // Assuming you have a QTableView named tableView in your MainWindow UI
    ui->tableView->setModel(resultModel);
    // Update the view to reflect the changes
    ui->tableView->show();

}
