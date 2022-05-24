#ifndef ODATEMIZLIKDIALOG_H
#define ODATEMIZLIKDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include "hotel.h"
#include <string>
#include <qmessagebox.h>
#include "vector"

namespace Ui {
class odaTemizlikDialog;
}

class odaTemizlikDialog : public QDialog
{
    Q_OBJECT

public:
    explicit odaTemizlikDialog(QWidget *parent = nullptr);
    ~odaTemizlikDialog();
    void readData();

private slots:
    void on_btnVazgec_clicked();

    void on_btnOdeme_clicked();

private:
    Ui::odaTemizlikDialog *ui;
};

#endif // ODATEMIZLIKDIALOG_H
