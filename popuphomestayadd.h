#ifndef POPUPHOMESTAYADD_H
#define POPUPHOMESTAYADD_H

#include <QWidget>

namespace Ui {
class PopupHomestayAdd;
}

class PopupHomestayAdd : public QWidget
{
    Q_OBJECT

public:
    explicit PopupHomestayAdd(QWidget *parent = nullptr);
    ~PopupHomestayAdd();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupHomestayAdd *ui;
};

#endif // POPUPHOMESTAYADD_H
