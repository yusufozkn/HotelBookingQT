#include "rezervasyondialog.h"
#include "ui_rezervasyondialog.h"


using namespace std;

rezervasyonDialog::rezervasyonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rezervasyonDialog)
{
    ui->setupUi(this);
    this->setFixedSize(720,340);
}

rezervasyonDialog::~rezervasyonDialog()
{
    delete ui;
}

void rezervasyonDialog::readData(){

    vector<int>kirliOdalar = Hotel::getInstance()->odaListesi("s");
    vector<int>temizOdalar = Hotel::getInstance()->odaListesi("y");
    this->ui->cmbOdalar->clear();


    for(vector<int>::iterator it = temizOdalar.begin(); it!=temizOdalar.end();it++){

        this->ui->cmbOdalar->addItem(QString::number(*it));
    }
//------------------

    vector<int>tempOdalar = {101,102,103,104,105,201,202,203,204,205,301,302,303,304,401,402,403,404,501,502};


    for(vector<int>::iterator it = tempOdalar.begin(); it!=tempOdalar.end();it++){

        QString lblname ="lbl"+QString::number(*it);
        QLabel * ptr =this->findChild<QLabel*>(lblname);


        if(ptr){
            ptr->setStyleSheet("QLabel { background-color : lightgrey; color : red; }");

        }
    }


    for(vector<int>::iterator it = temizOdalar.begin();it!=temizOdalar.end();it++){

        QString lblname ="lbl"+ QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
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
        ui->txtIsim->setFocus();
}




void rezervasyonDialog::on_btnVazgec_clicked()
{
    this->hide();
}



void rezervasyonDialog::on_btnKayit_clicked()
{

    int odaNo = ui->cmbOdalar->currentText().toInt();
    QString isim = ui->txtIsim->text();
    QString soyIsim = ui->txtSoyisim->text();
    QString telNo = ui->txtTelno->text();

    if(odaNo<1){
        QMessageBox::information(this,tr("uyari"),tr("bu oda uygun degil"));
        return;
    }
    int ret = Hotel::getInstance()->Rezervasyon(odaNo,isim,soyIsim,telNo);
    QString msg="";
    ret==0?msg="Basarili!":"Hata!";

    this->hide();
    if (ret==0){
        QMessageBox::information(this,tr("Basarili"),tr("Oda rezerve edildi"));
    }

    ui->txtIsim->setText("");
    ui->txtSoyisim->setText("");
    ui->txtTelno->setText("");

}

