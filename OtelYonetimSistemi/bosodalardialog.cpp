#include "bosodalardialog.h"
#include "ui_bosodalardialog.h"

using namespace std;

BosOdalarDialog::BosOdalarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BosOdalarDialog)
{
    ui->setupUi(this);
    this->setFixedSize(400,350);
}

void BosOdalarDialog::readData(){


    vector<int>odalar = Hotel::getInstance()->odaListesi("y");
    vector<int>tempOdalar = {101,102,103,104,105,201,202,203,204,205,301,302,303,304,401,402,403,404,501,502};


    for(vector<int>::iterator it = tempOdalar.begin(); it!=tempOdalar.end();it++){

        QString lblname ="lbl"+QString::number(*it);
        QLabel * ptr =this->findChild<QLabel*>(lblname);


        if(ptr){
            ptr->setStyleSheet("QLabel { background-color : lightgrey; color : red; }");

        }
    }


    for(vector<int>::iterator it = odalar.begin();it!=odalar.end();it++){

        QString lblname ="lbl"+ QString::number(*it);
        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            ptr->setStyleSheet("QLabel { background-color : white; color : green; }");
        }

    }

}


BosOdalarDialog::~BosOdalarDialog()
{
    delete ui;
}



void BosOdalarDialog::on_pushButton_clicked()
{
    this->close();
}

