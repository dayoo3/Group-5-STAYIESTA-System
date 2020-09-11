#ifndef HOMESTAYUPDATE_H
#define HOMESTAYUPDATE_H

#include <QWidget>

namespace Ui {
class HomestayUpdate;
}

class HomestayUpdate : public QWidget
{
    Q_OBJECT

public:
    explicit HomestayUpdate(QWidget *parent = nullptr);
    ~HomestayUpdate();

private slots:
    void on_buttonConfirm_clicked();

    void on_buttonCancel_clicked();

    void on_buttonHome_clicked();

private:
    Ui::HomestayUpdate *ui;
};

void getFormData(Ui::HomestayUpdate*);

#endif // HOMESTAYUPDATE_H
