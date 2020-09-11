#ifndef HOMESTAYDELETE_H
#define HOMESTAYDELETE_H

#include <QWidget>

namespace Ui {
class HomestayDelete;
}

class HomestayDelete : public QWidget
{
    Q_OBJECT

public:
    explicit HomestayDelete(QWidget *parent = nullptr);
    ~HomestayDelete();

private slots:
    void on_buttonConfirm_clicked();

    void on_buttonCancel_clicked();

    void on_lineEditPass_returnPressed();

private:
    Ui::HomestayDelete *ui;
};

#endif // HOMESTAYDELETE_H
