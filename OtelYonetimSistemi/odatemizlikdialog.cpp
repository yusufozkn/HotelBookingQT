#include "odatemizlikdialog.h"
#include "ui_odatemizlikdialog.h"

odaTemizlikDialog::odaTemizlikDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::odaTemizlikDialog)
{
    ui->setupUi(this);
    this->setFixedSize(600,340);
}

odaTemizlikDialog::~odaTemizlikDialog()
{
    delete ui;
}

void odaTemizlikDialog::readData(){


    vector<int>kirliOdalar = Hotel::getInstance()->odaListesi("s");
    vector<int>temizOdalar = Hotel::getInstance()->odaListesi("y");

    this->ui->cmbOdalar->clear();

    for(vector<int>::iterator it = kirliOdalar.begin(); it!=kirliOdalar.end();it++){

        this->ui->cmbOdalar->addItem(QString::number(*it));
    }

    vector<int>tempOdalar = {101,102,103,104,105,201,202,203,204,205,301,302,303,304,401,402,403,404,501,502};

    for(vector<int>::iterator it = tempOdalar.begin(); it!=tempOdalar.end();it++){

        QString lblname ="lbl"+QString::number(*it);
        QLabel * ptr =this->findChild<QLabel*>(lblname);


        if(ptr){
            ptr->setStyleSheet("QLabel { background-color : white; color : green; }");

        }
    }
    for(vector<int>::iterator it = kirliOdalar.begin();it!=kirliOdalar.end();it++){

        QString lblname ="lbl"+ QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            ptr->setStyleSheet("QLabel { background-color : lightgrey; color : yellow; }");
        }

    }

}




void odaTemizlikDialog::on_btnVazgec_clicked()
{
    this->hide();
}


void odaTemizlikDialog::on_btnOdeme_clicked()
{
    int odaNo = ui->cmbOdalar->currentText().toInt();

    if(odaNo<1){
        QMessageBox::information(this,tr("uyari"),tr("bu oda bosaltilamadi"));
    }


    int ret = Hotel::getInstance()->odaTemizlik(odaNo);
    QString msg="";
    ret==0?msg="Basarili!":"Hata!";

    this->hide();

    if(ret == 0){
        QMessageBox::information(this,tr("Basarili"),tr("Oda temizligi yapildi"));
    }
}

