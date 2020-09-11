#ifndef ALLCLASSES_H
#define ALLCLASSES_H

#include <QCoreApplication>

class User {
private:
    QString userID;
    QString userFirstName;
    QString userLastName;
    QString username;
    QString userPassword;
    QString userPhoneNum;
    QString userEmail;
    int accType;
public:
    User(){}
    void setUserID(QString a) {userID = a;}
    void setUserFirstName(QString a) {userFirstName = a;}
    void setUserLastName(QString a) {userLastName = a;}
    void setUsername(QString a) {username = a;}
    void setUserPassword(QString a) {userPassword = a;}
    void setUserPhoneNum(QString a) {userPhoneNum = a;}
    void setUserEmail(QString a) {userEmail = a;}
    void setAccType(int a) {accType = a;}
    QString getUserID() {return userID;}
    QString getUserFirstName() {return userFirstName;}
    QString getUserLastName() {return userLastName;}
    QString getUsername() {return username;}
    QString getUserPassword() {return userPassword;}
    QString getUserPhoneNum() {return userPhoneNum;}
    QString getUserEmail() {return userEmail;}
    int getAccType() {return accType;}
};

class Host : public User {
public:
    Host(QString a, QString c, QString d, QString e, QString f, QString g, QString h) {
        setUserID(a);
        setUserFirstName(c);
        setUserLastName(d);
        setUsername(e);
        setUserPassword(f);
        setUserPhoneNum(g);
        setUserEmail(h);
        setAccType(1);
    }
};

class Customer : public User {
public:
    Customer(QString a, QString c, QString d, QString e, QString f, QString g, QString h) {
        setUserID(a);
        setUserFirstName(c);
        setUserLastName(d);
        setUsername(e);
        setUserPassword(f);
        setUserPhoneNum(g);
        setUserEmail(h);
        setAccType(2);
    }
};

class TechSupport : public User {
public:
    TechSupport(QString a, QString c, QString d, QString e, QString f, QString g, QString h) {
        setUserID(a);
        setUserFirstName(c);
        setUserLastName(d);
        setUsername(e);
        setUserPassword(f);
        setUserPhoneNum(g);
        setUserEmail(h);
        setAccType(3);
    }
};

class Homestay {
private:
    QString homestayID;
    QString homestayName;
    QString homestayLoc;
    QString homestayType;
    QString homestayBedrmNum;
    QString homestayBathrmNum;
    QString homestayPrice;
    QString carparkNum;
    QString wifi;
    QString nonSmoking;
public:
    Homestay(QString a, QString b, QString c, QString d, QString e, QString f, QString g, QString h, QString i, QString j) {
        homestayID = a;
        homestayName = b;
        homestayLoc = c;
        homestayType = d;
        homestayBedrmNum = e;
        homestayBathrmNum = f;
        homestayPrice = g;
        carparkNum = h;
        wifi = i;
        nonSmoking = j;
    }
};

#endif // EVERYTHING_H
