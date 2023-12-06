#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QMainWindow
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();

private slots:
    void on_pushButton_emp_clicked();

    void on_pushButton_prod_clicked();

    void on_gestionclient_clicked();

    void on_pushButton_prod_2_clicked();

    void on_pushButton_prod_3_clicked();

private:
    Ui::widget *ui;

};
#endif // WIDGET_H
