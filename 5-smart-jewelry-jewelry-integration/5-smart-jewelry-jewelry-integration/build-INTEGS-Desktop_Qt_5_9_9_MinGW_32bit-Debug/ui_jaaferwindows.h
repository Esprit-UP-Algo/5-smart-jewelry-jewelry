/********************************************************************************
** Form generated from reading UI file 'jaaferwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JAAFERWINDOWS_H
#define UI_JAAFERWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_jaaferwindows
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_montant;
    QPushButton *ajout_button;
    QLabel *label_4;
    QLineEdit *lineEdit_method;
    QDateEdit *lineEdit_date;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QTableView *tableView;
    QPushButton *pushButton;
    QRadioButton *asc;
    QRadioButton *desc;
    QPushButton *all;
    QLabel *label_10;
    QLineEdit *idsearch;
    QProgressBar *progressBar;
    QLabel *qrcode;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_id_2;
    QLineEdit *lineEdit_montant_2;
    QPushButton *modifier_button;
    QLabel *label_8;
    QLineEdit *lineEdit_method_2;
    QDateEdit *lineEdit_date_2;
    QWidget *tab_4;
    QPushButton *pushButton_supprimer;
    QLineEdit *lineEdit_supprimer;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *jaaferwindows)
    {
        if (jaaferwindows->objectName().isEmpty())
            jaaferwindows->setObjectName(QStringLiteral("jaaferwindows"));
        jaaferwindows->resize(800, 600);
        centralwidget = new QWidget(jaaferwindows);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(90, 90, 571, 321));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(130, 20, 311, 251));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 71, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 47, 13));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 47, 13));
        lineEdit_id = new QLineEdit(groupBox);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(140, 40, 113, 20));
        lineEdit_montant = new QLineEdit(groupBox);
        lineEdit_montant->setObjectName(QStringLiteral("lineEdit_montant"));
        lineEdit_montant->setGeometry(QRect(140, 120, 113, 20));
        ajout_button = new QPushButton(groupBox);
        ajout_button->setObjectName(QStringLiteral("ajout_button"));
        ajout_button->setGeometry(QRect(220, 220, 75, 23));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 170, 131, 16));
        lineEdit_method = new QLineEdit(groupBox);
        lineEdit_method->setObjectName(QStringLiteral("lineEdit_method"));
        lineEdit_method->setGeometry(QRect(140, 160, 113, 22));
        lineEdit_date = new QDateEdit(groupBox);
        lineEdit_date->setObjectName(QStringLiteral("lineEdit_date"));
        lineEdit_date->setGeometry(QRect(140, 80, 110, 22));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 220, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 20, 331, 241));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(154, 270, 91, 23));
        asc = new QRadioButton(tab_2);
        asc->setObjectName(QStringLiteral("asc"));
        asc->setGeometry(QRect(250, 260, 83, 18));
        desc = new QRadioButton(tab_2);
        desc->setObjectName(QStringLiteral("desc"));
        desc->setGeometry(QRect(250, 280, 83, 18));
        all = new QPushButton(tab_2);
        all->setObjectName(QStringLiteral("all"));
        all->setGeometry(QRect(380, 270, 75, 23));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 270, 61, 16));
        idsearch = new QLineEdit(tab_2);
        idsearch->setObjectName(QStringLiteral("idsearch"));
        idsearch->setGeometry(QRect(70, 270, 81, 20));
        progressBar = new QProgressBar(tab_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(430, 180, 111, 23));
        progressBar->setValue(1);
        progressBar->setTextVisible(true);
        progressBar->setOrientation(Qt::Horizontal);
        qrcode = new QLabel(tab_2);
        qrcode->setObjectName(QStringLiteral("qrcode"));
        qrcode->setGeometry(QRect(370, 0, 191, 171));
        qrcode->setScaledContents(true);
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 270, 75, 23));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(130, 20, 311, 251));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 40, 71, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 80, 47, 13));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 120, 47, 13));
        lineEdit_id_2 = new QLineEdit(groupBox_2);
        lineEdit_id_2->setObjectName(QStringLiteral("lineEdit_id_2"));
        lineEdit_id_2->setGeometry(QRect(140, 40, 113, 20));
        lineEdit_montant_2 = new QLineEdit(groupBox_2);
        lineEdit_montant_2->setObjectName(QStringLiteral("lineEdit_montant_2"));
        lineEdit_montant_2->setGeometry(QRect(140, 120, 113, 20));
        modifier_button = new QPushButton(groupBox_2);
        modifier_button->setObjectName(QStringLiteral("modifier_button"));
        modifier_button->setGeometry(QRect(220, 220, 75, 23));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 170, 131, 16));
        lineEdit_method_2 = new QLineEdit(groupBox_2);
        lineEdit_method_2->setObjectName(QStringLiteral("lineEdit_method_2"));
        lineEdit_method_2->setGeometry(QRect(140, 160, 113, 22));
        lineEdit_date_2 = new QDateEdit(groupBox_2);
        lineEdit_date_2->setObjectName(QStringLiteral("lineEdit_date_2"));
        lineEdit_date_2->setGeometry(QRect(140, 80, 110, 22));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        pushButton_supprimer = new QPushButton(tab_4);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(200, 130, 93, 28));
        lineEdit_supprimer = new QLineEdit(tab_4);
        lineEdit_supprimer->setObjectName(QStringLiteral("lineEdit_supprimer"));
        lineEdit_supprimer->setGeometry(QRect(190, 70, 113, 22));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(180, 20, 191, 16));
        tabWidget->addTab(tab_4, QString());
        jaaferwindows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(jaaferwindows);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        jaaferwindows->setMenuBar(menubar);
        statusbar = new QStatusBar(jaaferwindows);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        jaaferwindows->setStatusBar(statusbar);

        retranslateUi(jaaferwindows);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(jaaferwindows);
    } // setupUi

    void retranslateUi(QMainWindow *jaaferwindows)
    {
        jaaferwindows->setWindowTitle(QApplication::translate("jaaferwindows", "jaaferwindows", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("jaaferwindows", "Ajouter Facture", Q_NULLPTR));
        label->setText(QApplication::translate("jaaferwindows", "Id Facture", Q_NULLPTR));
        label_2->setText(QApplication::translate("jaaferwindows", "Date ", Q_NULLPTR));
        label_3->setText(QApplication::translate("jaaferwindows", "Montant", Q_NULLPTR));
        ajout_button->setText(QApplication::translate("jaaferwindows", "Ajouter", Q_NULLPTR));
        label_4->setText(QApplication::translate("jaaferwindows", "Methode de paiement", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("jaaferwindows", "pdf", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("jaaferwindows", "Ajout", Q_NULLPTR));
        pushButton->setText(QApplication::translate("jaaferwindows", "trie montant", Q_NULLPTR));
        asc->setText(QApplication::translate("jaaferwindows", "asc", Q_NULLPTR));
        desc->setText(QApplication::translate("jaaferwindows", "desc", Q_NULLPTR));
        all->setText(QApplication::translate("jaaferwindows", "afficher tout", Q_NULLPTR));
        label_10->setText(QApplication::translate("jaaferwindows", "rechere id", Q_NULLPTR));
        qrcode->setText(QString());
        pushButton_2->setText(QApplication::translate("jaaferwindows", "stat", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("jaaferwindows", "Affichage", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("jaaferwindows", "Modifier Facture", Q_NULLPTR));
        label_5->setText(QApplication::translate("jaaferwindows", "Id Facture", Q_NULLPTR));
        label_6->setText(QApplication::translate("jaaferwindows", "Date ", Q_NULLPTR));
        label_7->setText(QApplication::translate("jaaferwindows", "Montant", Q_NULLPTR));
        modifier_button->setText(QApplication::translate("jaaferwindows", "Modifier", Q_NULLPTR));
        label_8->setText(QApplication::translate("jaaferwindows", "Methode de paiement", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("jaaferwindows", "Modification", Q_NULLPTR));
        pushButton_supprimer->setText(QApplication::translate("jaaferwindows", "supprimer", Q_NULLPTR));
        label_9->setText(QApplication::translate("jaaferwindows", "Id de la facture \303\240 supprimer:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("jaaferwindows", "suppression", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class jaaferwindows: public Ui_jaaferwindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JAAFERWINDOWS_H
