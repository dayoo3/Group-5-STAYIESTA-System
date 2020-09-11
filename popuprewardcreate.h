#ifndef POPUPREWARDCREATE_H
#define POPUPREWARDCREATE_H

#include <QWidget>

namespace Ui {
class PopupRewardCreate;
}

class PopupRewardCreate : public QWidget
{
    Q_OBJECT

public:
    explicit PopupRewardCreate(QWidget *parent = nullptr);
    ~PopupRewardCreate();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupRewardCreate *ui;
};

#endif // POPUPREWARDCREATE_H
