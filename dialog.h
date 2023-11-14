#ifndef DIALOG_H
#define DIALOG_H
#include <QTableView>
#include <QDialog>
#include "produit.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setProduit(Produit p);
    ~Dialog();

private slots:
    void on_pushButton_Add_clicked();
    void on_pushButton_Delete_clicked();
    void on_pushButton_Edit_clicked();

    void on_pushButton_PDF_clicked();
    void on_pushButton_TPrix_clicked();
    void on_pushButton_TQte_clicked();

    void on_lineEdit_recherche_textChanged(QString);



private:
    Ui::Dialog *ui;
    Produit Ptemp;
};

#endif // DIALOG_H
