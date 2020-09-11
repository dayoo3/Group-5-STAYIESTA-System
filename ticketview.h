#ifndef TICKETVIEW_H
#define TICKETVIEW_H

#include <QWidget>

namespace Ui {
class TicketView;
}

class TicketView : public QWidget
{
    Q_OBJECT

public:
    explicit TicketView(QWidget *parent = nullptr);
    ~TicketView();

private slots:
    void on_buttonHome_clicked();

private:
    Ui::TicketView *ui;
};

void refreshTable(Ui::TicketView*);

#endif // TICKETVIEW_H
