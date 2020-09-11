#include "popuphomestayunavailable.h"
#include "ui_popuphomestayunavailable.h"
#include "searchresult.h"

PopupHomestayUnavailable::PopupHomestayUnavailable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupHomestayUnavailable)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/error.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupHomestayUnavailable::~PopupHomestayUnavailable()
{
    delete ui;
}

void PopupHomestayUnavailable::on_buttonOK_clicked()
{
    SearchResult *sr = new SearchResult;
    sr->show();
    this->close();
}
