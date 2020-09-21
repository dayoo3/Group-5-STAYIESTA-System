#include "popuphomestayunavailable.h"
#include "ui_popuphomestayunavailable.h"
#include "searchresult.h"
#include "dblogin.h"

PopupHomestayUnavailable::PopupHomestayUnavailable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupHomestayUnavailable)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/error.png");
    ui->picLbl->setPixmap(pixmapTarget);

    DBLogin conn;
    conn.connOpen();

    QString BID = getSearchBID();
    QString day ="", mth ="", yr="";

    QSqlQuery query;

    query.prepare("SELECT bookingDayFinal, bookingMthFinal, bookingYrFinal FROM booking WHERE bookingID = '"+BID+"'");
    if (query.exec()) {
        query.next();
        day = query.value(0).toString();
        mth  = query.value(1).toString();
        yr = query.value(2).toString();
    }

    ui->label->setText("Homestay is already booked until " + day + "/" + mth + "/" + yr + ". Please choose another homestay.");
}

PopupHomestayUnavailable::~PopupHomestayUnavailable()
{
    delete ui;
}

void PopupHomestayUnavailable::on_buttonOK_clicked()
{
    this->close();
}
