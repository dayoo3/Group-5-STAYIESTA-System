#ifndef MAINMENUHOST_H
#define MAINMENUHOST_H

#include <QMainWindow>

namespace Ui {
class MainMenuHost;
}

class MainMenuHost : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuHost(QWidget *parent = nullptr);
    ~MainMenuHost();

private slots:
    void on_buttonLogout_clicked();

    void on_buttonAccount_clicked();

    void on_buttonHomestays_clicked();

    void on_buttonMaint_clicked();

private:
    Ui::MainMenuHost *ui;
};

#endif // MAINMENUHOST_H
