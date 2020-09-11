#include "popupregisterpanel.h"
#include "ui_popupregisterpanel.h"
#include "loginpanel.h"

PopupRegisterPanel::PopupRegisterPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopupRegisterPanel)
{
    ui->setupUi(this);
    setFixedSize(380,150);

    ui->aLabel->setText("Registration Successful!");
    ui->aLabel->setAlignment(Qt::AlignCenter);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/tick.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

PopupRegisterPanel::~PopupRegisterPanel()
{
    delete ui;
}

void PopupRegisterPanel::on_buttonOK_clicked()
{
    this->hide();
}
