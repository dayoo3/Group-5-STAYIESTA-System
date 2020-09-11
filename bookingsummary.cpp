#include "bookingsummary.h"
#include "ui_bookingsummary.h"
#include "dblogin.h"
#include "mainmenucust.h"
#include "popupbookingcreate.h"
#include "searchresult.h"
#include "bookingcreate.h"

BookingSummary::BookingSummary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookingSummary)
{
    ui->setupUi(this);
    setFixedSize(460,530);
    refreshTable(ui);
}

BookingSummary::~BookingSummary()
{
    delete ui;
}

void refreshTable(Ui::BookingSummary* ui) {
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID(),
            bookingID = getBookingID(),
            homestayID = getSearchActivatedID(),
            userName = "",
            userAddr = "";

    QSqlQuery query;
    query.prepare("SELECT userFirstName, userLastName, userEmail FROM User WHERE userID = '"+userID+"'");
    if (query.exec()) {
        query.next();
        userName = query.value(0).toString() + " " + query.value(1).toString();
        userAddr = query.value(2).toString();
    }

    query.prepare("SELECT * FROM Homestay WHERE homestayID = '"+homestayID+"'");
    if (query.exec()) {
        query.next();
        ui->lineEditBookID->setText(bookingID);
        ui->lineEditUserID->setText(userID);
        ui->lineEditName->setText(userName);
        ui->lineEditAddr->setText(userAddr);
        ui->lineEditHomeID->setText(homestayID);
        ui->lineEditHomeName->setText(query.value(1).toString());
        ui->lineEditLoc->setText(query.value(2).toString());
        ui->lineEditType->setText(query.value(3).toString());
        ui->lineEditBed->setText(query.value(4).toString());
        ui->lineEditBath->setText(query.value(5).toString());
        ui->lineEditCar->setText(query.value(7).toString());
        ui->lineEditPrice->setText(query.value(6).toString());

        if (query.value(8).toString() == "Y")
            ui->checkBoxWifi->setChecked(true);
        else
            ui->checkBoxWifi->setChecked(false);
        if (query.value(9).toString() == "N")
            ui->checkBoxSmoke->setChecked(true);
        else
            ui->checkBoxSmoke->setChecked(false);

        ui->dateEditIn->setDate(getDateIn());
        ui->dateEditOut->setDate(getDateOut());
    }
}


void BookingSummary::on_buttonHome_clicked()
{
    MainMenuCust *mmc = new MainMenuCust;
    mmc->show();
    this->close();
}

void BookingSummary::on_buttonReturn_clicked()
{
    BookingCreate *bc = new BookingCreate;
    bc->show();
    this->close();
}

void BookingSummary::on_buttonBook_clicked()
{
    DBLogin conn;
    conn.connOpen();

    QString bookingID = getBookingID(),
            userID = getCurrUserID(),
            homestayID = getSearchActivatedID(),
            bookingDayInit = QString::number(getDateIn().day()),
            bookingMthInit = QString::number(getDateIn().month()),
            bookingYrInit = QString::number(getDateIn().year()),
            bookingDayFinal = QString::number(getDateOut().day()),
            bookingMthFinal = QString::number(getDateOut().month()),
            bookingYrFinal = QString::number(getDateOut().year());

    QSqlQuery query;
    query.prepare("INSERT INTO Booking VALUES"
                  "('"+bookingID+"','"+bookingDayInit+"','"+bookingMthInit+"','"+bookingYrInit+"',"
                  "'"+bookingDayFinal+"','"+bookingMthFinal+"','"+bookingYrFinal+"','N','N','"+userID+"')");
    if (query.exec()) {
        query.prepare("UPDATE Homestay SET bookingID = '"+bookingID+"' "
                      "WHERE homestayID = '"+homestayID+"'");
        if (query.exec()) {
            PopupBookingCreate *pbc = new PopupBookingCreate;
            pbc->show();
            this->close();
        }
    }
}

