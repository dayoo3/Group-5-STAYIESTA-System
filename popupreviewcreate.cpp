#include "popupreviewcreate.h"
#include "ui_popupreviewcreate.h"
#include "reviewcreate.h"

PopupReviewCreate::PopupReviewCreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupReviewCreate)
{
    ui->setupUi(this);
    setFixedSize(380,150);
    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupReviewCreate::~PopupReviewCreate()
{
    delete ui;
}

void PopupReviewCreate::on_buttonOK_clicked()
{
    ReviewCreate *rc = new ReviewCreate;
    rc->show();
    this->close();
}
