#include "popupprofileupdate.h"
#include "ui_popupprofileupdate.h"

PopupProfileUpdate::PopupProfileUpdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupProfileUpdate)
{
    ui->setupUi(this);
    setFixedSize(380,150);
    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupProfileUpdate::~PopupProfileUpdate()
{
    delete ui;
}

void PopupProfileUpdate::on_buttonOK_clicked()
{
    this->close();
}
