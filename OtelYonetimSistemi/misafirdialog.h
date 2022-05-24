#ifndef MISAFIRDIALOG_H
#define MISAFIRDIALOG_H

#include <QDialog>
#include "hotel.h"

namespace Ui {
class MisafirDialog;
}

class MisafirDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MisafirDialog(QWidget *parent = nullptr);
    ~MisafirDialog();
    void readData();

private slots:
    void on_btnVazgec_clicked();

    void on_btnOdeme_clicked();



private:
    Ui::MisafirDialog *ui;
};

#endif // MISAFIRDIALOG_H
