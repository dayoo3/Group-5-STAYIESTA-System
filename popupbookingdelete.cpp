#include "popupbookingdelete.h"
#include "ui_popupbookingdelete.h"
#include "bookingview.h"

PopupBookingDelete::PopupBookingDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupBookingDelete)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupBookingDelete::~PopupBookingDelete()
{
    delete ui;
}

void PopupBookingDelete::on_buttonOK_clicked()
{
    BookingView *vb = new BookingView;
    vb->show();
    this->close();
}
