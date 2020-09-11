#ifndef POPUPBOOKINGDELETE_H
#define POPUPBOOKINGDELETE_H

#include <QWidget>

namespace Ui {
class PopupBookingDelete;
}

class PopupBookingDelete : public QWidget
{
    Q_OBJECT

public:
    explicit PopupBookingDelete(QWidget *parent = nullptr);
    ~PopupBookingDelete();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupBookingDelete *ui;
};

#endif // PopupBookingDelete
