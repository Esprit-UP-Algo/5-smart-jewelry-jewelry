#ifndef EVENTS_H
#define EVENTS_H

#include <QMap>
#include <QDate>
#include <QString>

class Events
{
public:
    Events();

    void addEvent(const QDate &date, const QString &description);
    void removeEvent(const QDate &date);
    QString getEvent(const QDate &date) const;

    QList<QDate> getAllEventDates() const;

private:
    QMap<QDate, QString> events;
};

#endif // EVENTS_H
