#include "profiledelete.h"
#include "ui_profiledelete.h"
#include "popupprofiledelete.h"
#include "profileview.h"
#include "dblogin.h"

ProfileDelete::ProfileDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileDelete)
{
    ui->setupUi(this);
    setFixedSize(410,210);
    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/trash.png");
    ui->picLbl->setPixmap(pixmapTarget);

    ui->lineEditPass->setEchoMode(QLineEdit::Password);
}

ProfileDelete::~ProfileDelete()
{
    delete ui;
}

void ProfileDelete::on_lineEditPass_returnPressed()
{
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID();
    QString userPass = ui->lineEditPass->text();
    bool isDelete = false;

    QSqlQuery query;
    query.prepare("SELECT userPassword FROM users WHERE userID = '"+userID+"'");
    if (query.exec()) {
        query.next();
        if (userPass == query.value(0).toString())
            isDelete = true;
        else {
            ui->aLabel->setText("<font color=red>Wrong Password</font>");
        }
    }

    if (isDelete) {
        query.prepare("DELETE FROM users WHERE userID = '"+userID+"'");
        if (query.exec()) {
            PopupProfileDelete *pdPopup = new PopupProfileDelete;
            pdPopup->show();
            this->close();
        }
    }
}

void ProfileDelete::on_buttonConfirm_clicked() {
    ProfileDelete::on_lineEditPass_returnPressed();
}

void ProfileDelete::on_buttonCancel_clicked()
{
    ProfileView *pPanel = new ProfileView;
    pPanel->show();
    this->close();
}
