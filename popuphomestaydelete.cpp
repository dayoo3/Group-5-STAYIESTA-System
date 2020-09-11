#include "popuphomestaydelete.h"
#include "ui_popuphomestaydelete.h"
#include "homestayview.h"

PopupHomestayDelete::PopupHomestayDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupHomestayDelete)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupHomestayDelete::~PopupHomestayDelete()
{
    delete ui;
}

void PopupHomestayDelete::on_buttonOK_clicked()
{
    HomestayView *vh = new HomestayView;
    vh->show();
    this->close();
}
