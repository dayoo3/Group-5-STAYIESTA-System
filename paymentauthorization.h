#ifndef PAYMENTAUTHORIZATION_H
#define PAYMENTAUTHORIZATION_H

#include <QWidget>

namespace Ui {
class PaymentAuthorization;
}

class PaymentAuthorization : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentAuthorization(QWidget *parent = nullptr);
    ~PaymentAuthorization();

private slots:
    void on_buttonCancel_clicked();

    void on_buttonSubmit_clicked();

    void on_lineEditCaptcha_returnPressed();

private:
    Ui::PaymentAuthorization *ui;
};

QString randomCaptcha(size_t);
QString IDCheckPayment();

#endif // PAYMENTAUTHORIZATION_H
