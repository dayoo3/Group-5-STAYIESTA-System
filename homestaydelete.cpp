#include "homestaydelete.h"
#include "ui_homestaydelete.h"
#include "homestayview.h"
#include "popuphomestaydelete.h"
#include "dblogin.h"
#include "QDebug"

HomestayDelete::HomestayDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomestayDelete)
{
    ui->setupUi(this);
    setFixedSize(410,210);

    QPixmap pixmapTarget = QPixmap("/Users/mlikr/QtProjects/ARROBA/trash.png");
    ui->picLbl->setPixmap(pixmapTarget);
}

HomestayDelete::~HomestayDelete()
{
    delete ui;
}

void HomestayDelete::on_buttonConfirm_clicked()
{
    DBLogin conn;
    conn.connOpen();

    QString homestayID = getHomestayActivatedID();
    QString userID = getCurrUserID();
    QString userPass = ui->lineEditPass->text();

    bool isDelete = false;

    QSqlQuery query;
    query.prepare("SELECT userPassword FROM users WHERE userID = '"+userID+"'");
    if (query.exec()) {
        query.next();
        if (userPass == query.value(0).toString()) {
            isDelete = true;
        }
    }
    else {
        qDebug() << query.lastError();
    }

    if (isDelete) {
        query.prepare("DELETE FROM homestay WHERE homestayID = '"+homestayID+"'");
        if (query.exec()) {
            PopupHomestayDelete *phd = new PopupHomestayDelete;
            phd->show();
            this->close();
        }
        else {
            qDebug() << query.lastError();
        }
    }
    conn.connClose();

}

void HomestayDelete::on_buttonCancel_clicked()
{
    HomestayView *vh = new HomestayView;
    vh->show();
    this->close();
}

void HomestayDelete::on_lineEditPass_returnPressed()
{
    HomestayDelete::on_buttonConfirm_clicked();
}
