#ifndef REWARDVIEW_H
#define REWARDVIEW_H

#include <QWidget>

namespace Ui {
class RewardView;
}

class RewardView : public QWidget
{
    Q_OBJECT

public:
    explicit RewardView(QWidget *parent = nullptr);
    ~RewardView();

private slots:
    void on_buttonHome_clicked();

private:
    Ui::RewardView *ui;
};

void refreshRewards(Ui::RewardView*);

#endif // REWARDVIEW_H
