#include "popuprewardapplyfailed.h"
#include "ui_popuprewardapplyfailed.h"

PopupRewardApplyFailed::PopupRewardApplyFailed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupRewardApplyFailed)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/error.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupRewardApplyFailed::~PopupRewardApplyFailed()
{
    delete ui;
}

void PopupRewardApplyFailed::on_buttonOK_clicked()
{
    this->close();
}
