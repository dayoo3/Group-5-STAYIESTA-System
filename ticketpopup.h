#ifndef TICKETPOPUP_H
#define TICKETPOPUP_H

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
    void on_buttonOk_clicked();

private:
    Ui::PopupTicketCreate *ui;
};

#endif // TICKETPOPUP_H
