#include "loginpanel.h"
#include "ui_loginpanel.h"
#include "dblogin.h"
#include "registerpanel.h"
#include "mainmenutech.h"
#include "mainmenucust.h"
#include "mainmenuhost.h"

// declare global vector to push_back currUserUD
                                  // and determine current user username by accessing database

LoginPanel::LoginPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPanel)
{
    ui->setupUi(this);
    setWindowTitle("Welcome to Stayiesta!");
    setFixedSize(350,232);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/logo.png");
    ui->picLbl->setPixmap(pixmapTarget );

    ui->label->setAlignment(Qt::AlignLeft);
    ui->label_2->setAlignment(Qt::AlignLeft);
    ui->lineEditPass->setEchoMode(QLineEdit::Password);
}

LoginPanel::~LoginPanel()
{
    delete ui;
}

void LoginPanel::on_buttonLogin_clicked() {
    LoginPanel::on_lineEditPass_returnPressed();
}
void LoginPanel::on_lineEditPass_returnPressed()
{
    currUser = "";

    DBLogin conn;
    conn.connOpen();

    QString username,password;
    int accType = 0;
    username = ui->lineEditUser->text();
    password = ui->lineEditPass->text();

    QSqlQuery query;
    query.exec("SELECT * FROM User");

    bool userVerify = false;
    while (query.next()) {
        QString userIDCheck=query.value(0).toString(),
                usernameCheck=query.value(3).toString(),
                passwordCheck=query.value(4).toString();
        int accTypeCheck=query.value(7).toInt();
        if (username==usernameCheck && password==passwordCheck) {
            qDebug() << "Username: " << usernameCheck << endl
                     << "Password: " << passwordCheck << endl;

            accType = accTypeCheck;
            currUser = userIDCheck;
            userVerify = true;
            break;
        }
    }
    if (userVerify==true) {
        ui->logStatus->setText("Login successful");
        qDebug() << "Login successful";
        conn.connClose();
        this->hide();

        if (accType==1) {
            MainMenuHost *mWindow = new MainMenuHost;
            mWindow->show();
        }
        else if (accType==2) {
            MainMenuCust *mWindow = new MainMenuCust;
            mWindow->show();
        }
        else if (accType==3) {
            MainMenuTech *mWindow = new MainMenuTech;
            mWindow->show();
        }
    }
    else {
        ui->logStatus->setText("Username/password does not match/exists.");
    }
    conn.connClose();
}

void LoginPanel::on_buttonReg_clicked() {
    RegisterPanel *rForm = new RegisterPanel;
    rForm->show();
}

QString getCurrUsername() { // class to use among multiple cpp files
    DBLogin conn;
    QString username = "";

    if (conn.connOpen()) {
        QSqlQuery query("SELECT username FROM User WHERE userID='"+currUser+"'");
        query.next();
        username = query.value(0).toString();
    }
    conn.connClose();
    return username;
}

QString getCurrUserID() { // class to use among multiple cpp files

    return currUser;
}
