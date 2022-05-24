#include "odabilgileridialog.h"
#include "ui_odabilgileridialog.h"
#include <qmessagebox.h>
#include "hotel.h"

using namespace std;

OdaBilgileriDialog::OdaBilgileriDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OdaBilgileriDialog)
{
    ui->setupUi(this);
    this->setFixedSize(350,200);
}

OdaBilgileriDialog::~OdaBilgileriDialog()
{
    delete ui;
}

void OdaBilgileriDialog::readData(){

    vector<int>odalar = Hotel::getInstance()->odaListesi("n");
    this->ui->cmbOdalar->clear();
    char flag = 0;
    for(vector<int>::iterator it = odalar.begin(); it!=odalar.end();it++){
        this->ui->cmbOdalar->addItem(QString::number(*it));
        flag=1;
    }

    if (flag == 1){
        this->ui->btnOdeme->setEnabled(true);
    }
}

void OdaBilgileriDialog::on_btnVazgec_clicked()
{
    this->hide();
}


void OdaBilgileriDialog::on_btnOdeme_clicked()
{
    int odaNo = ui->cmbOdalar->currentText().toInt();

    if(odaNo<1){
        QMessageBox::information(this,tr("uyari"),tr("bu oda bosaltilamadi"));
    }

    else{
        int tem = Hotel::getInstance()->odeme(odaNo);

        QString msg="";
        tem==0?msg="Basarili!":"Hata!";

        this->hide();


        if(tem == 0){
            QMessageBox::information(this,tr("Basarili"),tr("Oda bosaltildi"));
        }
    }



}











