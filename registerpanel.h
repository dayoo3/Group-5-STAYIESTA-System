#ifndef REGISTERPANEL_H
#define REGISTERPANEL_H

#include <QWidget>
#include <QtSql>
#include <QDebug>

namespace Ui {
class RegisterPanel;
}

class RegisterPanel : public QWidget
{
    Q_OBJECT

public:    
    explicit RegisterPanel(QWidget *parent = nullptr);
    ~RegisterPanel();

private slots:
    void on_lineEditAddr_returnPressed();

    void on_buttonBack_clicked();

    void on_checkBoxCust_toggled(bool checked);

    void on_checkBoxHost_toggled(bool checked);

    void on_buttonRegister_clicked();

private:
    Ui::RegisterPanel *ui;
};

QString IDCheck(QString);

#endif // REGISTERPANEL_H
