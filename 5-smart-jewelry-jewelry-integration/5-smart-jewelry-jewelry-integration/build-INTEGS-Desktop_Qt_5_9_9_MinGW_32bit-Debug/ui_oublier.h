/********************************************************************************
** Form generated from reading UI file 'oublier.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUBLIER_H
#define UI_OUBLIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_oublier
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit_q;
    QLineEdit *lineEdit_qq;
    QLabel *label_2;
    QPushButton *pushButton_valider;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *oublier)
    {
        if (oublier->objectName().isEmpty())
            oublier->setObjectName(QStringLiteral("oublier"));
        oublier->resize(1022, 600);
        centralwidget = new QWidget(oublier);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 80, 771, 391));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 150, 321, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 220, 241, 16));
        lineEdit_q = new QLineEdit(groupBox);
        lineEdit_q->setObjectName(QStringLiteral("lineEdit_q"));
        lineEdit_q->setGeometry(QRect(310, 220, 113, 22));
        lineEdit_qq = new QLineEdit(groupBox);
        lineEdit_qq->setObjectName(QStringLiteral("lineEdit_qq"));
        lineEdit_qq->setGeometry(QRect(310, 290, 113, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 290, 181, 16));
        pushButton_valider = new QPushButton(groupBox);
        pushButton_valider->setObjectName(QStringLiteral("pushButton_valider"));
        pushButton_valider->setGeometry(QRect(490, 250, 93, 28));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(-10, 0, 791, 411));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/image/3.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(270, 80, 321, 71));
        label_5->setStyleSheet(QLatin1String("font: 87 14pt \"Bodoni MT Black\";\n"
"text-decoration: underline;\n"
"color: rgb(255, 255, 255);"));
        label_4->raise();
        label_3->raise();
        label->raise();
        lineEdit_q->raise();
        lineEdit_qq->raise();
        label_2->raise();
        pushButton_valider->raise();
        label_5->raise();
        oublier->setCentralWidget(centralwidget);
        menubar = new QMenuBar(oublier);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1022, 26));
        oublier->setMenuBar(menubar);
        statusbar = new QStatusBar(oublier);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        oublier->setStatusBar(statusbar);

        retranslateUi(oublier);

        QMetaObject::connectSlotsByName(oublier);
    } // setupUi

    void retranslateUi(QMainWindow *oublier)
    {
        oublier->setWindowTitle(QApplication::translate("oublier", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("oublier", "GroupBox", Q_NULLPTR));
        label_3->setText(QApplication::translate("oublier", "pour recuperer votre mot de passe", Q_NULLPTR));
        label->setText(QApplication::translate("oublier", "quel est votre role", Q_NULLPTR));
        label_2->setText(QApplication::translate("oublier", "quel est votre ID", Q_NULLPTR));
        pushButton_valider->setText(QApplication::translate("oublier", "valider", Q_NULLPTR));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("oublier", "mot de passe oubli\303\251 ?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class oublier: public Ui_oublier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUBLIER_H
