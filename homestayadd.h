#ifndef HOMESTAYADD_H
#define HOMESTAYADD_H

#include <QWidget>

namespace Ui {
class HomestayAdd;
}

class HomestayAdd : public QWidget
{
    Q_OBJECT

public:
    explicit HomestayAdd(QWidget *parent = nullptr);
    ~HomestayAdd();

private slots:
    void on_buttonHome_clicked();

    void on_buttonReset_clicked();

    void on_buttonAdd_clicked();

private:
    Ui::HomestayAdd *ui;
};

QString IDCheckHomestay();

#endif // HOMESTAYADD_H
