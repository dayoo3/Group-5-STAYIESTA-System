#ifndef POPUPHOMESTAYDELETE_H
#define POPUPHOMESTAYDELETE_H

#include <QWidget>

namespace Ui {
class PopupHomestayDelete;
}

class PopupHomestayDelete : public QWidget
{
    Q_OBJECT

public:
    explicit PopupHomestayDelete(QWidget *parent = nullptr);
    ~PopupHomestayDelete();

    private slots:
        void on_buttonOK_clicked();

private:
    Ui::PopupHomestayDelete *ui;
};

#endif // POPUPHOMESTAYDELETE_H
