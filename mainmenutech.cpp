#include "mainmenutech.h"
#include "ui_mainmenutech.h"
#include "registerpanel.h"
#include "loginpanel.h"
#include "dblogin.h"
#include "ticketview.h"
#include "rewardcreate.h"
#include "userview.h"

MainMenuTech::MainMenuTech(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuTech)
{
    ui->setupUi(this);
    setWindowTitle("STAYIESTA");
    setFixedSize(380,290);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/logo.png");

    ui->picLbl->setPixmap(pixmapTarget );

    DBLogin conn;
    conn.connOpen();

    QString username = getCurrUserID();
    ui->loginAsLabel->setText("Logged in as "+username+",");
    ui->aLabel->setAlignment(Qt::AlignCenter);
}

MainMenuTech::~MainMenuTech()
{
    delete ui;
}

void MainMenuTech::on_buttonLogout_clicked()
{
    LoginPanel *lForm = new LoginPanel;
    lForm->show();
    this->hide();
}

void MainMenuTech::on_buttonAccount_clicked()
{
    UserView *uv = new UserView;
    uv->show();
    this->hide();
}

void MainMenuTech::on_buttonTicket_clicked()
{
    TicketView *tv = new TicketView;
    tv->show();
    this->hide();
}

void MainMenuTech::on_buttonReward_clicked()
{
    RewardCreate *rc = new RewardCreate;
    rc->show();
    this->hide();
}
