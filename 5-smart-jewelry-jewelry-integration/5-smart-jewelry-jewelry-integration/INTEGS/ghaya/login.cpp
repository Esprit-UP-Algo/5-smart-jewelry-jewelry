#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include "arduino.h"
#include "ui_login.h"
#include "login.h"
#include "conection.h"
#include "mainwindow.h"
#include "arduino.h"
#include"widget.h"
#include "employe.h"
#include "oublier.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
 ui->setupUi(this);
        int ret = A.connect_arduino();
        switch (ret) {
        case 0:
            qDebug() << "Arduino est disponible et connecté à : " << A.getarduino_port_name();
            break;
        case 1:
            qDebug() << "Arduino est disponible mais non connecté à : " << A.getarduino_port_name();
            break;
        case -1:
            qDebug() << "Arduino n'est pas disponible";
            break;
        }

        QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));

  }
login::~login()
{
    delete ui;
}

void login::on_pushButton_login_clicked()
{
    QString CIN = ui->lineEdit_username->text();
    QString mdp = ui->lineEdit_password->text();
    QSqlQuery query;

    query.prepare("SELECT * FROM EMPLOYE WHERE CIN=:CIN AND mdp=:mdp");
    query.bindValue(":CIN", CIN);
    query.bindValue(":mdp", mdp);

    if (query.exec() && query.next())
    {
        QMessageBox::information(this, QObject::tr("Login is open"),
                                 QObject::tr("Username and password are correct.\n"
                                            "Open."), QMessageBox::Cancel);

        this->hide();
        widget *auth = new widget;
        auth->show();
    }
    else
    {
        QMessageBox::warning(this, QObject::tr("Login is not open"),
                             QObject::tr("Username and password are incorrect.\n"
                                         "Try again."), QMessageBox::Cancel);
    }
}




QSerialPort* login::getserial() {
    return A.getserial();
}



void login::update_label()
{ QByteArray data = A.getserial()->readAll();
    qDebug() << "Data received: " << data;//a
    QString receivedData = QString::fromUtf8(data);

    if (!receivedData.isEmpty()) {
        // Supposons que les données série contiennent uniquement l'UID
        QString badgeCode = receivedData.trimmed();
        qDebug() << badgeCode;



        QSqlQuery query;
        query.prepare("SELECT * FROM EMPLOYE WHERE RFID=:badgeCode "); //b
        query.bindValue(":badgeCode", badgeCode);
        QString badgeCode1 = receivedData;
               badgeCode1.remove(QChar(' '));

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
    }


      }
void login::on_lineEdit_password_textChanged(const QString &text)
{
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

void login::on_pushButton_oublier_clicked()
{
   // this->hide();
     oublier *auth = new oublier;
     auth->show();
}
