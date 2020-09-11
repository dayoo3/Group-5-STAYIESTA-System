#include "homestayview.h"
#include "ui_homestayview.h"
#include "mainmenuhost.h"
#include "homestayadd.h"
#include "homestaydelete.h"
#include "homestayupdate.h"
#include "dblogin.h"

HomestayView::HomestayView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomestayView)
{
    ui->setupUi(this);
    setFixedSize(620,330);

    refreshTable(ui);
}

HomestayView::~HomestayView()
{
    delete ui;
}
void HomestayView::on_buttonAdd_clicked()
{
    HomestayAdd *ah = new HomestayAdd;
    ah->show();
    this->close();
}

void HomestayView::on_buttonUpdate_clicked()
{
    if (!(templateID == "")) {
        HomestayUpdate *uh = new HomestayUpdate;
        uh->show();
        this->close();
    }
}

void HomestayView::on_buttonDelete_clicked()
{
    if (!(templateID == "")) {
        HomestayDelete *dh = new HomestayDelete;
        dh->show();
        this->close();
    }
}

void HomestayView::on_buttonHome_clicked()
{
    MainMenuHost *mmh = new MainMenuHost;
    mmh->show();
    this->close();
}

void refreshTable(Ui::HomestayView *ui) {
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID();

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery *queryPtr = new QSqlQuery(conn.myDB);

    queryPtr->prepare("SELECT Homestay.homestayID as 'ID', "
                      "Homestay.homestayName as 'Name', "
                      "Homestay.homestayLoc as 'Location', "
                      "Homestay.homestayType as 'Type', "
                      "Homestay.homestayBedrmNum as 'Bedrooms', "
                      "Homestay.homestayBathrmNum as 'Bathrooms', "
                      "Homestay.homestayPrice as 'Price', "
                      "Homestay.carparkNum as 'Carpark(s)', "
                      "Homestay.nonSmoking as 'Non-Smoking', "
                      "Homestay.wifi as 'Wi-Fi'"
                      "FROM Homestay, User WHERE "
                      "Homestay.userID = '"+userID+"' AND "
                      "User.userID = Homestay.userID;");
    if (queryPtr->exec())  {
        model->setQuery(*queryPtr);
        ui->tableView->setModel(model);
        ui->tableView->setVisible(false);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setVisible(true);
    }

    conn.connClose();
}

QString getHomestayActivatedID() {
    return templateID;
}

void HomestayView::on_tableView_activated(const QModelIndex &index)
{
    templateID = ui->tableView->model()->data(index).toString();
}
