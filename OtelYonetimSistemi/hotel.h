#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <QFile>
#include <QtSql>
#include <QSqlQuery>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>

using namespace std;

class Hotel
{
private:
    Hotel(){}
    Hotel(Hotel const &);
    static Hotel * instance;
    void updateHotelData(int room);

public:
    int Rezervasyon(int odaNo,QString isim, QString soyIsim, QString telNo);
    int odeme(int odaNo);
    vector<int>odaListesi(QString);
    int odaTemizlik(int odaNo);
    int misafirBilgi(int odaNo);

    static Hotel* getInstance();
};

#endif // HOTEL_H
