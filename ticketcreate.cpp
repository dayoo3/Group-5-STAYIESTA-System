#include "ticketcreate.h"
#include "ticketpopup.h"
#include "dblogin.h"
#include "ui_ticketcreate.h"
#include "ctime"
#include "cstdlib"
#include "mainmenuhost.h"
#include "mainmenucust.h"

TicketCreate::TicketCreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicketCreate)
{
    ui->setupUi(this);
    setFixedSize(460,310);

    QString ticketID = "";
    QString accType;
    QString userID = getCurrUserID();

    DBLogin conn;
    conn.connOpen();

    QSqlQuery query;
    query.prepare("SELECT accType FROM User WHERE userID = '"+userID+"'");
    if (query.exec()) {
        query.next();
        accType = query.value(0).toString();
    }

    ticketID = IDCreate();
    if (accType == "1")
    {
        ui->lineType->setText("Host");
    }
    else if(accType == "2")
    {
        ui->lineType->setText("Customer");
    }
    ui->lineID->setText(ticketID);

    conn.connClose();
}

TicketCreate::~TicketCreate()
{
    delete ui;
}

void TicketCreate::on_buttonReset_clicked()
{

}

void TicketCreate::on_buttonSubmit_clicked()
{
    DBLogin conn;
    conn.connOpen();

    time_t now = time(nullptr);
    tm *localTime = localtime(&now);
    QString day = QString::number(localTime->tm_mday);
    QString month = QString::number(1 + localTime->tm_mon);
    QString year = QString::number(1900 + localTime->tm_year);

    QString ticketID = ui->lineID->text();
    QString userID = getCurrUserID();
    QString description = ui->textEdit->toPlainText();
    QString ticketType = ui->ticketType->currentText();
    QString userType = ui->lineType->text();
    QString title = ui->lineTitle->text();

    QSqlQuery query;
    query.prepare("INSERT INTO Ticket "
                  "VALUES('"+ticketID+"','"+title+"','"+description+"','"+day+"','"+month+"','"+year+"','"+ticketType+"','"+userID+"')" );

    if(query.exec()){
        query.next();
        PopupTicketCreate *tpop = new PopupTicketCreate;
        tpop->show();
        this->close();
    }
    else
        qDebug() << query.lastError();

    conn.connClose();
}

QString IDCreate() {
    QSqlQuery query;
    query.exec("SELECT ticketID FROM Ticket");

    bool IDChecking = true;
    QString tempID = "";
    srand(time(nullptr));
    while (IDChecking == true) {
        tempID = "T"+QString::number(rand() % 100000);
        qDebug() << tempID;

        while(query.next()) {
            if (tempID == query.value(0).toString()) {
                tempID = "T"+QString::number(rand() % 100000);
                continue;
            }
            else {
                IDChecking = false;
                break;
            }
        }
    }
    return tempID;
}

void TicketCreate::on_buttonHome_clicked()
{
    QString accType;
    QString userID = getCurrUserID();
    DBLogin conn;
    conn.connOpen();


    QSqlQuery query;
    query.prepare("SELECT acctype FROM User WHERE userID = '"+userID+"'");
    if(query.exec()){
        query.next();
        accType = query.value(0).toString();
    }

    if (accType == "1"){
    MainMenuHost *mmh = new MainMenuHost;
    mmh->show();
    this->close();
    }
    else if (accType == "2"){
        MainMenuCust *mmc = new MainMenuCust;
        mmc->show();
        this->close();
    }
}
