#include "popupbookingdateinvalid.h"
#include "ui_popupbookingdateinvalid.h"

popupBookingDateInvalid::popupBookingDateInvalid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::popupBookingDateInvalid)
{   
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/error.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

popupBookingDateInvalid::~popupBookingDateInvalid()
{
    delete ui;
}

void popupBookingDateInvalid::on_buttonOK_clicked()
{
    this->close();
}
