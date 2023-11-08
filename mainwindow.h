#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();



    void on_chercher_clicked();

    void on_pdf_clicked();

    void on_pushButton_clicked();



    void on_stat_clicked();

private:
    Ui::MainWindow *ui;
    Client C;
};

#endif // MAINWINDOW_H
