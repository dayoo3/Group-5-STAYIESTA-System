#ifndef BOOKINGCREATE_H
#define BOOKINGCREATE_H

#include <QWidget>

namespace Ui {
class BookingCreate;
}

class BookingCreate : public QWidget
{
    Q_OBJECT

public:
    explicit BookingCreate(QWidget *parent = nullptr);
    ~BookingCreate();

private slots:
    void on_buttonHome_clicked();

    void on_buttonReturn_clicked();

    void on_buttonBook_clicked();

    void on_dateEditIn_userDateChanged(const QDate &date);

    void on_dateEditOut_userDateChanged(const QDate &date);

private:
    Ui::BookingCreate *ui;
};

void getFormData(Ui::BookingCreate*);
QString IDCheckBooking();

QString getBookingID();
QDate getDateIn();
QDate getDateOut();

#endif // BOOKINGCREATE_H
