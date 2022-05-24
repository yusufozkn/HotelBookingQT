#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hotel.h"
#include "bosodalardialog.h"
#include "odabilgileridialog.h"
#include "rezervasyondialog.h"
#include "odatemizlikdialog.h"
#include "misafirdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    BosOdalarDialog * ptrBosOdalarDlg;
    OdaBilgileriDialog * ptrOdaBilgileriDlg;
    rezervasyonDialog * ptrRezervasyonDlg;
    odaTemizlikDialog * ptrOdaTemizlikDlg;
    MisafirDialog * ptrMisafirDlg;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRezervasyon_clicked();

    void on_btnOdaBilgileri_clicked();

    void on_btnBosOdalar_clicked();

    void on_btnOdaTemizlik_clicked();

    void on_btnMisafirBilgileri_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
