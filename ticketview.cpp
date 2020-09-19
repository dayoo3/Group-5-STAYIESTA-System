#include "ticketview.h"
#include "ui_ticketview.h"
#include "mainmenutech.h"
#include "dblogin.h"

TicketView::TicketView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicketView)
{
    ui->setupUi(this);
    setFixedSize(530,320);
    refreshTable(ui);
}

TicketView::~TicketView()
{
    delete ui;
}

void refreshTable(Ui::TicketView* ui) {
    DBLogin conn;
    conn.connOpen();

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery *queryPtr = new QSqlQuery(conn.myDB);

    queryPtr->prepare("SELECT ticketID as 'ID', "
                      "ticketType as 'Type', "
                      "ticketTitle as 'Title', "
                      "ticketDesc as 'Description', "
                      "userID as 'Submitted by', "
                      "(ticketDay || '/' || ticketMth || '/' || ticketYr) as 'Submitted on' "
                      "FROM ticket");
    if (queryPtr->exec())  {
        model->setQuery(*queryPtr);
        ui->tableView->setModel(model);
        ui->tableView->setVisible(false);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setVisible(true);
    }

    conn.connClose();
}

void TicketView::on_buttonHome_clicked()
{
    MainMenuTech *mmt = new MainMenuTech;
    mmt->show();
    this->close();
}
