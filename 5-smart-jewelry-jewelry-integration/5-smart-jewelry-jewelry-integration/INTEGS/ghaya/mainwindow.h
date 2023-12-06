#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "arduino.h"
#include "calendrier.h"
#include "events.h"
#include <QtCharts/QChartView>
#include <QVBoxLayout>



#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void exportToPDF();
    void afficherStatistiques();
    void revenirPageInitiale();
    void marquerJoursFeries(QCalendarWidget *calendrier);
    QWidget *mainWidget;
    QWidget *statsWidget;
    QWidget *centralWidget;

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();



    void on_pushButton_supprimer_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_modifier_clicked();

    void on_pushButton_pdf_clicked();

    //****************

    void on_pushButton_stat_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_rechcin_clicked();



    void on_pushButton_raf_clicked();



    //void on_calendarWidget_clicked(const QDate &dateE);


   // void on_pushButton_eve_clicked();

    void on_pushButton_deconect_clicked();
    void update_label() ;
    //void displayEmployeeInfoOnLCD();
    void connect_RFID();
    void loginArd();



    void on_pushButton_clicked();

private:
    QtCharts::QChartView *chartView;
    Ui::MainWindow *ui;
    employe e;
    arduino A;
    QByteArray data;


};
#endif // MAINWINDOW_H



