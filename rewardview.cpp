#include "rewardview.h"
#include "ui_rewardview.h"
#include "mainmenucust.h"
#include "profileview.h"
#include "dblogin.h"

RewardView::RewardView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RewardView)
{
    ui->setupUi(this);
    refreshRewards(ui);
    setFixedSize(520,230);
}

RewardView::~RewardView()
{
    delete ui;
}

void RewardView::on_buttonHome_clicked()
{
    ProfileView *pv = new ProfileView;
    pv->show();
    this->close();
}

void refreshRewards(Ui::RewardView *ui) {
    DBLogin conn;
    conn.connOpen();

    QString userID = getCurrUserID();

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery *queryPtr = new QSqlQuery(conn.myDB);

    queryPtr->prepare("SELECT reward.rewardID as 'Reward Code', "
                      "user_reward.isUsed as 'Used', "
                      "reward.rewardDesc as 'Description', "
                      "(reward.rewardValidDay || '/' || reward.rewardValidMth || '/' || reward.rewardValidYr) as 'Valid Until' "
                      "FROM reward, users, user_reward WHERE "
                      "users.userID = '"+userID+"' AND "
                      "reward.rewardID = user_reward.rewardID AND "
                      "users.userID = user_reward.userID");
    if (queryPtr->exec())  {
        model->setQuery(*queryPtr);
        ui->tableView->setModel(model);
        ui->tableView->setVisible(false);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setVisible(true);
    }

    conn.connClose();
}
