/********************************************************************************
** Form generated from reading UI file 'MainWindow1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW1_H
#define UI_MAINWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow1
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit_total;
    QPushButton *statistiques;
    QPushButton *ajout;
    QLabel *label_3;
    QPushButton *envoyer;
    QPushButton *pushButton_supp;
    QTableView *tableView_r;
    QLabel *label_stat;
    QLineEdit *lineEdit_statut;
    QLineEdit *lineEdit_recherche;
    QLabel *total_de_la_commande;
    QLineEdit *lineEdit_chatbot;
    QLabel *N_de_la_commande;
    QLabel *date_de_la_commande;
    QPushButton *historique;
    QLineEdit *lineEdit_N;
    QLineEdit *lineEdit_date;
    QPushButton *modif;
    QLabel *label_chatbot_response;
    QPushButton *tri;
    QPushButton *recherche_pushButton;
    QLabel *statut_de_la_commande;
    QPushButton *pdf;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow1)
    {
        if (MainWindow1->objectName().isEmpty())
            MainWindow1->setObjectName(QStringLiteral("MainWindow1"));
        MainWindow1->resize(1285, 738);
        centralwidget = new QWidget(MainWindow1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 161, 21));
        lineEdit_total = new QLineEdit(centralwidget);
        lineEdit_total->setObjectName(QStringLiteral("lineEdit_total"));
        lineEdit_total->setGeometry(QRect(230, 290, 113, 22));
        statistiques = new QPushButton(centralwidget);
        statistiques->setObjectName(QStringLiteral("statistiques"));
        statistiques->setGeometry(QRect(1080, 520, 121, 28));
        ajout = new QPushButton(centralwidget);
        ajout->setObjectName(QStringLiteral("ajout"));
        ajout->setGeometry(QRect(310, 360, 81, 28));
        QIcon icon;
        icon.addFile(QStringLiteral("../Users/skand/OneDrive/Bureau/design C++/Untitled-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        ajout->setIcon(icon);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(980, 80, 121, 16));
        envoyer = new QPushButton(centralwidget);
        envoyer->setObjectName(QStringLiteral("envoyer"));
        envoyer->setGeometry(QRect(500, 620, 101, 41));
        pushButton_supp = new QPushButton(centralwidget);
        pushButton_supp->setObjectName(QStringLiteral("pushButton_supp"));
        pushButton_supp->setGeometry(QRect(200, 360, 93, 28));
        tableView_r = new QTableView(centralwidget);
        tableView_r->setObjectName(QStringLiteral("tableView_r"));
        tableView_r->setGeometry(QRect(570, 140, 641, 321));
        label_stat = new QLabel(centralwidget);
        label_stat->setObjectName(QStringLiteral("label_stat"));
        label_stat->setGeometry(QRect(610, 570, 561, 81));
        lineEdit_statut = new QLineEdit(centralwidget);
        lineEdit_statut->setObjectName(QStringLiteral("lineEdit_statut"));
        lineEdit_statut->setGeometry(QRect(230, 240, 113, 22));
        lineEdit_recherche = new QLineEdit(centralwidget);
        lineEdit_recherche->setObjectName(QStringLiteral("lineEdit_recherche"));
        lineEdit_recherche->setGeometry(QRect(980, 100, 191, 31));
        total_de_la_commande = new QLabel(centralwidget);
        total_de_la_commande->setObjectName(QStringLiteral("total_de_la_commande"));
        total_de_la_commande->setGeometry(QRect(90, 290, 131, 16));
        lineEdit_chatbot = new QLineEdit(centralwidget);
        lineEdit_chatbot->setObjectName(QStringLiteral("lineEdit_chatbot"));
        lineEdit_chatbot->setGeometry(QRect(42, 621, 421, 41));
        N_de_la_commande = new QLabel(centralwidget);
        N_de_la_commande->setObjectName(QStringLiteral("N_de_la_commande"));
        N_de_la_commande->setGeometry(QRect(90, 140, 121, 16));
        date_de_la_commande = new QLabel(centralwidget);
        date_de_la_commande->setObjectName(QStringLiteral("date_de_la_commande"));
        date_de_la_commande->setGeometry(QRect(90, 190, 131, 16));
        historique = new QPushButton(centralwidget);
        historique->setObjectName(QStringLiteral("historique"));
        historique->setGeometry(QRect(970, 520, 93, 28));
        lineEdit_N = new QLineEdit(centralwidget);
        lineEdit_N->setObjectName(QStringLiteral("lineEdit_N"));
        lineEdit_N->setGeometry(QRect(230, 140, 113, 22));
        lineEdit_date = new QLineEdit(centralwidget);
        lineEdit_date->setObjectName(QStringLiteral("lineEdit_date"));
        lineEdit_date->setGeometry(QRect(230, 180, 113, 22));
        modif = new QPushButton(centralwidget);
        modif->setObjectName(QStringLiteral("modif"));
        modif->setGeometry(QRect(90, 360, 93, 28));
        label_chatbot_response = new QLabel(centralwidget);
        label_chatbot_response->setObjectName(QStringLiteral("label_chatbot_response"));
        label_chatbot_response->setGeometry(QRect(42, 411, 421, 191));
        tri = new QPushButton(centralwidget);
        tri->setObjectName(QStringLiteral("tri"));
        tri->setGeometry(QRect(750, 520, 93, 28));
        recherche_pushButton = new QPushButton(centralwidget);
        recherche_pushButton->setObjectName(QStringLiteral("recherche_pushButton"));
        recherche_pushButton->setGeometry(QRect(1180, 100, 93, 28));
        statut_de_la_commande = new QLabel(centralwidget);
        statut_de_la_commande->setObjectName(QStringLiteral("statut_de_la_commande"));
        statut_de_la_commande->setGeometry(QRect(90, 240, 141, 16));
        pdf = new QPushButton(centralwidget);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(860, 520, 93, 28));
        MainWindow1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1285, 26));
        MainWindow1->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow1->setStatusBar(statusbar);

        retranslateUi(MainWindow1);

        QMetaObject::connectSlotsByName(MainWindow1);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow1)
    {
        MainWindow1->setWindowTitle(QApplication::translate("MainWindow1", "Gestion des clients", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow1", "Gestion des commandes ", Q_NULLPTR));
        statistiques->setText(QApplication::translate("MainWindow1", "stat par statut", Q_NULLPTR));
        ajout->setText(QApplication::translate("MainWindow1", "ajout", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow1", "recherche par num", Q_NULLPTR));
        envoyer->setText(QApplication::translate("MainWindow1", "envoyer", Q_NULLPTR));
        pushButton_supp->setText(QApplication::translate("MainWindow1", "supp", Q_NULLPTR));
        label_stat->setText(QString());
        total_de_la_commande->setText(QApplication::translate("MainWindow1", "Total de la commande", Q_NULLPTR));
        N_de_la_commande->setText(QApplication::translate("MainWindow1", "N\302\260 de la commande", Q_NULLPTR));
        date_de_la_commande->setText(QApplication::translate("MainWindow1", "Date de la commande", Q_NULLPTR));
        historique->setText(QApplication::translate("MainWindow1", "historique", Q_NULLPTR));
        modif->setText(QApplication::translate("MainWindow1", "MODIFIER", Q_NULLPTR));
        label_chatbot_response->setText(QString());
        tri->setText(QApplication::translate("MainWindow1", "tri par total", Q_NULLPTR));
        recherche_pushButton->setText(QApplication::translate("MainWindow1", "rechercher", Q_NULLPTR));
        statut_de_la_commande->setText(QApplication::translate("MainWindow1", "Statut de la commande", Q_NULLPTR));
        pdf->setText(QApplication::translate("MainWindow1", "PDF", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow1: public Ui_MainWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW1_H
