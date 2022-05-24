#include "hotel.h"
#include "QDebug"

using namespace std;


Hotel* Hotel::instance = nullptr;

//odaBilgileriDialog
int Hotel::odeme(int odaNo){


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


    //DB de gezinme ve guncelleme islemi
    QSqlQuery query(Database);
    query.prepare("update odalar set available ='s' where number='" +QString::number(odaNo)+"'");

    if(!query.exec())
        qDebug()<<query.lastError().text()<<query.lastQuery();
    else
        qDebug()<<"Basariyla guncellendi"<<query.lastQuery();
    //---

    //

    query.clear();
    query.prepare("update islem set guncel ='n' where number='" +QString::number(odaNo)+"'");
    if(!query.exec())
        qDebug()<<query.lastError().text()<<query.lastQuery();
    else
        qDebug()<<"Basariyla guncellendi"<<query.lastQuery();
    //
    query.clear();
    query.prepare("update misafir set Guncellik ='n' where oda='" +QString::number(odaNo)+"'");
    if(!query.exec())
        qDebug()<<query.lastError().text()<<query.lastQuery();
    else
        qDebug()<<"Basariyla guncellendi"<<query.lastQuery();
    //





    Database.close();

    return 0;
}

//rezervasyonDialog
int Hotel::Rezervasyon(int odaNo, QString isim, QString soyIsim, QString telNo){


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


    //-------------------------------------------------------------------------
    QSqlQuery query(Database);

    query.prepare("update odalar set available ='n' where number='" +QString::number(odaNo)+"'");

    if(!query.exec())
        qDebug()<<query.lastError().text()<<query.lastQuery();
    else
        qDebug()<<"Basariyla guncellendi"<<query.lastQuery();




//--------------------------------------------------------------------------------

    //---
    query.clear();
    query.prepare("insert into misafir (isim, soyIsim, telNo, oda, Guncellik) values ('" + isim + "','" + soyIsim + "','" + telNo + "','" + QString::number(odaNo)+ "','"+"y"+"')");
    QString misafirID;
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else{
        qDebug()<<"Basariyla guncellendi"<<query.lastQuery();
        misafirID=query.lastInsertId().toString();
    }
    //---

    query.clear();
    query.prepare("insert into islem (number, misafirID,guncel) values ('" + QString::number(odaNo) + "','" + misafirID + "','y')");
    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug()<<"Basariyla guncellendi"<<query.lastQuery();
    //---


    Database.close();

    return 0;
}

//bosOdalarDialog
vector<int>Hotel::odaListesi(QString flag = "y"){

    vector<int>odalar;

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

    QSqlQuery query(Database);
    query.prepare("select number from odalar where available = '" + flag + "'");


    if(!query.exec())
        qDebug()<<query.lastError().text()<<query.lastQuery();
    else
        qDebug()<<"Basariyla guncellendi"<<query.lastQuery();


    while(query.next())
    {
        QString record = query.value(0).toString();
        odalar.push_back(record.toInt());
    }

    Database.close();
    return odalar;
}

//odaTemizlikDialog
int Hotel::odaTemizlik(int odaNo){

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


    //DB de gezinme ve guncelleme islemi
    QSqlQuery query(Database);
    query.prepare("update odalar set available ='y' where number='" +QString::number(odaNo)+"'");

    if(!query.exec())
        qDebug()<<query.lastError().text()<<query.lastQuery();
    else
        qDebug()<<"Basariyla guncellendi"<<query.lastQuery();
    //---

    Database.close();

    return 0;

}



Hotel *Hotel::getInstance(){
    if(instance == nullptr)
        instance = new Hotel();
    return instance;
}



