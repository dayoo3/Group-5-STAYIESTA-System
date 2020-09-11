#include "homestaydetail.h"
#include "ui_homestaydetail.h"
#include "homestaydetailhorizontal.h"
#include "popuphomestayunavailable.h"
#include "dblogin.h"
#include "mainmenucust.h"
#include "searchresult.h"
#include "bookingcreate.h"

HomestayDetail::HomestayDetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomestayDetail)
{
    ui->setupUi(this);
    i = 0;
    reviewVect.clear();

    refreshTable(ui);
    getFormData();
    setFormData(ui);
}

HomestayDetail::~HomestayDetail()
{
    delete ui;
}

void HomestayDetail::on_buttonBook_clicked()
{
    DBLogin conn;
    conn.connOpen();

    QSqlQuery query;
    query.prepare("SELECT bookingID FROM Homestay WHERE homestayID = '"+getSearchActivatedID()+"'");
    if (query.exec()) {
        query.next();
        QSqlRecord rec = query.record();
        if (rec.isNull("bookingID")) {
            BookingCreate *bc = new BookingCreate;
            bc->show();
            this->close();
        }
        else {
            PopupHomestayUnavailable *phu = new PopupHomestayUnavailable;
            phu->show();
            this->close();
        }
    }

    conn.connClose();
}

void HomestayDetail::on_buttonReturn_clicked()
{
    SearchResult *sr = new SearchResult;
    sr->show();
    this->close();
}

void HomestayDetail::on_buttonHome_clicked()
{
    MainMenuCust *mmc = new MainMenuCust;
    mmc->show();
    this->close();
}

void HomestayDetail::on_buttonNextRev_clicked()
{
    i++;
    setFormData(ui);
}

void HomestayDetail::on_buttonPrevRev_clicked()
{
    i--;
    setFormData(ui);
}

void refreshTable(Ui::HomestayDetail* ui) {
    DBLogin conn;
    conn.connOpen();

    QString homestayID = getSearchActivatedID();

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *queryPtr = new QSqlQuery(conn.myDB);

    HomestayDetailHorizontal *proxy_model = new HomestayDetailHorizontal();

    queryPtr->prepare("SELECT homestayID as 'Homestay ID', "
                      "homestayName as 'Name', "
                      "homestayLoc as 'Location', "
                      "homestayType as 'Type', "
                      "homestayBedrmNum as 'Bedrooms', "
                      "homestayBathrmNum as 'Bathrooms', "
                      "carparkNum as 'Carpark(s)', "
                      "wifi as 'Wi-Fi', "
                      "nonSmoking as 'Non-Smoking', "
                      "homestayPrice as 'Price' "
                      "FROM Homestay "
                      "WHERE homestayID = '"+homestayID+"'");
    if (queryPtr->exec())  {
        model->setQuery(*queryPtr);
        QHeaderView *header = ui->tableView->horizontalHeader();
        header->hide();
        proxy_model->setSourceModel(model);
        ui->tableView->setModel(proxy_model);
    }
}

void getFormData() {
    DBLogin conn;
    conn.connOpen();

    QString homestayID = getSearchActivatedID();

    QSqlQuery query;

    query.prepare("SELECT reviewID FROM Review "
                  "WHERE homestayID = '"+homestayID+"'");
    if (query.exec()) {
        while (query.next())
            reviewVect.push_back(query.value(0).toString());
    }
    conn.connClose();
}

void setFormData(Ui::HomestayDetail* ui) {
    DBLogin conn;
    conn.connOpen();

    QSqlQuery query;

    if (!reviewVect.isEmpty()) {
        query.prepare("SELECT reviewRate, reviewDesc FROM Review "
                      "WHERE reviewID = '"+reviewVect[i]+"'");
        if (query.exec()) {
            query.next();
            ui->lineEditRate->setText(query.value(0).toString());
            ui->textEditReview->setText(query.value(1).toString());
        }
    }

    if (i == 0)
            ui->buttonPrevRev->setEnabled(false);
    else
        ui->buttonPrevRev->setEnabled(true);
    if (i == reviewVect.size() - 1 || reviewVect.size() == 0)
        ui->buttonNextRev->setEnabled(false);
    else
        ui->buttonNextRev->setEnabled(true);

        conn.connClose();
    }

