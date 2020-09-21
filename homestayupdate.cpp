#include "homestayupdate.h"
#include "ui_homestayupdate.h"
#include "popuphomestayupdate.h"
#include "dblogin.h"
#include "homestayview.h"
#include "mainmenuhost.h"

HomestayUpdate::HomestayUpdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomestayUpdate)
{
    ui->setupUi(this);
    setFixedSize(580,380);

    getFormData(ui);
}

HomestayUpdate::~HomestayUpdate()
{
    delete ui;
}

void HomestayUpdate::on_buttonConfirm_clicked()
{
    DBLogin conn;
    conn.connOpen();

    QString ID = getHomestayActivatedID();
    QString homestayBedrmNum = ui->lineEditBed->text(),
            homestayBathrmNum = ui->lineEditBath->text(),
            homestayPrice = ui->lineEditPrice->text(),
            carparkNum = ui->lineEditCar->text(),
            wifi,
            nonSmoking;

    if (ui->checkBoxWifi->isChecked())
        wifi = "Y";
    else
        wifi = "N";

    if (ui->checkBoxSmoke->isChecked())
        nonSmoking = "Y";
    else
        nonSmoking = "N";

    QSqlQuery query;
    query.prepare("UPDATE homestay SET "
                  "homestayBedrmNum = '"+homestayBedrmNum+"', "
                  "homestayBathrmNum = '"+homestayBathrmNum+"', "
                  "homestayPrice = '"+homestayPrice+"', "
                  "carparkNum = '"+carparkNum+"', "
                  "wifi = '"+wifi+"', "
                  "nonSmoking = '"+nonSmoking+"' "
                  "WHERE homestayID = '"+ID+"' OR homestayName = '"+ID+"'");
    if (query.exec()) {
        PopupHomestayUpdate *hPopup = new PopupHomestayUpdate;
        hPopup->show();
        this->close();
    }
}

void HomestayUpdate::on_buttonCancel_clicked()
{
    HomestayView *vh = new HomestayView;
    vh->show();
    this->close();
}

void HomestayUpdate::on_buttonHome_clicked()
{
    MainMenuHost *mmh = new MainMenuHost;
    mmh->show();
    this->close();
}

void getFormData(Ui::HomestayUpdate* ui) {
    DBLogin conn;
    conn.connOpen();

    QString ID = getHomestayActivatedID();
    int index = 0;

    QSqlQuery query;
    query.prepare("SELECT * FROM homestay WHERE homestayID = '"+ID+"' OR homestayName = '"+ID+"'");
    if (query.exec()) {
        query.next();
        if (query.value(3).toString() == "Apartment")
            index = 0;
        if (query.value(3).toString() == "Condominium")
            index = 1;
        if (query.value(3).toString() == "Villa")
            index = 2;
        if (query.value(3).toString() == "Bungalow")
            index = 3;
        if (query.value(3).toString() == "Terrace")
            index = 4;

        ui->lineEditID->setText(query.value(0).toString());
        ui->lineEditName->setText(query.value(1).toString());
        ui->lineEditLoc->setText(query.value(2).toString());
        ui->comboBoxType->setCurrentIndex(index);
        ui->lineEditBed->setText(query.value(4).toString());
        ui->lineEditBath->setText(query.value(5).toString());
        ui->lineEditPrice->setText(query.value(6).toString());
        ui->lineEditCar->setText(query.value(7).toString());

        if (query.value(8).toString() == 'Y')
            ui->checkBoxWifi->setChecked(true);
        if (query.value(9).toString() == 'Y')
            ui->checkBoxSmoke->setChecked(true);
    }

    ui->comboBoxType->setEnabled(false);
}
