#ifndef BOOKINGDELETE_H
#define BOOKINGDELETE_H

#include <QWidget>

namespace Ui {
class BookingDelete;
}

class BookingDelete : public QWidget
{
    Q_OBJECT

public:
    explicit BookingDelete(QWidget *parent = nullptr);
    ~BookingDelete();

private slots:
    void on_buttonCancel_clicked();

    void on_buttonConfirm_clicked();

    void on_lineEditPass_returnPressed();

private:
    Ui::BookingDelete *ui;
};

#endif // DELBOOKPOPUP_H
