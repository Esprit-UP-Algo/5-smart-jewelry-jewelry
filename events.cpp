#include "events.h"

Events::Events()
{
    // Vous pouvez initialiser des événements par défaut ici si nécessaire
}

void Events::addEvent(const QDate &date, const QString &description)
{
    events.insert(date, description);
}

void Events::removeEvent(const QDate &date)
{
    events.remove(date);
}

QString Events::getEvent(const QDate &date) const
{
    return events.value(date);
}

QList<QDate> Events::getAllEventDates() const
{
    return events.keys();
}
