#include "popuprewardcreate.h"
#include "ui_popuprewardcreate.h"
#include "rewardcreate.h"

PopupRewardCreate::PopupRewardCreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupRewardCreate)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupRewardCreate::~PopupRewardCreate()
{
    delete ui;
}

void PopupRewardCreate::on_buttonOK_clicked()
{
    this->close();
    RewardCreate *r = new RewardCreate;
    r->show();
}
