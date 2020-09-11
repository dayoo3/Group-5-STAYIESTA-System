#include "popuphomestayadd.h"
#include "ui_popuphomestayadd.h"
#include "homestayview.h"

PopupHomestayAdd::PopupHomestayAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupHomestayAdd)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupHomestayAdd::~PopupHomestayAdd()
{
    delete ui;
}

void PopupHomestayAdd::on_buttonOK_clicked()
{
    HomestayView *vh = new HomestayView;
    vh->show();
    this->close();
}
