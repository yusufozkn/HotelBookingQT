#ifndef BOSODALARDIALOG_H
#define BOSODALARDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include "hotel.h"

namespace Ui {
class BosOdalarDialog;
}

class BosOdalarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BosOdalarDialog(QWidget *parent = nullptr);
    ~BosOdalarDialog();
    void readData();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BosOdalarDialog *ui;
};

#endif // BOSODALARDIALOG_H
