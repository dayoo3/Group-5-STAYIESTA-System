#include "rewardcreate.h"
#include "ui_rewardcreate.h"
#include "popuprewardcreate.h"
#include "dblogin.h"
#include "mainmenutech.h"

QString randomRewardID(size_t length);
RewardCreate::RewardCreate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RewardCreate)
{
    ui->setupUi(this);
    setFixedSize(460,310);

    QString rewardID = randomRewardID(6);
    ui->lineID->setText(rewardID);
}

RewardCreate::~RewardCreate()
{
    delete ui;
}

void RewardCreate::on_buttonReset_clicked()
{

}

void RewardCreate::on_buttonSubmt_clicked()
{
    QString rewardID = ui->lineID->text();
    QString day = ui->lineDay->text();
    QString month = ui->lineMonth->text();
    QString year = ui->lineYear->text();
    QString description = ui->textEdit->toPlainText();
    QString value = ui->lineValue->text();
    QString rewardType = ui->rewardType->currentText();

    DBLogin conn;
    conn.connOpen();
    QSqlQuery query;
    query.prepare("INSERT INTO reward VALUES"
                  "('"+rewardID+"','"+description+"','"+day+"','"+month+"','"+year+"','"+rewardType+"','"+value+"')");
    if(query.exec()){
        query.next();
        PopupRewardCreate *rpop = new PopupRewardCreate;
        rpop->show();
        this->close();
    }
    else{
        qDebug() << query.lastError();
    }

    conn.connClose();
}

QString randomRewardID(size_t length)
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    QString str(length, 0);

    DBLogin conn;
    conn.connOpen();

    QSqlQuery query;
    query.exec("SELECT rewardID FROM reward");

    bool IDChecking = true;
    while (IDChecking == true) {
        std::generate_n( str.begin(), length, randchar);
        while(query.next()) {
            if (str == query.value(0).toString()) {
                std::generate_n( str.begin(), length, randchar);
                continue;
            }
            else {
                IDChecking = false;
                break;
            }

        }
    }

    conn.connClose();
    return str;
}

void RewardCreate::on_buttonHome_clicked()
{
    MainMenuTech *mmt = new MainMenuTech;
    mmt->show();
    this->close();
}
