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
    query.prepare("SELECT paymentStatus, reviewStatus FROM booking WHERE bookingID = '"+bookingID+"'");
    if (query.exec()) {
        query.next();
        if (query.value(0).toString() == "Y") {
            ui->buttonPay->setEnabled(false);
            if (query.value(1).toString() == "Y") {
                ui->buttonReview->setEnabled(false); }
            else
                ui->buttonReview->setEnabled(true); }
        else {
            ui->buttonPay->setEnabled(true);
            ui->buttonReview->setEnabled(false);
        }
    }
    conn.connClose();
}

void refreshTable(Ui::BookingView* ui) {
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID();

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery *queryPtr = new QSqlQuery(conn.myDB);

    queryPtr->prepare("SELECT booking.bookingID AS 'BID', "
                      "homestay.homestayID AS 'HID', "
                      "homestay.homestayName AS 'Homestay Name', "
                      "homestay.homestayLoc AS 'Homestay Location', "
                      "(booking.bookingDayInit || '/' || booking.bookingMthInit || '/' || booking.bookingYrInit) AS 'Check-in Date', "
                      "(booking.bookingDayFinal || '/' || booking.bookingMthFinal || '/' || booking.bookingYrFinal) AS 'Check-out Date', "
                      "booking.paymentStatus AS 'Paid?', "
                      "booking.reviewStatus AS 'Reviewed?' FROM "
                      "booking, homestay WHERE "
                      "booking.userID = '"+userID+"' AND "
                      "booking.bookingID = homestay.bookingID");
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
