#include "popuprewardapplied.h"
#include "ui_popuprewardapplied.h"

PopupRewardApplied::PopupRewardApplied(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupRewardApplied)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupRewardApplied::~PopupRewardApplied()
{
    delete ui;
}

void PopupRewardApplied::on_buttonOK_clicked()
{
    this->close();
}
