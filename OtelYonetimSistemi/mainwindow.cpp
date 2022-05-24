#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1024,540);

    ptrBosOdalarDlg = new BosOdalarDialog(this);
    ptrOdaBilgileriDlg = new OdaBilgileriDialog(this);
    ptrRezervasyonDlg = new rezervasyonDialog(this);
    ptrOdaTemizlikDlg = new odaTemizlikDialog(this);
    ptrMisafirDlg = new MisafirDialog(this);


    QPixmap pm("c:/OtelYonetimKaynak/1.jpg");
    ui->imgLabel->setPixmap(pm);
    ui->imgLabel->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrBosOdalarDlg;
    delete ptrOdaBilgileriDlg;
    delete ptrRezervasyonDlg;
    delete ptrOdaTemizlikDlg;
    delete ptrMisafirDlg;


}


void MainWindow::on_btnRezervasyon_clicked()
{
    ptrRezervasyonDlg->readData();
    ptrRezervasyonDlg->show();

}


void MainWindow::on_btnOdaBilgileri_clicked()
{
    ptrOdaBilgileriDlg->readData();
    ptrOdaBilgileriDlg->show();

}


void MainWindow::on_btnBosOdalar_clicked()
{
    ptrBosOdalarDlg->readData();
    ptrBosOdalarDlg->show();

}


void MainWindow::on_btnOdaTemizlik_clicked()
{
    ptrOdaTemizlikDlg->readData();
    ptrOdaTemizlikDlg->show();
}


void MainWindow::on_btnMisafirBilgileri_clicked()
{
    ptrMisafirDlg->show();
}

