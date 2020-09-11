#include "paymentauthorization.h"
#include "ui_paymentauthorization.h"
#include "paymentgateway.h"
#include "paymentsummary.h"
#include "bookingview.h"
#include "popuppaymentsuccess.h"
#include "dblogin.h"
#include "ctime"


PaymentAuthorization::PaymentAuthorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaymentAuthorization)
{
    ui->setupUi(this);
    setFixedSize(410,160);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/verify.png");
    ui->picLbl->setPixmap(pixmapTarget);

    srand(time(nullptr));
    ui->labelCaptcha->setText(randomCaptcha(5));
}

PaymentAuthorization::~PaymentAuthorization()
{
    delete ui;
}

void PaymentAuthorization::on_buttonCancel_clicked() // Cancel
{
    PaymentGateway *pg = new PaymentGateway;
    pg->show();
    this->close();
}

void PaymentAuthorization::on_buttonSubmit_clicked()
{
    DBLogin conn;
    conn.connOpen();

    bool isUpdated = false;
    QSqlQuery query;

    bool isDiscounted = getIsDiscounted();
    QString userID = getCurrUserID(),
            bookingID = getBookingActivatedID(),
            rewardID = getRewardID(),
            cardHolderName = getCardHolderName(),
            cardNumber = getCardNum(),
            totalPrice = getTotalPrice();

    if (ui->lineEditAutho->text() == ui->labelCaptcha->text()) {
        time_t now = time(0);
        tm *lTime = localtime(&now);
        QString day = QString::number(lTime->tm_mday);
        QString month = QString::number(1 + lTime->tm_mon);
        QString year = QString::number(1900 + lTime->tm_year);

        if (isDiscounted) {
            query.prepare("UPDATE User_Reward SET isUsed = 'Y' "
                          "WHERE User_Reward.userID = '"+userID+"' AND "
                          "User_Reward.rewardID = '"+rewardID+"'");
            query.exec();

            query.prepare("INSERT INTO Payment VALUES"
                          "('"+IDCheckPayment()+"','"+totalPrice+"','"+day+"','"+month+"','"+year+"','"+cardHolderName+"','"+cardNumber+"','"+userID+"','"+bookingID+"','"+rewardID+"')");
            if (query.exec())
                isUpdated = true;
        }
        else {
            query.prepare("INSERT INTO Payment VALUES(paymentID, paymentAmount, paymentDay, paymentMth, paymentYr, cardName, cardNum, userID, bookingID)"
                          "('"+IDCheckPayment()+"','"+totalPrice+"','"+day+"','"+month+"','"+year+"','"+cardHolderName+"','"+cardNumber+"','"+userID+"','"+bookingID+"')");
            if (!query.exec())
                qDebug() << query.lastError();
            else
                isUpdated = true;
        }
    }

    if (isUpdated) {
        query.prepare("UPDATE Booking SET paymentStatus = 'Y' "
                      "WHERE bookingID = '"+bookingID+"'");
        if (query.exec()) {
            PopupPaymentSuccess *psp = new PopupPaymentSuccess;
            psp->show();
            this->close();
        }
    }

    conn.connClose();
}

void PaymentAuthorization::on_lineEditCaptcha_returnPressed()
{
    PaymentAuthorization::on_buttonSubmit_clicked();
}

QString randomCaptcha(size_t length)
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    QString str(length, 0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

QString IDCheckPayment() {
    QSqlQuery query;
    query.exec("SELECT paymentID FROM Payment");

    bool IDChecking = true;
    QString tempID = "";

    srand(time(nullptr));
    while (IDChecking == true) {
        tempID = "P"+QString::number(rand() % 100000);
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
