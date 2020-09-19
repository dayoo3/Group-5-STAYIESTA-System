#include "bookingcreate.h"
#include "ui_bookingcreate.h"
#include "mainmenucust.h"
#include "bookingsummary.h"
#include "searchresult.h"
#include "dblogin.h"

static QString bookingID;
static QDate dateEditIn, dateEditOut;

BookingCreate::BookingCreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookingCreate)
{
    ui->setupUi(this);
    setFixedSize(380,230);

    getFormData(ui);
}

BookingCreate::~BookingCreate()
{
    delete ui;
}

void BookingCreate::on_buttonHome_clicked()
{
    MainMenuCust *mmc = new MainMenuCust;
    mmc->show();
    this->close();
}

void BookingCreate::on_buttonReturn_clicked()
{
    SearchResult *sr = new SearchResult;
    sr->show();
    this->close();
}

void BookingCreate::on_buttonBook_clicked()
{
    BookingSummary *bs = new BookingSummary;
    bs->show();
    this->close();
}

void BookingCreate::on_dateEditIn_userDateChanged(const QDate &date)
{
    dateEditIn = date;
}

void BookingCreate::on_dateEditOut_userDateChanged(const QDate &date)
{
    dateEditOut = date;
}

void getFormData(Ui::BookingCreate* ui) {
    DBLogin conn;
    conn.connOpen();

    bookingID = IDCheckBooking();

    ui->lineEditBookID->setText(bookingID);
    ui->lineEditHomeID->setText(getSearchActivatedID());
    ui->lineEditUserID->setText(getCurrUserID());

    conn.connClose();
}

QString getBookingID() {
    return bookingID;
}
QDate getDateIn() {
    return dateEditIn;
}
QDate getDateOut() {
    return dateEditOut;
}

QString IDCheckBooking() {
    QSqlQuery query;
    query.exec("SELECT bookingID FROM booking");

    bool IDChecking = true;
    QString tempID = "";
    srand(time(nullptr));
    while (IDChecking == true) {
        tempID = "B"+QString::number(rand() % 100000);
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
