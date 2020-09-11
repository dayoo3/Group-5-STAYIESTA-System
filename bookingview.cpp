#include "bookingview.h"
#include "ui_bookingview.h"
#include "popupbookingdelete.h"
#include "mainmenucust.h"
#include "paymentsummary.h"
#include "dblogin.h"
#include "reviewcreate.h"
#include "bookingdelete.h"

static QString ID = "";

BookingView::BookingView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookingView)
{
    ui->setupUi(this);
    setFixedSize(620,330);
    refreshTable(ui);

    ui->buttonPay->setEnabled(false);
    ui->buttonDelete->setEnabled(false);
    ui->buttonReview->setEnabled(false);
}

BookingView::~BookingView()
{
    delete ui;
}

void BookingView::on_buttonDelete_clicked()
{
    if (!(ID == "")) {
        BookingDelete *db = new BookingDelete;
        db->show();
        this->close();
    }
}

void BookingView::on_buttonHome_clicked()
{
    MainMenuCust *mmc = new MainMenuCust;
    mmc->show();
    this->close();
}

void BookingView::on_tableView_activated(const QModelIndex &index)
{
    ID = ui->tableView->model()->data(index).toString();

    DBLogin conn;
    conn.connOpen();

    QString bookingID = ID;

    QSqlQuery query;
    query.prepare("SELECT paymentStatus, reviewStatus FROM Booking WHERE bookingID = '"+bookingID+"'");
    if (query.exec()) {
        query.next();
        if (query.value(0).toString() == "Y")
            ui->buttonPay->setEnabled(false);
        else
            ui->buttonPay->setEnabled(true);

        if (query.value(1).toString() == "Y")
            ui->buttonReview->setEnabled(false);
        else
            ui->buttonReview->setEnabled(true);
        ui->buttonDelete->setEnabled(true);
    }
    conn.connClose();
}

void refreshTable(Ui::BookingView* ui) {
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID();

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery *queryPtr = new QSqlQuery(conn.myDB);

    queryPtr->prepare("SELECT Booking.bookingID AS 'BID', "
                      "Homestay.homestayID AS 'HID', "
                      "Homestay.homestayName AS 'Homestay Name', "
                      "Homestay.homestayLoc AS 'Homestay Location', "
                      "(Booking.bookingDayInit || '/' || Booking.bookingMthInit || '/' || Booking.bookingYrInit) AS 'Check-in Date', "
                      "(Booking.bookingDayFinal || '/' || Booking.bookingMthFinal || '/' || Booking.bookingYrFinal) AS 'Check-out Date', "
                      "Booking.paymentStatus AS 'Paid?', "
                      "Booking.reviewStatus AS 'Reviewed?' FROM "
                      "Booking, Homestay WHERE "
                      "Booking.userID = '"+userID+"' AND "
                      "Booking.bookingID = Homestay.bookingID");
    if (queryPtr->exec())  {
        model->setQuery(*queryPtr);
        ui->tableView->setModel(model);
        ui->tableView->setVisible(false);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setVisible(true);
    }
    else
        qDebug() << queryPtr->lastError();

    conn.connClose();
}

void BookingView::on_buttonPay_clicked()
{
    if (!(ID == "")) {

        PaymentSummary *dh = new PaymentSummary;
        dh->show();
        this->close();
    }
}

void BookingView::on_buttonReview_clicked()
{
    ReviewCreate *rc = new ReviewCreate;
    rc->show();
    this->close();
}

QString getBookingActivatedID() {
    return ID;
}
