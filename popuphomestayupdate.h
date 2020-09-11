#ifndef POPUPHOMESTAYUPDATE_H
#define POPUPHOMESTAYUPDATE_H

#include <QWidget>

namespace Ui {
class PopupHomestayUpdate;
}

class PopupHomestayUpdate : public QWidget
{
    Q_OBJECT

public:
    explicit PopupHomestayUpdate(QWidget *parent = nullptr);
    ~PopupHomestayUpdate();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupHomestayUpdate *ui;
};

#endif // POPUPHOMESTAYUPDATE_H
