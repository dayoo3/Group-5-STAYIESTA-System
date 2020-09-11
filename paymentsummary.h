#ifndef PAYMENTSUMMARY_H
#define PAYMENTSUMMARY_H

#include <QWidget>
#include <QModelIndexList>

namespace Ui {
class PaymentSummary;
}

class PaymentSummary : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentSummary(QWidget *parent = nullptr);
    ~PaymentSummary();

private slots:
    void on_buttonCancel_clicked();

    void on_buttonHome_clicked();

    void on_buttonApply_clicked();

    void on_lineEditReward_returnPressed();

    void on_buttonPay_clicked();

private:
    Ui::PaymentSummary *ui;
};

void refreshList(Ui::PaymentSummary*);

QString getTotalPrice();
bool getIsDiscounted();
QString getRewardID();

static QString daysDiff, totalPrice, rewardID;
static bool isDiscounted = false;

#endif // PAYMENTSUMMARY_H
