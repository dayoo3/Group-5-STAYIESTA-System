#include "mainmenuhost.h"
#include "ui_mainmenuhost.h"
#include "registerpanel.h"
#include "loginpanel.h"
#include "dblogin.h"
#include "profileview.h"
#include "homestayview.h"
#include "ticketcreate.h"

MainMenuHost::MainMenuHost(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuHost)
{
    ui->setupUi(this);
    setWindowTitle("STAYIESTA");
    setFixedSize(380,280);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/logo.png");

    ui->picLbl->setPixmap(pixmapTarget );

    DBLogin conn;
    conn.connOpen();

    QString username = getCurrUsername();
    ui->loginAsLabel->setText("Logged in as "+username+",");
}

MainMenuHost::~MainMenuHost()
{
    delete ui;
}

void MainMenuHost::on_buttonLogout_clicked()
{
    LoginPanel *lForm = new LoginPanel;
    lForm->show();
    this->close();
}

void MainMenuHost::on_buttonAccount_clicked()
{
    ProfileView *ph = new ProfileView;
    ph->show();
    this->close();
}

void MainMenuHost::on_buttonHomestays_clicked()
{
    HomestayView *vh = new HomestayView;
    vh->show();
    this->close();
}

void MainMenuHost::on_buttonMaint_clicked()
{
    TicketCreate *tc = new TicketCreate;
    tc->show();
    this->close();
}
