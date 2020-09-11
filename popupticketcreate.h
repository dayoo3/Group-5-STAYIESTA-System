#ifndef POPUPTICKETCREATE_H
#define POPUPTICKETCREATE_H

#include <QWidget>

namespace Ui {
class PopupTicketCreate;
}

class PopupTicketCreate : public QWidget
{
    Q_OBJECT

public:
    explicit PopupTicketCreate(QWidget *parent = nullptr);
    ~PopupTicketCreate();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupTicketCreate *ui;
};

#endif // POPUPTICKETCREATE_H
