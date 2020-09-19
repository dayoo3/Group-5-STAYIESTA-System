#include "searchresult.h"
#include "ui_searchresult.h"
#include "mainmenucust.h"
#include "bookingcreate.h"
#include "homestaydetail.h"
#include "dblogin.h"
#include "QDebug"
#include "popuphomestayunavailable.h"

static QString ID;
static QString BID;

SearchResult::SearchResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchResult)
{
    ui->setupUi(this);
    setFixedSize(860,370);

    ui->buttonBook->setEnabled(false);
    SearchResult::on_buttonFilter_clicked();
}

SearchResult::~SearchResult()
{
    delete ui;
}

void SearchResult::on_buttonBook_clicked()
{
    DBLogin conn;
    conn.connOpen();

    QSqlQuery query;
    query.prepare("SELECT bookingID FROM homestay WHERE homestayID = '"+ID+"'");
    if (query.exec()) {
        query.next();
        QSqlRecord rec = query.record();
        if (rec.isNull("bookingID")) {
            BookingCreate *bc = new BookingCreate;
            bc->show();
            this->close();
        }
        else {
            BID = query.value(0).toString();
            PopupHomestayUnavailable *phu = new PopupHomestayUnavailable;
            phu->show();
            this->close();
        }
    }

    conn.connClose();
}

void SearchResult::on_buttonCancel_clicked()
{
    MainMenuCust *mmc = new MainMenuCust;
    mmc->show();
    this->close();
}

void SearchResult::on_buttonHome_clicked()
{
    MainMenuCust *mmc = new MainMenuCust;
    mmc->show();
    this->close();
}

void SearchResult::on_tableView_activated(const QModelIndex &index)
{
    ID = ui->tableView->model()->data(index).toString();
    ui->buttonBook->setEnabled(true);
}

void SearchResult::on_buttonFilter_clicked()
{
    DBLogin conn;
    conn.connOpen();

    QString searchLocation = getSearchLocation();
    QString homestayBedrmNum, homestayBathrmNum, carparkNum, wifi, nonSmoking;
    bool bedNumBool = false, bathNumBool = false, carkNumBool = false, wifiBool = false, nonSmokingBool = false;

    if (ui->comboBoxBed->currentText() != "Select") {
        homestayBedrmNum = ui->comboBoxBed->currentText();
        bedNumBool = true;
    }
    if (ui->comboBoxBath->currentText() != "Select") {
        homestayBathrmNum = ui->comboBoxBath->currentText();
        bathNumBool = true;
    }
    if (ui->comboBoxCar->currentText() != "Select") {
        carparkNum = ui->comboBoxCar->currentText();
        carkNumBool = true;
    }
    if (ui->comboBoxWifi->currentText() != "Select") {
        wifi = ui->comboBoxWifi->currentText();
        wifiBool = true;
    }
    if (ui->comboBoxSmoke->currentText() != "Select") {
        nonSmoking = ui->comboBoxSmoke->currentText();
        nonSmokingBool = true;
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery *queryPtr = new QSqlQuery(conn.myDB);

    if (bedNumBool) {
        if (bathNumBool) {
            if (carkNumBool) {
                if (wifiBool) {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "wifi = '"+wifi+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "wifi = '"+wifi+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
                else {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
            }
            else {
                if (wifiBool) {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "wifi = '"+wifi+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "wifi = '"+wifi+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
                else {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
            }
        }
        else {
            if (carkNumBool) {
                if (wifiBool) {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "wifi = '"+wifi+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "wifi = '"+wifi+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
                else {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
            }
            else {
                if (wifiBool) {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "wifi = '"+wifi+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "wifi = '"+wifi+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
                else {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBedrmNum = '"+homestayBedrmNum+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
            }
        }
    }
    else {
        if (bathNumBool) {
            if (carkNumBool) {
                if (wifiBool) {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "wifi = '"+wifi+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "wifi = '"+wifi+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
                else {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "carparkNum = '"+carparkNum+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
            }
            else {
                if (wifiBool) {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "wifi = '"+wifi+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "wifi = '"+wifi+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
                else {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "homestayBathrmNum = '"+homestayBathrmNum+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
            }
        }
        else {
            if (carkNumBool) {
                if (wifiBool) {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "wifi = '"+wifi+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "wifi = '"+wifi+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
                else {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "carparkNum = '"+carparkNum+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "carparkNum = '"+carparkNum+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
            }
            else {
                if (wifiBool) {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "wifi = '"+wifi+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "wifi = '"+wifi+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
                else {
                    if (nonSmokingBool) {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"' AND "
                                          "nonSmoking = '"+nonSmoking+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                    else {
                        queryPtr->prepare("SELECT homestayID as 'ID', "
                                          "homestayName as 'Name', "
                                          "homestayLoc as 'Location', "
                                          "homestayType as 'Type', "
                                          "homestayBedrmNum as 'Bedrooms', "
                                          "homestayBathrmNum as 'Bathrooms', "
                                          "homestayPrice as 'Price', "
                                          "carparkNum as 'Carpark(s)', "
                                          "wifi as 'Wi-Fi', "
                                          "nonSmoking as 'Non-Smoking' "
                                          "FROM homestay WHERE "
                                          "homestayLoc = '"+searchLocation+"'");
                        if (queryPtr->exec())  {
                            model->setQuery(*queryPtr);
                            ui->tableView->setModel(model);
                            ui->tableView->setVisible(false);
                            ui->tableView->resizeColumnsToContents();
                            ui->tableView->setVisible(true);
                        }
                    }
                }
            }
        }
    }
    conn.connClose();
}

QString getSearchActivatedID() {
    return ID;
}

QString getSearchBID() {
    return BID;
}

void SearchResult::on_buttonReset_clicked()
{
    ui->comboBoxBed->setCurrentIndex(0);
    ui->comboBoxBath->setCurrentIndex(0);
    ui->comboBoxCar->setCurrentIndex(0);
    ui->comboBoxWifi->setCurrentIndex(0);
    ui->comboBoxSmoke->setCurrentIndex(0);

    SearchResult::on_buttonFilter_clicked();
}

void SearchResult::on_buttonDetail_clicked()
{
    HomestayDetail *hd = new HomestayDetail;
    hd->show();
    this->close();
}
