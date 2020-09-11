#include "bookingdelete.h"
#include "ui_bookingdelete.h"
#include "popupbookingdelete.h"
#include "bookingview.h"
#include "dblogin.h"

BookingDelete::BookingDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookingDelete)
{
    ui->setupUi(this);
    setFixedSize(410,210);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/trash.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

BookingDelete::~BookingDelete()
{
    delete ui;
}

void BookingDelete::on_buttonCancel_clicked()
{
    BookingView *vb = new BookingView;
    vb->show();
    this->close();
}

void BookingDelete::on_buttonConfirm_clicked()
{
    DBLogin conn;
    conn.connOpen();

    QString bookingID = getBookingActivatedID();
    QString userID = getCurrUserID();
    QString userPass = ui->lineEditPass->text();

    bool isDelete = false;

    QSqlQuery query;
    query.prepare("SELECT userPassword FROM User WHERE userID = '"+userID+"'");
    if (query.exec()) {
        query.next();
        if (userPass == query.value(0).toString()) {
            isDelete = true;
        }
    }
    else {
        qDebug() << query.lastError();
    }

    if (isDelete) {
        query.prepare("DELETE FROM Booking WHERE bookingID = '"+bookingID+"'");
        if (query.exec()) {
            PopupBookingDelete *pbd = new PopupBookingDelete;
            pbd->show();
            this->close();
        }
        else {
            qDebug() << query.lastError();
        }
    }
    conn.connClose();
}

void BookingDelete::on_lineEditPass_returnPressed()
{
    BookingDelete::on_buttonConfirm_clicked();
}
