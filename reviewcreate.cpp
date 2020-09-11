#include "reviewcreate.h"
#include "ui_reviewcreate.h"
#include "popupreviewcreate.h"
#include "dblogin.h"
#include "ctime"
#include "bookingview.h"

ReviewCreate::ReviewCreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReviewCreate)
{
    ui->setupUi(this);
    setFixedSize(460,310);

    QString bookingID = getBookingActivatedID();

    time_t now = time(nullptr);
    tm *localTime = localtime(&now);
    QString day = QString::number(localTime->tm_mday);
    QString month = QString::number(1 + localTime->tm_mon);
    QString year = QString::number(1900 + localTime->tm_year);

    ui->lineBook->setText(bookingID);
    ui->lineDay->setText(day);
    ui->lineMonth->setText(month);
    ui->lineyear->setText(year);
}

ReviewCreate::~ReviewCreate()
{
    delete ui;
}

void ReviewCreate::on_buttonReset_clicked()
{
}

void ReviewCreate::on_buttonSubmit_clicked()
{
    QString bookingID = ui->lineBook->text();
    QString userID = "C32269";
    QString reviewID = IDCheck();
    QString day = ui->lineDay->text();
    QString month = ui->lineMonth->text();
    QString year = ui->lineyear->text();
    QString desc = ui->description->toPlainText();
    QString rate = QString::number(1 + (ui->rating->currentIndex()));

    DBLogin conn;
    conn.connOpen();
    QSqlQuery query;
    query.prepare("INSERT INTO Review VALUES"
                  "'"+reviewID+"','"+rate+"','"+desc+"','"+day+"','"+month+"','"+year+"','"+userID+"','"+bookingID+"',");

    if(query.exec()){
        query.next();
        query.exec("UPDATE Booking SET reviewStatus = 'Y' WHERE bookingID = '"+bookingID+"'");
        PopupReviewCreate *rpop = new PopupReviewCreate;
        rpop->show();
    }
    conn.connClose();
}

QString IDCheck() {
    QSqlQuery query;
    query.exec("SELECT reviewID FROM Review");

    bool IDChecking = true;
    QString tempID = "";
    srand(time(nullptr));
    while (IDChecking == true) {
        tempID = "T"+QString::number(rand() % 100000);
        while(query.next()) {
            if (tempID == query.value(0)){
                continue;
            }
            else {
                IDChecking = false;
                break;
            }
        }
    }
    return tempID;
}

void ReviewCreate::on_buttonHome_clicked()
{
    BookingView *vb = new BookingView;
    vb->show();
    this->close();
}
