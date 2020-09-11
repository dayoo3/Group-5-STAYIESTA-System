#ifndef TICKETCREATE_H
#define TICKETCREATE_H

#include <QWidget>

namespace Ui {
class TicketCreate;
}

class TicketCreate : public QWidget
{
    Q_OBJECT

public:
    explicit TicketCreate(QWidget *parent = nullptr);
    ~TicketCreate();

private slots:
    void on_buttonReset_clicked();

    void on_buttonSubmit_clicked();

    void on_buttonHome_clicked();

private:
    Ui::TicketCreate *ui;
};

QString IDCreate();

#endif // TICKETCREATE_H
