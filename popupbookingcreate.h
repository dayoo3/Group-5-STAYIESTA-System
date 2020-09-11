#ifndef POPUPBOOKINGCREATE_H
#define POPUPBOOKINGCREATE_H

#include <QWidget>

namespace Ui {
class PopupBookingCreate;
}

class PopupBookingCreate : public QWidget
{
    Q_OBJECT

public:
    explicit PopupBookingCreate(QWidget *parent = nullptr);
    ~PopupBookingCreate();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupBookingCreate *ui;
};

#endif // POPUPBOOKINGCREATE_H
