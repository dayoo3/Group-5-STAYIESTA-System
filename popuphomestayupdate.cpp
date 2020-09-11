#include "popuphomestayupdate.h"
#include "ui_popuphomestayupdate.h"
#include "homestayview.h"

PopupHomestayUpdate::PopupHomestayUpdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupHomestayUpdate)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupHomestayUpdate::~PopupHomestayUpdate()
{
    delete ui;
}

void PopupHomestayUpdate::on_buttonOK_clicked()
{
    HomestayView *vh = new HomestayView;
    vh->show();
    this->close();
}
