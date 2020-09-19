#include "registerpanel.h"
#include "ui_registerpanel.h"
#include "dblogin.h"
#include "allclasses.h"
#include "popupregisterpanel.h"

RegisterPanel::RegisterPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterPanel)
{
    ui->setupUi(this);
    setWindowTitle("Registration");
    setFixedSize(400,320);

    ui->label->setAlignment(Qt::AlignRight);
    ui->label_2->setAlignment(Qt::AlignRight);
    ui->label_3->setAlignment(Qt::AlignRight);
    ui->label_4->setAlignment(Qt::AlignRight);
    ui->label_5->setAlignment(Qt::AlignRight);
    ui->label_6->setAlignment(Qt::AlignRight);
    ui->regStatus->setText("<font color='grey'>(*) indicates required field</font>");

    ui->lineEditPass->setEchoMode(QLineEdit::Password);

    ui->checkBoxCust->setChecked(true);
    connect(ui->checkBoxCust, SIGNAL(toggled()), this, SLOT(on_checkBoxCust_toggled(bool)));
    connect(ui->checkBoxHost, SIGNAL(toggled()), this, SLOT(on_checkBoxHost_toggled(bool)));
}

RegisterPanel::~RegisterPanel()
{
    delete ui;
}

void RegisterPanel::on_lineEditAddr_returnPressed()
{
    DBLogin conn;
    conn.connOpen();

    QString fName,lName,user,password,phoneNum,email;
    fName = ui->lineEditFName->text();
    lName = ui->lineEditLName->text();
    user = ui->lineEditUser->text();
    password = ui->lineEditPass->text();
    phoneNum = ui->lineEditPhone->text();
    email = ui->lineEditAddr->text();

    if (!(fName == "" || lName == "" || user == "" || password == "" || phoneNum == "" || email == "")) {
        QSqlQuery query;
        query.exec("SELECT userID FROM users");

        query.prepare("INSERT INTO users (userID,userFirstName,userLastName,username,userPassword,userPhoneNum,userEmail, accType) VALUES"
                   "(:userID, :userFirstName, :userLastName, :username, :userPassword, :userPhoneNum, :userEmail, :accType)");
        if (ui->checkBoxCust->isChecked()) {
            Customer newUser("C", fName, lName, user, password, phoneNum, email);
            newUser.setUserID(IDCheck("C"));
            query.bindValue(":userID", newUser.getUserID());
            query.bindValue(":userFirstName",fName);
            query.bindValue(":userLastName",lName);
            query.bindValue(":username",user);
            query.bindValue(":userPassword",password);
            query.bindValue(":userPhoneNum",phoneNum);
            query.bindValue(":userEmail",email);
            query.bindValue(":accType",2);

        }
        else {
            Host newUser("H", fName, lName, user, password, phoneNum, email);
            newUser.setUserID(IDCheck("H"));
            query.bindValue(":userID", newUser.getUserID());
            query.bindValue(":userFirstName",fName);
            query.bindValue(":userLastName",lName);
            query.bindValue(":username",user);
            query.bindValue(":userPassword",password);
            query.bindValue(":userPhoneNum",phoneNum);
            query.bindValue(":userEmail",email);
            query.bindValue(":accType",1);
       }

       bool results = query.exec();

       if (results == false) {
           ui->regStatus->setText("<font color=red>Username/Email already exists</font>");
       }
       else {
           ui->regStatus->setText("");
           PopupRegisterPanel *rPopup = new PopupRegisterPanel;
           rPopup->show();
           this->hide();

       }
    }
    else {
        ui->regStatus->setText("<font color=red>Required field(s) is empty</font>");
    }

    conn.connClose();
}

void RegisterPanel::on_buttonBack_clicked()
{
    this->close();
}

void RegisterPanel::on_checkBoxCust_toggled(bool checked)
{
    if (checked == false) {
        ui->checkBoxHost->setChecked(true);
    }
    else {
        ui->checkBoxHost->setChecked(false);
    }
}

void RegisterPanel::on_checkBoxHost_toggled(bool checked)
{
    if (checked == false) {
        ui->checkBoxCust->setChecked(true);
    }
    else {
        ui->checkBoxCust->setChecked(false);
    }
}

void RegisterPanel::on_buttonRegister_clicked()
{
    on_lineEditAddr_returnPressed();
}

QString IDCheck(QString accType) {
    QSqlQuery query;
    query.exec("SELECT userID FROM users");

    bool IDChecking = true;
    QString tempID = "";
    srand(time(nullptr));
    while (IDChecking == true) {
        tempID = accType+QString::number(rand() % 100000);
        while(query.next()) {
            if (tempID == query.value(0))
                continue;
            else {
                IDChecking = false;
                break;
            }
        }
    }
    return tempID;
}
