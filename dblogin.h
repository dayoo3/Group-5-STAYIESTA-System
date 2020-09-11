#ifndef DBLOGIN_H
#define DBLOGIN_H

#include <QtSql>
#include <QDebug>

class DBLogin {
public:
    QSqlDatabase myDB;
    bool connOpen() {
        QSqlDatabase myDB = QSqlDatabase::addDatabase("QSQLITE");
        myDB.setDatabaseName("/Users/USER/Desktop/PP3_ArrobaInc/arrobaDB.sqlite");
        if(myDB.open()) {
            qDebug() << "DB Connection Established";
            return true;
        }
        else {
            qDebug() << "DB Connection Failed";
            return false;
        }
    }

    void connClose() {
        myDB.close();
        myDB.removeDatabase(QSqlDatabase::defaultConnection);
    }
};

QString getCurrUserID(); // class declaration at header to be called/defined at different cpp files
QString getCurrUsername();

#endif // DBLOGIN_H
