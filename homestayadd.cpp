#include "homestayadd.h"
#include "ui_homestayadd.h"
#include "mainmenuhost.h"
#include "popuphomestayadd.h"
#include "dblogin.h"
#include "allclasses.h"
#include "QDebug"

HomestayAdd::HomestayAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomestayAdd)
{
    ui->setupUi(this);
    setFixedSize(580,390);
}

HomestayAdd::~HomestayAdd()
{
    delete ui;
}

void HomestayAdd::on_buttonHome_clicked()
{
    MainMenuHost *mmh = new MainMenuHost;
    mmh->show();
    this->close();
}

void HomestayAdd::on_buttonReset_clicked()
{
    foreach(QLineEdit* le, findChildren<QLineEdit*>())
        le->clear();
}

void HomestayAdd::on_buttonAdd_clicked()
{
    DBLogin conn;
    conn.connOpen();

    QString homestayID = IDCheckHomestay(), userID = getCurrUserID();

    QString homestayName = ui->lineEditName->text(),
            homestayLoc = ui->lineEditLoc->text(),
            homestayType = ui->comboBoxType->currentText(),
            homestayBedrmNum = ui->lineEditBed->text(),
            homestayBathrmNum = ui->lineEditBath->text(),
            homestayPrice = ui->lineEditPrice->text(),
            carparkNum = ui->lineEditCar->text(),
            wifi = "N",
            nonSmoking = "N";

    if (!(homestayName == "" || homestayLoc == "" || homestayType == "")) {
        conn.connOpen();

        if (ui->checkBoxWifi->isChecked())
            wifi = "Y";
        if (ui->checkBoxSmoke->isChecked())
            nonSmoking = "Y";

        Homestay newHomestay(homestayID, homestayName, homestayLoc, homestayType, homestayBedrmNum, homestayBathrmNum, homestayPrice, carparkNum, wifi, nonSmoking);
        QSqlQuery query;
        query.prepare("INSERT INTO homestay(homestayID, homestayName, homestayLoc, homestayType, homestayBedrmNum, homestayBathrmNum, homestayPrice, carparkNum, wifi, nonSmoking, userID) VALUES"
                      "('"+homestayID+"', '"+homestayName+"', '"+homestayLoc+"', '"+homestayType+"', '"+homestayBedrmNum+"', '"+homestayBathrmNum+"', '"+homestayPrice+"', '"+carparkNum+"', '"+wifi+"', '"+nonSmoking+"', '"+userID+"')");
        if (query.exec()) {
            PopupHomestayAdd *hPopup = new PopupHomestayAdd;
            hPopup->show();
            this->close();
        }
    }
    else {
        ui->aLabel->setText("<font color=red>Required field(s) is empty</font>");
    }

    conn.connClose();
}

QString IDCheckHomestay() {
    QSqlQuery query;
    query.exec("SELECT homestayID FROM homestay");

    bool IDChecking = true;
    QString tempID = "";
    srand(time(nullptr));
    while (IDChecking == true) {
        tempID = "H"+QString::number(rand() % 100000);
        while(query.next()) {
            if (tempID == query.value(0).toString())
                continue;
            else {
                IDChecking = false;
                break;
            }
        }
    }
    return tempID;
}
