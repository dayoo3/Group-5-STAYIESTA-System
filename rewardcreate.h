#ifndef REWARDCREATE_H
#define REWARDCREATE_H

#include <QWidget>

namespace Ui {
class RewardCreate;
}

class RewardCreate : public QWidget
{
    Q_OBJECT

public:
    explicit RewardCreate(QWidget *parent = nullptr);
    ~RewardCreate();

private slots:
    void on_buttonReset_clicked();

    void on_buttonSubmt_clicked();

    void on_buttonHome_clicked();

private:
    Ui::RewardCreate *ui;
};

#endif // CREATEREWARD_H
