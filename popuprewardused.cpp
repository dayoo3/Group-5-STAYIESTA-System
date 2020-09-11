#include "popuprewardused.h"
#include "ui_popuprewardused.h"

PopupRewardUsed::PopupRewardUsed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupRewardUsed)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/error.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupRewardUsed::~PopupRewardUsed()
{
    delete ui;
}

void PopupRewardUsed::on_buttonOK_clicked()
{
    this->close();
}

