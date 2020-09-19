#include "paymentgateway.h"
#include "ui_paymentgateway.h"
#include "paymentsummary.h"
#include "mainmenucust.h"
#include "paymentauthorization.h"
#include "bookingview.h"
#include "dblogin.h"

PaymentGateway::PaymentGateway(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaymentGateway)
{
    ui->setupUi(this);

    getFormData(ui);
    setFixedSize(400,410);
}

PaymentGateway::~PaymentGateway()
{
    delete ui;
}

void PaymentGateway::on_buttonHome_clicked()
{
    MainMenuCust *mmc = new MainMenuCust;
    mmc->show();
    this->hide();
}

void PaymentGateway::on_buttonCancel_clicked()
{
    PaymentSummary *ps = new PaymentSummary;
    ps->show();
    this->hide();
}

void PaymentGateway::on_buttonAutho_clicked()
{
    cardHolderName = ui->lineEditName->text();
    cardNumber = ui->lineEditCard->text();
    QString date = ui->lineEditDate->text(), cvv = ui->lineEditCVV->text();

    if (!(cardNumber == "" || cardHolderName == "" || date == "" || cvv == "")) {
        PaymentAuthorization *pa = new PaymentAuthorization;
        pa->show();
        this->close();
    }
}

void getFormData(Ui::PaymentGateway* ui) {
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID(),
            bookingID = getBookingActivatedID(),
            totalPrice = getTotalPrice();

    QSqlQuery query;
    query.prepare("SELECT homestay.homestayID "
                  "FROM booking, homestay WHERE "
                  "booking.bookingID = homestay.bookingID");
    if (query.exec()) {
        query.next();
        ui->lineEditHomeID->setText(query.value(0).toString());
        ui->lineEditUserID->setText(userID);
        ui->lineEditBookID->setText(bookingID);
    }
    ui->lineEditPrice->setText(totalPrice);
    ui->comboBoxType->addItem("Credit Card");
    ui->comboBoxType->addItem("Debit Card");

    ui->lineEditCard->setPlaceholderText("e.g. 1212-1212-1212-1212");
    ui->lineEditDate->setPlaceholderText("mm/yy");
}

QString getCardNum() {
    return cardNumber;
}

QString getCardHolderName() {
    return cardHolderName;
}
