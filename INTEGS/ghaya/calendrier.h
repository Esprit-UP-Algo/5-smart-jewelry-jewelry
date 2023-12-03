#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <QMainWindow>
#include <QCalendarWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMap>
#include <QDate>

namespace Ui {
class calendrier;
}
class calendrier : public QMainWindow
{
    Q_OBJECT

public:
    explicit calendrier(QWidget *parent = nullptr);
    ~calendrier();
    void updateCalendar();
private slots:
    void dateClicked(const QDate &date);

private:
    QCalendarWidget *calendar;
    QLineEdit *eventLineEdit;
    Ui::calendrier *ui;

    QMap<QDate, QString> events;

};

#endif // CALENDRIER_H




