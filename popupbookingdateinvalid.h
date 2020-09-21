#ifndef POPUPBOOKINGDATEINVALID_H
#define POPUPBOOKINGDATEINVALID_H

#include <QWidget>

namespace Ui {
class popupBookingDateInvalid;
}

class popupBookingDateInvalid : public QWidget
{
    Q_OBJECT

public:
    explicit popupBookingDateInvalid(QWidget *parent = nullptr);
    ~popupBookingDateInvalid();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::popupBookingDateInvalid *ui;
};

#endif // POPUPBOOKINGDATEINVALID_H
