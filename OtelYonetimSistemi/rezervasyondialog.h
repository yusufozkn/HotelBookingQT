#ifndef REZERVASYONDIALOG_H
#define REZERVASYONDIALOG_H

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
class rezervasyonDialog;
}

class rezervasyonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit rezervasyonDialog(QWidget *parent = nullptr);
    ~rezervasyonDialog();
    void readData();
private slots:
    void on_btnVazgec_clicked();

    void on_btnKayit_clicked();

private:
    Ui::rezervasyonDialog *ui;
};

#endif // REZERVASYONDIALOG_H
