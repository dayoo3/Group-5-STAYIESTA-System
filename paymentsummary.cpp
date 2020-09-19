#include "paymentsummary.h"
#include "ui_paymentsummary.h"
#include "mainmenucust.h"
#include "popuprewardapplied.h"
#include "popuprewardapplyfailed.h"
#include "popuprewardused.h"
#include "paymentgateway.h"
#include "bookingview.h"
#include "QDebug"
#include "dblogin.h"
#include "paymentsummaryhorizontal.h"
#include "QHeaderView"

PaymentSummary::PaymentSummary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaymentSummary)
{
    ui->setupUi(this);
    setFixedSize(460,530);

    daysDiff = "";
    totalPrice= "";
    rewardID = "";
    isDiscounted = false;
    refreshList(ui);
}

PaymentSummary::~PaymentSummary()
{
    delete ui;
}

void refreshList(Ui::PaymentSummary* ui) {
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID();
    QString bookingID = getBookingActivatedID();

    QString dateInit, dateFinal;

    QSqlQuery query;
    query.prepare("SELECT booking.bookingDayInit, booking.bookingMthInit, booking.bookingYrInit, "
                  "booking.bookingDayFinal, booking.bookingMthFinal, booking.bookingYrFinal, homestay.homestayPrice "
                  "FROM booking, homestay "
                  "WHERE booking.bookingID = '"+bookingID+"' AND "
                  "booking.bookingID = homestay.bookingID");
    if (query.exec()) {
        query.next();
        QDate dateInit(query.value(2).toInt(),query.value(1).toInt(),query.value(0).toInt());
        QDate dateFinal(query.value(5).toInt(),query.value(4).toInt(),query.value(3).toInt());

        daysDiff = QString::number(dateInit.daysTo(dateFinal));
        totalPrice = QString::number(query.value(6).toInt() * daysDiff.toInt());
    }
    else {
        qDebug() << query.lastError();
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *queryPtr = new QSqlQuery(conn.myDB);

    PaymentSummaryHorizontal* proxy_model = new PaymentSummaryHorizontal();

    queryPtr->prepare("SELECT booking.bookingID as 'Booking ID', "
                      "users.userID as 'Customer ID', "
                      "(users.userFirstName || ' ' || users.userLastName) as 'Name', "
                      "users.userEmail as 'E-mail',"
                      "homestay.homestayID as 'Homestay ID', "
                      "homestay.homestayName as 'Name', "
                      "homestay.homestayLoc as 'Location', "
                      "homestay.homestayType as 'Type', "
                      "homestay.homestayBedrmNum as 'Bedrooms', "
                      "homestay.homestayBathrmNum as 'Bathrooms', "
                      "homestay.carparkNum as 'Carparks', "
                      "homestay.wifi as 'Wi-Fi', "
                      "homestay.nonSmoking as 'Non-Smoking', "
                      "(booking.bookingDayInit || '/' || booking.bookingMthInit || '/' || booking.bookingYrInit) as 'Check-in Date', "
                      "(booking.bookingDayFinal || '/' || booking.bookingMthFinal || '/' || booking.bookingYrFinal) as 'Check-out Date', "
                      "(homestay.homestayPrice * "+daysDiff+") as 'Price' "
                      "FROM users, booking, homestay WHERE "
                      "users.userID = '"+userID+"' AND "
                      "booking.bookingID = '"+bookingID+"' AND "
                      "user.userID = booking.userID AND "
                      "booking.bookingID = homestay.bookingID");
    if (queryPtr->exec())  {
        model->setQuery(*queryPtr);
        QHeaderView *header = ui->tableView->horizontalHeader();
        header->hide();
        proxy_model->setSourceModel(model);
        ui->tableView->setModel(proxy_model);
    }
}

void PaymentSummary::on_buttonCancel_clicked()
{
    BookingView *vb = new BookingView;
    vb->show();
    this->close();
}

void PaymentSummary::on_buttonHome_clicked()
{
    MainMenuCust *mmc = new MainMenuCust;
    mmc->show();
    this->close();
}

void PaymentSummary::on_buttonApply_clicked()
{
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID();
    rewardID = ui->lineEditReward->text();
    QString bookingID = getBookingActivatedID();

    QString discountType, discountRate;
    int discountRateCalc = 0;

    QSqlQuery query;
    if (rewardID != "") {
        query.prepare("SELECT isUsed "
                      "FROM user_Reward WHERE "
                      "userID = '"+userID+"' AND "
                      "rewardID = '"+rewardID+"'");
        if (query.exec()) {
            query.next();
            QSqlRecord rec = query.record();
            if (rec.isNull("isUsed")) {
                PopupRewardApplyFailed *prf = new PopupRewardApplyFailed;
                prf->show();
            }
            else if (query.value(0).toString() == "Y") {
                PopupRewardUsed *pru = new PopupRewardUsed;
                pru->show();
            }
            else {
                query.prepare("SELECT discountType, discountRate FROM reward "
                              "WHERE rewardID = '"+rewardID+"'");
                if (query.exec()) {
                    query.next();
                    if (query.value(0).toString() == "%") {
                        discountType = "*";
                        discountRate = QString::number(100 - query.value(1).toInt())+"/100";
                        discountRateCalc = 100 - query.value(1).toInt();
                    }
                    else if (query.value(0).toString() == "$") {
                        discountType = "-";
                        discountRate = query.value(1).toString();
                        discountRateCalc = query.value(1).toInt();
                    }
                    isDiscounted = true;
                }
            }
        }
    }

    if (isDiscounted) {
        if (discountType == "*")
            totalPrice = QString::number(totalPrice.toInt() * discountRateCalc / 100);
        else if (discountType == "-")
            totalPrice = QString::number(totalPrice.toInt() - discountRateCalc);

        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *queryPtr = new QSqlQuery(conn.myDB);

        PaymentSummaryHorizontal* proxy_model = new PaymentSummaryHorizontal();

        queryPtr->prepare("SELECT booking.bookingID as 'Booking ID', "
                          "users.userID as 'Customer ID', "
                          "(users.userFirstName || ' ' || users.userLastName) as 'Name', "
                          "users.userEmail as 'E-mail',"
                          "homestay.homestayID as 'Homestay ID', "
                          "homestay.homestayName as 'Name', "
                          "homestay.homestayLoc as 'Location', "
                          "homestay.homestayType as 'Type', "
                          "homestay.homestayBedrmNum as 'Bedrooms', "
                          "homestay.homestayBathrmNum as 'Bathrooms', "
                          "homestay.carparkNum as 'Carparks', "
                          "homestay.wifi as 'Wi-Fi', "
                          "homestay.nonSmoking as 'Non-Smoking', "
                          "(booking.bookingDayInit || '/' || booking.bookingMthInit || '/' || booking.bookingYrInit) as 'Check-in Date', "
                          "(booking.bookingDayFinal || '/' || booking.bookingMthFinal || '/' || booking.bookingYrFinal) as 'Check-out Date', "
                          "(homestay.homestayPrice*"+daysDiff+discountType+discountRate+") as 'Price' "
                          "FROM user, booking, homestay WHERE "
                          "users.userID = '"+userID+"' AND "
                          "booking.bookingID = '"+bookingID+"' AND "
                          "users.userID = booking.userID AND "
                          "booking.bookingID = homestay.bookingID");
        if (queryPtr->exec())  {
            model->setQuery(*queryPtr);
            QHeaderView *header = ui->tableView->horizontalHeader();
            header->hide();
            proxy_model->setSourceModel(model);
            ui->tableView->setModel(proxy_model);
        }
        else {
            qDebug() << queryPtr->lastError();
        }

        PopupRewardApplied *ra = new PopupRewardApplied;
        ra->show();
    }
}

void PaymentSummary::on_lineEditReward_returnPressed()
{
    PaymentSummary::on_buttonApply_clicked();
}

QString getTotalPrice() {
    return totalPrice;
}

void PaymentSummary::on_buttonPay_clicked()
{
    PaymentGateway *pg = new PaymentGateway;
    pg->show();
    this->close();
}

bool getIsDiscounted() {
    return isDiscounted;
}

QString getRewardID() {
    return rewardID;
}
