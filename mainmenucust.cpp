#include "mainmenucust.h"
#include "ui_mainmenucust.h"
#include "registerpanel.h"
#include "loginpanel.h"
#include "bookingview.h"
#include "profileview.h"
#include "ticketcreate.h"
#include "dblogin.h"
#include "searchresult.h"

static QString searchLocation;

MainMenuCust::MainMenuCust(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuCust)
{
    ui->setupUi(this);
    setWindowTitle("STAYIESTA");
    setFixedSize(380,320);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/logo.png");

    ui->picLbl->setPixmap(pixmapTarget );

    DBLogin conn;
    conn.connOpen();

    QString username = getCurrUsername();
    ui->loginAsLabel->setText("Logged in as "+username+",");
    ui->lineEditSearch->setPlaceholderText("Search");
}

MainMenuCust::~MainMenuCust()
{
    delete ui;
}

void MainMenuCust::on_buttonLogout_clicked()
{
    LoginPanel *lForm = new LoginPanel;
    lForm->show();
    this->close();
}

void MainMenuCust::on_buttonAccount_clicked()
{
    ProfileView *pp = new ProfileView;
    pp->show();
    this->close();
}

void MainMenuCust::on_buttonBookings_clicked()
{
    BookingView *vb = new BookingView;
    vb->show();
    this->close();
}

void MainMenuCust::on_buttonTicket_clicked()
{
    TicketCreate *tc = new TicketCreate;
    tc->show();
    this->close();
}

QString getSearchLocation() {
    return searchLocation;
}

void MainMenuCust::on_lineEditSearch_returnPressed()
{
    searchLocation = ui->lineEditSearch->text();

    DBLogin conn;
    conn.connOpen();

    QSqlQuery query;
    query.prepare("SELECT homestayLoc FROM homestay WHERE homestayLoc LIKE '%"+searchLocation+"%'");
    if (query.exec()) {
        query.next();
        searchLocation = query.value(0).toString();

        SearchResult *sr = new SearchResult;
        sr->show();
        this->close();
    }
    conn.connClose();
}
