#ifndef MAINMENUTECH_H
#define MAINMENUTECH_H

#include <QMainWindow>

namespace Ui {
class MainMenuTech;
}

class MainMenuTech : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuTech(QWidget *parent = nullptr);
    ~MainMenuTech();

private slots:
    void on_buttonAccount_clicked();
    void on_buttonTicket_clicked();
    void on_buttonReward_clicked();
    void on_buttonLogout_clicked();

private:
    Ui::MainMenuTech *ui;
};

#endif // MAINMENUTECH_H
