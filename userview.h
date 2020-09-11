#ifndef USERVIEW_H
#define USERVIEW_H

#include <QWidget>

namespace Ui {
class UserView;
}

class UserView : public QWidget
{
    Q_OBJECT

public:
    explicit UserView(QWidget *parent = nullptr);
    ~UserView();

private slots:
    void on_buttonHome_clicked();

private:
    Ui::UserView *ui;
};

void refreshTable(Ui::UserView*);

#endif // VIEWUSER_H
