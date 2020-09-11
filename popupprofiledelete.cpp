#include "popupprofiledelete.h"
#include "ui_popupprofiledelete.h"
#include "loginpanel.h"

PopupProfileDelete::PopupProfileDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupProfileDelete)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupProfileDelete::~PopupProfileDelete()
{
    delete ui;
}

void PopupProfileDelete::on_buttonOK_clicked()
{
    LoginPanel *lp = new LoginPanel;
    lp->show();
    this->close();
}
