#ifndef POPUPREWARDUSED_H
#define POPUPREWARDUSED_H

#include <QWidget>

namespace Ui {
class PopupRewardUsed;
}

class PopupRewardUsed : public QWidget
{
    Q_OBJECT

public:
    explicit PopupRewardUsed(QWidget *parent = nullptr);
    ~PopupRewardUsed();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupRewardUsed *ui;
};

#endif // POPUPREWARDUSED_H
