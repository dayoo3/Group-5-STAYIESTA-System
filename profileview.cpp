#include "profileview.h"
#include "ui_profileview.h"
#include "popupprofileupdate.h"
#include "mainmenucust.h"
#include "rewardview.h"
#include "profiledelete.h"
#include "popupprofiledelete.h"
#include "dblogin.h"
#include "mainmenuhost.h"

static QString accType = "0";

ProfileView::ProfileView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileView)
{
    ui->setupUi(this);
    getFormData(ui);
    setFixedSize(530,360);
}

ProfileView::~ProfileView()
{
    delete ui;
}

void ProfileView::on_buttonHome_clicked()
{
    QString userID = getCurrUserID();
    DBLogin conn;
    conn.connOpen();

    QSqlQuery query;
    query.prepare("SELECT acctype FROM User WHERE userID = '"+userID+"'");
    if(query.exec()) {
        query.next();
        accType = query.value(0).toString();
    }

    if (accType == "1") {
        MainMenuHost *mmh = new MainMenuHost;
        mmh->show();
        this->close();
    }
    else if (accType == "2"){
        MainMenuCust *mmc = new MainMenuCust;
        mmc->show();
        this->close();
    }
    conn.connClose();
}

void ProfileView::on_buttonDelete_clicked()
{
    ProfileDelete *pd = new ProfileDelete;
    pd->show();
    this->close();
}

void ProfileView::on_buttonUpdate_clicked()
{
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID();

    bool isUpdate = false;
    QSqlQuery query;
    QString userPass = ui->lineEditPass->text(),
            userPassCheck = ui->lineEditPass_2->text(),
            userAddr = ui->lineEditAddr->text(),
            userPhone = ui->lineEditPhone->text();

    query.prepare("SELECT userPassword FROM User WHERE userID = '"+userID+"'");
    if (query.exec()) {
        query.next();
        if (userPass != query.value(0).toString()) {
            if (userPass == userPassCheck) {
                isUpdate = true;
                ui->aLabel->setText("");
            }
            else
                ui->aLabel->setText("Passwords do not match");
        }
        else {
            isUpdate = true;
            ui->aLabel->setText("");
        }
    }

    if (isUpdate) {
        query.prepare("UPDATE User SET userPassword = '"+userPass+"', userEmail = '"+userAddr+"', userPhoneNum = '"+userPhone+"'"
                      "WHERE userID = '"+userID+"'");
        if (query.exec()) {
            PopupProfileUpdate *pud = new PopupProfileUpdate;
            pud->show();
        }
    }
}

void ProfileView::on_buttonReward_clicked()
{
    RewardView *vRew = new RewardView;
    vRew->show();
    this->close();
}

void getFormData(Ui::ProfileView* ui) {
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID();
    QString userFName,
            userLName,
            username,
            userPass,
            userPhoneNum,
            userAddr;

    if (accType == "1") {
         ui->buttonReward->setEnabled(false);
    }

    QSqlQuery query;
    query.exec("SELECT * FROM User WHERE userID = '"+userID+"'");
    if (query.exec()) {
        query.next();
        userFName = query.value(1).toString();
        userLName = query.value(2).toString();
        username = query.value(3).toString();
        userPass = query.value(4).toString();
        userPhoneNum = query.value(5).toString();
        userAddr = query.value(6).toString();
        accType = query.value(7).toString();
    }

    ui->lineEditFName->setText(userFName);
    ui->lineEditLName->setText(userLName);
    ui->lineEditType->setText("Customer");
    ui->lineEditAddr->setText(userAddr);
    ui->lineEditPhone->setText(userPhoneNum);
    ui->lineEditUser->setText(username);
    ui->lineEditPass->setText(userPass);
    ui->lineEditPass_2->setPlaceholderText("Leave empty if password unchanged");

    ui->lineEditPass->setEchoMode(QLineEdit::Password);
    ui->lineEditPass_2->setEchoMode(QLineEdit::Password);

    conn.connClose();
}
