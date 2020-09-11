#ifndef PAYMENTGATEWAY_H
#define PAYMENTGATEWAY_H

#include <QWidget>

namespace Ui {
class PaymentGateway;
}

class PaymentGateway : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentGateway(QWidget *parent = nullptr);
    ~PaymentGateway();

private slots:
    void on_buttonHome_clicked();

    void on_buttonCancel_clicked();

    void on_buttonAutho_clicked();

private:
    Ui::PaymentGateway *ui;
};

void getFormData(Ui::PaymentGateway*);
QString getCardNum();
QString getCardHolderName();

static QString cardHolderName, cardNumber;

#endif // PAYMENTGATEWAY_H
