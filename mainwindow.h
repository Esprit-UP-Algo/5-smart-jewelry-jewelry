#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "facture.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "qrcodegen.hpp"


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
    void on_ajout_button_clicked();

    void on_modifier_button_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_clicked();

    void on_all_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_idsearch_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
     Facture Ftmp;
};

#endif // MAINWINDOW_H
