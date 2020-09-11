#include "popupbookingcreate.h"
#include "ui_popupbookingcreate.h"
#include "bookingview.h"

PopupBookingCreate::PopupBookingCreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupBookingCreate)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupBookingCreate::~PopupBookingCreate()
{
    delete ui;
}

void PopupBookingCreate::on_buttonOK_clicked()
{
    BookingView *vb = new BookingView;
    vb->show();
    this->close();
}
