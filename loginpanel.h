#ifndef LOGINPANEL_H
#define LOGINPANEL_H

#include <QWidget>

namespace Ui {
class LoginPanel;
}

class LoginPanel : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPanel(QWidget *parent = nullptr);
    ~LoginPanel();

private slots:
    void on_buttonReg_clicked();

    void on_buttonLogin_clicked();

    void on_lineEditPass_returnPressed();

private:
    Ui::LoginPanel *ui;
};

static QString currUser;

#endif // LOGINPANEL_H
