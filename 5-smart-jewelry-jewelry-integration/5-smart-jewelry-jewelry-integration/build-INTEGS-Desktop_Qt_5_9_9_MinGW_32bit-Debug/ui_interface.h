/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QStackedWidget *GestionApp;
    QWidget *Produit;
    QGroupBox *groupBox;
    QLabel *NomProd;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_NomP;
    QLineEdit *lineEdit_TypeP;
    QLineEdit *lineEdit_PoidsP;
    QLineEdit *lineEdit_PrixP;
    QLineEdit *lineEdit_NombreP;
    QWidget *ProductFree;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_5;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *lineEdit_NomT;
    QLineEdit *lineEdit_TypeT;
    QLineEdit *lineEdit_PoidsT;
    QLineEdit *lineEdit_PrixT;
    QLineEdit *lineEdit_NombreT;
    QPushButton *pushButton_2;
    QPushButton *pushButton_p;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QGroupBox *groupBox_4;
    QLabel *NomProd_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_NomP_2;
    QLineEdit *lineEdit_TypeP_2;
    QLineEdit *lineEdit_PoidsP_2;
    QLineEdit *lineEdit_PrixP_2;
    QLineEdit *lineEdit_NombreP_2;
    QWidget *page_6;
    QGroupBox *groupBox_6;
    QLabel *NomProd_3;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *lineEdit_NomP_3;
    QLineEdit *lineEdit_TypeP_3;
    QLineEdit *lineEdit_PoidsP_3;
    QLineEdit *lineEdit_PrixP_3;
    QLineEdit *lineEdit_NombreP_3;
    QWidget *ProductTemp;
    QLabel *label_7;
    QLabel *label_ID;
    QLineEdit *lineEdit_ID;
    QLabel *label_Nom;
    QLineEdit *lineEdit_Nom;
    QLabel *label_Type;
    QLineEdit *lineEdit_Type;
    QLabel *label_Poids;
    QLineEdit *lineEdit_Poids;
    QLabel *label_Prix;
    QLineEdit *lineEdit_Prix;
    QLabel *label_Qte;
    QLineEdit *lineEdit_Qte;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_Delete;
    QLabel *label_22;
    QPushButton *pushButton_Edit;
    QPushButton *pushButton_PDF;
    QPushButton *pushButton_TPrix;
    QLineEdit *lineEdit_recherche;
    QPushButton *pushButton_TQte;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QWidget *Statistiques;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_OOS;
    QPushButton *pushButton_stats;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_QR;
    QPushButton *pushButton_Excel;
    QLabel *label_23;
    QLabel *label_24;
    QPushButton *pushButton;
    QWidget *Login;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_6;
    QLabel *label_21;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1239, 749);
        GestionApp = new QStackedWidget(Dialog);
        GestionApp->setObjectName(QStringLiteral("GestionApp"));
        GestionApp->setGeometry(QRect(-50, 30, 2641, 1921));
        GestionApp->setMinimumSize(QSize(1661, 0));
        Produit = new QWidget();
        Produit->setObjectName(QStringLiteral("Produit"));
        groupBox = new QGroupBox(Produit);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 0, 391, 311));
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 233, 255);"));
        NomProd = new QLabel(groupBox);
        NomProd->setObjectName(QStringLiteral("NomProd"));
        NomProd->setGeometry(QRect(50, 60, 47, 14));
        NomProd->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 94, 47, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 140, 47, 14));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 180, 47, 14));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 220, 47, 14));
        lineEdit_NomP = new QLineEdit(groupBox);
        lineEdit_NomP->setObjectName(QStringLiteral("lineEdit_NomP"));
        lineEdit_NomP->setGeometry(QRect(160, 60, 113, 20));
        lineEdit_NomP->setReadOnly(true);
        lineEdit_TypeP = new QLineEdit(groupBox);
        lineEdit_TypeP->setObjectName(QStringLiteral("lineEdit_TypeP"));
        lineEdit_TypeP->setGeometry(QRect(160, 100, 113, 20));
        lineEdit_TypeP->setReadOnly(true);
        lineEdit_PoidsP = new QLineEdit(groupBox);
        lineEdit_PoidsP->setObjectName(QStringLiteral("lineEdit_PoidsP"));
        lineEdit_PoidsP->setGeometry(QRect(160, 140, 113, 20));
        lineEdit_PoidsP->setReadOnly(true);
        lineEdit_PrixP = new QLineEdit(groupBox);
        lineEdit_PrixP->setObjectName(QStringLiteral("lineEdit_PrixP"));
        lineEdit_PrixP->setGeometry(QRect(160, 180, 113, 20));
        lineEdit_PrixP->setReadOnly(true);
        lineEdit_NombreP = new QLineEdit(groupBox);
        lineEdit_NombreP->setObjectName(QStringLiteral("lineEdit_NombreP"));
        lineEdit_NombreP->setGeometry(QRect(160, 220, 113, 20));
        lineEdit_NombreP->setReadOnly(true);
        GestionApp->addWidget(Produit);
        ProductFree = new QWidget();
        ProductFree->setObjectName(QStringLiteral("ProductFree"));
        groupBox_3 = new QGroupBox(ProductFree);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 10, 841, 431));
        groupBox_3->setStyleSheet(QLatin1String("background-color: rgb(197, 205, 255);\n"
"color: rgb(0, 0, 127);\n"
"font: 87 8pt \"Segoe UI Black\";"));
        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 50, 351, 311));
        groupBox_5->setStyleSheet(QLatin1String("background-color: rgb(28, 46, 127);\n"
"\n"
"font: 8pt \"MV Boli\";\n"
"color: rgb(255, 176, 38);\n"
""));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(50, 60, 47, 14));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(50, 94, 47, 20));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(50, 140, 47, 14));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(50, 180, 47, 14));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(50, 220, 47, 14));
        lineEdit_NomT = new QLineEdit(groupBox_5);
        lineEdit_NomT->setObjectName(QStringLiteral("lineEdit_NomT"));
        lineEdit_NomT->setGeometry(QRect(160, 60, 113, 20));
        lineEdit_TypeT = new QLineEdit(groupBox_5);
        lineEdit_TypeT->setObjectName(QStringLiteral("lineEdit_TypeT"));
        lineEdit_TypeT->setGeometry(QRect(160, 100, 113, 20));
        lineEdit_PoidsT = new QLineEdit(groupBox_5);
        lineEdit_PoidsT->setObjectName(QStringLiteral("lineEdit_PoidsT"));
        lineEdit_PoidsT->setGeometry(QRect(160, 140, 113, 20));
        lineEdit_PrixT = new QLineEdit(groupBox_5);
        lineEdit_PrixT->setObjectName(QStringLiteral("lineEdit_PrixT"));
        lineEdit_PrixT->setGeometry(QRect(160, 180, 113, 20));
        lineEdit_NombreT = new QLineEdit(groupBox_5);
        lineEdit_NombreT->setObjectName(QStringLiteral("lineEdit_NombreT"));
        lineEdit_NombreT->setGeometry(QRect(160, 220, 113, 20));
        pushButton_2 = new QPushButton(groupBox_5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 270, 75, 23));
        pushButton_2->setStyleSheet(QStringLiteral("color: rgb(170, 0, 127);"));
        pushButton_p = new QPushButton(groupBox_5);
        pushButton_p->setObjectName(QStringLiteral("pushButton_p"));
        pushButton_p->setGeometry(QRect(220, 270, 75, 23));
        pushButton_p->setStyleSheet(QLatin1String("\n"
"color: rgb(170, 0, 127);"));
        stackedWidget = new QStackedWidget(groupBox_3);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(410, 50, 371, 401));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        groupBox_4 = new QGroupBox(page_5);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(60, 10, 291, 291));
        groupBox_4->setStyleSheet(QLatin1String("background-color: rgb(28, 46, 127);\n"
"font: 8pt \"MV Boli\";\n"
"color: rgb(255, 176, 38);\n"
""));
        NomProd_2 = new QLabel(groupBox_4);
        NomProd_2->setObjectName(QStringLiteral("NomProd_2"));
        NomProd_2->setGeometry(QRect(50, 60, 47, 14));
        NomProd_2->setStyleSheet(QStringLiteral(""));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 94, 47, 20));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 140, 47, 14));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(50, 180, 47, 14));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(50, 220, 47, 14));
        lineEdit_NomP_2 = new QLineEdit(groupBox_4);
        lineEdit_NomP_2->setObjectName(QStringLiteral("lineEdit_NomP_2"));
        lineEdit_NomP_2->setGeometry(QRect(160, 60, 113, 20));
        lineEdit_NomP_2->setReadOnly(true);
        lineEdit_TypeP_2 = new QLineEdit(groupBox_4);
        lineEdit_TypeP_2->setObjectName(QStringLiteral("lineEdit_TypeP_2"));
        lineEdit_TypeP_2->setGeometry(QRect(160, 100, 113, 20));
        lineEdit_TypeP_2->setReadOnly(true);
        lineEdit_PoidsP_2 = new QLineEdit(groupBox_4);
        lineEdit_PoidsP_2->setObjectName(QStringLiteral("lineEdit_PoidsP_2"));
        lineEdit_PoidsP_2->setGeometry(QRect(160, 140, 113, 20));
        lineEdit_PoidsP_2->setReadOnly(true);
        lineEdit_PrixP_2 = new QLineEdit(groupBox_4);
        lineEdit_PrixP_2->setObjectName(QStringLiteral("lineEdit_PrixP_2"));
        lineEdit_PrixP_2->setGeometry(QRect(160, 180, 113, 20));
        lineEdit_PrixP_2->setReadOnly(true);
        lineEdit_NombreP_2 = new QLineEdit(groupBox_4);
        lineEdit_NombreP_2->setObjectName(QStringLiteral("lineEdit_NombreP_2"));
        lineEdit_NombreP_2->setGeometry(QRect(160, 220, 113, 20));
        lineEdit_NombreP_2->setReadOnly(true);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        groupBox_6 = new QGroupBox(page_6);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(60, 0, 291, 311));
        groupBox_6->setStyleSheet(QLatin1String("background-color: rgb(28, 46, 127);\n"
"font: 8pt \"MV Boli\";\n"
"color: rgb(255, 176, 38);\n"
""));
        NomProd_3 = new QLabel(groupBox_6);
        NomProd_3->setObjectName(QStringLiteral("NomProd_3"));
        NomProd_3->setGeometry(QRect(50, 60, 47, 14));
        NomProd_3->setStyleSheet(QStringLiteral(""));
        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(50, 94, 47, 20));
        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(50, 140, 47, 14));
        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(50, 180, 47, 14));
        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(50, 220, 47, 14));
        lineEdit_NomP_3 = new QLineEdit(groupBox_6);
        lineEdit_NomP_3->setObjectName(QStringLiteral("lineEdit_NomP_3"));
        lineEdit_NomP_3->setGeometry(QRect(160, 60, 113, 20));
        lineEdit_NomP_3->setReadOnly(true);
        lineEdit_TypeP_3 = new QLineEdit(groupBox_6);
        lineEdit_TypeP_3->setObjectName(QStringLiteral("lineEdit_TypeP_3"));
        lineEdit_TypeP_3->setGeometry(QRect(160, 100, 113, 20));
        lineEdit_TypeP_3->setReadOnly(true);
        lineEdit_PoidsP_3 = new QLineEdit(groupBox_6);
        lineEdit_PoidsP_3->setObjectName(QStringLiteral("lineEdit_PoidsP_3"));
        lineEdit_PoidsP_3->setGeometry(QRect(160, 140, 113, 20));
        lineEdit_PoidsP_3->setReadOnly(true);
        lineEdit_PrixP_3 = new QLineEdit(groupBox_6);
        lineEdit_PrixP_3->setObjectName(QStringLiteral("lineEdit_PrixP_3"));
        lineEdit_PrixP_3->setGeometry(QRect(160, 180, 113, 20));
        lineEdit_PrixP_3->setReadOnly(true);
        lineEdit_NombreP_3 = new QLineEdit(groupBox_6);
        lineEdit_NombreP_3->setObjectName(QStringLiteral("lineEdit_NombreP_3"));
        lineEdit_NombreP_3->setGeometry(QRect(160, 220, 113, 20));
        lineEdit_NombreP_3->setReadOnly(true);
        stackedWidget->addWidget(page_6);
        GestionApp->addWidget(ProductFree);
        ProductTemp = new QWidget();
        ProductTemp->setObjectName(QStringLiteral("ProductTemp"));
        label_7 = new QLabel(ProductTemp);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(-60, -310, 1381, 1561));
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../../gestion-des-client1 resized.jpg")));
        label_ID = new QLabel(ProductTemp);
        label_ID->setObjectName(QStringLiteral("label_ID"));
        label_ID->setGeometry(QRect(130, 220, 81, 31));
        label_ID->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        lineEdit_ID = new QLineEdit(ProductTemp);
        lineEdit_ID->setObjectName(QStringLiteral("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(300, 230, 113, 20));
        label_Nom = new QLabel(ProductTemp);
        label_Nom->setObjectName(QStringLiteral("label_Nom"));
        label_Nom->setGeometry(QRect(90, 270, 71, 51));
        label_Nom->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        lineEdit_Nom = new QLineEdit(ProductTemp);
        lineEdit_Nom->setObjectName(QStringLiteral("lineEdit_Nom"));
        lineEdit_Nom->setGeometry(QRect(300, 290, 113, 20));
        label_Type = new QLabel(ProductTemp);
        label_Type->setObjectName(QStringLiteral("label_Type"));
        label_Type->setGeometry(QRect(120, 330, 81, 61));
        label_Type->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        lineEdit_Type = new QLineEdit(ProductTemp);
        lineEdit_Type->setObjectName(QStringLiteral("lineEdit_Type"));
        lineEdit_Type->setGeometry(QRect(300, 350, 113, 20));
        label_Poids = new QLabel(ProductTemp);
        label_Poids->setObjectName(QStringLiteral("label_Poids"));
        label_Poids->setGeometry(QRect(160, 400, 71, 51));
        label_Poids->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        lineEdit_Poids = new QLineEdit(ProductTemp);
        lineEdit_Poids->setObjectName(QStringLiteral("lineEdit_Poids"));
        lineEdit_Poids->setGeometry(QRect(300, 410, 113, 20));
        label_Prix = new QLabel(ProductTemp);
        label_Prix->setObjectName(QStringLiteral("label_Prix"));
        label_Prix->setGeometry(QRect(160, 440, 61, 71));
        label_Prix->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        lineEdit_Prix = new QLineEdit(ProductTemp);
        lineEdit_Prix->setObjectName(QStringLiteral("lineEdit_Prix"));
        lineEdit_Prix->setGeometry(QRect(300, 470, 113, 20));
        label_Qte = new QLabel(ProductTemp);
        label_Qte->setObjectName(QStringLiteral("label_Qte"));
        label_Qte->setGeometry(QRect(150, 510, 81, 71));
        QFont font;
        font.setPointSize(12);
        label_Qte->setFont(font);
        lineEdit_Qte = new QLineEdit(ProductTemp);
        lineEdit_Qte->setObjectName(QStringLiteral("lineEdit_Qte"));
        lineEdit_Qte->setGeometry(QRect(300, 530, 113, 20));
        pushButton_Add = new QPushButton(ProductTemp);
        pushButton_Add->setObjectName(QStringLiteral("pushButton_Add"));
        pushButton_Add->setGeometry(QRect(460, 470, 191, 41));
        QFont font1;
        font1.setPointSize(19);
        pushButton_Add->setFont(font1);
        pushButton_Add->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Delete = new QPushButton(ProductTemp);
        pushButton_Delete->setObjectName(QStringLiteral("pushButton_Delete"));
        pushButton_Delete->setGeometry(QRect(1000, 470, 191, 41));
        pushButton_Delete->setFont(font1);
        pushButton_Delete->setCursor(QCursor(Qt::PointingHandCursor));
        label_22 = new QLabel(ProductTemp);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(1000, 430, 31, 21));
        QFont font2;
        font2.setPointSize(14);
        label_22->setFont(font2);
        pushButton_Edit = new QPushButton(ProductTemp);
        pushButton_Edit->setObjectName(QStringLiteral("pushButton_Edit"));
        pushButton_Edit->setGeometry(QRect(680, 470, 211, 41));
        pushButton_Edit->setFont(font1);
        pushButton_Edit->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_PDF = new QPushButton(ProductTemp);
        pushButton_PDF->setObjectName(QStringLiteral("pushButton_PDF"));
        pushButton_PDF->setGeometry(QRect(570, 160, 61, 23));
        pushButton_PDF->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_TPrix = new QPushButton(ProductTemp);
        pushButton_TPrix->setObjectName(QStringLiteral("pushButton_TPrix"));
        pushButton_TPrix->setGeometry(QRect(660, 160, 75, 23));
        pushButton_TPrix->setCursor(QCursor(Qt::PointingHandCursor));
        lineEdit_recherche = new QLineEdit(ProductTemp);
        lineEdit_recherche->setObjectName(QStringLiteral("lineEdit_recherche"));
        lineEdit_recherche->setGeometry(QRect(1010, 160, 251, 21));
        pushButton_TQte = new QPushButton(ProductTemp);
        pushButton_TQte->setObjectName(QStringLiteral("pushButton_TQte"));
        pushButton_TQte->setGeometry(QRect(750, 160, 75, 23));
        pushButton_TQte->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget = new QTabWidget(ProductTemp);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(460, 190, 761, 231));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 10, 741, 192));
        tabWidget->addTab(tab, QString());
        Statistiques = new QWidget();
        Statistiques->setObjectName(QStringLiteral("Statistiques"));
        horizontalFrame = new QFrame(Statistiques);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(10, 10, 631, 191));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget->addTab(Statistiques, QString());
        pushButton_OOS = new QPushButton(ProductTemp);
        pushButton_OOS->setObjectName(QStringLiteral("pushButton_OOS"));
        pushButton_OOS->setGeometry(QRect(1040, 40, 91, 31));
        QFont font3;
        font3.setPointSize(11);
        pushButton_OOS->setFont(font3);
        pushButton_OOS->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_stats = new QPushButton(ProductTemp);
        pushButton_stats->setObjectName(QStringLiteral("pushButton_stats"));
        pushButton_stats->setGeometry(QRect(980, 580, 221, 71));
        pushButton_stats->setFont(font1);
        lineEdit_3 = new QLineEdit(ProductTemp);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(1040, 430, 113, 20));
        pushButton_QR = new QPushButton(ProductTemp);
        pushButton_QR->setObjectName(QStringLiteral("pushButton_QR"));
        pushButton_QR->setGeometry(QRect(580, 560, 121, 31));
        pushButton_Excel = new QPushButton(ProductTemp);
        pushButton_Excel->setObjectName(QStringLiteral("pushButton_Excel"));
        pushButton_Excel->setGeometry(QRect(740, 560, 121, 31));
        label_23 = new QLabel(ProductTemp);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(980, 130, 211, 16));
        label_23->setFont(font3);
        label_24 = new QLabel(ProductTemp);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(60, 10, 1191, 661));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/image/2.png")));
        label_24->setScaledContents(true);
        pushButton = new QPushButton(ProductTemp);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(930, 30, 93, 28));
        GestionApp->addWidget(ProductTemp);
        label_24->raise();
        label_7->raise();
        label_ID->raise();
        lineEdit_ID->raise();
        label_Nom->raise();
        lineEdit_Nom->raise();
        label_Type->raise();
        lineEdit_Type->raise();
        label_Poids->raise();
        lineEdit_Poids->raise();
        label_Prix->raise();
        lineEdit_Prix->raise();
        label_Qte->raise();
        lineEdit_Qte->raise();
        pushButton_Add->raise();
        pushButton_Delete->raise();
        label_22->raise();
        pushButton_Edit->raise();
        pushButton_PDF->raise();
        pushButton_TPrix->raise();
        lineEdit_recherche->raise();
        pushButton_TQte->raise();
        tabWidget->raise();
        pushButton_OOS->raise();
        pushButton_stats->raise();
        lineEdit_3->raise();
        pushButton_QR->raise();
        pushButton_Excel->raise();
        label_23->raise();
        pushButton->raise();
        Login = new QWidget();
        Login->setObjectName(QStringLiteral("Login"));
        groupBox_2 = new QGroupBox(Login);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 40, 761, 281));
        groupBox_2->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 127);\n"
"font: 8pt \"MV Boli\";\n"
"color: rgb(255, 199, 58);"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(390, 130, 113, 20));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 130, 91, 21));
        label->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(390, 180, 113, 20));
        lineEdit_2->setAutoFillBackground(false);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 170, 111, 31));
        label_6->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(0, 20, 411, 81));
        label_21->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/381518971_1302290803745035_2055574946688680530_n-removebg-preview.png")));
        GestionApp->addWidget(Login);

        retranslateUi(Dialog);

        GestionApp->setCurrentIndex(2);
        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "Produit", Q_NULLPTR));
        NomProd->setText(QApplication::translate("Dialog", "Nom", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Type", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "Poids", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "Prix", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "Nombre ", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Dialog", "Gestion de Produit", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Dialog", "Ajouter un produit", Q_NULLPTR));
        label_12->setText(QApplication::translate("Dialog", "Nom", Q_NULLPTR));
        label_13->setText(QApplication::translate("Dialog", "Type", Q_NULLPTR));
        label_14->setText(QApplication::translate("Dialog", "Poids", Q_NULLPTR));
        label_15->setText(QApplication::translate("Dialog", "Prix", Q_NULLPTR));
        label_16->setText(QApplication::translate("Dialog", "Nombre ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog", "Annuler", Q_NULLPTR));
        pushButton_p->setText(QApplication::translate("Dialog", "Valider", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Dialog", "Produit", Q_NULLPTR));
        NomProd_2->setText(QApplication::translate("Dialog", "Nom", Q_NULLPTR));
        label_8->setText(QApplication::translate("Dialog", "Type", Q_NULLPTR));
        label_9->setText(QApplication::translate("Dialog", "Poids", Q_NULLPTR));
        label_10->setText(QApplication::translate("Dialog", "Prix", Q_NULLPTR));
        label_11->setText(QApplication::translate("Dialog", "Nombre ", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("Dialog", "Produit", Q_NULLPTR));
        NomProd_3->setText(QApplication::translate("Dialog", "Nom", Q_NULLPTR));
        label_17->setText(QApplication::translate("Dialog", "Type", Q_NULLPTR));
        label_18->setText(QApplication::translate("Dialog", "Poids", Q_NULLPTR));
        label_19->setText(QApplication::translate("Dialog", "Prix", Q_NULLPTR));
        label_20->setText(QApplication::translate("Dialog", "Nombre ", Q_NULLPTR));
        label_7->setText(QString());
        label_ID->setText(QApplication::translate("Dialog", "ID Produit", Q_NULLPTR));
        label_Nom->setText(QApplication::translate("Dialog", "Nom", Q_NULLPTR));
        label_Type->setText(QApplication::translate("Dialog", "Type", Q_NULLPTR));
        label_Poids->setText(QApplication::translate("Dialog", "Poids", Q_NULLPTR));
        label_Prix->setText(QApplication::translate("Dialog", "Prix", Q_NULLPTR));
        label_Qte->setText(QApplication::translate("Dialog", "Quantit\303\251", Q_NULLPTR));
        pushButton_Add->setText(QApplication::translate("Dialog", "Ajout", Q_NULLPTR));
        pushButton_Delete->setText(QApplication::translate("Dialog", "Supprimer", Q_NULLPTR));
        label_22->setText(QApplication::translate("Dialog", "ID", Q_NULLPTR));
        pushButton_Edit->setText(QApplication::translate("Dialog", "Modifier", Q_NULLPTR));
        pushButton_PDF->setText(QApplication::translate("Dialog", "EXPORT", Q_NULLPTR));
        pushButton_TPrix->setText(QApplication::translate("Dialog", "TRI Prix", Q_NULLPTR));
        pushButton_TQte->setText(QApplication::translate("Dialog", "TRI Quantit\303\251", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog", "Produits", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Statistiques), QApplication::translate("Dialog", "Statistiques", Q_NULLPTR));
        pushButton_OOS->setText(QApplication::translate("Dialog", "Notifications", Q_NULLPTR));
        pushButton_stats->setText(QApplication::translate("Dialog", "Statistiques", Q_NULLPTR));
        pushButton_QR->setText(QApplication::translate("Dialog", "Generate QR", Q_NULLPTR));
        pushButton_Excel->setText(QApplication::translate("Dialog", "Export Excel", Q_NULLPTR));
        label_23->setText(QApplication::translate("Dialog", "Entrez le nom \303\240 rechercher:", Q_NULLPTR));
        label_24->setText(QString());
        pushButton->setText(QApplication::translate("Dialog", "quitter", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Dialog", "Authentification", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "ID", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", "Mot de passe", Q_NULLPTR));
        label_21->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
