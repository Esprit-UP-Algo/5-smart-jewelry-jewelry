/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_login;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_oublier;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(800, 600);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 260, 56, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 300, 101, 16));
        pushButton_login = new QPushButton(centralwidget);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setGeometry(QRect(240, 370, 93, 28));
        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(390, 260, 113, 22));
        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(390, 300, 113, 22));
        pushButton_oublier = new QPushButton(centralwidget);
        pushButton_oublier->setObjectName(QStringLiteral("pushButton_oublier"));
        pushButton_oublier->setGeometry(QRect(350, 370, 181, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-5, 5, 811, 551));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/image/1.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 150, 141, 91));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/image/users-removebg-preview.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(610, 10, 181, 131));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/image/lo-removebg-preview.png")));
        label_5->setScaledContents(true);
        login->setCentralWidget(centralwidget);
        label_3->raise();
        label->raise();
        label_2->raise();
        pushButton_login->raise();
        lineEdit_username->raise();
        lineEdit_password->raise();
        pushButton_oublier->raise();
        label_4->raise();
        label_5->raise();
        menubar = new QMenuBar(login);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("login", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "mot de passe", Q_NULLPTR));
        pushButton_login->setText(QApplication::translate("login", "se connecter", Q_NULLPTR));
        pushButton_oublier->setText(QApplication::translate("login", "mot de passe oubli\303\251?", Q_NULLPTR));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
