#include "misafirdialog.h"
#include "ui_misafirdialog.h"

MisafirDialog::MisafirDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MisafirDialog)
{
    this->setFixedSize(350,280);
    ui->setupUi(this);
}

MisafirDialog::~MisafirDialog()
{
    delete ui;
}

void MisafirDialog::readData(){

    this->ui->listWidget->clear();
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE","Data");
    Database.setDatabaseName("c:/OtelYonetimKaynak/hotelmanagement.db");

    //DB nin kontrolu
    if(QFile::exists("c:/OtelYonetimKaynak/hotelmanagement.db"))
        qDebug()<<"Dataya ulasildi..";
    else
        qDebug()<<"Data dosyalarina ulasilamadi !";

    if(!Database.open())
        qDebug()<<Database.lastError().text();
    else
        qDebug()<<"Data basariyla okundu..";


    //---



    //---



    QSqlQuery query(Database);
    query.prepare("select * from islem");

    QSqlQuery query2(Database);
    query2.prepare("select * from misafir");


    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Başarılı"<< query.lastQuery();

    if(!query2.exec())
        qDebug() << query2.lastError().text() << query2.lastQuery();
    else
        qDebug() << "Başarılı"<< query2.lastQuery();



/*
                                    int odaNo = 101;

    while(query.next())
    {
       if(query.value(3).toString()=="y"){
            if(query.value(1).toInt() == odaNo){





                            this->ui->listWidget->addItem(query.value(1).toString());
                            this->ui->listWidget_2->addItem(query.value(2).toString());
                            this->ui->listWidget_3->addItem(query.value(3).toString());

           }
        }
    }
*/

    while(query2.next()){
            if(query2.value(5).toString()=="y"){

                    this->ui->listWidget->addItem(query2.value(1).toString()+"\t"+query2.value(2).toString()+" - "+query2.value(3).toString()+"\t"+query2.value(4).toString());
            }
    }


Database.close();
}

void MisafirDialog::on_btnVazgec_clicked()
{
    this->ui->listWidget->clear();
    this->close();
    this->ui->listWidget->clear();
}


void MisafirDialog::on_btnOdeme_clicked()//odeme degil getir aslinda :d
{

    this->ui->listWidget->clear();
    readData();

}

