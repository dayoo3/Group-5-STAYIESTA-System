#include "popupticketcreate.h"
#include "ui_popupticketcreate.h"
#include "ticketcreate.h"

PopupTicketCreate::PopupTicketCreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopupTicketCreate)
{
    ui->setupUi(this);
    setFixedSize(380,150);
    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupTicketCreate::~PopupTicketCreate()
{
    delete ui;
}

void PopupTicketCreate::on_buttonOK_clicked()
{
    TicketCreate *tc = new TicketCreate;
    tc->show();
    this->close();
}
