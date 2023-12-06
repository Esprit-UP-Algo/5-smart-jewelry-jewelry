/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_cin;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_salaire;
    QLineEdit *lineEdit_abs;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_modifier;
    QPushButton *pushButton_supprimer;
    QLineEdit *lineEdit_cinsupp;
    QLabel *label_7;
    QPushButton *pushButton_pdf;
    QDateEdit *dateEdit;
    QComboBox *comboBox;
    QLabel *label_8;
    QLineEdit *lineEdit_mdp;
    QLabel *label_9;
    QLineEdit *lineEdit_rechcin;
    QPushButton *pushButton_rechcin;
    QPushButton *pushButton_raf;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushButton_deconect;
    QLabel *label_19;
    QLineEdit *lineEdit_RFID;
    QLabel *label_14;
    QPushButton *pushButton;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QTableView *tableView;
    QLabel *label_16;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_stat;
    QWidget *tab_4;
    QCalendarWidget *calendarWidget;
    QTextEdit *textEdit;
    QLabel *label_15;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(2014, 1243);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 80, 1311, 841));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 180, 56, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 220, 56, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 260, 56, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 380, 56, 16));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 340, 56, 16));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(110, 300, 56, 16));
        lineEdit_cin = new QLineEdit(tab);
        lineEdit_cin->setObjectName(QStringLiteral("lineEdit_cin"));
        lineEdit_cin->setGeometry(QRect(220, 180, 113, 22));
        lineEdit_nom = new QLineEdit(tab);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(220, 220, 113, 22));
        lineEdit_prenom = new QLineEdit(tab);
        lineEdit_prenom->setObjectName(QStringLiteral("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(220, 260, 113, 22));
        lineEdit_salaire = new QLineEdit(tab);
        lineEdit_salaire->setObjectName(QStringLiteral("lineEdit_salaire"));
        lineEdit_salaire->setGeometry(QRect(220, 340, 113, 22));
        lineEdit_abs = new QLineEdit(tab);
        lineEdit_abs->setObjectName(QStringLiteral("lineEdit_abs"));
        lineEdit_abs->setGeometry(QRect(220, 380, 113, 22));
        pushButton_ajouter = new QPushButton(tab);
        pushButton_ajouter->setObjectName(QStringLiteral("pushButton_ajouter"));
        pushButton_ajouter->setGeometry(QRect(160, 510, 41, 28));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/ajouter.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ajouter->setIcon(icon);
        pushButton_ajouter->setIconSize(QSize(40, 40));
        pushButton_modifier = new QPushButton(tab);
        pushButton_modifier->setObjectName(QStringLiteral("pushButton_modifier"));
        pushButton_modifier->setGeometry(QRect(230, 510, 21, 28));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_modifier->setIcon(icon1);
        pushButton_modifier->setIconSize(QSize(30, 30));
        pushButton_supprimer = new QPushButton(tab);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(270, 560, 31, 31));
        pushButton_supprimer->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/zebla.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_supprimer->setIcon(icon2);
        pushButton_supprimer->setIconSize(QSize(30, 30));
        lineEdit_cinsupp = new QLineEdit(tab);
        lineEdit_cinsupp->setObjectName(QStringLiteral("lineEdit_cinsupp"));
        lineEdit_cinsupp->setGeometry(QRect(150, 560, 113, 22));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 560, 56, 16));
        pushButton_pdf = new QPushButton(tab);
        pushButton_pdf->setObjectName(QStringLiteral("pushButton_pdf"));
        pushButton_pdf->setGeometry(QRect(1040, 110, 31, 41));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_pdf->setIcon(icon3);
        pushButton_pdf->setIconSize(QSize(40, 40));
        dateEdit = new QDateEdit(tab);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(220, 300, 110, 22));
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(960, 510, 111, 22));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(900, 510, 51, 31));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/image/trier.png")));
        label_8->setScaledContents(true);
        lineEdit_mdp = new QLineEdit(tab);
        lineEdit_mdp->setObjectName(QStringLiteral("lineEdit_mdp"));
        lineEdit_mdp->setGeometry(QRect(220, 420, 113, 22));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(110, 420, 56, 16));
        lineEdit_rechcin = new QLineEdit(tab);
        lineEdit_rechcin->setObjectName(QStringLiteral("lineEdit_rechcin"));
        lineEdit_rechcin->setGeometry(QRect(380, 160, 113, 22));
        pushButton_rechcin = new QPushButton(tab);
        pushButton_rechcin->setObjectName(QStringLiteral("pushButton_rechcin"));
        pushButton_rechcin->setGeometry(QRect(500, 150, 31, 28));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/recherche.webp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_rechcin->setIcon(icon4);
        pushButton_rechcin->setIconSize(QSize(40, 40));
        pushButton_raf = new QPushButton(tab);
        pushButton_raf->setObjectName(QStringLiteral("pushButton_raf"));
        pushButton_raf->setGeometry(QRect(1040, 170, 31, 31));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/rafraichir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_raf->setIcon(icon5);
        pushButton_raf->setIconSize(QSize(40, 40));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(390, 140, 56, 16));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 10, 1101, 641));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/image/2.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(160, 120, 121, 51));
        label_12->setStyleSheet(QLatin1String("font: 12pt \"Rockwell\";\n"
"text-decoration: underline;\n"
"color: rgb(0, 0, 122);"));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(140, 0, 131, 61));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/lo-removebg-preview.png")));
        label_13->setScaledContents(true);
        pushButton_deconect = new QPushButton(tab);
        pushButton_deconect->setObjectName(QStringLiteral("pushButton_deconect"));
        pushButton_deconect->setGeometry(QRect(1000, 30, 41, 31));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/quitter.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_deconect->setIcon(icon6);
        pushButton_deconect->setIconSize(QSize(70, 70));
        label_19 = new QLabel(tab);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(450, 30, 271, 31));
        label_19->setStyleSheet(QLatin1String("color: rgb(255, 217, 151);\n"
"font: 14pt \"MS Serif\";\n"
"text-decoration: underline;"));
        lineEdit_RFID = new QLineEdit(tab);
        lineEdit_RFID->setObjectName(QStringLiteral("lineEdit_RFID"));
        lineEdit_RFID->setGeometry(QRect(220, 460, 113, 22));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(110, 460, 56, 16));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(960, 30, 31, 28));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/dar.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon7);
        pushButton->setIconSize(QSize(40, 40));
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(380, 190, 701, 311));
        tabWidget_2->setStyleSheet(QStringLiteral("background-color: rgb(85, 0, 0);"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 50, 661, 192));
        tableView->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(8, 8, 8);"));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 20, 211, 16));
        label_16->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayoutWidget = new QWidget(tab_3);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 10, 641, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_stat = new QPushButton(tab_3);
        pushButton_stat->setObjectName(QStringLiteral("pushButton_stat"));
        pushButton_stat->setGeometry(QRect(0, 110, 41, 41));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/image/stat.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stat->setIcon(icon8);
        pushButton_stat->setIconSize(QSize(40, 40));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        calendarWidget = new QCalendarWidget(tab_4);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(20, 10, 311, 211));
        calendarWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        textEdit = new QTextEdit(tab_4);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(350, 90, 321, 61));
        textEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(360, 40, 141, 41));
        label_15->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tabWidget_2->addTab(tab_4, QString());
        tabWidget->addTab(tab, QString());
        label_11->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        lineEdit_cin->raise();
        lineEdit_nom->raise();
        lineEdit_prenom->raise();
        lineEdit_salaire->raise();
        lineEdit_abs->raise();
        pushButton_ajouter->raise();
        pushButton_modifier->raise();
        pushButton_supprimer->raise();
        lineEdit_cinsupp->raise();
        label_7->raise();
        pushButton_pdf->raise();
        dateEdit->raise();
        comboBox->raise();
        label_8->raise();
        lineEdit_mdp->raise();
        label_9->raise();
        lineEdit_rechcin->raise();
        pushButton_rechcin->raise();
        pushButton_raf->raise();
        label_10->raise();
        label_12->raise();
        label_13->raise();
        pushButton_deconect->raise();
        label_19->raise();
        lineEdit_RFID->raise();
        label_14->raise();
        pushButton->raise();
        tabWidget_2->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 2014, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "cin", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "prenom ", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "absence", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "salaire", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "date_embauche", Q_NULLPTR));
        pushButton_ajouter->setText(QString());
        pushButton_modifier->setText(QString());
        pushButton_supprimer->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "cin", Q_NULLPTR));
        pushButton_pdf->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Salaire", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Date d'embauche", Q_NULLPTR)
        );
        label_8->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "mdp", Q_NULLPTR));
        pushButton_rechcin->setText(QString());
        pushButton_raf->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "par cin", Q_NULLPTR));
        label_11->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "formulaire", Q_NULLPTR));
        label_13->setText(QString());
        pushButton_deconect->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "Gestion des employes", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "RFID", Q_NULLPTR));
        pushButton->setText(QString());
        label_16->setText(QApplication::translate("MainWindow", "la liste des employ\303\251s", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "liste", Q_NULLPTR));
        pushButton_stat->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "stat", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "To do list :", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "calendrier", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "gestemp", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
