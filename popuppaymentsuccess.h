#ifndef POPUPPAYMENTSUCCESS_H
#define POPUPPAYMENTSUCCESS_H

#include <QWidget>

namespace Ui {
class PopupPaymentSuccess;
}

class PopupPaymentSuccess : public QWidget
{
    Q_OBJECT

public:
    explicit PopupPaymentSuccess(QWidget *parent = nullptr);
    ~PopupPaymentSuccess();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupPaymentSuccess *ui;
};

#endif // POPUPPAYMENTSUCCESS_H
