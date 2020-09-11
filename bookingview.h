#ifndef BOOKINGVIEW_H
#define BOOKINGVIEW_H

#include <QWidget>

namespace Ui {
class BookingView;
}

class BookingView : public QWidget
{
    Q_OBJECT

public:
    explicit BookingView(QWidget *parent = nullptr);
    ~BookingView();

    private slots:
        void on_buttonDelete_clicked();

        void on_buttonHome_clicked();

        void on_tableView_activated(const QModelIndex &index);

        void on_buttonPay_clicked();

        void on_buttonReview_clicked();

private:
    Ui::BookingView *ui;
};

void refreshTable(Ui::BookingView*);

QString getBookingActivatedID();

#endif // BOOKINGVIEW_H
