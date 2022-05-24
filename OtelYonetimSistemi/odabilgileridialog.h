#ifndef ODABILGILERIDIALOG_H
#define ODABILGILERIDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>

namespace Ui {
class OdaBilgileriDialog;
}

class OdaBilgileriDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OdaBilgileriDialog(QWidget *parent = nullptr);
    ~OdaBilgileriDialog();
    void readData();

private slots:
    void on_btnVazgec_clicked();

    void on_btnOdeme_clicked();

private:
    Ui::OdaBilgileriDialog *ui;
};

#endif // ODABILGILERIDIALOG_H
