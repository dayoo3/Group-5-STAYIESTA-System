#ifndef POPUPREWARDAPPLIED_H
#define POPUPREWARDAPPLIED_H

#include <QWidget>

namespace Ui {
class PopupRewardApplied;
}

class PopupRewardApplied : public QWidget
{
    Q_OBJECT

public:
    explicit PopupRewardApplied(QWidget *parent = nullptr);
    ~PopupRewardApplied();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupRewardApplied *ui;
};

#endif // REWARDAPPLIED_H
