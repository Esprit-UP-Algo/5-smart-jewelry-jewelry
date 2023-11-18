#include "calendrier.h"
#include "ui_calendrier.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "events.h"

calendrier::calendrier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calendrier)
{
    ui->setupUi(this);

    // Vous avez accidentellement placé le destructeur à l'intérieur du constructeur,
    // ce qui n'est pas correct. Je l'ai déplacé à l'extérieur du constructeur.

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    calendar = new QCalendarWidget(this);
    eventLineEdit = new QLineEdit(this);

    connect(calendar, &QCalendarWidget::clicked, this, &calendrier::dateClicked);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(calendar);
    mainLayout->addWidget(eventLineEdit);

    setWindowTitle("Calendrier App");
}

// Destructeur de la classe
calendrier::~calendrier()
{
    delete  ui;
}

void calendrier::dateClicked(const QDate &date)
{

    // Implémentez la logique de la fonction dateClicked ici
    // C'est dans cette fonction que vous pouvez mettre à jour le QLineEdit
    // avec le texte de l'événement associé à la date cliquée.
    // Assurez-vous également de mettre à jour le calendrier avec la couleur appropriée.

    // Exemple :
    if (events.contains(date)) {
        eventLineEdit->setText(events.value(date));
    } else {
        eventLineEdit->clear();
    }



    // Ajout des jours fériés en 2023
    events.insert(QDate(2023, 1, 1), "Jour de l'An");
    events.insert(QDate(2023, 5, 1), "Fête du Travail");
    events.insert(QDate(2023, 7, 14), "Fête nationale");
    events.insert(QDate(2023, 12, 25), "Noël");

    updateCalendar();
}



void calendrier::updateCalendar()
{
    QList<QDate> eventDates = events.keys();
    calendar->setDateTextFormat(QDate(), QTextCharFormat()); // Clear existing formats

    for (const QDate &date : eventDates) {
        QTextCharFormat format;
        format.setForeground(Qt::red);
        calendar->setDateTextFormat(date, format);
    }
}
