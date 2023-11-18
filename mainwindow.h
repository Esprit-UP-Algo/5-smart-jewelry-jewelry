#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"


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
    QWidget *mainWidget;
    QWidget *statsWidget;

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();



    void on_pushButton_supprimer_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_modifier_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_stat_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_rechcin_clicked();



    void on_pushButton_raf_clicked();


    void on_pushButton_chat_clicked();

    //void on_calendarWidget_clicked(const QDate &dateE);


    void on_pushButton_eve_clicked();

private:
    Ui::MainWindow *ui;
    employe e;
};
#endif // MAINWINDOW_H



