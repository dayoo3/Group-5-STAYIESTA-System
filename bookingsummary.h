#ifndef BOOKINGSUMMARY_H
#define BOOKINGSUMMARY_H

#include <QWidget>

namespace Ui {
class BookingSummary;
}

class BookingSummary : public QWidget
{
    Q_OBJECT

public:
    explicit BookingSummary(QWidget *parent = nullptr);
    ~BookingSummary();

private slots:
    void on_buttonHome_clicked();

    void on_buttonReturn_clicked();

    void on_buttonBook_clicked();

private:
    Ui::BookingSummary *ui;
};

void refreshTable(Ui::BookingSummary*);

#endif // BOOKINGSUMMARY_H
