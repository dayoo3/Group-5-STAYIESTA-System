#ifndef MAINMENUCUST_H
#define MAINMENUCUST_H

#include <QMainWindow>

namespace Ui {
class MainMenuCust;
}

class MainMenuCust : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuCust(QWidget *parent = nullptr);
    ~MainMenuCust();

private slots:
    void on_buttonLogout_clicked();

    void on_buttonBookings_clicked();

    void on_buttonAccount_clicked();

    void on_buttonTicket_clicked();

    void on_lineEditSearch_returnPressed();

private:
    Ui::MainMenuCust *ui;

};

QString getSearchLocation();

#endif // MAINMENUCUST_H
