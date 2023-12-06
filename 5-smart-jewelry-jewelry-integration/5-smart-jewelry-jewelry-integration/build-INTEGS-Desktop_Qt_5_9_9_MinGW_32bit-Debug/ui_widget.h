/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_emp;
    QPushButton *pushButton_prod;
    QLabel *label;
    QLabel *label_2;
    QPushButton *gestionclient;
    QPushButton *pushButton_prod_2;
    QPushButton *pushButton_prod_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName(QStringLiteral("widget"));
        widget->resize(1057, 676);
        centralwidget = new QWidget(widget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_emp = new QPushButton(centralwidget);
        pushButton_emp->setObjectName(QStringLiteral("pushButton_emp"));
        pushButton_emp->setGeometry(QRect(90, 200, 241, 71));
        pushButton_emp->setStyleSheet(QStringLiteral(""));
        pushButton_prod = new QPushButton(centralwidget);
        pushButton_prod->setObjectName(QStringLiteral("pushButton_prod"));
        pushButton_prod->setGeometry(QRect(720, 200, 261, 71));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, 5, 1061, 631));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/menu.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(390, 90, 251, 111));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/lo-removebg-preview.png")));
        label_2->setScaledContents(true);
        gestionclient = new QPushButton(centralwidget);
        gestionclient->setObjectName(QStringLiteral("gestionclient"));
        gestionclient->setGeometry(QRect(90, 330, 241, 71));
        gestionclient->setStyleSheet(QStringLiteral(""));
        pushButton_prod_2 = new QPushButton(centralwidget);
        pushButton_prod_2->setObjectName(QStringLiteral("pushButton_prod_2"));
        pushButton_prod_2->setGeometry(QRect(720, 330, 261, 71));
        pushButton_prod_3 = new QPushButton(centralwidget);
        pushButton_prod_3->setObjectName(QStringLiteral("pushButton_prod_3"));
        pushButton_prod_3->setGeometry(QRect(380, 460, 261, 71));
        widget->setCentralWidget(centralwidget);
        label->raise();
        pushButton_emp->raise();
        pushButton_prod->raise();
        label_2->raise();
        gestionclient->raise();
        pushButton_prod_2->raise();
        pushButton_prod_3->raise();
        menubar = new QMenuBar(widget);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1057, 22));
        widget->setMenuBar(menubar);
        statusbar = new QStatusBar(widget);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        widget->setStatusBar(statusbar);

        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QMainWindow *widget)
    {
        widget->setWindowTitle(QApplication::translate("widget", "widget", Q_NULLPTR));
        pushButton_emp->setText(QApplication::translate("widget", "GESTION EMPLOYE", Q_NULLPTR));
        pushButton_prod->setText(QApplication::translate("widget", "GESTION PRODUIT", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        gestionclient->setText(QApplication::translate("widget", "GESTION CLIENT", Q_NULLPTR));
        pushButton_prod_2->setText(QApplication::translate("widget", "GESTION COMMANDE", Q_NULLPTR));
        pushButton_prod_3->setText(QApplication::translate("widget", "GESTION FACTURE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
