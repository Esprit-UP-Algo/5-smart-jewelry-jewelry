#ifndef JAAFERWINDOWS_H
#define JAAFERWINDOWS_H
#include "facture.h"

#include <QMainWindow>
 #include "qrcodegen.hpp"
#include"../ghaya/arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class jaaferwindows; }
QT_END_NAMESPACE

class jaaferwindows : public QMainWindow
{
    Q_OBJECT

public:
    jaaferwindows(QWidget *parent = nullptr);
    ~jaaferwindows();

private slots:
    void on_ajout_button_clicked();

    void on_modifier_button_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_clicked();

    void on_all_clicked();

    void update_label();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_idsearch_cursorPositionChanged(int arg1, int arg2);


private:
    Ui::jaaferwindows *ui;
    Facture Ftmp;
    arduino Ar;
    QByteArray data;
};
#endif // JAAFERWINDOWS_H
