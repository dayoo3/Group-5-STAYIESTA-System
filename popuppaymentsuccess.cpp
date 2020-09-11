#include "popuppaymentsuccess.h"
#include "ui_popuppaymentsuccess.h"
#include "bookingview.h"

PopupPaymentSuccess::PopupPaymentSuccess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupPaymentSuccess)
{
    ui->setupUi(this);

    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupPaymentSuccess::~PopupPaymentSuccess()
{
    delete ui;
}

void PopupPaymentSuccess::on_buttonOK_clicked()
{
    BookingView *vb = new BookingView;
    vb->show();
    this->close();
}
