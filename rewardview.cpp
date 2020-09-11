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

    queryPtr->prepare("SELECT Reward.rewardID as 'Reward Code', "
                      "User_Reward.isUsed as 'Used', "
                      "Reward.rewardDesc as 'Description', "
                      "(Reward.rewardValidDay || '/' || Reward.rewardValidMth || '/' || Reward.rewardValidYr) as 'Valid Until' "
                      "FROM Reward, User, User_Reward WHERE "
                      "User.userID = '"+userID+"' AND "
                      "Reward.rewardID = User_Reward.rewardID AND "
                      "User.userID = User_Reward.userID");
    if (queryPtr->exec())  {
        model->setQuery(*queryPtr);
        ui->tableView->setModel(model);
        ui->tableView->setVisible(false);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setVisible(true);
    }

    conn.connClose();
}
