#include "userview.h"
#include "ui_userview.h"
#include "mainmenutech.h"
#include "dblogin.h"

UserView::UserView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserView)
{
    ui->setupUi(this);
    setFixedSize(530,310);

    refreshTable(ui);
}

UserView::~UserView()
{
    delete ui;
}

void UserView::on_buttonHome_clicked()
{
    MainMenuTech *mmt = new MainMenuTech;
    mmt->show();
    this->close();
}

void refreshTable(Ui::UserView* ui) {
    DBLogin conn;
    conn.connOpen();

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery *queryPtr = new QSqlQuery(conn.myDB);

    queryPtr->prepare("SELECT userID as 'ID', "
                      "(userFirstName || ' ' || userLastName) as 'Name', "
                      "username as 'Username', "
                      "userEmail as 'E-Mail', "
                      "userPhoneNum as 'Phone Number' "
                      "FROM User");
    if (queryPtr->exec())  {
        model->setQuery(*queryPtr);
        ui->tableView->setModel(model);
        ui->tableView->setVisible(false);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setVisible(true);
    }

    conn.connClose();
}
