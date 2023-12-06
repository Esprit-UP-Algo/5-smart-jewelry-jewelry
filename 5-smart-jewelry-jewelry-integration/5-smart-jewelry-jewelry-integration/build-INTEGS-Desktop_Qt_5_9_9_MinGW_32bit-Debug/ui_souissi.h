/********************************************************************************
** Form generated from reading UI file 'souissi.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUISSI_H
#define UI_SOUISSI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_souissi
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *image;
    QLineEdit *nomc;
    QLineEdit *prenomc;
    QLineEdit *idc;
    QLineEdit *datec;
    QLineEdit *agec;
    QRadioButton *masculin;
    QRadioButton *feminin;
    QLineEdit *phonec;
    QLineEdit *emailc;
    QPushButton *modifierCl;
    QPushButton *ajouterCl;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_4;
    QTableView *tab_client;
    QPushButton *pdfCl;
    QPushButton *chercherCl;
    QPushButton *supprimerCl;
    QLineEdit *suppid_cl;
    QLineEdit *chercher_idCl;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QPushButton *triageCl;
    QPushButton *ref_Cl;
    QWidget *tab_2;
    QLabel *label_3;
    QFrame *horizontalFrameCl;
    QPushButton *statistiqueCl;
    QWidget *tab_3;
    QLabel *label_2;
    QLineEdit *server;
    QLineEdit *port;
    QLineEdit *uname;
    QLineEdit *paswd;
    QLineEdit *rcpt;
    QLineEdit *subject;
    QLineEdit *file;
    QTextEdit *msg;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *sendBtn;
    QPushButton *browseBtn;
    QLabel *label_27;
    QWidget *tab_4;
    QLabel *label;
    QPushButton *ContratCl;
    QLineEdit *idcontratCl;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_28;
    QPushButton *homeCl;
    QPushButton *deconnectCl;
    QLabel *label_29;
    QLabel *label_24;
    QLabel *label_30;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *souissi)
    {
        if (souissi->objectName().isEmpty())
            souissi->setObjectName(QStringLiteral("souissi"));
        souissi->resize(1029, 634);
        centralwidget = new QWidget(souissi);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 10, 1021, 581));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        image = new QLabel(page);
        image->setObjectName(QStringLiteral("image"));
        image->setGeometry(QRect(10, 20, 1001, 551));
        image->setPixmap(QPixmap(QString::fromUtf8(":/image/2.png")));
        image->setScaledContents(true);
        image->setWordWrap(false);
        image->setOpenExternalLinks(false);
        nomc = new QLineEdit(page);
        nomc->setObjectName(QStringLiteral("nomc"));
        nomc->setGeometry(QRect(200, 180, 113, 22));
        prenomc = new QLineEdit(page);
        prenomc->setObjectName(QStringLiteral("prenomc"));
        prenomc->setGeometry(QRect(200, 220, 113, 22));
        idc = new QLineEdit(page);
        idc->setObjectName(QStringLiteral("idc"));
        idc->setGeometry(QRect(200, 260, 113, 22));
        datec = new QLineEdit(page);
        datec->setObjectName(QStringLiteral("datec"));
        datec->setGeometry(QRect(210, 340, 113, 22));
        agec = new QLineEdit(page);
        agec->setObjectName(QStringLiteral("agec"));
        agec->setGeometry(QRect(210, 380, 113, 22));
        masculin = new QRadioButton(page);
        masculin->setObjectName(QStringLiteral("masculin"));
        masculin->setGeometry(QRect(250, 300, 97, 20));
        feminin = new QRadioButton(page);
        feminin->setObjectName(QStringLiteral("feminin"));
        feminin->setGeometry(QRect(170, 300, 71, 20));
        phonec = new QLineEdit(page);
        phonec->setObjectName(QStringLiteral("phonec"));
        phonec->setGeometry(QRect(210, 420, 113, 22));
        emailc = new QLineEdit(page);
        emailc->setObjectName(QStringLiteral("emailc"));
        emailc->setGeometry(QRect(210, 450, 113, 22));
        modifierCl = new QPushButton(page);
        modifierCl->setObjectName(QStringLiteral("modifierCl"));
        modifierCl->setGeometry(QRect(220, 500, 93, 28));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        modifierCl->setIcon(icon);
        modifierCl->setIconSize(QSize(25, 25));
        ajouterCl = new QPushButton(page);
        ajouterCl->setObjectName(QStringLiteral("ajouterCl"));
        ajouterCl->setGeometry(QRect(110, 500, 93, 28));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/ajouter.png"), QSize(), QIcon::Normal, QIcon::Off);
        ajouterCl->setIcon(icon1);
        ajouterCl->setIconSize(QSize(30, 30));
        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(360, 130, 631, 421));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 641, 401));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/image/m.png")));
        label_4->setScaledContents(true);
        tab_client = new QTableView(tab);
        tab_client->setObjectName(QStringLiteral("tab_client"));
        tab_client->setGeometry(QRect(20, 60, 601, 241));
        pdfCl = new QPushButton(tab);
        pdfCl->setObjectName(QStringLiteral("pdfCl"));
        pdfCl->setGeometry(QRect(190, 10, 41, 41));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdfCl->setIcon(icon2);
        pdfCl->setIconSize(QSize(40, 40));
        chercherCl = new QPushButton(tab);
        chercherCl->setObjectName(QStringLiteral("chercherCl"));
        chercherCl->setGeometry(QRect(530, 10, 31, 31));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/recherche.webp"), QSize(), QIcon::Normal, QIcon::Off);
        chercherCl->setIcon(icon3);
        chercherCl->setIconSize(QSize(43, 40));
        supprimerCl = new QPushButton(tab);
        supprimerCl->setObjectName(QStringLiteral("supprimerCl"));
        supprimerCl->setGeometry(QRect(20, 320, 93, 28));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/zebla.png"), QSize(), QIcon::Normal, QIcon::Off);
        supprimerCl->setIcon(icon4);
        supprimerCl->setIconSize(QSize(20, 20));
        suppid_cl = new QLineEdit(tab);
        suppid_cl->setObjectName(QStringLiteral("suppid_cl"));
        suppid_cl->setGeometry(QRect(90, 360, 113, 22));
        chercher_idCl = new QLineEdit(tab);
        chercher_idCl->setObjectName(QStringLiteral("chercher_idCl"));
        chercher_idCl->setGeometry(QRect(410, 20, 113, 22));
        label_21 = new QLabel(tab);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 20, 181, 16));
        label_21->setStyleSheet(QLatin1String("font: 87 12pt \"Neue Haas Grotesk Text Pro Blac\";\n"
"text-decoration: underline;"));
        label_22 = new QLabel(tab);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(390, 20, 21, 16));
        label_23 = new QLabel(tab);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(50, 360, 56, 16));
        triageCl = new QPushButton(tab);
        triageCl->setObjectName(QStringLiteral("triageCl"));
        triageCl->setGeometry(QRect(482, 320, 111, 28));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/trier.png"), QSize(), QIcon::Normal, QIcon::Off);
        triageCl->setIcon(icon5);
        triageCl->setIconSize(QSize(20, 20));
        ref_Cl = new QPushButton(tab);
        ref_Cl->setObjectName(QStringLiteral("ref_Cl"));
        ref_Cl->setGeometry(QRect(580, 10, 31, 31));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/rafraichir.png"), QSize(), QIcon::Normal, QIcon::Off);
        ref_Cl->setIcon(icon6);
        ref_Cl->setIconSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/users-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon7, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 631, 401));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/image/m.png")));
        label_3->setScaledContents(true);
        horizontalFrameCl = new QFrame(tab_2);
        horizontalFrameCl->setObjectName(QStringLiteral("horizontalFrameCl"));
        horizontalFrameCl->setGeometry(QRect(10, 40, 601, 341));
        horizontalFrameCl->setFrameShape(QFrame::StyledPanel);
        horizontalFrameCl->setFrameShadow(QFrame::Raised);
        statistiqueCl = new QPushButton(tab_2);
        statistiqueCl->setObjectName(QStringLiteral("statistiqueCl"));
        statistiqueCl->setGeometry(QRect(10, 10, 111, 28));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/image/statCl2.png"), QSize(), QIcon::Normal, QIcon::Off);
        statistiqueCl->setIcon(icon8);
        statistiqueCl->setIconSize(QSize(30, 30));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/image/statCl.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon9, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 631, 401));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/m.png")));
        label_2->setScaledContents(true);
        server = new QLineEdit(tab_3);
        server->setObjectName(QStringLiteral("server"));
        server->setGeometry(QRect(120, 20, 181, 22));
        port = new QLineEdit(tab_3);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(120, 60, 181, 22));
        uname = new QLineEdit(tab_3);
        uname->setObjectName(QStringLiteral("uname"));
        uname->setGeometry(QRect(120, 100, 181, 22));
        paswd = new QLineEdit(tab_3);
        paswd->setObjectName(QStringLiteral("paswd"));
        paswd->setGeometry(QRect(120, 140, 181, 22));
        rcpt = new QLineEdit(tab_3);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(120, 180, 181, 22));
        subject = new QLineEdit(tab_3);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(120, 220, 181, 22));
        file = new QLineEdit(tab_3);
        file->setObjectName(QStringLiteral("file"));
        file->setGeometry(QRect(120, 260, 181, 22));
        msg = new QTextEdit(tab_3);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(120, 300, 311, 81));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 20, 91, 16));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 60, 101, 16));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 100, 81, 16));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 140, 91, 16));
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 180, 101, 20));
        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(40, 220, 56, 16));
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(40, 260, 71, 16));
        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 300, 56, 16));
        sendBtn = new QPushButton(tab_3);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(470, 340, 93, 28));
        browseBtn = new QPushButton(tab_3);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(320, 260, 93, 28));
        label_27 = new QLabel(tab_3);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(340, 30, 241, 181));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/image/lo-removebg-preview.png")));
        label_27->setScaledContents(true);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/image/mail.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon10, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label = new QLabel(tab_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 631, 391));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/m.png")));
        label->setScaledContents(true);
        ContratCl = new QPushButton(tab_4);
        ContratCl->setObjectName(QStringLiteral("ContratCl"));
        ContratCl->setGeometry(QRect(30, 30, 93, 28));
        idcontratCl = new QLineEdit(tab_4);
        idcontratCl->setObjectName(QStringLiteral("idcontratCl"));
        idcontratCl->setGeometry(QRect(200, 80, 113, 22));
        label_25 = new QLabel(tab_4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(150, 80, 56, 16));
        label_26 = new QLabel(tab_4);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(270, 120, 341, 231));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/image/contrat.png")));
        label_26->setScaledContents(true);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/image/contratCl2.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_4, icon11, QString());
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 180, 56, 16));
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 220, 56, 16));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(110, 260, 71, 16));
        label_8 = new QLabel(page);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 340, 121, 16));
        label_9 = new QLabel(page);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(140, 380, 56, 16));
        label_10 = new QLabel(page);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(110, 300, 56, 16));
        label_11 = new QLabel(page);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(80, 420, 131, 16));
        label_12 = new QLabel(page);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(130, 450, 56, 16));
        label_28 = new QLabel(page);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(90, 350, 91, 16));
        homeCl = new QPushButton(page);
        homeCl->setObjectName(QStringLiteral("homeCl"));
        homeCl->setGeometry(QRect(920, 50, 31, 28));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/image/dar.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        homeCl->setIcon(icon12);
        homeCl->setIconSize(QSize(40, 40));
        deconnectCl = new QPushButton(page);
        deconnectCl->setObjectName(QStringLiteral("deconnectCl"));
        deconnectCl->setGeometry(QRect(960, 50, 31, 28));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/image/quitter.png"), QSize(), QIcon::Normal, QIcon::Off);
        deconnectCl->setIcon(icon13);
        deconnectCl->setIconSize(QSize(50, 50));
        label_29 = new QLabel(page);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(390, 40, 271, 31));
        label_29->setStyleSheet(QLatin1String("color: rgb(255, 217, 151);\n"
"font: 14pt \"MS Serif\";\n"
"text-decoration: underline;"));
        label_24 = new QLabel(page);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(150, 120, 121, 51));
        label_24->setStyleSheet(QLatin1String("font: 12pt \"Rockwell\";\n"
"text-decoration: underline;\n"
"color: rgb(0, 0, 122);"));
        label_30 = new QLabel(page);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(30, 40, 71, 41));
        label_30->setPixmap(QPixmap(QString::fromUtf8(":/image/users-removebg-preview.png")));
        label_30->setScaledContents(true);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        souissi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(souissi);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1029, 26));
        souissi->setMenuBar(menubar);
        statusbar = new QStatusBar(souissi);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        souissi->setStatusBar(statusbar);

        retranslateUi(souissi);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(souissi);
    } // setupUi

    void retranslateUi(QMainWindow *souissi)
    {
        souissi->setWindowTitle(QApplication::translate("souissi", "souissi", Q_NULLPTR));
        image->setText(QString());
        masculin->setText(QApplication::translate("souissi", "masculin", Q_NULLPTR));
        feminin->setText(QApplication::translate("souissi", "feminin", Q_NULLPTR));
        modifierCl->setText(QApplication::translate("souissi", "modifier", Q_NULLPTR));
        ajouterCl->setText(QApplication::translate("souissi", "ajouter", Q_NULLPTR));
        label_4->setText(QString());
        pdfCl->setText(QString());
        chercherCl->setText(QString());
        supprimerCl->setText(QApplication::translate("souissi", "supprimer", Q_NULLPTR));
        label_21->setText(QApplication::translate("souissi", "Liste des Clients", Q_NULLPTR));
        label_22->setText(QApplication::translate("souissi", "ID:", Q_NULLPTR));
        label_23->setText(QApplication::translate("souissi", "ID:", Q_NULLPTR));
        triageCl->setText(QApplication::translate("souissi", "tri par age", Q_NULLPTR));
        ref_Cl->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("souissi", " Clients", Q_NULLPTR));
        label_3->setText(QString());
        statistiqueCl->setText(QApplication::translate("souissi", "statistique", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("souissi", "Statistique", Q_NULLPTR));
        label_2->setText(QString());
        server->setText(QApplication::translate("souissi", "smtp.gmail.com", Q_NULLPTR));
        port->setText(QApplication::translate("souissi", "465", Q_NULLPTR));
        label_13->setText(QApplication::translate("souissi", "Smtp_server:", Q_NULLPTR));
        label_14->setText(QApplication::translate("souissi", "Server port:", Q_NULLPTR));
        label_15->setText(QApplication::translate("souissi", "Exp\303\251diteur:", Q_NULLPTR));
        label_16->setText(QApplication::translate("souissi", "Mot De Passe:", Q_NULLPTR));
        label_17->setText(QApplication::translate("souissi", "Destinataire:", Q_NULLPTR));
        label_18->setText(QApplication::translate("souissi", "Objet:", Q_NULLPTR));
        label_19->setText(QApplication::translate("souissi", "Document:", Q_NULLPTR));
        label_20->setText(QApplication::translate("souissi", "Message:", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("souissi", "Envoyer", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("souissi", "browse", Q_NULLPTR));
        label_27->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("souissi", "Mailing", Q_NULLPTR));
        label->setText(QString());
        ContratCl->setText(QApplication::translate("souissi", "Contrat", Q_NULLPTR));
        label_25->setText(QApplication::translate("souissi", "ID:", Q_NULLPTR));
        label_26->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("souissi", "Contrat", Q_NULLPTR));
        label_5->setText(QApplication::translate("souissi", "Nom:", Q_NULLPTR));
        label_6->setText(QApplication::translate("souissi", "Prenom:", Q_NULLPTR));
        label_7->setText(QApplication::translate("souissi", "Identifiant:", Q_NULLPTR));
        label_8->setText(QApplication::translate("souissi", "Date de naissance:", Q_NULLPTR));
        label_9->setText(QApplication::translate("souissi", "Age:", Q_NULLPTR));
        label_10->setText(QApplication::translate("souissi", "Sexe:", Q_NULLPTR));
        label_11->setText(QApplication::translate("souissi", "Numero du telephone:", Q_NULLPTR));
        label_12->setText(QApplication::translate("souissi", "Email:", Q_NULLPTR));
        label_28->setText(QApplication::translate("souissi", "jj/mm/aaaa", Q_NULLPTR));
        homeCl->setText(QString());
        deconnectCl->setText(QString());
        label_29->setText(QApplication::translate("souissi", "Gestion des Clients", Q_NULLPTR));
        label_24->setText(QApplication::translate("souissi", "formulaire", Q_NULLPTR));
        label_30->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class souissi: public Ui_souissi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUISSI_H
