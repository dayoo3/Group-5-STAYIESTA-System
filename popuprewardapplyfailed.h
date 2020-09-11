#ifndef POPUPREWARDAPPLYFAILED_H
#define POPUPREWARDAPPLYFAILED_H

#include <QWidget>

namespace Ui {
class PopupRewardApplyFailed;
}

class PopupRewardApplyFailed : public QWidget
{
    Q_OBJECT

public:
    explicit PopupRewardApplyFailed(QWidget *parent = nullptr);
    ~PopupRewardApplyFailed();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupRewardApplyFailed *ui;
};

#endif // POPUPREWARDAPPLYFAILED_H
